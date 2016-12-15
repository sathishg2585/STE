	jQuery(window).load(function() {
    // reset vimeo players
    jQuery('.vimeo-feed .video-player').each(function() {
      jQuery(this).find('iframe').attr('src', jQuery(this).data('url'));
      jQuery(this).find('.playlist ul li:first a').click();
    });

    jQuery('.vimeo-feed').each(function() {
      var self = jQuery(this);
      jQuery(this).find('.playlist ul li a').each(function() {
        jQuery(this).on('click', function() {
          jQuery(this).parents('ul').children('li').removeClass('selected');
          jQuery(this).parent('li').addClass('selected');
          var info = self.find('.video-description span');
          var title = jQuery(this).data('title');

          if (jQuery(this).data('fullepisode') == 'full') {
            if (jQuery(this).data('season') && jQuery(this).data('episode')) {
              title = 'Episode #' + jQuery(this).data('season') + (parseInt(jQuery(this).data('episode')) < 10 ? '0' : '') + jQuery(this).data('episode') + ' ' + title;
            }
            title += '<small>(Full Episode)</small>';
          }

          info.children('h1').html(title);
          info.children('p').text(jQuery(this).data('description'));
        });
      });
    });

  })(jQuery);
