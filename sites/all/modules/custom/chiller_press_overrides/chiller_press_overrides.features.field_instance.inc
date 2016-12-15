<?php
/**
 * @file
 * chiller_press_overrides.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function chiller_press_overrides_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-press_kit-field_press_kit_date_timezone'
  $field_instances['node-press_kit-field_press_kit_date_timezone'] = array(
    'bundle' => 'press_kit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div',
    'field_name' => 'field_press_kit_date_timezone',
    'label' => 'Timezone',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Timezone');

  return $field_instances;
}
