<?php
/**
 * @file
 * Template for a 2 regions panel layout for pages.
 *
 * This template provides a 2 region panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['content']: Page content.
 *   - $content['secondary_menu']: Secondary menu.
 */
?>
<div class="panel-display clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if (!empty($content['content'])): ?>
    <div class="syfy-press-content-sidebar">
      <?php print $content['content']; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($content['secondary_menu'])): ?>
    <div class="syfy-press-secondary-menu-sidebar">
      <?php print $content['secondary_menu']; ?>
    </div>
  <?php endif; ?>
</div>
