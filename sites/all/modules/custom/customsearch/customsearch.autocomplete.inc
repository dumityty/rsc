<?php

/**
 * Function to retrieve autocomplete results for the search form.
 * @param  string
 * @return [type]
 */
function customsearch_search_autocomplete($string = '') {
  $autocomplete = array();

  // Autocomplete - Road name
  $query = db_query('SELECT DISTINCT field_kf_road_name_value FROM field_data_field_kf_road_name WHERE field_kf_road_name_value LIKE :road', array('road' => $string . '%'));
  $result = $query->fetchAll();
  if (!empty($result)) {
    foreach ($result as $key => $road) {
      // $autocomplete[$result->field_kf_road_name_value] = "<h5>Testing header??</h5><b>".$result->field_kf_road_name_value."</b>";
      $autocomplete[$road->field_kf_road_name_value] = $road->field_kf_road_name_value;
    }
  }

  // Autocomplete - City
  $query = db_query('SELECT field_kf_address_locality FROM field_data_field_kf_address WHERE field_kf_address_locality LIKE :search GROUP BY field_kf_address_locality', array('search' => $string . '%'));
  $result = $query->fetchAll();
  if (!empty($result)) {
    foreach ($result as $key => $address) {
      if (!empty($address->field_kf_address_locality)) {
        $autocomplete[$address->field_kf_address_locality] = $address->field_kf_address_locality;
      }
    }
  }

  // Autocomplete - County
  $query = db_query('SELECT field_kf_address_administrative_area FROM field_data_field_kf_address WHERE field_kf_address_administrative_area LIKE :search GROUP BY field_kf_address_administrative_area', array('search' => $string . '%'));
  $result = $query->fetchAll();
  if (!empty($result)) {
    foreach ($result as $key => $address) {
      if (!empty($address->field_kf_address_administrative_area)) {
        $autocomplete[$address->field_kf_address_administrative_area] = $address->field_kf_address_administrative_area;
      }
    }
  }

  // Autocomplete - County
  $query = db_query('SELECT field_kf_address_postal_code FROM field_data_field_kf_address WHERE field_kf_address_postal_code LIKE :search GROUP BY field_kf_address_postal_code', array('search' => $string . '%'));
  $result = $query->fetchAll();
  if (!empty($result)) {
    foreach ($result as $key => $address) {
      if (!empty($address->field_kf_address_postal_code)) {
        $autocomplete[$address->field_kf_address_postal_code] = $address->field_kf_address_postal_code;
      }
    }
  }

  drupal_json_output($autocomplete);
//  drupal_exit();
}