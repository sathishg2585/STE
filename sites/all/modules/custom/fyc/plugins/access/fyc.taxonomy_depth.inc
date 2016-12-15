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
  'title' => t('FYC taxonomy term depth'),
  'description' => t('Context of term depth.'),
  'callback' => 'fyc_taxonomy_depth_ctools_access_check',
  'settings form' => 'fyc_taxonomy_depth_access_settings_form',
  'required context' => new ctools_context_required(t('Taxonomy term'), array('taxonomy_term')),
  // Provides a summary descriptions depends on settings selected.
  'summary' => 'fyc_taxonomy_depth_ctools_access_summary',
);

/**
 * Check for access.
 */
function fyc_taxonomy_depth_ctools_access_check($conf, $context) {
  // As far as I know there should always be a context at this point, but this
  // is safe.

  if (empty($context) || empty($context->data)) {
    return FALSE;
  }

  $depth = count(taxonomy_get_parents_all($context->data->tid));
  return $conf['depth'] == $depth;
}

/**
 * Plugin settings form.
 */
function fyc_taxonomy_depth_access_settings_form(&$form, &$form_state, $conf) {
  $form['settings']['depth'] = array(
    '#type' => 'select',
    '#title' => t('Term depth'),
    '#options' => array(
      drupal_map_assoc(array(1,2,3,4,5)),
    ),
    '#default_value' => !empty($conf['depth']) ? $conf['depth'] : 1,
  );
  return $form;
}

/**
 * Summary callback for plugin.
 */
function fyc_taxonomy_depth_ctools_access_summary($conf, $context) {
  return !empty($conf['depth']) ?  t('Taxonomy term with depth ' . $conf['depth']) : '';
}
