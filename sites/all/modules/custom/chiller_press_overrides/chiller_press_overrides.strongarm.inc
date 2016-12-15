<?php
/**
 * @file
 * chiller_press_overrides.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function chiller_press_overrides_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_unavailable_link';
  $strongarm->value = array(
    'text' => 'ChillerTV.com',
    'url' => 'http://chillertv.com',
    'options' => array(
      'external' => TRUE,
    ),
  );
  $export['page_unavailable_link'] = $strongarm;

  return $export;
}
