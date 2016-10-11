<?php
/**
 * @file
 * rsc_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rsc_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'search_solr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_cafes';
  $view->human_name = 'Search Solr';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Solr';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'There are <b>@total</b> cafes in your search area.';
  /* Field: DIstance from filter */
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['id'] = 'field_kf_geolocation_maps_latlng';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['table'] = 'search_api_index_cafes';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['field'] = 'field_kf_geolocation_maps_latlng';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['ui_name'] = 'DIstance from filter';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['label'] = '';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['show_distance_to_point'] = TRUE;
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['conversion_factor'] = '1.60926939169617';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['field_kf_geolocation_maps_latlng']['precision'] = '2';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_cafes';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_cafes';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'kf-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: Road name */
  $handler->display->display_options['fields']['field_kf_road_name']['id'] = 'field_kf_road_name';
  $handler->display->display_options['fields']['field_kf_road_name']['table'] = 'search_api_index_cafes';
  $handler->display->display_options['fields']['field_kf_road_name']['field'] = 'field_kf_road_name';
  $handler->display->display_options['fields']['field_kf_road_name']['label'] = '';
  $handler->display->display_options['fields']['field_kf_road_name']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_kf_road_name']['element_class'] = 'kf-road';
  $handler->display->display_options['fields']['field_kf_road_name']['element_label_colon'] = FALSE;
  /* Field: Indexed Node: Full address » Postal code */
  $handler->display->display_options['fields']['field_kf_address_postal_code']['id'] = 'field_kf_address_postal_code';
  $handler->display->display_options['fields']['field_kf_address_postal_code']['table'] = 'search_api_index_cafes';
  $handler->display->display_options['fields']['field_kf_address_postal_code']['field'] = 'field_kf_address_postal_code';
  $handler->display->display_options['fields']['field_kf_address_postal_code']['label'] = '';
  $handler->display->display_options['fields']['field_kf_address_postal_code']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_kf_address_postal_code']['element_class'] = 'kf-postcode';
  $handler->display->display_options['fields']['field_kf_address_postal_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kf_address_postal_code']['link_to_entity'] = 0;
  /* Field: Address: Latitude (indexed) */
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lat']['id'] = 'field_kf_geolocation_maps_lat';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lat']['table'] = 'search_api_index_cafes';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lat']['field'] = 'field_kf_geolocation_maps_lat';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lat']['label'] = 'Address » Latitude';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lat']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lat']['precision'] = '0';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lat']['link_to_entity'] = 0;
  /* Field: Address: Longitude (indexed) */
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lng']['id'] = 'field_kf_geolocation_maps_lng';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lng']['table'] = 'search_api_index_cafes';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lng']['field'] = 'field_kf_geolocation_maps_lng';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lng']['label'] = 'Address » Longitude';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lng']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lng']['precision'] = '0';
  $handler->display->display_options['fields']['field_kf_geolocation_maps_lng']['link_to_entity'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/report/cafe?id=[nid]">report</a>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'kf-meta';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Sort by distance */
  $handler->display->display_options['sorts']['field_kf_geolocation_maps_latlng']['id'] = 'field_kf_geolocation_maps_latlng';
  $handler->display->display_options['sorts']['field_kf_geolocation_maps_latlng']['table'] = 'search_api_index_cafes';
  $handler->display->display_options['sorts']['field_kf_geolocation_maps_latlng']['field'] = 'field_kf_geolocation_maps_latlng';
  $handler->display->display_options['sorts']['field_kf_geolocation_maps_latlng']['ui_name'] = 'Sort by distance';
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_cafes';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Location */
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['id'] = 'field_kf_geolocation_maps_latlng';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['table'] = 'search_api_index_cafes';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['field'] = 'field_kf_geolocation_maps_latlng';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['ui_name'] = 'Location';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['operator'] = '8.05';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['expose']['operator_id'] = 'location_distance';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['expose']['operator'] = 'field_kf_geolocation_maps_latlng_op';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['expose']['identifier'] = 'location';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['group_info']['label'] = 'the latlng of point (indexed)';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['group_info']['identifier'] = 'field_kf_geolocation_maps_latlng';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['plugin'] = 'geocoder';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['plugin-geocoder'] = array(
    'geocoder_handler' => 'google',
    'geocoder_handler_options' => array(
      'geometry_type' => 'point',
      'all_results' => 0,
      'reject_results' => array(
        'APPROXIMATE' => 0,
        'GEOMETRIC_CENTER' => 0,
        'RANGE_INTERPOLATED' => 0,
        'ROOFTOP' => 0,
      ),
      'biasing' => array(
        'bounds' => '61.105739/4.341997|48.626867/-12.414527',
        'region' => '',
        'components' => '',
      ),
    ),
  );
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng']['radius_options'] = '8.05 5 miles
16.09 10 miles
32.19 20 miles';
  /* Filter criterion: Near Me */
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['id'] = 'field_kf_geolocation_maps_latlng_1';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['table'] = 'search_api_index_cafes';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['field'] = 'field_kf_geolocation_maps_latlng';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['ui_name'] = 'Near Me';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['operator'] = '';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['expose']['operator_id'] = 'field_kf_geolocation_maps_latlng_1_op';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['expose']['label'] = 'the latlng of point (indexed)';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['expose']['operator'] = 'field_kf_geolocation_maps_latlng_1_op';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['expose']['identifier'] = 'field_kf_geolocation_maps_latlng_1';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['plugin'] = 'raw';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['plugin-geocoder'] = array(
    'geocoder_handler' => 'latlon',
  );
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['radius_type'] = 'textfield';
  $handler->display->display_options['filters']['field_kf_geolocation_maps_latlng_1']['radius_units'] = '1.60935';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'search-solr';

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'ip_geoloc_map';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => '',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_latitude'] = array(
    'field_kf_geolocation_maps_lat' => 'field_kf_geolocation_maps_lat',
  );
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_longitude'] = 'field_kf_geolocation_maps_lng';
  $handler->display->display_options['style_options']['center_option'] = '6';
  $handler->display->display_options['style_options']['visitor_marker'] = '00FF00';
  $handler->display->display_options['style_options']['gps_roles'] = array(
    1 => '1',
    2 => '2',
    3 => 0,
  );
  $handler->display->display_options['style_options']['map_options'] = '{"zoom":10}';
  $handler->display->display_options['style_options']['empty_map_center'] = 'visitor';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $export['search_solr'] = $view;

  return $export;
}
