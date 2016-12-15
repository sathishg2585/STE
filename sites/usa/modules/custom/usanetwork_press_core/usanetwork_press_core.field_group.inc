<?php
/**
 * @file
 * usanetwork_press_core.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function usanetwork_press_core_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_block|node|press_kit|form';
  $field_group->group_name = 'group_date_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_kit';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_press_kit_prop';
  $field_group->data = array(
    'label' => 'Tune In block',
    'weight' => '5',
    'children' => array(
      0 => 'field_press_kit_date_color',
      1 => 'field_press_kit_date_date',
      2 => 'field_press_kit_date_text',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Tune In block',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-date-block field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_date_block|node|press_kit|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_enter_project|node|press_kit|form';
  $field_group->group_name = 'group_enter_project';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_kit';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_press_kit_prop';
  $field_group->data = array(
    'label' => 'Enter project',
    'weight' => '6',
    'children' => array(
      0 => 'field_press_enter_button',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-enter-project field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_enter_project|node|press_kit|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|press_kit|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_kit';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_press_kit_prop';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '4',
    'children' => array(
      0 => 'field_press_kit_background',
      1 => 'field_press_kit_header_bg',
      2 => 'field_press_kit_logo',
      3 => 'field_press_kit_animated_header',
      4 => 'field_is_press_kit_project_logo',
      5 => 'field_is_press_kit_logo',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-images field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_images|node|press_kit|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_press_kit_prop|node|press_kit|form';
  $field_group->group_name = 'group_press_kit_prop';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'press_kit';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Press kit properties',
    'weight' => '3',
    'children' => array(
      0 => 'group_date_block',
      1 => 'group_enter_project',
      2 => 'group_images',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'label' => 'Press kit properties',
      'instance_settings' => array(
        'classes' => 'group-press-kit-prop field-group-tabs',
      ),
    ),
  );
  $field_groups['group_press_kit_prop|node|press_kit|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Enter project');
  t('Images');
  t('Press kit properties');
  t('Tune In block');

  return $field_groups;
}
