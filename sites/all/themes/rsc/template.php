<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

function rsc_preprocess_html(&$variables) {
 	// After allowing html in the menu to display icons, 
 	// we want to get rid of it in the page title itself.
  $variables['head_title'] = strip_tags(html_entity_decode($variables['head_title']));
}