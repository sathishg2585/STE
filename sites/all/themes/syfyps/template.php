<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */

/**
 * Implements hook_theme().
 */
function syfyps_theme() {
  return array(
    'syfyps_color_css' => array(
      'variables' => array(
        'tune_in' => NULL,
      ),
      'template' => 'templates/color.css'
    ),
  );
}

/**
 * Implements template_preprocess_html().
 */
function syfyps_preprocess_html(&$variables) {
  drupal_add_css(theme('syfyps_color_css'), 'inline');
}

/**
 * Implements template_preprocess_syfyps_color_css().
 */
function syfyps_preprocess_syfyps_color_css(&$variables) {
  $colors = &drupal_static('syfyps_color_css', array());
  foreach ($colors as $name => $color) {
    if (empty($variables[$name])) {
      $variables[$name] = $color;
    }
  }
  $variables += $colors;
}

/**
 * Implements theme_preprocess_panels_pane().
 */
function syfyps_preprocess_panels_pane(&$variables, $hook) {
  if($variables['pane']->panel == 'header_image' && $variables['pane']->subtype == 'node:url') {
    $variables['theme_hook_suggestions'][] = 'panels_pane__project_node';
  }
}

/**
 * Implements theme_preprocess_field().
 */
function syfyps_preprocess_field(&$variables) {
  $colors = &drupal_static('syfyps_color_css', array());
  $field = &$variables['element'];
  if ($field['#field_name'] == 'field_press_kit_date_text' || $field['#field_name'] == 'field_press_kit_date_date') {
    $entity_type = $field['#entity_type'];
    $entity = $field['#object'];
    if ($color = field_get_items($entity_type, $entity, 'field_press_kit_date_color')) {
      $color = reset($color);
      if ($color) {
        $colors['tune_in'] = $color['rgb'];
      }
    }
  }
}
