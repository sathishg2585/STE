<?php

/**
 * @file
 * This file is included for all Drush commands by all Publisher 7 sites.
 */

/**
 * Remove the memory limit from all drush commands.
 */
ini_set('memory_limit', '-1');

/**
 * Drush default settings.
 */
$options['include'] = array(__DIR__ . '/commands');
$options['alias-path'] = array(__DIR__ . '/aliases');

/**
 * List of tables whose *data* is skipped by the 'sql-dump' and 'sql-sync'
 * commands when the "--structure-tables-key=common" option is provided.
 * You may add specific tables to the existing array or add a new element.
 */
$options['structure-tables']['common'] = array(
  'cache',
  'cache_block',
  'cache_bootstrap',
  'cache_field',
  'cache_filter',
  'cache_form',
  'cache_image',
  'cache_menu',
  'cache_page',
  'cache_path',
  'history',
  'sessions',
);
$options['structure-tables-key'] = 'common';

/**
 * Create shell aliases sites and support a local sites/{sitename}/drush folder.
 */
if (is_file(__DIR__ . '/../../sites.php')) {
  include __DIR__ . '/../../sites.php';
  $sites = array_keys($multisites);
  $sites[] = 'default';
}
foreach ($sites as $site) {
  $options['shell-aliases']['pull-files'] = '!drush -y -v rsync @' . $site . '.prod:%files/ @' . $site . '.local:%files';
  $options['shell-aliases']['sync-db'] = '!drush sql-sync @' . $site . '.prod @' . $site . '.local --create-db --no-cache --structure-tables-key=common --sanitize --sanitize-password=pa55word -y';
  if (is_dir(__DIR__ . '/../../' . $site . '/drush/commands')) {
    $options['include'][] = __DIR__ . '/../../' . $site . '/drush/commands';
  }
  if (is_file(__DIR__ . '/../../' . $site . '/drush/drushrc.php')) {
    require_once __DIR__ . '/../../' . $site . '/drush/drushrc.php';
  }
  if (is_dir(__DIR__ . '/../../' . $site . '/drush/aliases')) {
    array_unshift($options['alias-path'], __DIR__ . '/../../' . $site . '/drush/aliases');
  }
}
