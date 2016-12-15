<?php
/**
 * @file
 * usanetwork_press_core.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function usanetwork_press_core_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__multi_press_kit_project';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Multi press kit project',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'usanetwork-press-multi-homepage',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'multi_press_kit_project',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'usanetwork_press.single_project',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'press_kit_project' => 'press_kit_project',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'usanetwork_press.landing_page',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        3 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'multiple';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'header' => NULL,
      'projects' => NULL,
    ),
    'header' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7d96d9e1-a4df-4327-9206-e91396b6a8a6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-df355b9c-4075-4232-998c-e1861a1c21b6';
    $pane->panel = 'header';
    $pane->type = 'usanetwork_press.project_menu';
    $pane->subtype = 'usanetwork_press.project_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any press_kit_project content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'df355b9c-4075-4232-998c-e1861a1c21b6';
    $display->content['new-df355b9c-4075-4232-998c-e1861a1c21b6'] = $pane;
    $display->panels['header'][0] = 'new-df355b9c-4075-4232-998c-e1861a1c21b6';
    $pane = new stdClass();
    $pane->pid = 'new-e52695d2-5613-4170-a6c7-099aa12bb558';
    $pane->panel = 'header';
    $pane->type = 'usanetwork_press.logo';
    $pane->subtype = 'usanetwork_press.logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e52695d2-5613-4170-a6c7-099aa12bb558';
    $display->content['new-e52695d2-5613-4170-a6c7-099aa12bb558'] = $pane;
    $display->panels['header'][1] = 'new-e52695d2-5613-4170-a6c7-099aa12bb558';
    $pane = new stdClass();
    $pane->pid = 'new-1b7d4e3d-0bdd-4c2e-8cfa-76a7dcc5a8d8';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_press_kit_intro_text';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '1b7d4e3d-0bdd-4c2e-8cfa-76a7dcc5a8d8';
    $display->content['new-1b7d4e3d-0bdd-4c2e-8cfa-76a7dcc5a8d8'] = $pane;
    $display->panels['header'][2] = 'new-1b7d4e3d-0bdd-4c2e-8cfa-76a7dcc5a8d8';
    $pane = new stdClass();
    $pane->pid = 'new-0488494f-827a-4aba-a2a2-373519531e37';
    $pane->panel = 'projects';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0488494f-827a-4aba-a2a2-373519531e37';
    $display->content['new-0488494f-827a-4aba-a2a2-373519531e37'] = $pane;
    $display->panels['projects'][0] = 'new-0488494f-827a-4aba-a2a2-373519531e37';
    $pane = new stdClass();
    $pane->pid = 'new-ea74550d-9b21-4e77-b5d6-dc22aeb93f30';
    $pane->panel = 'projects';
    $pane->type = 'views_panes';
    $pane->subtype = 'langing_page_projects-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ea74550d-9b21-4e77-b5d6-dc22aeb93f30';
    $display->content['new-ea74550d-9b21-4e77-b5d6-dc22aeb93f30'] = $pane;
    $display->panels['projects'][1] = 'new-ea74550d-9b21-4e77-b5d6-dc22aeb93f30';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ea74550d-9b21-4e77-b5d6-dc22aeb93f30';
  $handler->conf['display'] = $display;
  $export['node_view__multi_press_kit_project'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__single_press_kit_project';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Single press kit project',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'usanetwork-press-single-homepage',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Node (on Node: Press kits [field_press_kit])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_press_kit-node-node',
        'delta' => '0',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'single_press_kit_project',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'press_kit_project' => 'press_kit_project',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'usanetwork_press.single_project',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'usanetwork_press.landing_page',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        3 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'single';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
      'project' => NULL,
    ),
    'middle' => array(
      'style' => 'naked',
    ),
    'project' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '987ef1c5-b398-413f-9ad1-5c3ff5657565';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e6755c12-2a4c-4e48-9a06-1b0ad4e39869';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.node_link';
    $pane->subtype = 'usanetwork_press.node_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_entity_from_field:field_press_kit-node-node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e6755c12-2a4c-4e48-9a06-1b0ad4e39869';
    $display->content['new-e6755c12-2a4c-4e48-9a06-1b0ad4e39869'] = $pane;
    $display->panels['project'][0] = 'new-e6755c12-2a4c-4e48-9a06-1b0ad4e39869';
    $pane = new stdClass();
    $pane->pid = 'new-94922d75-b0be-40e2-97be-4de50c8571f0';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.logo';
    $pane->subtype = 'usanetwork_press.logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '94922d75-b0be-40e2-97be-4de50c8571f0';
    $display->content['new-94922d75-b0be-40e2-97be-4de50c8571f0'] = $pane;
    $display->panels['project'][1] = 'new-94922d75-b0be-40e2-97be-4de50c8571f0';
    $pane = new stdClass();
    $pane->pid = 'new-c424c70b-55d2-41ba-b97e-624d3f258c97';
    $pane->panel = 'project';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_press_kit_logo';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:press_kit:field_is_press_kit_project_logo',
          'settings' => array(
            'field_is_press_kit_project_logo' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_press_kit_project_logo_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'relationship_entity_from_field:field_press_kit-node-node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => '',
        'image_link' => '',
      ),
      'context' => 'relationship_entity_from_field:field_press_kit-node-node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c424c70b-55d2-41ba-b97e-624d3f258c97';
    $display->content['new-c424c70b-55d2-41ba-b97e-624d3f258c97'] = $pane;
    $display->panels['project'][2] = 'new-c424c70b-55d2-41ba-b97e-624d3f258c97';
    $pane = new stdClass();
    $pane->pid = 'new-d1b2bc8f-9576-4a13-a2cc-7bc5b1733a16';
    $pane->panel = 'project';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_press_kit_date_text';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_entity_from_field:field_press_kit-node-node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'd1b2bc8f-9576-4a13-a2cc-7bc5b1733a16';
    $display->content['new-d1b2bc8f-9576-4a13-a2cc-7bc5b1733a16'] = $pane;
    $display->panels['project'][3] = 'new-d1b2bc8f-9576-4a13-a2cc-7bc5b1733a16';
    $pane = new stdClass();
    $pane->pid = 'new-6d00e419-97ca-4cf9-80ed-fd3a83f40ce6';
    $pane->panel = 'project';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_press_kit_date_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_entity_from_field:field_press_kit-node-node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '6d00e419-97ca-4cf9-80ed-fd3a83f40ce6';
    $display->content['new-6d00e419-97ca-4cf9-80ed-fd3a83f40ce6'] = $pane;
    $display->panels['project'][4] = 'new-6d00e419-97ca-4cf9-80ed-fd3a83f40ce6';
    $pane = new stdClass();
    $pane->pid = 'new-b227c8e1-fb28-46a0-9b47-33142a406c4c';
    $pane->panel = 'project';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_press_kit_background';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'bg_image_formatter',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'usanetwork_press_large_home_page_background',
        'css_settings' => array(
          'bg_image_selector' => '.usanetwork-press-single-homepage .usanetwork-homepage-single-project-wrapper',
          'bg_image_color' => '#FFFFFF',
          'bg_image_x' => 'left',
          'bg_image_y' => 'top',
          'bg_image_attachment' => 'scroll',
          'bg_image_repeat' => 'no-repeat',
          'bg_image_background_size' => '',
          'bg_image_background_size_ie8' => 0,
          'bg_image_media_query' => 'all',
          'bg_image_important' => 0,
        ),
      ),
      'context' => 'relationship_entity_from_field:field_press_kit-node-node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'b227c8e1-fb28-46a0-9b47-33142a406c4c';
    $display->content['new-b227c8e1-fb28-46a0-9b47-33142a406c4c'] = $pane;
    $display->panels['project'][5] = 'new-b227c8e1-fb28-46a0-9b47-33142a406c4c';
    $pane = new stdClass();
    $pane->pid = 'new-847cfb34-e2b7-4151-960b-d9253aaff3d5';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.enter_label';
    $pane->subtype = 'usanetwork_press.enter_label';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_entity_from_field:field_press_kit-node-node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '847cfb34-e2b7-4151-960b-d9253aaff3d5';
    $display->content['new-847cfb34-e2b7-4151-960b-d9253aaff3d5'] = $pane;
    $display->panels['project'][6] = 'new-847cfb34-e2b7-4151-960b-d9253aaff3d5';
    $pane = new stdClass();
    $pane->pid = 'new-68d8445f-5c9e-40b5-9872-e14e15940a46';
    $pane->panel = 'project';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_press_kit_background';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'bg_image_formatter',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'usanetwork_press_hp_tablet_single',
        'css_settings' => array(
          'bg_image_selector' => '.usanetwork-press-single-homepage.tablet .usanetwork-homepage-single-project-wrapper',
          'bg_image_color' => '#FFFFFF',
          'bg_image_x' => 'left',
          'bg_image_y' => 'top',
          'bg_image_attachment' => 'scroll',
          'bg_image_repeat' => 'no-repeat',
          'bg_image_background_size' => '',
          'bg_image_background_size_ie8' => 0,
          'bg_image_media_query' => 'all',
          'bg_image_important' => 0,
        ),
      ),
      'context' => 'relationship_entity_from_field:field_press_kit-node-node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '68d8445f-5c9e-40b5-9872-e14e15940a46';
    $display->content['new-68d8445f-5c9e-40b5-9872-e14e15940a46'] = $pane;
    $display->panels['project'][7] = 'new-68d8445f-5c9e-40b5-9872-e14e15940a46';
    $pane = new stdClass();
    $pane->pid = 'new-97009cdb-44df-495b-9bce-c74c2535c3c2';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.project_menu';
    $pane->subtype = 'usanetwork_press.project_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any press_kit_project content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '97009cdb-44df-495b-9bce-c74c2535c3c2';
    $display->content['new-97009cdb-44df-495b-9bce-c74c2535c3c2'] = $pane;
    $display->panels['project'][8] = 'new-97009cdb-44df-495b-9bce-c74c2535c3c2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__single_press_kit_project'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__403';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => '403',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '403',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'access-denied',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'single';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'project' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f5565ab1-b05a-4916-b94c-c268895240ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4043addd-5484-427d-a8d8-a4f3c5370b88';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.logo';
    $pane->subtype = 'usanetwork_press.logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4043addd-5484-427d-a8d8-a4f3c5370b88';
    $display->content['new-4043addd-5484-427d-a8d8-a4f3c5370b88'] = $pane;
    $display->panels['project'][0] = 'new-4043addd-5484-427d-a8d8-a4f3c5370b88';
    $pane = new stdClass();
    $pane->pid = 'new-e0ac1452-1d43-4bbf-adf1-c425d7cf8594';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.page_unavailable';
    $pane->subtype = 'usanetwork_press.page_unavailable';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e0ac1452-1d43-4bbf-adf1-c425d7cf8594';
    $display->content['new-e0ac1452-1d43-4bbf-adf1-c425d7cf8594'] = $pane;
    $display->panels['project'][1] = 'new-e0ac1452-1d43-4bbf-adf1-c425d7cf8594';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4043addd-5484-427d-a8d8-a4f3c5370b88';
  $handler->conf['display'] = $display;
  $export['site_template__403'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__404';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => '404',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '404',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'page-not-found
user/login',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'single';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'project' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a3b1dd41-80f3-4056-8501-ef94837617d8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-81670b96-affb-4d05-90cb-c6696bb45598';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.logo';
    $pane->subtype = 'usanetwork_press.logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '81670b96-affb-4d05-90cb-c6696bb45598';
    $display->content['new-81670b96-affb-4d05-90cb-c6696bb45598'] = $pane;
    $display->panels['project'][0] = 'new-81670b96-affb-4d05-90cb-c6696bb45598';
    $pane = new stdClass();
    $pane->pid = 'new-e652328c-dabe-4a0b-9b56-a2ac4aa6c281';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.page_unavailable';
    $pane->subtype = 'usanetwork_press.page_unavailable';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e652328c-dabe-4a0b-9b56-a2ac4aa6c281';
    $display->content['new-e652328c-dabe-4a0b-9b56-a2ac4aa6c281'] = $pane;
    $display->panels['project'][1] = 'new-e652328c-dabe-4a0b-9b56-a2ac4aa6c281';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__404'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__login_page';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Login page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'login_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'single';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'project' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e190e955-9eb1-4408-a0a3-7d7a489e7f1f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5ddfb908-0f18-4b72-9d3c-610703b417cb';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.logo';
    $pane->subtype = 'usanetwork_press.logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5ddfb908-0f18-4b72-9d3c-610703b417cb';
    $display->content['new-5ddfb908-0f18-4b72-9d3c-610703b417cb'] = $pane;
    $display->panels['project'][0] = 'new-5ddfb908-0f18-4b72-9d3c-610703b417cb';
    $pane = new stdClass();
    $pane->pid = 'new-b7e17752-8f35-4df2-a402-f005368678a4';
    $pane->panel = 'project';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b7e17752-8f35-4df2-a402-f005368678a4';
    $display->content['new-b7e17752-8f35-4df2-a402-f005368678a4'] = $pane;
    $display->panels['project'][1] = 'new-b7e17752-8f35-4df2-a402-f005368678a4';
    $pane = new stdClass();
    $pane->pid = 'new-323d4509-78a3-48b8-a903-232c6953aef3';
    $pane->panel = 'project';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '323d4509-78a3-48b8-a903-232c6953aef3';
    $display->content['new-323d4509-78a3-48b8-a903-232c6953aef3'] = $pane;
    $display->panels['project'][2] = 'new-323d4509-78a3-48b8-a903-232c6953aef3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5ddfb908-0f18-4b72-9d3c-610703b417cb';
  $handler->conf['display'] = $display;
  $export['site_template__login_page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__project_pages';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Project pages',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: USA Network Entitireference context',
        'keyword' => 'view',
        'name' => 'view_from_argument:usanetwork_entitireference_context-ctools_context_1',
        'context' => array(
          0 => 'node',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node_from_view',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:usanetwork_entitireference_context-ctools_context_1_1',
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'Taxonomy term parent',
        'keyword' => 'taxonomy_term_parent',
        'name' => 'entity_from_field:field_press_kit_tax_item-node-taxonomy_term',
        'delta' => 0,
        'context' => 'node',
        'id' => 1,
      ),
    ),
    'name' => 'project_pages',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'press_kit' => 'press_kit',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '925c86db-6f9b-4982-8682-d8dfbf7a2ac9';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__project_pages'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__reset_password_page';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'Reset password page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'reset_password_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/reset/*',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'single';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'project' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a27f541e-f3d7-44fa-a0fc-d6156b56c366';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0459d2ff-f91a-4314-b798-e9c4c756a770';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.logo';
    $pane->subtype = 'usanetwork_press.logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0459d2ff-f91a-4314-b798-e9c4c756a770';
    $display->content['new-0459d2ff-f91a-4314-b798-e9c4c756a770'] = $pane;
    $display->panels['project'][0] = 'new-0459d2ff-f91a-4314-b798-e9c4c756a770';
    $pane = new stdClass();
    $pane->pid = 'new-deab2279-0682-4d52-aeeb-956e79803fb4';
    $pane->panel = 'project';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'deab2279-0682-4d52-aeeb-956e79803fb4';
    $display->content['new-deab2279-0682-4d52-aeeb-956e79803fb4'] = $pane;
    $display->panels['project'][1] = 'new-deab2279-0682-4d52-aeeb-956e79803fb4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__reset_password_page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__single_press_kit_project';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Press kit project',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'single_press_kit_project',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'press_kit_project' => 'press_kit_project',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b354155d-d1fd-44a3-80b9-944977677a40';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c10cc115-a14a-43fb-bc0b-d83f03307b88';
    $pane->panel = 'middle';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c10cc115-a14a-43fb-bc0b-d83f03307b88';
    $display->content['new-c10cc115-a14a-43fb-bc0b-d83f03307b88'] = $pane;
    $display->panels['middle'][0] = 'new-c10cc115-a14a-43fb-bc0b-d83f03307b88';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c10cc115-a14a-43fb-bc0b-d83f03307b88';
  $handler->conf['display'] = $display;
  $export['site_template__single_press_kit_project'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__taxonomy_term_page';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Taxonomy term page (First level)',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Term parent',
        'keyword' => 'parent_term',
        'name' => 'term_parent',
        'type' => 'top',
        'context' => 'term',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'View: USA Network get node from term item',
        'keyword' => 'view',
        'name' => 'view_from_argument:usanetwork_get_node_from_term_item-ctools_context_1',
        'context' => array(
          0 => 'relationship_term_parent_1',
        ),
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:usanetwork_get_node_from_term_item-ctools_context_1_1',
        'id' => 1,
      ),
      3 => array(
        'identifier' => 'View: USA Network get node from term item(secondary menu)',
        'keyword' => 'view_2',
        'name' => 'view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'term',
        ),
        'id' => 1,
      ),
      4 => array(
        'identifier' => 'View: USA Network Entitireference context',
        'keyword' => 'view_3',
        'name' => 'view_from_argument:usanetwork_entitireference_context-ctools_context_1',
        'context' => array(
          0 => 'relationship_node_from_view_1',
        ),
        'id' => 1,
      ),
      5 => array(
        'identifier' => 'Project node',
        'keyword' => 'project_node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:usanetwork_entitireference_context-ctools_context_1_1',
        'id' => 2,
      ),
    ),
    'name' => 'taxonomy_term_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'press_kit_items' => 'press_kit_items',
            ),
          ),
          'context' => 'term',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_2',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'header';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'press_kits' => NULL,
      'header_image' => NULL,
      'main_menu' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '31b60b55-418a-4bb6-98ad-70c4a6a3be59';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-16b17fff-babf-4b05-8c7f-3e708857fd3e';
    $pane->panel = 'content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '16b17fff-babf-4b05-8c7f-3e708857fd3e';
    $display->content['new-16b17fff-babf-4b05-8c7f-3e708857fd3e'] = $pane;
    $display->panels['content'][0] = 'new-16b17fff-babf-4b05-8c7f-3e708857fd3e';
    $pane = new stdClass();
    $pane->pid = 'new-5110cdcc-ff75-4850-809e-ea9772c49b11';
    $pane->panel = 'header_image';
    $pane->type = 'usanetwork_press.project_menu';
    $pane->subtype = 'usanetwork_press.project_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any press_kit_project content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_2',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5110cdcc-ff75-4850-809e-ea9772c49b11';
    $display->content['new-5110cdcc-ff75-4850-809e-ea9772c49b11'] = $pane;
    $display->panels['header_image'][0] = 'new-5110cdcc-ff75-4850-809e-ea9772c49b11';
    $pane = new stdClass();
    $pane->pid = 'new-fecf071e-3cbb-413d-9ba9-1d45efcc8292';
    $pane->panel = 'header_image';
    $pane->type = 'usanetwork_press.node_link';
    $pane->subtype = 'usanetwork_press.node_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_2',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fecf071e-3cbb-413d-9ba9-1d45efcc8292';
    $display->content['new-fecf071e-3cbb-413d-9ba9-1d45efcc8292'] = $pane;
    $display->panels['header_image'][1] = 'new-fecf071e-3cbb-413d-9ba9-1d45efcc8292';
    $pane = new stdClass();
    $pane->pid = 'new-8842a5cc-40ee-4505-b3c0-00c0c7e0c3e0';
    $pane->panel = 'header_image';
    $pane->type = 'usanetwork_press.dynamic_header';
    $pane->subtype = 'usanetwork_press.dynamic_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8842a5cc-40ee-4505-b3c0-00c0c7e0c3e0';
    $display->content['new-8842a5cc-40ee-4505-b3c0-00c0c7e0c3e0'] = $pane;
    $display->panels['header_image'][2] = 'new-8842a5cc-40ee-4505-b3c0-00c0c7e0c3e0';
    $pane = new stdClass();
    $pane->pid = 'new-0619dc26-de0d-4185-9a98-cb5d1038c2c4';
    $pane->panel = 'header_image';
    $pane->type = 'usanetwork_press.logo';
    $pane->subtype = 'usanetwork_press.logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '0619dc26-de0d-4185-9a98-cb5d1038c2c4';
    $display->content['new-0619dc26-de0d-4185-9a98-cb5d1038c2c4'] = $pane;
    $display->panels['header_image'][3] = 'new-0619dc26-de0d-4185-9a98-cb5d1038c2c4';
    $pane = new stdClass();
    $pane->pid = 'new-8d102540-7ae1-4c26-a626-d4c9479dfe32';
    $pane->panel = 'header_image';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_press_kit_logo';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:press_kit:field_is_press_kit_logo',
          'settings' => array(
            'field_is_press_kit_logo' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_press_kit_logo_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => '',
        'image_link' => '',
      ),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '8d102540-7ae1-4c26-a626-d4c9479dfe32';
    $display->content['new-8d102540-7ae1-4c26-a626-d4c9479dfe32'] = $pane;
    $display->panels['header_image'][4] = 'new-8d102540-7ae1-4c26-a626-d4c9479dfe32';
    $pane = new stdClass();
    $pane->pid = 'new-e25f1228-240e-4339-ad6d-f268fd934aab';
    $pane->panel = 'header_image';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_press_kit_date_text';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'e25f1228-240e-4339-ad6d-f268fd934aab';
    $display->content['new-e25f1228-240e-4339-ad6d-f268fd934aab'] = $pane;
    $display->panels['header_image'][5] = 'new-e25f1228-240e-4339-ad6d-f268fd934aab';
    $pane = new stdClass();
    $pane->pid = 'new-a2f80d29-9bcc-433b-88e7-4e9d2df032f9';
    $pane->panel = 'header_image';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_press_kit_date_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'a2f80d29-9bcc-433b-88e7-4e9d2df032f9';
    $display->content['new-a2f80d29-9bcc-433b-88e7-4e9d2df032f9'] = $pane;
    $display->panels['header_image'][6] = 'new-a2f80d29-9bcc-433b-88e7-4e9d2df032f9';
    $pane = new stdClass();
    $pane->pid = 'new-e22e7a5a-3982-4b15-aa58-3c3b3d8f3d43';
    $pane->panel = 'main_menu';
    $pane->type = 'usanetwork_press.menu_main';
    $pane->subtype = 'usanetwork_press.menu_main';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e22e7a5a-3982-4b15-aa58-3c3b3d8f3d43';
    $display->content['new-e22e7a5a-3982-4b15-aa58-3c3b3d8f3d43'] = $pane;
    $display->panels['main_menu'][0] = 'new-e22e7a5a-3982-4b15-aa58-3c3b3d8f3d43';
    $pane = new stdClass();
    $pane->pid = 'new-1f12d6f2-3abe-4a9f-a62e-641bf8b18d44';
    $pane->panel = 'press_kits';
    $pane->type = 'usanetwork_press.menu_switch';
    $pane->subtype = 'usanetwork_press.menu_switch';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'node' => '%node:nid',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'context' => 'relationship_node_from_view_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1f12d6f2-3abe-4a9f-a62e-641bf8b18d44';
    $display->content['new-1f12d6f2-3abe-4a9f-a62e-641bf8b18d44'] = $pane;
    $display->panels['press_kits'][0] = 'new-1f12d6f2-3abe-4a9f-a62e-641bf8b18d44';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__taxonomy_term_page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__taxonomy_term_page_second_level_';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Taxonomy term page (Second level)',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Term parent',
        'keyword' => 'parent_term',
        'name' => 'term_parent',
        'type' => 'parent',
        'context' => 'term',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'View: USA Network get node from term item',
        'keyword' => 'view',
        'name' => 'view_from_argument:usanetwork_get_node_from_term_item-ctools_context_1',
        'context' => array(
          0 => 'relationship_term_parent_1',
        ),
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:usanetwork_get_node_from_term_item-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'name' => 'taxonomy_term_page_second_level_',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'press_kit_items' => 'press_kit_items',
            ),
          ),
          'context' => 'term',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'usanetwork_press.taxonomy_depth',
          'settings' => array(
            'depth' => '3',
          ),
          'context' => 'term',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'header';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'press_kits' => NULL,
      'header_image' => NULL,
      'main_menu' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array(
    'method' => 0,
  );
  $display->title = '';
  $display->uuid = 'bcfc1997-ab42-4d20-b7a7-f5718c02b553';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b1325dac-bd62-4dfb-bc50-754307b94605';
    $pane->panel = 'content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b1325dac-bd62-4dfb-bc50-754307b94605';
    $display->content['new-b1325dac-bd62-4dfb-bc50-754307b94605'] = $pane;
    $display->panels['content'][0] = 'new-b1325dac-bd62-4dfb-bc50-754307b94605';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__taxonomy_term_page_second_level_'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__user_password_recovery';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'User password recovery',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'user_password_recovery',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/password',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'single';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'project' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd64cdb08-9c97-4f54-a365-ef12dbe7b2d6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d6a8a46b-9399-47ba-bfbb-f76a82ca23c0';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.logo';
    $pane->subtype = 'usanetwork_press.logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd6a8a46b-9399-47ba-bfbb-f76a82ca23c0';
    $display->content['new-d6a8a46b-9399-47ba-bfbb-f76a82ca23c0'] = $pane;
    $display->panels['project'][0] = 'new-d6a8a46b-9399-47ba-bfbb-f76a82ca23c0';
    $pane = new stdClass();
    $pane->pid = 'new-c9e1fbcc-fd29-4504-bd64-6c53d02d2010';
    $pane->panel = 'project';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c9e1fbcc-fd29-4504-bd64-6c53d02d2010';
    $display->content['new-c9e1fbcc-fd29-4504-bd64-6c53d02d2010'] = $pane;
    $display->panels['project'][1] = 'new-c9e1fbcc-fd29-4504-bd64-6c53d02d2010';
    $pane = new stdClass();
    $pane->pid = 'new-10faed5d-e529-4d61-98b5-2515376ab759';
    $pane->panel = 'project';
    $pane->type = 'usanetwork_press.password_recovery';
    $pane->subtype = 'usanetwork_press.password_recovery';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '10faed5d-e529-4d61-98b5-2515376ab759';
    $display->content['new-10faed5d-e529-4d61-98b5-2515376ab759'] = $pane;
    $display->panels['project'][2] = 'new-10faed5d-e529-4d61-98b5-2515376ab759';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__user_password_recovery'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__403_term_page';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => '403 term page',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: USA Network get node from term item(secondary menu)',
        'keyword' => 'view',
        'name' => 'view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'argument_term_1',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'code' => '403',
    'destination' => '',
    'name' => '403_term_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'press_kit_items' => 'press_kit_items',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_1',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['term_view__403_term_page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__press_contacts_page';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Press contacts page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: USA Network get node from term item(secondary menu)',
        'keyword' => 'view',
        'name' => 'view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'argument_term_1',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'name' => 'press_contacts_page',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'contacts_page' => 'contacts_page',
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'press_kit_items' => 'press_kit_items',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'links_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1e6d6c86-2866-4c7f-89bf-7160e2f64dcf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b134bdb6-7b15-46cd-b8a9-cc05293911b5';
    $pane->panel = 'content';
    $pane->type = 'usanetwork_press.content_menu';
    $pane->subtype = 'usanetwork_press.content_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create contacts_page content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any contacts_page content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b134bdb6-7b15-46cd-b8a9-cc05293911b5';
    $display->content['new-b134bdb6-7b15-46cd-b8a9-cc05293911b5'] = $pane;
    $display->panels['content'][0] = 'new-b134bdb6-7b15-46cd-b8a9-cc05293911b5';
    $pane = new stdClass();
    $pane->pid = 'new-c53bf435-6cce-45ee-8617-0b0cfd582721';
    $pane->panel = 'content';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:contacts_page:field_display_title_on_the_page',
          'settings' => array(
            'field_display_title_on_the_page' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_display_title_on_the_page_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c53bf435-6cce-45ee-8617-0b0cfd582721';
    $display->content['new-c53bf435-6cce-45ee-8617-0b0cfd582721'] = $pane;
    $display->panels['content'][1] = 'new-c53bf435-6cce-45ee-8617-0b0cfd582721';
    $pane = new stdClass();
    $pane->pid = 'new-f7f0677d-4e82-4e42-a466-425d92106811';
    $pane->panel = 'content';
    $pane->type = 'views_panes';
    $pane->subtype = 'usanetwork_contacts_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'relationship_node_from_view_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f7f0677d-4e82-4e42-a466-425d92106811';
    $display->content['new-f7f0677d-4e82-4e42-a466-425d92106811'] = $pane;
    $display->panels['content'][2] = 'new-f7f0677d-4e82-4e42-a466-425d92106811';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__press_contacts_page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__press_kit_links_page';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Press kit links page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: USA Network get node from term item(secondary menu)',
        'keyword' => 'view',
        'name' => 'view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'argument_term_1',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'name' => 'press_kit_links_page',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'links_page' => 'links_page',
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'press_kit_items' => 'press_kit_items',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'links_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '98a041ca-4ea0-4295-b0da-3396412c7ea9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3ccf9fc9-bde1-43bf-8937-3119b33379f1';
    $pane->panel = 'content';
    $pane->type = 'usanetwork_press.content_menu';
    $pane->subtype = 'usanetwork_press.content_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create links_page content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any links_page content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3ccf9fc9-bde1-43bf-8937-3119b33379f1';
    $display->content['new-3ccf9fc9-bde1-43bf-8937-3119b33379f1'] = $pane;
    $display->panels['content'][0] = 'new-3ccf9fc9-bde1-43bf-8937-3119b33379f1';
    $pane = new stdClass();
    $pane->pid = 'new-d01da41e-0432-4196-839c-33398eb00e6f';
    $pane->panel = 'content';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:links_page:field_display_title_on_the_page',
          'settings' => array(
            'field_display_title_on_the_page' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_display_title_on_the_page_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd01da41e-0432-4196-839c-33398eb00e6f';
    $display->content['new-d01da41e-0432-4196-839c-33398eb00e6f'] = $pane;
    $display->panels['content'][1] = 'new-d01da41e-0432-4196-839c-33398eb00e6f';
    $pane = new stdClass();
    $pane->pid = 'new-3ab2bcf2-2d2f-4684-bff8-702f3ce3344c';
    $pane->panel = 'content';
    $pane->type = 'views_panes';
    $pane->subtype = 'usanetwork_links_view-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'relationship_node_from_view_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3ab2bcf2-2d2f-4684-bff8-702f3ce3344c';
    $display->content['new-3ab2bcf2-2d2f-4684-bff8-702f3ce3344c'] = $pane;
    $display->panels['content'][2] = 'new-3ab2bcf2-2d2f-4684-bff8-702f3ce3344c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__press_kit_links_page'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__press_kit_menu_first_level';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Press kit press page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: USA Network get node from term item(secondary menu)',
        'keyword' => 'view',
        'name' => 'view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'argument_term_1',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'name' => 'press_kit_menu_first_level',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'press_kit_items' => 'press_kit_items',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'press_materials_page' => 'press_materials_page',
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'secondary_menu_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
      'content' => NULL,
      'secondary_menu' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '948bf498-27be-4b48-9844-74146448de5d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d248a7bf-e7ee-409b-84f0-40a2037baecd';
    $pane->panel = 'content';
    $pane->type = 'usanetwork_press.content_menu';
    $pane->subtype = 'usanetwork_press.content_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create press_materials_page content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any press_materials_page content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd248a7bf-e7ee-409b-84f0-40a2037baecd';
    $display->content['new-d248a7bf-e7ee-409b-84f0-40a2037baecd'] = $pane;
    $display->panels['content'][0] = 'new-d248a7bf-e7ee-409b-84f0-40a2037baecd';
    $pane = new stdClass();
    $pane->pid = 'new-6067d804-cacd-46e1-be2d-727e844207e1';
    $pane->panel = 'content';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:press_materials_page:field_display_title_on_the_page',
          'settings' => array(
            'field_display_title_on_the_page' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_display_title_on_the_page_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6067d804-cacd-46e1-be2d-727e844207e1';
    $display->content['new-6067d804-cacd-46e1-be2d-727e844207e1'] = $pane;
    $display->panels['content'][1] = 'new-6067d804-cacd-46e1-be2d-727e844207e1';
    $pane = new stdClass();
    $pane->pid = 'new-e49ff564-8879-47d3-b809-844bf93ab321';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_download_pdf';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e49ff564-8879-47d3-b809-844bf93ab321';
    $display->content['new-e49ff564-8879-47d3-b809-844bf93ab321'] = $pane;
    $display->panels['content'][2] = 'new-e49ff564-8879-47d3-b809-844bf93ab321';
    $pane = new stdClass();
    $pane->pid = 'new-67ba7a2b-431f-4d40-8a45-c66ba9825462';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '67ba7a2b-431f-4d40-8a45-c66ba9825462';
    $display->content['new-67ba7a2b-431f-4d40-8a45-c66ba9825462'] = $pane;
    $display->panels['content'][3] = 'new-67ba7a2b-431f-4d40-8a45-c66ba9825462';
    $pane = new stdClass();
    $pane->pid = 'new-247d26ad-2f0e-4f39-aae2-054fedc6698e';
    $pane->panel = 'secondary_menu';
    $pane->type = 'usanetwork_press.secondary_menu';
    $pane->subtype = 'usanetwork_press.secondary_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '247d26ad-2f0e-4f39-aae2-054fedc6698e';
    $display->content['new-247d26ad-2f0e-4f39-aae2-054fedc6698e'] = $pane;
    $display->panels['secondary_menu'][0] = 'new-247d26ad-2f0e-4f39-aae2-054fedc6698e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__press_kit_menu_first_level'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__press_kit_no_content';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Press kit no content',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: USA Network get node from term item(secondary menu)',
        'keyword' => 'view',
        'name' => 'view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'argument_term_1',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'name' => 'press_kit_no_content',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'press_kit_items' => 'press_kit_items',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '0',
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'secondary_menu_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
      'secondary_menu' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'bd429c8a-8116-45a9-bf60-a5819d9209c6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-da3408ba-6988-4336-b6c0-4a72ca8b221d';
    $pane->panel = 'content';
    $pane->type = 'usanetwork_press.content_menu';
    $pane->subtype = 'usanetwork_press.content_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create press_materials_page content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any press_materials_page content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'da3408ba-6988-4336-b6c0-4a72ca8b221d';
    $display->content['new-da3408ba-6988-4336-b6c0-4a72ca8b221d'] = $pane;
    $display->panels['content'][0] = 'new-da3408ba-6988-4336-b6c0-4a72ca8b221d';
    $pane = new stdClass();
    $pane->pid = 'new-a8672e2d-0d68-4185-9500-62dd98c4acf9';
    $pane->panel = 'secondary_menu';
    $pane->type = 'usanetwork_press.secondary_menu';
    $pane->subtype = 'usanetwork_press.secondary_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a8672e2d-0d68-4185-9500-62dd98c4acf9';
    $display->content['new-a8672e2d-0d68-4185-9500-62dd98c4acf9'] = $pane;
    $display->panels['secondary_menu'][0] = 'new-a8672e2d-0d68-4185-9500-62dd98c4acf9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__press_kit_no_content'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__press_kit_photos';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Press kit photos',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: USA Network get node from term item(secondary menu)',
        'keyword' => 'view',
        'name' => 'view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'argument_term_1',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'name' => 'press_kit_photos',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'press_kit_items' => 'press_kit_items',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'usanetwork_photos' => 'usanetwork_photos',
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'secondary_menu_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
      'secondary_menu' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '339902bf-78f7-4acb-bcbc-35064f0eb664';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-79c8a076-ba54-45d9-88d6-37318a322903';
    $pane->panel = 'content';
    $pane->type = 'usanetwork_press.content_menu';
    $pane->subtype = 'usanetwork_press.content_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create usanetwork_photos content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any usanetwork_photos content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '79c8a076-ba54-45d9-88d6-37318a322903';
    $display->content['new-79c8a076-ba54-45d9-88d6-37318a322903'] = $pane;
    $display->panels['content'][0] = 'new-79c8a076-ba54-45d9-88d6-37318a322903';
    $pane = new stdClass();
    $pane->pid = 'new-dbc08303-e173-45d5-95fb-71a1144e3f97';
    $pane->panel = 'content';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:usanetwork_photos:field_display_title_on_the_page',
          'settings' => array(
            'field_display_title_on_the_page' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_display_title_on_the_page_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h2',
      'id' => '',
      'class' => '',
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'dbc08303-e173-45d5-95fb-71a1144e3f97';
    $display->content['new-dbc08303-e173-45d5-95fb-71a1144e3f97'] = $pane;
    $display->panels['content'][1] = 'new-dbc08303-e173-45d5-95fb-71a1144e3f97';
    $pane = new stdClass();
    $pane->pid = 'new-81dc2361-8ee8-40ab-bab6-f45e7d3c3c2f';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_usanetwork_photos';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'field_collection_entity_flexslider',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'full',
        'optionset' => 'photos_page',
      ),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '81dc2361-8ee8-40ab-bab6-f45e7d3c3c2f';
    $display->content['new-81dc2361-8ee8-40ab-bab6-f45e7d3c3c2f'] = $pane;
    $display->panels['content'][2] = 'new-81dc2361-8ee8-40ab-bab6-f45e7d3c3c2f';
    $pane = new stdClass();
    $pane->pid = 'new-e00a96d7-4ac2-483d-bfa1-d6580179fae3';
    $pane->panel = 'secondary_menu';
    $pane->type = 'usanetwork_press.secondary_menu';
    $pane->subtype = 'usanetwork_press.secondary_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e00a96d7-4ac2-483d-bfa1-d6580179fae3';
    $display->content['new-e00a96d7-4ac2-483d-bfa1-d6580179fae3'] = $pane;
    $display->panels['secondary_menu'][0] = 'new-e00a96d7-4ac2-483d-bfa1-d6580179fae3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__press_kit_photos'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__press_kit_videos';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Press kit videos',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'View: USA Network get node from term item(secondary menu)',
        'keyword' => 'view',
        'name' => 'view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1',
        'context' => array(
          0 => 'argument_term_1',
        ),
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Node from view',
        'keyword' => 'node',
        'name' => 'node_from_view',
        'row' => '1',
        'context' => 'relationship_view_from_argument:usanetwork_get_node_from_term_item_secondary_menu-ctools_context_1_1',
        'id' => 1,
      ),
    ),
    'name' => 'press_kit_videos',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'press_kit_items' => 'press_kit_items',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'videos_page' => 'videos_page',
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'usanetwork_press.premissions',
          'settings' => NULL,
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'secondary_menu_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
      'secondary_menu' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a66d9223-84a6-4bc7-86e3-d3de60c9a8c9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9d9ab9d5-020d-400f-aaba-c6062bc61b28';
    $pane->panel = 'content';
    $pane->type = 'usanetwork_press.content_menu';
    $pane->subtype = 'usanetwork_press.content_menu';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create videos_page content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any videos_page content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9d9ab9d5-020d-400f-aaba-c6062bc61b28';
    $display->content['new-9d9ab9d5-020d-400f-aaba-c6062bc61b28'] = $pane;
    $display->panels['content'][0] = 'new-9d9ab9d5-020d-400f-aaba-c6062bc61b28';
    $pane = new stdClass();
    $pane->pid = 'new-134c0a22-b14c-435a-bda9-8e51cbf180a0';
    $pane->panel = 'content';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:videos_page:field_display_title_on_the_page',
          'settings' => array(
            'field_display_title_on_the_page' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_display_title_on_the_page_value' => array(
              0 => 1,
            ),
          ),
          'context' => 'relationship_node_from_view_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h2',
      'id' => '',
      'class' => '',
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '134c0a22-b14c-435a-bda9-8e51cbf180a0';
    $display->content['new-134c0a22-b14c-435a-bda9-8e51cbf180a0'] = $pane;
    $display->panels['content'][1] = 'new-134c0a22-b14c-435a-bda9-8e51cbf180a0';
    $pane = new stdClass();
    $pane->pid = 'new-0bcdf930-95a0-44a0-9e59-e62e0b2c5436';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_video_description_top';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0bcdf930-95a0-44a0-9e59-e62e0b2c5436';
    $display->content['new-0bcdf930-95a0-44a0-9e59-e62e0b2c5436'] = $pane;
    $display->panels['content'][2] = 'new-0bcdf930-95a0-44a0-9e59-e62e0b2c5436';
    $pane = new stdClass();
    $pane->pid = 'new-7a66b1da-1de0-45b2-9bd3-7d9f0c66a407';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_video_url';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'video_embed_field',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'video_style' => 'normal',
      ),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '7a66b1da-1de0-45b2-9bd3-7d9f0c66a407';
    $display->content['new-7a66b1da-1de0-45b2-9bd3-7d9f0c66a407'] = $pane;
    $display->panels['content'][3] = 'new-7a66b1da-1de0-45b2-9bd3-7d9f0c66a407';
    $pane = new stdClass();
    $pane->pid = 'new-d0796f8c-8531-443d-b3c5-1af81d18d9c8';
    $pane->panel = 'content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_video_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'd0796f8c-8531-443d-b3c5-1af81d18d9c8';
    $display->content['new-d0796f8c-8531-443d-b3c5-1af81d18d9c8'] = $pane;
    $display->panels['content'][4] = 'new-d0796f8c-8531-443d-b3c5-1af81d18d9c8';
    $pane = new stdClass();
    $pane->pid = 'new-758e8920-524f-4c35-97a9-c3ddc5e9122a';
    $pane->panel = 'secondary_menu';
    $pane->type = 'usanetwork_press.secondary_menu';
    $pane->subtype = 'usanetwork_press.secondary_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_from_view_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '758e8920-524f-4c35-97a9-c3ddc5e9122a';
    $display->content['new-758e8920-524f-4c35-97a9-c3ddc5e9122a'] = $pane;
    $display->panels['secondary_menu'][0] = 'new-758e8920-524f-4c35-97a9-c3ddc5e9122a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view__press_kit_videos'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view__redirect_user_on_content_page';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Redirect user on content page',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'admin/content',
    'name' => 'redirect_user_on_content_page',
  );
  $export['user_view__redirect_user_on_content_page'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function usanetwork_press_core_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panels_customerror_403';
  $page->task = 'page';
  $page->admin_title = 'Panels Custom Error Access Denied';
  $page->admin_description = '';
  $page->path = 'access-denied';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panels_customerror_403_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panels_customerror_403';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'single';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left' => NULL,
      'right' => NULL,
      'project' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Page not available';
  $display->uuid = '7e0e26d2-b517-443a-9d53-95a60f476fa6';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panels_customerror_403'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panels_customerror_404';
  $page->task = 'page';
  $page->admin_title = 'Panels Custom Error Page Not Found';
  $page->admin_description = '';
  $page->path = 'page-not-found';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panels_customerror_404_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panels_customerror_404';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'single';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'project' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Page not available';
  $display->uuid = '17b277ea-d05c-4565-93c9-95bde15960eb';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panels_customerror_404'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'password_recovery_page';
  $page->task = 'page';
  $page->admin_title = 'Password recovery page';
  $page->admin_description = '';
  $page->path = 'user/reset/%text';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'text' => array(
      'settings' => array(),
      'identifier' => 'No context',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_password_recovery_page__panel_context_8ab04700-a8f4-4ab2-9148-14b451f79b70';
  $handler->task = 'page';
  $handler->subtask = 'password_recovery_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9c84afba-0cfc-44bf-b7ca-9c104e0926eb';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['password_recovery_page'] = $page;

  return $pages;

}
