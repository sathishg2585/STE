<?php
/**
 * @file
 * Template for a 3 regions panel layout for header on pages.
 *
 * This template provides a 3 region panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['press_kits']: Content in the press_kits part.
 *   - $content['header_image']: Content in the header_image part.
 *   - $content['main_menu']: Content in the main_menu part.
 */
?>
<div class="panel-display clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="usanetwork-press-header-kits-menu">
  <?php if (!empty($content['press_kits'])): ?>
    <?php print $content['press_kits']; ?>
  <?php endif; ?>
  </div>
  <div class="usanetwork-press-header-wrapper clearfix">
  <?php if (!empty($content['header_image'])): ?>
     <?php print $content['header_image']; ?>
  <?php endif; ?>
  </div>
  <div class="usanetwork-press-header-main-menu">
  <?php if (!empty($content['main_menu'])): ?>
    <?php print $content['main_menu']; ?>
  <?php endif; ?>
  </div>
  <div class="usanetwork-press-content-wrapper">
    <?php if (!empty($content['content'])): ?>
        <?php print $content['content']; ?>
    <?php endif; ?>
  </div>
</div>
