<?php
/**
 * @file
 * fycusa_build.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function fycusa_build_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fyc_date_block|node|fyc_show|form';
  $field_group->group_name = 'group_fyc_date_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fyc_show';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fyc_show_prop';
  $field_group->data = array(
    'label' => 'Tune In block',
    'weight' => '44',
    'children' => array(
      0 => 'field_fyc_show_date_color',
      1 => 'field_fyc_show_date_date',
      2 => 'field_fyc_show_date_text',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fyc-date-block field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_fyc_date_block|node|fyc_show|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fyc_enter_project|node|fyc_show|form';
  $field_group->group_name = 'group_fyc_enter_project';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fyc_show';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fyc_show_prop';
  $field_group->data = array(
    'label' => 'Enter project',
    'weight' => '45',
    'children' => array(
      0 => 'field_fyc_show_enter_button',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fyc-enter-project field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_fyc_enter_project|node|fyc_show|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fyc_images|node|fyc_show|form';
  $field_group->group_name = 'group_fyc_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fyc_show';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fyc_show_prop';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '43',
    'children' => array(
      0 => 'field_fyc_show_background',
      1 => 'field_fyc_show_header_bg',
      2 => 'field_fyc_show_logo',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fyc-images field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_fyc_images|node|fyc_show|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fyc_show_prop|node|fyc_show|form';
  $field_group->group_name = 'group_fyc_show_prop';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fyc_show';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'FYC Show properties',
    'weight' => '2',
    'children' => array(
      0 => 'group_fyc_images',
      1 => 'group_show_info',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-fyc-show-prop field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_fyc_show_prop|node|fyc_show|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_show_info|node|fyc_show|form';
  $field_group->group_name = 'group_show_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fyc_show';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fyc_show_prop';
  $field_group->data = array(
    'label' => 'Show Info',
    'weight' => '44',
    'children' => array(
      0 => 'field_fyc_show_enter_button',
      1 => 'field_fyc_show_date_color',
      2 => 'field_fyc_show_color',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-show-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_show_info|node|fyc_show|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Enter project');
  t('FYC Show properties');
  t('Images');
  t('Show Info');
  t('Tune In block');

  return $field_groups;
}
