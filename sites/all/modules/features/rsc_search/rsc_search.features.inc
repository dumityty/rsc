<?php
/**
 * @file
 * rsc_search.features.inc
 */

/**
 * Implements hook_views_api().
 */
function rsc_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function rsc_search_default_search_api_index() {
  $items = array();
  $items['cafes'] = entity_import('search_api_index', '{
    "name" : "Cafes",
    "machine_name" : "cafes",
    "description" : null,
    "server" : "rsc",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "cafes" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_kf_geolocation_maps:lat" : { "type" : "decimal" },
        "field_kf_geolocation_maps:latlng" : { "type" : "string", "real_type" : "location" },
        "field_kf_geolocation_maps:lng" : { "type" : "decimal" },
        "field_kf_road_name" : { "type" : "text", "boost" : "2.0" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text", "boost" : "3.0" }
      },
      "additional fields" : { "field_kf_address" : "field_kf_address" }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function rsc_search_default_search_api_server() {
  $items = array();
  $items['rsc'] = entity_import('search_api_server', '{
    "name" : "RSC",
    "machine_name" : "rsc",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/rsc",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "log_query" : 0,
      "log_response" : 0
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function rsc_search_default_search_api_sort() {
  $items = array();
  $items['cafes__field_kf_geolocation_maps:latlng'] = entity_import('search_api_sort', '{
    "index_id" : "cafes",
    "field" : "field_kf_geolocation_maps:latlng",
    "name" : "Sort by distance",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "cafes__field_kf_geolocation_maps:latlng",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "Address \\u00bb the latlng of point" },
    "rdf_mapping" : []
  }');
  return $items;
}
