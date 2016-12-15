<?php

// Plugin definition
$plugin = array(
  'title' => t('Links page with single region'),
  'category' => t('Links'),
  'icon' => 'links_page.png',
  'theme' => 'links_page',
  'css' => 'links_page.css',
  'regions' => array(
    'content' => t('Content'),
  ),
);
