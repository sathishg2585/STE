<?php
/**
 * FYC Awards tab
 */
?>
<div class="fyc-award-tabs">
  <div class="sub_nav">
    <?php foreach ($data['#content']['fyc_awards_list'] as $awards_list): ?>
      <?php
        $patterns = array('/[^A-Za-z0-9\-]/');
        $replacements = array("");
        $classname = strtolower(preg_replace($patterns, $replacements, $awards_list->field_fyc_award_name->value()));
      ?>
      <span class="link">
        <a class="<?php print $classname; ?>" href="#awards">
          <strong><?php print $awards_list->field_fyc_award_name->value(); ?></strong>
        </a>
      </span>
    <?php endforeach; ?>
  </div>
</div>
