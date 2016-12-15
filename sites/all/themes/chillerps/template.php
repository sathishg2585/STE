<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */

/**
 * Implements theme_preprocess_field().
 */
function chillerps_preprocess_field(&$variables) {
  $field = &$variables['element'];
  if ($field['#field_name'] == 'field_press_kit_date_date') {
    $entity_type = $field['#entity_type'];
    $entity = $field['#object'];
    if ($timezone = field_get_items($entity_type, $entity, 'field_press_kit_date_timezone')) {
      $timezone = reset($timezone);
      if ($timezone && !empty($timezone['value'])) {
        foreach ($variables['items'] as &$item) {
          $item['#markup'] .= '<sup>' . $timezone['value'] . '</sup>';
        }
      }
    }
  }
}

/**
 * Implements hook_form_alter().
 */
function chillerps_form_alter( &$form, &$form_state, $form_id ) {
  if ( TRUE === in_array( $form_id, array( 'user_login', 'user_login_block') ) )
    $form['name']['#attributes']['placeholder'] = t( 'Your Email' );
    $form['pass']['#attributes']['placeholder'] = t( 'Your Password' );
}
