<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728096
 */

/**
 * Implements template_preprocess_html().
 */
function fycsyfy_skin_preprocess_html(&$variables) {
  drupal_add_css('http://www.syfy.com/sites/syfy/themes/syfy/css/fonts.css',array('type' => 'external'));
}
