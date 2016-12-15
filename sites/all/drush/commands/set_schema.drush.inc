<?php

/**
 * Implements hook_drush_command().
 */
function set_schema_drush_command() {
  $items = array();
  $items['set-schema'] = array(
    'description' => 'Reset the schema version of a module.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array('ss'),
    'arguments' => array(
      'module' => 'The module to set the schema version for.',
      'version' => 'The schema version to set.'
    ),
  );

  return $items;
}

/**
 * Command callback. Reset the schema version of a module to a given schema
 * version, or report the current schema version.
 */
function drush_set_schema($module = NULL, $version = NULL) {
  if (!$module) {
    drush_log(dt('You must specify a module name.'), 'error');
    return;
  }

  if ($module && module_exists($module) && is_numeric($version)) {
    if (drush_drupal_major_version() >= 7) {
      db_update('system')
      ->fields(array(
        'schema_version' => $version,
      ))
      ->condition('name', $module, '=')
      ->execute();
    }
    else {
      db_query("UPDATE {system} SET schema_version = %d WHERE name = %s", array($version, $module));
    }
    drush_log(dt('!module set to schema version !version.', array('!module' => $module, '!version' => $version)), 'ok');
  }
  elseif ($module && module_exists($module)) {
    $result = drush_db_select('system', 'schema_version', 'name = :module', array(':module' => $module), 0, 1);
    $version = drush_db_result($result);
    drush_log(dt('!module is at schema version !version.', array('!module' => $module, '!version' => $version)), 'ok');
  }
}

