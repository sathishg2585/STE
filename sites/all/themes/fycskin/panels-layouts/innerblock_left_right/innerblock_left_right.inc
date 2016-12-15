<?php

// Plugin definition
$plugin = array(
  'title' => t('Inner Block Left Right'),
  'category' => t('Panel Block'),
  'icon' => 'innerblock_left_right.png',
  'theme' => 'innerblock_left_right',
  'css' => 'innerblock_left_right.css',
  'regions' => array(
    'left' => t('Left'),
    'right' => t('Right'),
  ),
);
