<?php

$plugin = array(
  'title' => t('USA Network Press Content creation menu'),
  'description' => t('Displays a menu.'),
  'single' => TRUE,
  'required context' => new ctools_context_required(t('Term'), array('taxonomy_term')),
  'content_types' => array('usanetwork_content_menu'),
  'render callback' => 'usanetwork_content_menu_content_type_render',
  'edit form' => 'usanetwork_press_content_menu_content_type_edit_form',
  'category' => array(t('USA Network press'), -9),
);

/**
 * Renders plugin with node links.
 */
function usanetwork_content_menu_content_type_render($subtype, $conf, $args, $context) {
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
    ->fieldCondition('field_menu_position', 'tid', $context->data->tid);
  $result = $query->execute();

  $node = NULL;

  if (!empty($result['node'])) {
    $node = reset($result['node']);
  }

  $block = new stdClass();

  switch ($term->name) {
    case 'Press Materials':
      $type = 'press-materials-page';
      break;
    case 'Photos':
      $type = 'usanetwork-photos';
      break;
    case 'Videos':
      $type = 'videos-page';
      break;
    case 'Links':
      $type = 'links-page';
      break;
    case 'Contacts':
      $type = 'contacts-page';
      break;
    default:
      $type = 'press-materials-page';
  }

  $items = array();

  $attributes = array(
    'id' => 'usanetwork-content-menu',
    'class' => 'usanetwork-content-menu-list',
  );


  $items['add_new'] = array(
    'data' => l('Add new ' . $term->name, 'node/add/' . $type, array('query' => array('project' => $term->tid))),
    'class' => array('usanetwork-content_menu-item'),
  );

  // Hide button for links and conctacts.
  if (!empty($node) && in_array($type, array('contacts-page', 'links-page'))) {
    unset($items['add_new']);
  }

  // Edit link for node.
  if (!empty($node)) {
    $items['edit'] = array(
      'data' => l('Edit', 'node/' . $node->nid . '/edit'),
      'class' => array('usanetwork-content_menu-item'),
    );
  }


  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->fieldCondition('field_press_kit_tax_item', 'tid', $project_term->tid);
  $result = $query->execute();

  $press_kit_node = NULL;
  if (!empty($result['node'])) {
    $press_kit_node = reset($result['node']);

    $items[] = array(
      'data' => l('Manage Menu', 'node/' . $press_kit_node->nid . '/menu'),
      'class' => array('usanetwork-content_menu-item'),
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
function usanetwork_press_content_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}
