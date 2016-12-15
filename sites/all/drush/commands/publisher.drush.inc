<?php

/**
 * @file
 *
 * Used for Publisher Based commands.
 */


/**
 * Implementation of hook_drush_help().
 */
function publisher_drush_help($section) {
  switch ($section) {
    case 'meta:publisher:title':
      return dt("Publisher commands");
      break;
  }
}

/**
 * Implementation of hook_drush_command().
 */
function publisher_drush_command() {

  $items['pub-site-install'] = array(
    'description' => 'Install Publisher along with modules/themes/configuration using the specified Publisher profile.',
    'arguments' => array(
      'profile' => 'the install profile you wish to run. Defaults to Publisher.',
      'key=value...' => 'By default Division is set to Operations and the brand is NBCUOTS. You can overwrite the default form values. Ex: [form name].[parameter name].',
    ),
    'options' => array(
      'db-url' => array(
        'description' => 'A Drupal 6 style database URL. Only required for initial install - not re-install.',
        'example-value' => 'mysql://root:pass@127.0.0.1/db',
      ),
      'db-prefix' => 'An optional table prefix to use for initial install.  Can be a key-value array of tables/prefixes in a drushrc file (not the command line).',
      'db-su' => array(
        'description' => 'Account to use when creating a new database. Must have Grant permission (mysql only). Optional.',
        'example-value' => 'root',
      ),
      'db-su-pw' => array(
        'description' => 'Password for the "db-su" account. Optional.',
        'example-value' => 'pass',
      ),
      'account-name' => 'uid1 name. Defaults to admin',
      'account-pass' => 'uid1 pass. Defaults to a randomly generated password. If desired, set a fixed password in drushrc.php.',
      'account-mail' => 'uid1 email. Defaults to admin@publisher.nbcuni.com',
      'locale' => array(
        'description' => 'A short language code. Sets the default site language. Language files must already be present. You may use download command to get them.',
        'example-value' => 'en-GB',
      ),
      'clean-url' => 'Defaults to 1',
      'site-name' => 'Defaults to Site-Install',
      'site-mail' => 'From: for system mailings. Defaults to admin@publisher.nbcuni.com',
      'sites-subdir' => array(
        'description' => "Name of directory under 'sites' which should be created. Only needed when the subdirectory does not already exist. Defaults to 'default'",
        'value' => 'required',
        'example-value' => 'directory_name',
      ),
    ),
    'examples' => array(
      "drush pub-site-install pub'" => 'Install the publisher profile.',
      "drush psi publisher'" => 'Install the publisher profile.',
      "drush psi'" => 'Install the publisher profile.',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_ROOT,
    'aliases' => array('psi'),
  );

  $items['cache-kill'] = array(
    'description' => 'Kill stubborn caches multiple times with fire, knives, starvation and a bomb.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
    'aliases' => array('ck'),
  );

  $items['migrate-filepath'] = array(
    'description' => "Move files to subdirectories",
    // We are using options rather than arguments so the source can be omitted
    // if needed (e.g. files are just directly under sites/default/files).
    'options' => array(
      'source' => array(
        'description' => 'The directory under files/ that contains the files to be moved.',
        'example_value' => 'field/image',
      ),
      'target' => array(
        'description' => 'The target directory where the files will be moved.',
        'example_value' => 'pictures',
      ),
    ),
    'examples' => array(
      'drush migrate-filepath' => 'Moves all files located in the public file directory to YYYY/MM style subdirectory.',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL
  );

  return $items;
}

/**
 * Implements hook_drush_help_alter().
 *
 * For CI purposes we need to be able to set uri from the command line ( instead
 * of setting it in aliases file ) when running sql-sync.
 */
function publisher_drush_help_alter(&$command){
  if ($command['command'] == 'sql-sync') {
    $command['options']['source-uri'] = 'Allows the user to properly set the uri parameter.';
  }
}

/**
 * Implements drush_hook_COMMAND().
 *
 * Publisher Site Install.
 */
function drush_publisher_pub_site_install($profile = NULL) {
  $args = func_get_args();

  // Set up our default options.
  $profile = 'publisher';
  $form_options = array();
  $form_options['install_configure_form.site_mail'] = drush_get_option('site-mail', 'admin@publisher.nbcuni.com');
  $form_options['install_configure_form.account.mail'] = drush_get_option('account-mail', 'admin@publisher.nbcuni.com');
  $form_options['install_configure_form.division'] = 'Operations';
  $form_options['install_configure_form.brand'] = 'NBCUOTS';

  // We are lazy so we allow profile short names.
  $short_name = array(
    'pub' => 'publisher',
  );

  // Actual profile name.
  $valid_names = array('publisher');

  if ($args) {
    // The first argument is the profile.
    $profile = array_shift($args);
    if (!in_array($profile, $valid_names)) {
      // If it's not a valid profile then lets check out shortnames.
      if (isset($short_name[$profile])) {
        $profile = $short_name[$profile];
      }
      else {
        // If we got here then lets error out.
        $error = dt('Sorry, !profile is not a valid profile.', array('!profile' => $profile));
        drush_set_error('pub_invalid_profile', $error);
      }
    }

    // Subsequent arguments are additional form values.
    foreach ($args as $arg) {
      list($key, $value) = explode('=', $arg);
      $form_options[$key] = $value;
    }
  }

  drush_include_engine('drupal', 'site_install', drush_drupal_major_version());
  drush_core_site_install_version($profile, $form_options);
}

/**
 * Implements drush_hook_COMMAND().
 *
 * Cache killer.
 */
function drush_publisher_cache_kill($type = 1) {
  $loop = 4;
  while ($loop > 0) {
    try {
      drush_db_delete('cache');
      drush_print('Cache Killed!');
    }
    catch (Exception $e) {
      echo 'catch';
      db_delete('cache')
        ->condition('cid', 'entity_info:en')
        ->execute();
    }
    $loop--;
  }
}

/**
 * Implements drush_hook_COMMAND_validate().
 */
function drush_publisher_pub_site_install_validate() {
  drush_core_site_install_validate();
}

/**
 * Implements drush_hook_pre_COMMAND().
 */
function drush_publisher_pre_pub_site_install($profile = NULL) {
  return drush_core_pre_site_install($profile);
}
 
/**
 * Implements drush_hook_COMMAND().
 *
 * Perform the file migration.
 *
 * The two optional options are the source and target directories. By default
 * assumes that these are under the default path, e.g. sites/default/files.
 *
 * This is a modified version of the script supplied by Acquia.
 * @link https://docs.acquia.com/articles/optimizing-file-paths-organizing-files-subfolders @endlink
 */
function drush_publisher_migrate_filepath() {
  // Source directory to be cleaned up. All images in this directory will be relocated.
  $source_directory = rtrim(drush_get_option('source', ''), '/');
  // Directory to place the new structure under. If does not exist will be created.
  $target_directory = rtrim(drush_get_option('target', ''), '/');
 
  // Regular expression to find files in the source directory.
  // For now assume public files only.
  // public://field/image/imagefield_hENvtS.png
  $extensions = array('jpeg', 'jpg', 'gif', 'png', 'txt');
 
  // Construct a expression to find images located in the source directory.
  $file_pattern = "[^\/]*"; // Finds anything that does not contain "/", should be fine.
 
  // Append the trailing slash for the regular expression.
  // Note, in some instances drupal places under public:/// (three slashes)
  // even when no folder specified. Reason for this is not known yet.
  $source_pattern = $source_directory ? $source_directory . "\/" : '';
  $regex = "^public:\/\/" . $source_pattern . "(" . $file_pattern . ")\.(" . implode($extensions, '|') . ")$";

  // Query the database for files that match this pattern.
  $filetypes = array('image/jpeg', 'image/jpg', 'image/gif', 'image/png', 'text/plain');
  $query = db_select('file_managed', 'f')
    ->condition('filemime', $filetypes , 'IN')
    ->condition('uri', $regex, 'REGEXP');
  $total_count = $query->countQuery()->execute()->fetchField();
 
  drush_print(dt('@count entries are to be moved.', array('@count' => $total_count)));
 
  // Select the files to be moved.
  $files = $query->fields('f', array('fid', 'filename', 'uri', 'timestamp'))
    ->execute()
    ->fetchAll();
 
  $count = 1;
  foreach ($files as $file) {
    preg_match_all("/$regex/i", $file->uri, $matches); // Note, $file->filename can be the SAME for different uri-s!
    $file_base = $matches[1][0];
    $file_extension = $matches[2][0];
    $file_name = $file_base . "." . $file_extension;
 
    $old_file_wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
 
    // If the file has already been moved, or does not exist in the filesystem, move on.
    if (FALSE === ($status = $old_file_wrapper->url_stat($file->uri, STREAM_URL_STAT_QUIET))) {
      drush_log("File entry in the database does not exist on the filesystem.", 'notice');
      continue;
    }
 
    // Each file should go to the directory based on its timestamp.
    $year = date('Y', $file->timestamp);
    $month = date('m', $file->timestamp);
    $target_directory_for_file = $target_directory . '/' . $year . '/' .$month;
 
    // Construct a dummy URI for it so we can use the stream wrappers.
    $new_directory = file_build_uri($target_directory_for_file);
    $wrapper = file_stream_wrapper_get_instance_by_uri($new_directory);
    // Make sure that the new directory exists.
    if (!file_exists($new_directory)) {
      $wrapper->mkdir($new_directory, 0755, STREAM_MKDIR_RECURSIVE | STREAM_REPORT_ERRORS);
    }

    // If a file with that name already exists in the directory, find a new name.
    $file_count = 1;
    while (file_exists($new_directory . '/' . $file_name)) {
      $file_name = $file_base . '_' . $file_count . '.' . $file_extension;
      $file_count++;
    }
 
    // Construct the new directory.
    $wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
    $new_uri = file_build_uri($target_directory_for_file . '/' . $file_name);
    $wrapper->rename($file->uri, $new_uri);
 
    $progress = round(($count / $total_count) * 100);
    drush_print($progress . '%');

    $query = db_update('file_managed')
      ->fields(array('uri' => $new_uri))
      ->condition('fid', $file->fid)
      ->execute();

    if (module_exists('file_entity_revisions')) {
      $query = db_update('file_managed_revisions')
        ->fields(array('uri' => $new_uri))
        ->condition('fid', $file->fid)
        ->execute();
    }

    $count++;
  }

  if ($count > 0) {
    db_query('truncate table cache_entity_file');
  }
}
