<?php
/**
 * Dynamic header template.
 */
?>
<div class="usanetwork-press-dynamic_header">
  <?php if (!empty($data['#content']['video_url'])): ?>
    <video width="100%" height="auto" autoplay="true" loop="true"<?php print (!empty($data['#content']['image_url']))? ' poster="'.$data['#content']['image_url'].'"': ''; ?>>
      <source src="<?php print $data['#content']['video_url']; ?>" type="video/mp4">
      <?php if (!empty($data['#content']['image_url'])): ?>
        <img src="<?php print $data['#content']['image_url']; ?>" alt="">
      <?php endif; ?>
    </video>
  <?php elseif(!empty($data['#content']['image_url'])): ?>
    <img src="<?php print $data['#content']['image_url']; ?>" alt="">
  <?php else: ?>
    <div class="header-blank"></div>
  <?php endif; ?>
</div>
