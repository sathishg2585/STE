<?php

$plugin = array(
  'title' => t('FYC Landing Page Menu'),
  'description' => t('FYC Landing Page Menu'),
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'single' => TRUE,
  'content_types' => array('fyc_landing_page_menu'),
  'render callback' => 'fyc_landing_page_menu_content_type_render',
  'edit form' => 'fyc_landing_page_menu_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);

/**
 * Renders plugin with node links for project page.
 */
function fyc_landing_page_menu_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data) || $context->data->type != 'fyc_project') {
    return FALSE;
  }

  $block = new stdClass();
  $block->content = '';

  $node_wrapper = entity_metadata_wrapper('node', $context->data->nid);
  $values = $node_wrapper->{'field_fyc_show'}->value();

  $items = array();
  foreach($values as $key => $value) {
    if ($value->status == 1) {
      $alias = drupal_get_path_alias('node/' . $value->nid);

      $items[] = array(
        'data' => l($value->title, $alias),
        'class' => array('fyc-main-menu'),
      );
    }
  }

  $block->content = theme_item_list(array('items' => $items, 'title'=> '', 'type' => 'ul', 'attributes' => array()));

  return $block;
}

/**
 * Settings form for plugin.
 */
function fyc_landing_page_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}
