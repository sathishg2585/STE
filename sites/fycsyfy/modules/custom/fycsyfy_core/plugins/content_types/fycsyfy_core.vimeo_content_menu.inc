<?php

$plugin = array(
  'title' => t('FYC Vimeo Content creation menu'),
  'description' => t('Displays a menu.'),
  'single' => TRUE,
  'required context' => new ctools_context_required(t('Term'), array('taxonomy_term')),
  'content_types' => array('fyc_vimeo_content_menu'),
  'render callback' => 'fyc_vimeo_content_menu_content_type_render',
  'edit form' => 'fyc_vimeo_content_menu_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);

/**
 * Renders plugin with node links.
 */
function fyc_vimeo_content_menu_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return FALSE;
  }

  $parents = taxonomy_get_parents_all($context->data->tid);
  if (count($parents) < 2) {
    return FALSE;
  }
  $term = $parents[count($parents)-2];

  $project_term = $parents[count($parents)-1];

  // Search parent node.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->fieldCondition('field_fyc_menu_position', 'tid', $context->data->tid);
  $result = $query->execute();

  $node = NULL;

  if (!empty($result['node'])) {
    $node = reset($result['node']);
  }

  $block = new stdClass();

  switch ($term->name) {
    case 'Series Overview':
      $type = 'fyc-series-overview';
      break;
    case 'Vimeo Video':
      $type = 'fycsyfy-vimeo-video';
      break;
    default:
      $type = 'fyc-series-overview';
  }

  $items = array();

  $attributes = array(
    'id' => 'fyc-content-menu',
    'class' => 'fyc-content-menu-list',
  );


  $items['add_new'] = array(
    'data' => l('Add new ' . $term->name, 'node/add/' . $type, array('query' => array('project' => $term->tid))),
    'class' => array('fyc-content_menu-item'),
  );

  // Edit link for node.
  if (!empty($node)) {
    $items['edit'] = array(
      'data' => l('Edit', 'node/' . $node->nid . '/edit'),
      'class' => array('fyc-content_menu-item'),
    );
  }


  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->fieldCondition('field_fyc_show_tax_item', 'tid', $project_term->tid);
  $result = $query->execute();

  $fyc_show_node = NULL;
  if (!empty($result['node'])) {
    $fyc_show_node = reset($result['node']);

    $items[] = array(
      'data' => l('Manage Menu', 'node/' . $fyc_show_node->nid . '/menu'),
      'class' => array('fyc-content_menu-item'),
    );
  }



  // Render as list.
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
function fyc_vimeo_content_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}
