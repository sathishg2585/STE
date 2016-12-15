<?php

$plugin = array(
  'title' => t('USA Network dynamic header'),
  'description' => t('Displays a dynamic header.'),
  'single' => TRUE,
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'content_types' => array('usanetwork_dynamic_header'),
  'render callback' => 'usanetwork_press_dynamic_header_render',
  'category' => array(t('USA Network press'), -9),
  'edit form' => 'usanetwork_press_dynamic_header_content_type_edit_form',
);


/**
 * Renders markup for usanetwork dynamic header.
 */
function usanetwork_press_dynamic_header_render($subtype, $conf, $args, $context) {

  if (empty($context) || empty($context->data)) {
    return FALSE;
  }

  $block = new stdClass();
  $press_kit_wrapper = entity_metadata_wrapper('node', $context->data);

  $video_url = NULL;
  $image_url = NULL;
  if (usanetwork_press_core_check_field($context->data, 'field_press_kit_animated_header')) {
    $video_url =$press_kit_wrapper->field_press_kit_animated_header->file->url->value();
  }
  if (usanetwork_press_core_check_field($context->data, 'field_press_kit_header_bg')) {
    $image_file = $press_kit_wrapper->field_press_kit_header_bg->file->value();
    $url = image_style_url('usanetwork_press_header_background', $image_file->uri);
    $url = _manualcrop_add_cache_control('usanetwork_press_header_background', $url);
    $image_url = $image_file = $press_kit_wrapper->field_press_kit_header_bg->file->url->value();
    if (isset($image_file->uri)) {
      $image_path = image_style_path('usanetwork_press_header_background', $image_file->uri);
    }
    if (!empty($url) && file_exists($image_path)) {
      $image_url = $url;
    }
  }
  $data = array(
    'video_url' => $video_url,
    'image_url' => $image_url,
  );

  $content = array(
    '#theme' => 'usanetwork_press_dynamic_header',
    '#content' => $data,
  );
  $block->content = $content;

  return $block;
}

function usanetwork_press_dynamic_header_content_type_edit_form($form, &$form_state) {
  return $form;
}
