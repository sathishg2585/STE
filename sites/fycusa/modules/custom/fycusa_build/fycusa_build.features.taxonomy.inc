<?php
/**
 * @file
 * fycusa_build.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function fycusa_build_taxonomy_default_vocabularies() {
  return array(
    'award_category' => array(
      'name' => 'Award Category',
      'machine_name' => 'award_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
    ),
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
