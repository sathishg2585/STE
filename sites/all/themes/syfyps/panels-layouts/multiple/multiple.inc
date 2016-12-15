<?php

// Plugin definition
$plugin = array(
  'title' => t('Landing page for multiple projects'),
  'category' => t('Landing'),
  'icon' => 'multiple.png',
  'theme' => 'multiple',
  'css' => 'multiple.css',
  'regions' => array(
    'header' => t('Header'),
    'projects' => t('Projects'),
  ),
);
