<?php

// Plugin definition
$plugin = array(
  'title' => t('Inner Pages'),
  'category' => t('Inner Page'),
  'icon' => 'innerpages.png',
  'theme' => 'innerpages',
  'css' => 'innerpages.css',
  'regions' => array(
    'header' => t('Header'),
    'content' => t('Content'),
    'footer' => t('Footer'),
  ),
);
