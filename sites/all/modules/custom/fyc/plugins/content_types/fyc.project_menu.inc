<?php

$plugin = array(
  'title' => t('FYC Project menu'),
  'description' => t('Displays a menu.'),
  'single' => TRUE,
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'content_types' => array('fyc_project_menu'),
  'render callback' => 'fyc_project_menu_content_type_render',
  'edit form' => 'fyc_project_menu_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);

/**
 * Renders plugin with node links.
 */
function fyc_project_menu_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return FALSE;
  }

  $items = array();
  $block = new stdClass();

  $attributes = array(
    'id' => 'fyc-project-menu',
    'class' => 'fyc-project-menu-list',
  );

  $items[] = array(
    'data' => l('Edit Project', 'node/' . $context->data->nid . '/edit'),
    'class' => array('fyc-project_menu-item'),
  );

  $block->content = theme('item_list', array(
    'items' => $items,
    'title'=> '',
    'type' => 'ul',
    'attributes' => $attributes,
  ));
  return $block;
}

/**
 * Settings form for plugin.
 */
function fyc_project_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}
