<?php


/**
 * @file
 * Definition of geolocation_proximity_views_handler_sort_distance.
 */

/**
 * Distance field handler for views.
 */
class geolocation_proximity_views_handler_sort_distance extends views_handler_sort {

  /**
   * init the handler with necessary data.
   */
  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->field_alias = $this->options['id'] . '_sort';
    $field_id = str_replace('_distance', '', $this->real_field);
    $this->geolocation_proximity_field_id = $field_id;
  }

  /**
   *  Provide the ability to expose it or not.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['expose_button']['#access'] = TRUE;
  }


  /**
   * views_handler_filter::option_definition
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['exposed'] = array(
      'default' => TRUE,
      'bool' => TRUE,
    );
    $options['label'] = "Distance"; //default
    $option['use_filter'] = TRUE;
    return $options;
  }

  /**
   * Render our chunk of the exposed handler form when selecting
   */
  function exposed_form(&$form, &$form_state) {

    $form[$this->field_alias] = array(
      '#tree' => TRUE,
      '#title' => $this->options['label'],
      '#type' => 'item',
    );

    $form[$this->field_alias]['latitude'] = array(
      '#type' => 'textfield',
      '#title' => t('Latitude'),
      '#required' => TRUE,
      '#default_value' => $this->options['location']['latitude'],
      '#weight' => 1,
    );
    $form[$this->field_alias]['longitude'] = array(
      '#type' => 'textfield',
      '#title' => t('Longitude'),
      '#required' => TRUE,
      '#default_value' => $this->options['location']['longitude'],
      '#weight' => 2,
    );
  }


  /**
   * Provide a form for setting options.
   */
  function extra_options_form(&$form, &$form_state) {
    $filters = array(
      '' => t(' - Use own values - ')
    );
    foreach ($this->view->get_items('filter') as $filter) {
      if (preg_match('/^' . $this->real_field . '/', $filter['field'])) {
        $filters[$filter['id']] = $filter['ui_name'] ? $filter['ui_name'] . " ({$filter['field']})" : $filter['field'];
      }
    }
    $form['use_filter'] = array(
      '#type' => 'select',
      '#options' => $filters,
      '#title' => t('Use filter'),
      '#default_value' => $this->options['use_filter'],
      '#description' => t('This field requires a location (latitude, longitude) to use as reference for calculating the distance. If there are filters for this same field, the location set for the given filter can be used. If not one needs to be provided.'),
    );

    $form['location'] = array(
      '#tree' => TRUE,
      '#type' => 'fieldset',
      '#title' => t('Default location'),
      '#states' => array(
        // Only show this field when the 'toggle_me' checkbox is enabled.
        'visible' => array(
          '[name="options[use_filter]"]' => array('value' => ''),
        ),
      ),
    );

    $form['location']['latitude'] = array(
      '#type' => 'textfield',
      '#title' => t('Latitude'),
      '#required' => TRUE,
      '#default_value' => $this->options['location']['latitude'],
      '#weight' => 1,
    );
    $form['location']['longitude'] = array(
      '#type' => 'textfield',
      '#title' => t('Longitude'),
      '#required' => TRUE,
      '#default_value' => $this->options['location']['longitude'],
      '#weight' => 2,
    );
  }

  /**
   * If a handler has 'extra options' it will get a little settings widget and
   * another form called extra_options.
   */
  function has_extra_options() {
    return TRUE;
  }

  /**
   * Provide defaults for the handler.
   */
  function extra_options(&$option) {
    $option['use_filter'] = FALSE;
    $option['location'] = array(
      'latitude' => 0,
      'longitude' => 0,
    );
  }

  /**
   * Validate the options form.
   */
  function extra_options_validate(&$form, &$form_state) {
    $this->latlng_validate($form['location'], $form_state['values']['options']['location']);
  }

  /**
   * Validate the exposed handler form
   */
  function exposed_validate(&$form, &$form_state) {
    $field_id = $this->geolocation_proximity_field_id;
    $this->latlng_validate($form[$this->field_alias], $form_state['values'][$this->field_alias]);
  }

  /**
   * Submit the exposed handler form.
   */
  function exposed_submit(&$form, &$form_state) {
    $field_id = $this->geolocation_proximity_field_id;
    $this->options['location']['latitude'] = $form_state['values'][$this->field_alias]['latitude'];
    $this->options['location']['longitude'] = $form_state['values'][$this->field_alias]['longitude'];
  }


  /**
   * Validate the latitude and longitude values
   */
  function latlng_validate(&$elements, &$values) {
    switch (TRUE) {
      case !is_numeric($values['latitude']):
        form_error($elements['latitude'], t('Invalid Latitude. Value must be numeric.'));
        break;

      case $values['latitude'] > 90:
      case $values['latitude'] < -90:
        form_error($elements['latitude'], t('Invalid Latitude. Value must be between 90 and -90.'));
        break;
    }

    switch (TRUE) {
      case !is_numeric($values['longitude']):
        form_error($elements['longitude'], t('Invalid Longitude. Value must be numeric.'));
        break;

      case $values['longitude'] > 180:
      case $values['longitude'] < -180:
        form_error($elements['longitude'], t('Invalid Longitude. Value must be between 180 and -180.'));
        break;
    }
  }


  /**
   * Called to add the field to a query.
   */
  function query() {
    $this->ensure_my_table();
    $table = $this->table_alias;
    $field_id = $this->geolocation_proximity_field_id;

    // Prepare filter values.
    if (isset($this->options['use_filter']) && $this->options['use_filter']) {
      // Let's just use the same sql that the filter uses
      //$sql = $this->query->fields[$this->options['use_filter']]['field'];
      $field = $this->query->fields[$this->options['use_filter'] . '_filter']['alias'];
      $this->query->add_orderby(NULL, NULL, $this->options['order'], $field);
    } else {
      // use provided values for lat/lng
      $filter_lat = $this->options['location']['latitude'];
      $filter_lng = $this->options['location']['longitude'];

      // Prepare field values.
      $field_latsin = "{$table}.{$field_id}_lat_sin";
      $field_latcos = "{$table}.{$field_id}_lat_cos";
      $field_lng= "{$table}.{$field_id}_lng_rad";

      // build sql fragment
      $sql = _proximity_sql_fragment($filter_lat, $filter_lng, $field_latsin, $field_latcos, $field_lng);

      // add the order by fragment to the query!
      $this->query->add_orderby(NULL, $sql, $this->options['order'], $this->field_alias);
    }
  }
}