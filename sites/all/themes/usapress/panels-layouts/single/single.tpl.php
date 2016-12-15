<?php
/**
 * @file
 * Template for a single projects panel layout.
 *
 * This template provides a one region panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['project']: Content in the project.
 */
?>
<div class="panel-display clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if (!empty($content['project'])): ?>
    <div class="usanetwork-homepage-single-project-wrapper">
      <?php print $content['project']; ?>
    </div>
  <?php endif; ?>
</div>
