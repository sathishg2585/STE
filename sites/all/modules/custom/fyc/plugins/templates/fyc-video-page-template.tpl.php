<?php
/**
 * FYC Video Page
 */
?>
<div class="fyc-video-page">
  <?php if (!empty($data['#content']['video_category'])): ?>
    <section class="player video-feed">
      <section class="grid">				
        <section  class="video-player" data-enabled="true" data-category="<?php print $data['#content']['video_category']; ?>">
          <div class="poster">
            <button class="play">Play</button>
          </div>
        </section>

        <script id="video-template" type="text/template">
          <aside class="playlist">
            <div id="video-scroll" class="scroll-vertical scrollbars container">
              <ul class="content scrollbars">
                {{#videos}}
                  <li>
                    <a href="{{url}}" data-description="{{description}}" data-title="{{title}}" data-fullepisode="{{fullEpisode}}">
                      <img src="{{thumb}}"/>
                      <span>{{title}}</span>
                    </a>
                  </li>
                {{/videos}}
              </ul>
            </div>
          </aside>
        </script>
        <section class="grid">
          <section class="video-description">
            <span>
              <h1></h1>
              <p></p>
            </span>
          </section>
          <section class="quotes">
            <span class="fyc">
              For Your Consideration
            </span>
          </section>
        </section>			
      </section><!-- /.grid -->
    </section>
  <?php endif; ?>

</div>
