<?php
/**
 * @file
 * rsc_cafes.features.inc
 */

/**
 * Implements hook_node_info().
 */
function rsc_cafes_node_info() {
  $items = array(
    'cafes' => array(
      'name' => t('Cafes'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Cafe name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
