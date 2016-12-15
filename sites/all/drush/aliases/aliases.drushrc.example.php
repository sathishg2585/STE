<?php

/**
 * @file
 * Local and overridden aliases file.
 *
 * Rename this file to aliases.drushrc.php, it will be ignored by .gitignore.
 */

$aliases['pub7.pubstack'] = array(
  'root' => getenv('HOME') . '/Sites/nbcu/Publisher7/docroot',
  'uri' => 'http://local.publisher7.com',
  'path-aliases' => array(
    // @see docroot/sites/all/drush/commands/rebuild/examples/example.drebuild.aliases.drushrc.php
    '%rebuild' => 'sites/default/drush/rebuild.yml',
    '%dump-dir' => '/tmp',
  ),
);
