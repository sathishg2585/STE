<?php
/**
 * @file
 * usanetwork_press_wysiwyg.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function usanetwork_press_wysiwyg_filter_default_formats() {
  $formats = array();

  // Exported format: Full_html.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full_html',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'media_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
