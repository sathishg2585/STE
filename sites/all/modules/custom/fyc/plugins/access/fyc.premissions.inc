<?php
/**
 * @file
 * Plugin to provide access control based upon a parent term.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('FYC premissions'),
  'description' => t('Control access.'),
  'callback' => 'fyc_permissions_ctools_access_check',
  'required context' => new ctools_context_required(t('Node'), array('node', 'fyc-project')),
);

/**
 * Check for access.
 */
function fyc_permissions_ctools_access_check($conf, $context) {
  // As far as I know there should always be a context at this point, but this
  // is safe.
  if (empty($context) || empty($context->data)) {
    return FALSE;
  }

  return fyc_check_access($context->data);
}
