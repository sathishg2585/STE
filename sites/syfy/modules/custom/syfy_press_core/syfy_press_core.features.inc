<?php
/**
 * @file
 * syfy_press_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function syfy_press_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_type") {
    return array("version" => "1");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function syfy_press_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function syfy_press_core_image_default_styles() {
  $styles = array();

  // Exported image style: sy_fy_wysiwyg.
  $styles['sy_fy_wysiwyg'] = array(
    'label' => 'Sy-fy Wysiwyg',
    'effects' => array(
      11 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '',
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'sy_fy_wysiwyg',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: syfy_press_header_background.
  $styles['syfy_press_header_background'] = array(
    'label' => 'SyFy Press Header Desktop',
    'effects' => array(
      2 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 1280,
          'height' => 450,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'syfy_press_header_background',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: syfy_press_hp_tablet_single.
  $styles['syfy_press_hp_tablet_single'] = array(
    'label' => 'SyFy Press HP Tablet single',
    'effects' => array(
      3 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 768,
          'height' => 1024,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'syfy_press_hp_tablet_single',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: syfy_press_large_home_page_background.
  $styles['syfy_press_large_home_page_background'] = array(
    'label' => 'SyFy Press HP Desktop single',
    'effects' => array(
      5 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 1280,
          'height' => 1024,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'syfy_press_large_home_page_background',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: syfy_press_multiply_home_page_background.
  $styles['syfy_press_multiply_home_page_background'] = array(
    'label' => 'SyFy Press HP Desktop multiple',
    'effects' => array(
      7 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 1000,
          'height' => 352,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'syfy_press_multiply_home_page_background',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: syfy_press_slider_image.
  $styles['syfy_press_slider_image'] = array(
    'label' => 'SyFy Press Photo Desktop',
    'effects' => array(
      9 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 800,
          'height' => 450,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'syfy_press_slider_image',
        ),
        'weight' => 0,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function syfy_press_core_node_info() {
  $items = array(
    'contacts_page' => array(
      'name' => t('Contacts page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'links_page' => array(
      'name' => t('Links page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'press_kit' => array(
      'name' => t('Press Kit'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Press Kit Title'),
      'help' => '',
    ),
    'press_kit_project' => array(
      'name' => t('Press Kit Project'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Project Title'),
      'help' => '',
    ),
    'press_materials_page' => array(
      'name' => t('Press Materials Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'syfy_photos' => array(
      'name' => t('Photos page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Photos Gallery Title'),
      'help' => '',
    ),
    'videos_page' => array(
      'name' => t('Videos page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Videos Page Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
