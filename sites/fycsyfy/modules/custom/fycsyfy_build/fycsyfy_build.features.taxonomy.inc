<?php
/**
 * @file
 * fycsyfy_build.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function fycsyfy_build_taxonomy_default_vocabularies() {
  return array(
    'fyc_show_items' => array(
      'name' => 'FYC Show Items',
      'machine_name' => 'fyc_show_items',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -10,
    ),
    'menu_items' => array(
      'name' => 'Show menu items',
      'machine_name' => 'menu_items',
      'description' => 'Show menu items vocabulary',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
