<?php

$plugin = array(
  'title' => t('FYC Inner Page menu'),
  'description' => t('Displays a menu.'),
  'single' => TRUE,
  'required context' => new ctools_context_required(t('Term'), array('taxonomy_term')),
  'content_types' => array('fyc_innerpage_menu'),
  'render callback' => 'fyc_innerpage_menu_content_type_render',
  'edit form' => 'fyc_innerpage_menu_content_type_edit_form',
  'category' => array(t('FYC'), -9),
);

/**
 * Renders plugin with node links for term page.
 */
function fyc_innerpage_menu_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context) || empty($context->data)) {
    return FALSE;
  }

  $parents = taxonomy_get_parents_all($context->data->tid);
  if (count($parents) < 2) {
    return FALSE;
  }
  $term = $parents[count($parents)-2];

  $project_term = $parents[count($parents)-1];

  $block = new stdClass();

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->fieldCondition('field_fyc_show_tax_item', 'tid', $project_term->tid);
  $result = $query->execute();

  $fyc_show_node = NULL;
  if (!empty($result['node'])) {
    $fyc_show_node = reset($result['node']);
  }
  // Search project node.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'fyc_project')
    ->fieldCondition('field_fyc_show', 'target_id', $fyc_show_node->nid);
  $result = $query->execute();

  if(!empty($result) && !empty($result['node'])){
    foreach($result['node'] as $project) {
      $node_wrapper = entity_metadata_wrapper('node', $project->nid);
      $values = $node_wrapper->{'field_fyc_show'}->value();

      $items = array();
      foreach($values as $key => $value) {
        if ($value->status == 1) {
          $alias = drupal_get_path_alias('node/' . $value->nid);
          $class_selected = ($value->title == $project_term->name) ? 'highlight' : NULL;
          $items[] = array(
            'data' => l($value->title, $alias),
            'class' => array($class_selected, 'fyc-main-menu')
          );
        }
      }

      $block->content = theme_item_list(array('items' => $items, 'title'=> '', 'type' => 'ul', 'attributes' => array()));
    }
  }
  
  return $block;
}

/**
 * Settings form for plugin.
 */
function fyc_innerpage_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}
