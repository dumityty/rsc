<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <?php
    $kf_location = array(
      'latitude' => $view->result[$id]->_entity_properties["field_kf_geolocation_maps:lat"],
      'longitude' => $view->result[$id]->_entity_properties["field_kf_geolocation_maps:lng"],
    );
    $distance_to_user = round((ip_geoloc_distance($kf_location)/1000)*0.62,2);
  ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <div class="kf-distance">
      <span class='glyphicon glyphicon-map-marker'></span><?php print $distance_to_user; ?> miles
    </div>
    <div class='kf-info'>
      <?php print $row; ?>
    </div>
  </div>
<?php endforeach; ?>