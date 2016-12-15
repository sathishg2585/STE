<?php

$plugin = array(
  'title' => t('USA Network Press Project menu'),
  'description' => t('Displays a menu.'),
  'single' => TRUE,
  'required context' => new ctools_context_required(t('Node'), array('node')),
  'content_types' => array('usanetwork_project_menu'),
  'render callback' => 'usanetwork_press_project_menu_content_type_render',
  'edit form' => 'usanetwork_press_project_menu_content_type_edit_form',
  'category' => array(t('USA Network press'), -9),
);

/**
 * Renders plugin with node links.
 */
function usanetwork_press_project_menu_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return FALSE;
  }

  $items = array();
  $block = new stdClass();

  $attributes = array(
    'id' => 'usanetwork-project-menu',
    'class' => 'usanetwork-project-menu-list',
  );

  $items[] = array(
    'data' => l('Edit Project', 'node/' . $context->data->nid . '/edit'),
    'class' => array('usanetwork-project_menu-item'),
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
function usanetwork_press_project_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}
