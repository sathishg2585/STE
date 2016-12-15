<?php

/**
 * @file
 * Aliases for Publisher7.
 */

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}

/**
 * Site nbcupublisher7, environment local.
 *
 * Override this alias by copying and configuring aliases.drushrc.example.php to
 * aliases.drushrc.php in docroot/sites/all/drush/aliases/.
 *
 * The aliases.drushrc.php file is for local and overridden aliases and is
 * Git ignored.
 */
$aliases['pubstack'] = array(
  'root' => '/var/www/html/Publisher7/docroot/',
  'uri' => 'http://local.publisher7.com',
  'path-aliases' => array(
    '%rebuild' => 'sites/default/drush/rebuild.yml',
    '%dump-dir' => '/tmp',
  ),
  'remote-host' => '127.0.0.1',
  'remote-user' => 'vagrant',
  'ssh-options' => '-p 2222',
);

// Site nbcupublisher7, environment prod.
$aliases['prod'] = array(
  'root' => '/var/www/html/nbcupublisher7.prod/docroot',
  'ac-site' => 'nbcupublisher7',
  'ac-env' => 'prod',
  'ac-realm' => 'prod',
  'uri' => 'nbcupublisher7.prod.acquia-sites.com',
  'remote-host' => 'web-7885.prod.hosting.acquia.com',
  'remote-user' => 'nbcupublisher7.prod',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
    '%dump-dir' => '/tmp',
  ),
);
$aliases['prod.livedev'] = array(
  'parent' => '@pub7.prod',
  'root' => '/mnt/gfs/nbcupublisher7.prod/livedev/docroot',
);

// Site nbcupublisher7, environment stage.
$aliases['stage'] = array(
  'root' => '/var/www/html/nbcupublisher7.stage/docroot',
  'ac-site' => 'nbcupublisher7',
  'ac-env' => 'stage',
  'ac-realm' => 'prod',
  'uri' => 'nbcupublisher7stage.prod.acquia-sites.com',
  'remote-host' => 'staging-7893.prod.hosting.acquia.com',
  'remote-user' => 'nbcupublisher7.stage',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
    '%dump-dir' => '/tmp',
  ),
);
$aliases['stage.livedev'] = array(
  'parent' => '@pub7.stage',
  'root' => '/mnt/gfs/nbcupublisher7.stage/livedev/docroot',
);

// Site nbcupublisher7, environment acceptance.
$aliases['acc'] = array(
  'root' => '/var/www/html/nbcupublisher7.acceptance/docroot',
  'ac-site' => 'nbcupublisher7',
  'ac-env' => 'acceptance',
  'ac-realm' => 'prod',
  'uri' => 'nbcupublisher7acc.prod.acquia-sites.com',
  'remote-host' => 'staging-8574.prod.hosting.acquia.com',
  'remote-user' => 'nbcupublisher7.acceptance',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
    '%dump-dir' => '/tmp',
  ),
);
$aliases['acc.livedev'] = array(
  'parent' => '@pub7.acceptance',
  'root' => '/mnt/gfs/nbcupublisher7.acceptance/livedev/docroot',
);

// Site nbcupublisher7, environment acc-test(devi0).
$aliases['acc-test'] = array(
  'root' => '/var/www/html/nbcupublisher7.devi0/docroot',
  'ac-site' => 'nbcupublisher7',
  'ac-env' => 'devi0',
  'ac-realm' => 'prod',
  'uri' => 'nbcupublisher7devi0.prod.acquia-sites.com',
  'remote-host' => 'staging-9029.prod.hosting.acquia.com',
  'remote-user' => 'nbcupublisher7.devi0',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  ),
);
$aliases['acc-test.livedev'] = array(
  'parent' => '@pub7.devi0',
  'root' => '/mnt/gfs/nbcupublisher7.devi0/livedev/docroot',
);

// Site nbcupublisher7, environment tmp.
$aliases['tmp'] = array(
  'root' => '/var/www/html/nbcupublisher7.tmp/docroot',
  'ac-site' => 'nbcupublisher7',
  'ac-env' => 'tmp',
  'ac-realm' => 'prod',
  'uri' => 'nbcupublisher7tmp.prod.acquia-sites.com',
  'remote-host' => 'staging-7893.prod.hosting.acquia.com',
  'remote-user' => 'nbcupublisher7.tmp',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
    '%dump-dir' => '/tmp',
  ),
);
$aliases['tmp.livedev'] = array(
  'parent' => '@pub7.tmp',
  'root' => '/mnt/gfs/nbcupublisher7.tmp/livedev/docroot',
);

