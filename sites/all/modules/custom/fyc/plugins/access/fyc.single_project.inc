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
  'title' => t('FYC is single project'),
  'description' => t('Control access by the count of projects.'),
  'callback' => 'fyc_single_project_ctools_access_check',
  'required context' => new ctools_context_required(t('Node'), array('node')),
);

/**
 * Check for access.
 */
function fyc_single_project_ctools_access_check($conf, $context) {
  // As far as I know there should always be a context at this point, but this
  // is safe.
  if (empty($context) || empty($context->data) || $context->data->type != 'fyc_project') {
    return FALSE;
  }

  $node_wrapper = entity_metadata_wrapper('node', $context->data);
  $values = $node_wrapper->{'field_fyc_show'}->value();

  return count($values) <= 1;
}
