<?php

/**
 * Settings file for local development environments. Use this to store local
 * database credentials, API keys, and debugging settings. This file should
 * never be committed to version control.
 */

$conf['pub_site_shortname'] = 'sitename'; // <--- This should match the folder name under sites

ini_set('error_reporting', E_ALL);
ini_set('memory_limit','512M');

// Set some default conf settings.
$conf['pub_utilities_git_bin'] = '/usr/local/git/bin/git'; // <--- This may be different for you
$conf['pub_utilities_drush_bin'] = '/Applications/MAMP/bin/php/php5.4.4/bin/drush'; // <--- This may be different for you

// Define the current environment.
$_ENV['AH_SITE_ENVIRONMENT'] = 'local';

$databases['default'] = array ('default' =>
  array (
    'database' => 'publisher',  // <--- Local database name (required)
    'username' => 'root',  // <--- Local database username (required)
    'password' => 'root',  // <--- Local database password (not required)
    'host' => 'localhost',
    'port' => '',
    'driver' => 'mysql',
    'prefix' => '',
  ),
);
