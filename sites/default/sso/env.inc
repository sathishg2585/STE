<?php
/**
 * @file
 * The domains and their corresponding ACS ids need to be communicated to the
 * IDM/SSO team.
 */

global $conf;
// Set pub_sso_server. Allowed values are 'stage' and 'prod'
// This is a duplicate setting from settings.publisher.php
$conf['pub_sso_server'] = 'stage';

$environment_info['database_name'] = 'nbcupublisher7';
$environment_info['cert_directory_directory'] = 'default';
$environment_info['dynamic_domains'] = FALSE;

switch ($conf['pub_sso_server']) {
  case 'prod':
    $environment_info['entity_id'] = 'publisher7-prod';
    $environment_info['metadata_name'] = 'Publisher Prod';
    $environment_info['metadata_signonservice'] = 'https://fss.external.nbcuni.com/fss/idp/SSO.saml2';
    $environment_info['metadata_logoutservice'] = 'https://ssologin.external.nbcuni.com/ssologin/logoff.jsp';
    $environment_info['metadata.key'] = 'nbcufssprd';
    break;

  case 'stage':
  default:
    $environment_info['entity_id'] = 'publisher7-stage';
    $environment_info['metadata_name'] = 'Publisher Stage';
    $environment_info['metadata_signonservice'] = 'https://fss.external.stg.nbcuni.com/fss/idp/SSO.saml2';
    $environment_info['metadata_logoutservice'] = 'https://ssologin.external.stg.nbcuni.com/ssologin/logoff.jsp';
    $environment_info['metadata.key'] = 'nbcufssstg';
    break;
}

/*
 * When setting up SimpleSAML, create an array property called
 * $environment_info['auth.adminpassword'] and assign it the desired password.
 */
$environment_info['admin.protectindexpage'] = TRUE;
$environment_info['admin.protectmetadata'] = TRUE;
$environment_info['technicalcontact_name'] = 'Administrator';
$environment_info['technicalcontact_email'] = '';

if (empty($_ENV['AH_SITE_ENVIRONMENT'])) {
  if ($local) {
    $environment_info['environment'] = 'local';
  }
  else {
    $environment_info['environment'] = 'dev';
  }
  $_ENV['AH_SITE_ENVIRONMENT'] = $environment_info['environment'];
}
elseif (in_array($_ENV['AH_SITE_ENVIRONMENT'], array(
  'qa', 'qa1', 'qa2', 'qa3', 'qa4', 'qa5'))) {
  $environment_info['environment'] = 'qa';
}
elseif (in_array($_ENV['AH_SITE_ENVIRONMENT'], array(
  'stage', 'hotfix-stage', 'tmp', 'test'))) {
  $environment_info['environment'] = 'stage';
}
// For the purposes of SSO, "acceptance" is considered a production environment.
elseif (in_array($_ENV['AH_SITE_ENVIRONMENT'], array(
  'prod', 'acc', 'acceptance'))) {
  $environment_info['environment'] = 'prod';
}

// The list of authentication sources keys.
include DRUPAL_ROOT . '/' . conf_path() . '/sso/domains.inc';

// This condition is for SSO with static specific domains.
if (array_key_exists($_SERVER['SERVER_NAME'], $domains)) {
  $environment_info['authentication-source.key'] = $domains[$_SERVER['SERVER_NAME']];
}

// This condition is for SSO with dynamic domains.
// It's for non-prod environments only.
if(empty($environment_info['authentication-source.key']) && !empty($main_domain) && $conf['pub_sso_server'] == 'stage') {
  $main_domain_key = array_keys($main_domain);
  $main_domain_pattern = reset($main_domain_key);
  if ($main_domain_pattern && preg_match('/' . $main_domain_pattern . '$/', $_SERVER['SERVER_NAME'])) {
    $environment_info['authentication-source.key'] = reset($main_domain);
    $environment_info['dynamic_domains'] = TRUE;
    $environment_info['entity_id'] = 'publisher7sp';
    $environment_info['metadata.key'] = 'pub7vsid';
  }
}
