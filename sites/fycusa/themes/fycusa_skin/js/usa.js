(function($) {
  $(window).load(function() {
    $('.video-feed .video-player').each(function() { // Video
      $(this).videoloader({
          template: $('#video-template').html()
      });
    });
  });
})(jQuery);
