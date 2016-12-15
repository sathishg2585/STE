<?php
/**
 * @file
 * chiller_press_overrides.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function chiller_press_overrides_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_press_kit_date_timezone'
  $field_bases['field_press_kit_date_timezone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_press_kit_date_timezone',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'ET' => 'ET',
        'PT' => 'PT',
        'DT' => 'DT',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
