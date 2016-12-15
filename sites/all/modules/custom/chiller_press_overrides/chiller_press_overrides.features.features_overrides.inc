<?php
/**
 * @file
 * chiller_press_overrides.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function chiller_press_overrides_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_group
  $overrides["field_group.group_date_block|node|press_kit|form.data|children|3"] = 'field_press_kit_date_timezone';

  // Exported overrides for: field_instance
  $overrides["field_instance.node-press_kit-field_press_kit_date_color.widget|weight"] = 9;

  // Exported overrides for: page_manager_handlers
  $overrides["page_manager_handlers.site_template__403.conf|display|content|new-c1c11bb8-a711-4828-8e9a-f77319f61d64"] = (object) array(
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
    );
  $overrides["page_manager_handlers.site_template__403.conf|display|content|new-e0ac1452-1d43-4bbf-adf1-c425d7cf8594"]["DELETED"] = TRUE;
  $overrides["page_manager_handlers.site_template__403.conf|display|panels|project|1"] = 'new-c1c11bb8-a711-4828-8e9a-f77319f61d64';

  // Exported overrides for: variable
  $overrides["variable.page_unavailable_error_message.value|value"] = '<p>The page you are trying to reach is unavailable. Perhaps you are looking for something that can be found on ChillerTV.com?</p>';
  $overrides["variable.theme_default.value"] = 'chillerps';

 return $overrides;
}
