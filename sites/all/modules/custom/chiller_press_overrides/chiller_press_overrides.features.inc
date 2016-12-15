<?php
/**
 * @file
 * chiller_press_overrides.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function chiller_press_overrides_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_group_info_alter().
 */
function chiller_press_overrides_field_group_info_alter(&$data) {
  if (isset($data['group_date_block|node|press_kit|form'])) {
    $data['group_date_block|node|press_kit|form']->data['children'][3] = 'field_press_kit_date_timezone'; /* WAS: '' */
  }
}

/**
 * Implements hook_field_default_field_instances_alter().
 */
function chiller_press_overrides_field_default_field_instances_alter(&$data) {
  if (isset($data['node-press_kit-field_press_kit_date_color'])) {
    $data['node-press_kit-field_press_kit_date_color']['widget']['weight'] = 9; /* WAS: 8 */
  }
}

/**
 * Implements hook_default_page_manager_handlers_alter().
 */
function chiller_press_overrides_default_page_manager_handlers_alter(&$data) {
  if (isset($data['site_template__403'])) {
    $data['site_template__403']->conf['display']->content['new-c1c11bb8-a711-4828-8e9a-f77319f61d64'] = (object) array(
          'pid' => 'new-c1c11bb8-a711-4828-8e9a-f77319f61d64',
          'panel' => 'project',
          'type' => 'syfy_press.access_denied',
          'subtype' => 'syfy_press.access_denied',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 1,
          'locks' => array(),
          'uuid' => 'c1c11bb8-a711-4828-8e9a-f77319f61d64',
        ); /* WAS: '' */
    $data['site_template__403']->conf['display']->panels['project'][1] = 'new-c1c11bb8-a711-4828-8e9a-f77319f61d64'; /* WAS: 'new-e0ac1452-1d43-4bbf-adf1-c425d7cf8594' */
    unset($data['site_template__403']->conf['display']->content['new-e0ac1452-1d43-4bbf-adf1-c425d7cf8594']);
  }
}

/**
 * Implements hook_strongarm_alter().
 */
function chiller_press_overrides_strongarm_alter(&$data) {
  if (isset($data['page_unavailable_error_message'])) {
    $data['page_unavailable_error_message']->value['value'] = '<p>The page you are trying to reach is unavailable. Perhaps you are looking for something that can be found on ChillerTV.com?</p>'; /* WAS: '<p>The page you are trying to reach is unavailable. Perhaps you are looking for something that can be found on Syfy.com?</p>' */
  }
  if (isset($data['theme_default'])) {
    $data['theme_default']->value = 'chillerps'; /* WAS: 'syfyps' */
  }
}
