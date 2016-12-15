<?php

/**
 * Settings file for local development environments. Use this to store local
 * database credentials, API keys, and debugging settings. This file should
 * never be committed to version control.
 */

// Define the current environment.
$_ENV['AH_SITE_ENVIRONMENT'] = 'local';

$databases['default'] = array ('default' =>
  array (
    'database' => 'fyc_syfy_1',  // <--- Local database name (required)
    'username' => 'root',  // <--- Local database username (required)
    'password' => '',  // <--- Local database password (not required)
    'host' => 'localhost',
    'port' => '',
    'driver' => 'mysql',
    'prefix' => '',
  ),
);
