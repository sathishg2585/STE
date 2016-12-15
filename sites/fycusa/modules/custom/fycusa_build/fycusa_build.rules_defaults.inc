<?php
/**
 * @file
 * fycusa_build.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function fycusa_build_default_rules_configuration() {
  $items = array();
  $items['rules_after_creating_menu_item_from_tax_admin_fyc'] = entity_import('rules_config', '{ "rules_after_creating_menu_item_from_tax_admin_fyc" : {
      "LABEL" : "After creating menu item from tax admin",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations", "path", "taxonomy" ],
      "ON" : {
        "taxonomy_term_insert--fyc_show_items" : { "bundle" : "fyc_show_items" },
        "taxonomy_term_update--fyc_show_items" : { "bundle" : "fyc_show_items" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "term:parents-all" ], "value" : "2" } },
        { "views_bulk_operations_condition_result_count" : {
            "view" : "fyc_shows_from_term|default",
            "args" : "[term:parent:tid]",
            "minimum" : "2"
          }
        },
        { "views_bulk_operations_condition_result_count" : {
            "view" : "fyc_get_node_from_term_item|ctools_context_1",
            "args" : "[term:parent:tid]",
            "minimum" : "1"
          }
        }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "fyc_get_node_from_term_item|ctools_context_1",
              "args" : "[term:parent:tid]"
            },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "entity-list:0:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "fyc_entityreference_context|panel_pane_1",
              "args" : "[entity-fetched:nid]"
            },
            "PROVIDE" : { "entity_list" : { "ref_nodes" : "A list of entities" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "ref-nodes:0:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "project" : "Fetched entity" } }
          }
        },
        { "path_alias" : { "source" : "taxonomy\\/term\\/[term:tid]" } },
        { "taxonomy_term_path_alias" : {
            "node" : [ "term" ],
            "alias" : "[project:url:alias]\\/[entity-fetched:title]\\/[term:name]"
          }
        }
      ]
    }
  }');
  $items['rules_after_creating_menu_item_from_tax_admin_single_fyc_show'] = entity_import('rules_config', '{ "rules_after_creating_menu_item_from_tax_admin_single_fyc_show" : {
      "LABEL" : "After creating menu item from tax admin (Single FYC Show)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "2",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations", "path", "taxonomy" ],
      "ON" : {
        "taxonomy_term_insert--fyc_show_items" : { "bundle" : "fyc_show_items" },
        "taxonomy_term_update--fyc_show_items" : { "bundle" : "fyc_show_items" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "term:parents-all" ], "value" : "2" } },
        { "NOT views_bulk_operations_condition_result_count" : {
            "view" : "fyc_shows_from_term|default",
            "args" : "[term:parent:tid]",
            "minimum" : "2"
          }
        },
        { "views_bulk_operations_condition_result_count" : {
            "view" : "fyc_get_node_from_term_item|ctools_context_1",
            "args" : "[term:parent:tid]",
            "minimum" : "1"
          }
        }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "fyc_get_node_from_term_item|ctools_context_1",
              "args" : "[term:parent:tid]"
            },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "entity-list:0:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "fyc_entityreference_context|panel_pane_1",
              "args" : "[entity-fetched:nid]"
            },
            "PROVIDE" : { "entity_list" : { "ref_nodes" : "A list of entities" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "ref-nodes:0:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "project" : "Fetched entity" } }
          }
        },
        { "path_alias" : { "source" : "taxonomy\\/term\\/[term:tid]" } },
        { "taxonomy_term_path_alias" : { "node" : [ "term" ], "alias" : "[project:url:alias]\\/[term:name]" } }
      ]
    }
  }');
  $items['rules_after_creating_menu_item_fyc'] = entity_import('rules_config', '{ "rules_after_creating_menu_item_fyc" : {
      "LABEL" : "After creating menu item",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "path", "taxonomy" ],
      "ON" : {
        "taxonomy_term_insert--fyc_show_items" : { "bundle" : "fyc_show_items" },
        "taxonomy_term_update--fyc_show_items" : { "bundle" : "fyc_show_items" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "term:parents-all" ], "op" : "\\u003E", "value" : "2" } }
      ],
      "DO" : [
        { "path_alias" : { "source" : "taxonomy\\/term\\/[term:tid]" } },
        { "taxonomy_term_path_alias" : {
            "node" : [ "term" ],
            "alias" : "[term:parents:url:alias:join-path]\\/[term:name]?after_creating_menu_item_fyc=1"
          }
        }
      ]
    }
  }');
  $items['rules_after_deleting_content_of_fyc_project'] = entity_import('rules_config', '{ "rules_after_deleting_content_of_fyc_project" : {
      "LABEL" : "After deleting content of project",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "3",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_delete" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "fyc_series_overview" : "fyc_series_overview",
                "fyc_video" : "fyc_video",
                "fyc_award" : "fyc_award"
              }
            }
          }
        }
      ],
      "DO" : [ { "entity_delete" : { "data" : [ "node:field-fyc-menu-position" ] } } ]
    }
  }');
  $items['rules_after_save_fyc_multi_project'] = entity_import('rules_config', '{ "rules_after_save_fyc_multi_project" : {
      "LABEL" : "After save multi project",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "5",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations", "path" ],
      "ON" : {
        "node_insert--fyc_project" : { "bundle" : "fyc_project" },
        "node_update--fyc_project" : { "bundle" : "fyc_project" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "node:field-fyc-show" ], "op" : "\\u003E", "value" : "1" } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-fyc-show" ] },
            "ITEM" : { "fyc_show_item" : "Current list item" },
            "DO" : [
              { "entity_fetch" : {
                  "USING" : { "type" : "node", "id" : [ "fyc-show-item:nid" ] },
                  "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
                }
              },
              { "views_bulk_operations_action_load_list" : {
                  "USING" : {
                    "view" : "fyc_menu_reference|default",
                    "args" : [ "fyc-show-item:nid" ]
                  },
                  "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
                }
              },
              { "entity_fetch" : {
                  "USING" : { "type" : "taxonomy_term", "id" : [ "entity-list:0:tid" ] },
                  "PROVIDE" : { "entity_fetched" : { "term_fetched" : "Fetched entity" } }
                }
              },
              { "views_bulk_operations_action_load_list" : {
                  "USING" : {
                    "view" : "fyc_rules_get_child_terms|default",
                    "args" : [ "term-fetched:tid" ]
                  },
                  "PROVIDE" : { "entity_list" : { "child_list" : "A list of entities" } }
                }
              },
              { "LOOP" : {
                  "USING" : { "list" : [ "child-list" ] },
                  "ITEM" : { "list_item" : "Current list item" },
                  "DO" : [
                    { "taxonomy_term_path_alias" : {
                        "node" : [ "list-item" ],
                        "alias" : "[node:url:alias]\\/[fyc-show-item:title]\\/[list-item:name]"
                      }
                    }
                  ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_after_save_fyc_single_project'] = entity_import('rules_config', '{ "rules_after_save_fyc_single_project" : {
      "LABEL" : "After save single project",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations", "path" ],
      "ON" : { "node_insert--fyc_project" : { "bundle" : "fyc_project" } },
      "IF" : [
        { "list_count_is" : { "list" : [ "node:field-fyc-show" ], "value" : "1" } }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "fyc_menu_reference|default",
              "args" : [ "node:field-fyc-show:0:nid" ]
            },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "taxonomy_term", "id" : [ "entity-list:0:tid" ] },
            "PROVIDE" : { "entity_fetched" : { "term_fetched" : "Fetched entity" } }
          }
        },
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "fyc_rules_get_child_terms|default",
              "args" : [ "term-fetched:tid" ]
            },
            "PROVIDE" : { "entity_list" : { "child_list" : "A list of entities" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "child-list" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "taxonomy_term_path_alias" : {
                  "node" : [ "list-item" ],
                  "alias" : "[node:url:alias]\\/[list-item:name]"
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_create_url_aliases_for_fyc_shows'] = entity_import('rules_config', '{ "rules_create_url_aliases_for_fyc_shows" : {
      "LABEL" : "Create url aliases for FYC Show",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "6",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "path" ],
      "ON" : {
        "node_insert--fyc_project" : { "bundle" : "fyc_project" },
        "node_update--fyc_project" : { "bundle" : "fyc_project" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "node:field-fyc-show" ], "op" : "\\u003E", "value" : "1" } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-fyc-show" ] },
            "ITEM" : { "fyc_show_item" : "FYC Show item" },
            "DO" : [
              { "node_path_alias" : {
                  "node" : [ "fyc-show-item" ],
                  "alias" : "[node:url:alias]\\/[fyc-show-item:title]"
                }
              },
              { "entity_save" : { "data" : [ "fyc-show-item" ], "immediate" : "1" } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_create_url_aliases_for_fyc_single_project'] = entity_import('rules_config', '{ "rules_create_url_aliases_for_fyc_single_project" : {
      "LABEL" : "Create url aliases for single project",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "7",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "path" ],
      "ON" : {
        "node_insert--fyc_project" : { "bundle" : "fyc_project" },
        "node_update--fyc_project" : { "bundle" : "fyc_project" }
      },
      "IF" : [
        { "list_count_is" : { "list" : [ "node:field-fyc-show" ], "value" : "1" } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "node:field-fyc-show:0" ] },
            "PROVIDE" : { "variable_added" : { "single_fyc_show" : "Single FYC Show" } }
          }
        },
        { "node_path_alias" : { "node" : [ "single-fyc-show" ], "alias" : "[single-fyc-show:title]" } }
      ]
    }
  }');
  $items['rules_fyc_on_project_view'] = entity_import('rules_config', '{ "rules_fyc_on_project_view" : {
      "LABEL" : "FYC On project view",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "8",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations" ],
      "ON" : { "node_view--fyc_show" : { "bundle" : "fyc_show" } },
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "taxonomy_term",
              "id" : [ "node:field-fyc-show-tax-item:tid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "menu_term_fetched" : "Fetched entity" } }
          }
        },
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "fyc_rules_get_child_terms|default",
              "args" : "[menu-term-fetched:tid]"
            },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "taxonomy_term", "value" : [ "entity-list:0" ] },
            "PROVIDE" : { "variable_added" : { "first_menu_item" : "Added variable" } }
          }
        },
        { "redirect" : { "url" : "[first-menu-item:url]" } }
      ]
    }
  }');
  $items['rules_fyc_secondary_menu_items_viewed'] = entity_import('rules_config', '{ "rules_fyc_secondary_menu_items_viewed" : {
      "LABEL" : "Secondary menu items viewed",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "views_bulk_operations", "taxonomy" ],
      "ON" : { "taxonomy_term_view" : [] },
      "IF" : [
        { "list_count_is" : { "list" : [ "term:parents-all" ], "op" : "\\u003E", "value" : "1" } },
        { "NOT views_bulk_operations_condition_result_count" : {
            "view" : "fyc_get_node_from_term_item_secondary_menu|panel_pane_1",
            "args" : "[term:tid]",
            "minimum" : "1"
          }
        },
        { "views_bulk_operations_condition_result_count" : {
            "view" : "fyc_rules_get_child_terms|default",
            "args" : [ "term:tid" ],
            "minimum" : "1"
          }
        }
      ],
      "DO" : [
        { "views_bulk_operations_action_load_list" : {
            "USING" : {
              "view" : "fyc_rules_get_published_child_terms|default",
              "args" : "[term:tid]"
            },
            "PROVIDE" : { "entity_list" : { "entity_list" : "A list of entities" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "taxonomy_term", "value" : [ "entity-list:0" ] },
            "PROVIDE" : { "variable_added" : { "child_term" : "Added variable" } }
          }
        },
        { "redirect" : { "url" : "[child-term:url]" } }
      ]
    }
  }');
  $items['rules_fyc_show_add'] = entity_import('rules_config', '{ "rules_fyc_show_add" : {
      "LABEL" : "Add FYC Show",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "9",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--fyc_show" : { "bundle" : "fyc_show" } },
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "taxonomy_term",
              "param_name" : [ "node:title" ],
              "param_vocabulary" : "fyc_show_items"
            },
            "PROVIDE" : { "entity_created" : { "tax_term_created" : "Tax term created" } }
          }
        },
        { "entity_save" : { "data" : [ "tax-term-created" ], "immediate" : 1 } },
        { "data_set" : {
            "data" : [ "node:field-fyc-show-tax-item" ],
            "value" : [ "tax-term-created" ]
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "taxonomy_vocabulary", "value" : "menu_items" },
            "PROVIDE" : { "variable_added" : { "vocabulary_menu_items" : "Vocabulary menu items" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "taxonomy_term",
              "property" : "vocabulary",
              "value" : [ "vocabulary-menu-items" ]
            },
            "PROVIDE" : { "entity_fetched" : { "fetched_terms" : "Fetched terms" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "fetched-terms" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_fyc_show_tax_items_add" : {
                  "tax_term_name" : [ "list-item:name" ],
                  "parent_term" : [ "tax-term-created" ],
                  "term_weight" : [ "list-item:weight" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_fyc_show_delete'] = entity_import('rules_config', '{ "rules_fyc_show_delete" : {
      "LABEL" : "Delete FYC Show",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_delete--fyc_show" : { "bundle" : "fyc_show" } },
      "DO" : [ { "entity_delete" : { "data" : [ "node:field-fyc-show-tax-item" ] } } ]
    }
  }');
  $items['rules_fyc_show_edit'] = entity_import('rules_config', '{ "rules_fyc_show_edit" : {
      "LABEL" : "Edit FYC Show",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "11",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--fyc_show" : { "bundle" : "fyc_show" } },
      "IF" : [
        { "NOT data_is" : { "data" : [ "node:title" ], "value" : [ "node-unchanged:title" ] } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : {
              "type" : "taxonomy_term",
              "id" : [ "node:field-fyc-show-tax-item:tid" ]
            },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "data_set" : { "data" : [ "entity-fetched:name" ], "value" : [ "node:title" ] } }
      ]
    }
  }');
  $items['rules_fyc_show_tax_items_add'] = entity_import('rules_config', '{ "rules_fyc_show_tax_items_add" : {
      "LABEL" : "Add taxonomy items for FYC Show",
      "PLUGIN" : "action set",
      "WEIGHT" : "12",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "tax_term_name" : { "label" : "Tax term name", "type" : "text" },
        "parent_term" : { "label" : "Parent term", "type" : "taxonomy_term" },
        "term_weight" : { "label" : "Term weight", "type" : "integer" }
      },
      "ACTION SET" : [
        { "entity_create" : {
            "USING" : {
              "type" : "taxonomy_term",
              "param_name" : [ "tax-term-name" ],
              "param_vocabulary" : "fyc_show_items"
            },
            "PROVIDE" : { "entity_created" : { "created_tax_term" : "Created tax term" } }
          }
        },
        { "entity_save" : { "data" : [ "created-tax-term" ], "immediate" : 1 } },
        { "data_set" : { "data" : [ "created-tax-term:parent:0" ], "value" : [ "parent-term" ] } },
        { "data_set" : { "data" : [ "created-tax-term:weight" ], "value" : [ "term-weight" ] } }
      ]
    }
  }');
  $items['rules_fyc_user_redirect'] = entity_import('rules_config', '{ "rules_fyc_user_redirect" : {
      "LABEL" : "FYC User Redirect",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_view" : [] },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "3" : "3", "4" : "4", "5" : "5" } }
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "[site:url]" } } ]
    }
  }');
  $items['rules_redirect_on_fyc_page_raw_view'] = entity_import('rules_config', '{ "rules_redirect_on_fyc_page_raw_view" : {
      "LABEL" : "Redirect on fyc page raw view",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_view--fyc_series_overview" : { "bundle" : "fyc_series_overview" },
        "node_view--fyc_video" : { "bundle" : "fyc_video" },
        "node_view--fyc_award" : { "bundle" : "fyc_award" }
      },
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "taxonomy_term", "value" : [ "node:field-fyc-menu-position" ] },
            "PROVIDE" : { "variable_added" : { "menu_term" : "Added variable" } }
          }
        },
        { "redirect" : { "url" : "[menu-term:url]" } }
      ]
    }
  }');
  $items['rules_redirect_on_series_overview_page_raw_view'] = entity_import('rules_config', '{ "rules_redirect_on_series_overview_page_raw_view" : {
      "LABEL" : "Redirect on series overview page raw view",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_view--fyc_series_overview" : { "bundle" : "fyc_series_overview" } },
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "taxonomy_term", "value" : [ "node:field-fyc-menu-position" ] },
            "PROVIDE" : { "variable_added" : { "menu_term" : "Added variable" } }
          }
        },
        { "redirect" : { "url" : "[menu-term:url]" } }
      ]
    }
  }');
  return $items;
}
