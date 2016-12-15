<?php
/**
 * @file
 * syfy_press_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function syfy_press_core_taxonomy_default_vocabularies() {
  return array(
    'media_categories' => array(
      'name' => 'Media Categories',
      'machine_name' => 'media_categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
    ),
    'menu_items' => array(
      'name' => 'Menu items',
      'machine_name' => 'menu_items',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -10,
    ),
    'press_kit_items' => array(
      'name' => 'Press Kit Projects',
      'machine_name' => 'press_kit_items',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -8,
    ),
  );
}
