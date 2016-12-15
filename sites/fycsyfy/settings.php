<?php

/**
 * First we require the default settings.php file so that global settings can
 * be set in one place for all sites. PLEASE REFERENCE ../default/settings.php
 * TO SEE WHAT SETTINGS ARE AVAILABLE TO BE OVERRIDDEN.
 */

// Include the environment-agnostic file from Publisher7 core.
//require_once dirname(__FILE__) . "/../../.p7settings/settings.p7core.php";
require_once dirname(__FILE__) . "/../../profiles/publisher/settings.publisher.php";
$_ENV['AH_SITE_ENVIRONMENT'] = 'local';
$drupal_hash_salt = 'nI2lAWAcZVwwuMp_f5nW3ASHa5fbdAyCAuJHhpvILfg';

// Include AWS settings.
$env = $_ENV['AH_SITE_ENVIRONMENT'];
switch ($_ENV['AH_SITE_ENVIRONMENT']) {
  case 'prod':
  case 'lt':
    $env = '';
    break;
  case 'stage':
    $env = 'stg';
    break;
  default:
    $env = $_ENV['AH_SITE_ENVIRONMENT'];
}

$env_dir = basename(__DIR__). 'press' .$env;
if (file_exists('/var/www/site-php/'.$env_dir)) {
  require '/var/www/site-php/'.$env_dir.'/'.$env_dir.'-settings.inc';
}



if (file_exists(dirname(__FILE__) . "/settings.local.php")) {
  $_ENV['AH_SITE_ENVIRONMENT'] = 'local';
}

// Include environment specific overrides.
if (file_exists(__DIR__ . '/settings.' . $_ENV['AH_SITE_ENVIRONMENT'] . '.php')) {
  include_once(__DIR__ . '/settings.' . $_ENV['AH_SITE_ENVIRONMENT'] . '.php');
}

switch ($_ENV['AH_SITE_ENVIRONMENT']) {
  case 'dev':
    break;
  case 'test':
  case 'stage':
    break;
  case 'local':
    break;
  case 'prod':
    if ($_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
      $_SERVER['HTTPS'] = 'on';
    }
    break;
}

/**
 * Include local config.
 */
if (file_exists(__DIR__ . '/settings.local.php')) {
  include_once __DIR__ . '/settings.local.php';
}

