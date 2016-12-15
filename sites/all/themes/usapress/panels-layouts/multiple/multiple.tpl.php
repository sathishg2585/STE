<?php
/**
 * @file
 * Template for a multiple projects panel layout.
 *
 * This template provides a two region panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['header']: Content in the header part.
 *   - $content['projects']: Content in the projects part.
 */
?>
<div class="panel-display clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if (!empty($content['header'])): ?>
    <div class="usanetwork-homepage-header">
      <?php print $content['header']; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['projects'])): ?>
    <div class="usanetwork-homepage-projects">
      <?php print $content['projects']; ?>
    </div>
  <?php endif; ?>
</div>