// Site nbcupublisher7, environment qa.
$aliases['qa'] = array(
  'root' => '/var/www/html/nbcupublisher7.qa/docroot',
  'ac-site' => 'nbcupublisher7',
  'ac-env' => 'qa',
  'ac-realm' => 'prod',
  'uri' => 'nbcupublisher7qa.prod.acquia-sites.com',
  'remote-host' => 'staging-7893.prod.hosting.acquia.com',
  'remote-user' => 'nbcupublisher7.qa',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
    '%dump-dir' => '/tmp',
  ),
);
$aliases['qa.livedev'] = array(
  'parent' => '@pub7.qa',
  'root' => '/mnt/gfs/nbcupublisher7.qa/livedev/docroot',
);

// Site nbcupublisher7, environment qa1.
$aliases['qa1'] = array(
  'root' => '/var/www/html/nbcupublisher7.qa1/docroot',
  'ac-site' => 'nbcupublisher7',
  'ac-env' => 'qa1',
  'ac-realm' => 'prod',
  'uri' => 'nbcupublisher7qa1.prod.acquia-sites.com',
  'remote-host' => 'staging-7893.prod.hosting.acquia.com',
  'remote-user' => 'nbcupublisher7.qa1',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
    '%dump-dir' => '/tmp',
  ),
);
$aliases['qa1.livedev'] = array(
  'parent' => '@pub7.qa1',
  'root' => '/mnt/gfs/nbcupublisher7.qa1/livedev/docroot',
);

// Site nbcupublisher7, environment qa2.
$aliases['qa2'] = array(
  'root' => '/var/www/html/nbcupublisher7.qa2/docroot',
  'ac-site' => 'nbcupublisher7',
  'ac-env' => 'qa2',
  'ac-realm' => 'prod',
  'uri' => 'nbcupublisher7qa2.prod.acquia-sites.com',
  'remote-host' => 'staging-7893.prod.hosting.acquia.com',
  'remote-user' => 'nbcupublisher7.qa2',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
    '%dump-dir' => '/tmp',
  ),
);
$aliases['qa2.livedev'] = array(
  'parent' => '@pub7.qa2',
  'root' => '/mnt/gfs/nbcupublisher7.qa2/livedev/docroot',
);

// Site nbcupublisher7, environment qa3.
$aliases['qa3'] = array(
  'root' => '/var/www/html/nbcupublisher7.qa3/docroot',
  'ac-site' => 'nbcupublisher7',
  'ac-env' => 'qa3',
  'ac-realm' => 'prod',
  'uri' => 'nbcupublisher7qa3.prod.acquia-sites.com',
  'remote-host' => 'staging-7893.prod.hosting.acquia.com',
  'remote-user' => 'nbcupublisher7.qa3',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
    '%dump-dir' => '/tmp',
  ),
);
$aliases['qa3.livedev'] = array(
  'parent' => '@pub7.qa3',
  'root' => '/mnt/gfs/nbcupublisher7.qa3/livedev/docroot',
);


// Site nbcupublisher7, environment qa4.
$aliases['qa4'] = array(
  'root' => '/var/www/html/nbcupublisher7.qa4/docroot',
  'ac-site' => 'nbcupublisher7',
  'ac-env' => 'qa4',
  'ac-realm' => 'prod',
  'uri' => 'nbcupublisher7qa4.prod.acquia-sites.com',
  'remote-host' => 'staging-7893.prod.hosting.acquia.com',
  'remote-user' => 'nbcupublisher7.qa4',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
    '%dump-dir' => '/tmp',
  ),
);
$aliases['qa4.livedev'] = array(
  'parent' => '@pub7.qa4',
  'root' => '/mnt/gfs/nbcupublisher7.qa4/livedev/docroot',
);

// Site nbcupublisher7, environment qa5.
$aliases['qa5'] = array(
  'root' => '/var/www/html/nbcupublisher7.qa5/docroot',
  'ac-site' => 'nbcupublisher7',
  'ac-env' => 'qa5',
  'ac-realm' => 'prod',
  'uri' => 'nbcupublisher7qa5.prod.acquia-sites.com',
  'remote-host' => 'staging-8574.prod.hosting.acquia.com',
  'remote-user' => 'nbcupublisher7.qa5',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
    '%dump-dir' => '/tmp',
  ),
);
$aliases['qa5.livedev'] = array(
  'parent' => '@pub7.qa5',
  'root' => '/mnt/gfs/nbcupublisher7.qa5/livedev/docroot',
);
