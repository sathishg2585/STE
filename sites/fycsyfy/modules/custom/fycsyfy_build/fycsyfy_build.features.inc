<?php
/**
 * @file
 * fycsyfy_build.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fycsyfy_build_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
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
function fycsyfy_build_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function fycsyfy_build_image_default_styles() {
  $styles = array();

  // Exported image style: fyc_header_background.
  $styles['fyc_header_background'] = array(
    'label' => 'FYC Show Header Desktop',
    'effects' => array(
      2 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 1280,
          'height' => 450,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'fyc_header_background',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: fyc_hp_tablet_single.
  $styles['fyc_hp_tablet_single'] = array(
    'label' => 'FYC Show HP Tablet single',
    'effects' => array(
      3 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 768,
          'height' => 1024,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'fyc_hp_tablet_single',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: fyc_large_home_page_background.
  $styles['fyc_large_home_page_background'] = array(
    'label' => 'FYC Show HP Desktop single',
    'effects' => array(
      5 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 1280,
          'height' => 1024,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'fyc_large_home_page_background',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: fyc_multiply_home_page_background.
  $styles['fyc_multiply_home_page_background'] = array(
    'label' => 'FYC Show HP Desktop multiple',
    'effects' => array(
      7 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 1000,
          'height' => 352,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'fyc_multiply_home_page_background',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: fyc_slider_image.
  $styles['fyc_slider_image'] = array(
    'label' => 'FYC Show Photo Desktop',
    'effects' => array(
      9 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 800,
          'height' => 450,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'fyc_slider_image',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: fyc_wysiwyg.
  $styles['fyc_wysiwyg'] = array(
    'label' => 'FYC Wysiwyg',
    'effects' => array(
      11 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => '',
          'height' => '',
          'keepproportions' => 0,
          'reuse_crop_style' => '',
          'style_name' => 'fyc_wysiwyg',
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
function fycsyfy_build_node_info() {
  $items = array(
    'fyc_project' => array(
      'name' => t('FYC Project'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Project Title'),
      'help' => '',
    ),
    'fyc_series_overview' => array(
      'name' => t('Series Overview'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'fyc_show' => array(
      'name' => t('FYC Show'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Show Title'),
      'help' => '',
    ),
    'fycsyfy_vimeo_video' => array(
      'name' => t('Vimeo Video'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
