/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
  Drupal.behaviors.my_custom_behavior = {
    attach: function (context, settings) {

      // Place your code here.

    }
  };

  Drupal.behaviors.dynamic_header = {
    attach: function (context, settings) {

      if($('.usanetwork-press-dynamic_header').length > 0) {
        var isIphone = navigator.userAgent.match(/iPhone/i) != null,
            dynamicVideo = $('.usanetwork-press-dynamic_header > video'),
            dynamicVideoImage = $('.usanetwork-press-dynamic_header > video > img');
        if(isIphone) {
          if (dynamicVideoImage.length > 0) {
            dynamicVideoImage.insertAfter(dynamicVideo);
            dynamicVideo.remove();
          }
        }
      }

    }
  };

  Drupal.behaviors.context_menu = {
    attach: function (context, settings) {

      document.addEventListener("contextmenu", function (e) {
        if (e.target.nodeName === "IMG") {
          e.preventDefault();
        }
      }, false);

    }
  };

  Drupal.behaviors.adaptive_body_class = {
    attach: function(context, settings) {
      var bodySingle = $('.usanetwork-press-single-homepage'),
          bodyTablet = 'tablet',
          tabletWidth = 800;

      function checkWindowWidth () {
        var isIOS = (navigator.userAgent.match(/(iPad|iPhone|iPod)/g) ? true : false);

        if (isIOS && screen.width <= tabletWidth) {
          if (window.orientation === 0 && !bodySingle.hasClass(bodyTablet) || window.orientation === 180 && !bodySingle.hasClass(bodyTablet)) {
            bodySingle.addClass(bodyTablet);
          } else if (window.orientation === -90 && bodySingle.hasClass(bodyTablet) || window.orientation === 90 && bodySingle.hasClass(bodyTablet)) {
            bodySingle.removeClass(bodyTablet);
          }
        } else if (!isIOS) {
          if (window.innerWidth  <= tabletWidth && !bodySingle.hasClass(bodyTablet)) {
            bodySingle.addClass(bodyTablet);
          } else if (window.innerWidth > tabletWidth && bodySingle.hasClass(bodyTablet)) {
            bodySingle.removeClass(bodyTablet);
          }
        }
      }

      if(bodySingle.length !== 0) {
        checkWindowWidth();
        $(window).on('resize orientationchange', checkWindowWidth);
      }
    }
  }

  /*
  * Custom slider functions
  * */
  Drupal.behaviors.slider_custom_functions = {
    attach: function(context, settings) {
      var sliderWrapper = $('.flexslider', context);

      // Check if slider exists
      if (sliderWrapper.length !== 0) {
        var slidesContainer = sliderWrapper.find('.slides'),
            slide = slidesContainer.find('.field-name-field-usanetwork-photos-photo'),
            pageTitle = $('.pane-node-title'),
            photoContainer = $('.pane-node-field-usanetwork-photos'),
            fakeDownloadClass = 'fake-photos-download-link',
            realDonwloadClass = 'field-name-field-photos-download-link',
            downloadContainerFake = $('<div class=' + fakeDownloadClass + '><a href="" target="_blank">Download link</a></div>'),
            downloadBtnFake,
            textArr = [],
            elMinWidth;

        // Add fake download button to DOM
        downloadContainerFake.insertBefore(photoContainer);
        downloadBtnFake = $('.' + fakeDownloadClass + ' a');

        // Get max download text length to calculate min width for fake download button container
        $('.' + realDonwloadClass + ' a').each(function() {
          var textLen = $(this).text().length;

          textArr.push(textLen);
        });

        // Set min width for fake download button container
        // This will allow for photo page header to stay the same max allowed width without jumping to another line
        elMinWidth = 10 * Math.max.apply(Math,textArr);
        $('.' + fakeDownloadClass).css('min-width', elMinWidth)

        // Function to alter fake button properties according to real
        function fakeDownloadProperties() {
          var activeSlide = $('.flex-active-slide'),
              downloadBtnReal = activeSlide.find('.' + realDonwloadClass + ' a'),
              downloadText = downloadBtnReal.text(),
              downloadUrl = downloadBtnReal.attr('href');

          // Check if button properties exist
          if (downloadText === '' && typeof(downloadUrl) ===  'undefined' || downloadText.trim().length === 0) {
            downloadBtnFake.hide();
          } else {
            downloadBtnFake.show();
            downloadBtnFake.text(downloadText).attr('href', downloadUrl);
          }
        }

        // Add counter to each slide
        slide.each(function(index, item) {
          var slideCounter = $('<div class="slideCounter"><span>' + (index + 1) + '</span> of <span>' + slide.length + '</span></div>'),
              slideControls = $('<ul class="flex-nav-fake"><li class="flex-nav-prev"><a class="flex-prev" href="#">Previous</a></li><li class="flex-nav-next"><a class="flex-next" href="#">Next</a></li></ul>');

          slideControls.appendTo($(this));
          slideCounter.insertAfter($(this));
        });

        $('.flex-nav-fake a').on('click touch', function(e) {
          var getClickClass = $(this).attr('class');

          e.preventDefault();
          $('.flex-direction-nav ' + '.' + getClickClass).trigger(e);
        });

        // Change fake download button url and name
        $(document).ready(fakeDownloadProperties);
        sliderWrapper.flexslider({
          animation: 'slide',
          easing: 'swing',
          slideshow: false,
          after: function(){
            fakeDownloadProperties();
          }
        });
      }
    }
  };

  Drupal.behaviors.links_item_height = {
    attach: function(context, settings) {
      var linkWrapper = $('.view-usanetwork-links-view', context),
          tabletWidth = 1024;

      // Returns true if screen is a tablet
      function checkWindowWidth () {
        return (window.innerWidth <= tabletWidth) ? true : false;
      }

      // Change row height for links columns
      function setItemHeight (option) {
        var linkItemArr = linkWrapper.find('.usanetwork-links-row'),
            linkItemArrLen = linkItemArr.length,
            heightArr = [],
            n;

        (option) ? n = 2 : n = 3;

        // Set height to auto to get correct values
        linkItemArr.each(function() {
          $(this).height('auto');
        });

        // Iterate through array of link blocks with breakpoint each 2/3 blocks
        // depending from screen size
        for (var i = 0; i < linkItemArrLen; i++) {
          var counter = (i + 1);

          heightArr.push($(linkItemArr[i]).height());

          if ((counter % n) === 0 || i === (linkItemArrLen - 1)) {
            var maxHeight = Math.max.apply(null, heightArr),
                heightArrLen = heightArr.length;

            // Set new height for 2/3 link blocks depending from screen width
            for (var j = (i + 1 - heightArrLen); j < i + 1; j++) {
              $(linkItemArr[j]).height(maxHeight);
            }

            heightArr = [];
          }
        }
      }

      // Check if it's links page
      if (linkWrapper.length !== 0) {
        var option = checkWindowWidth();
        // Adjust height on load
        setItemHeight(option);

        // Adjust height on window resize
        $(window).on('resize', function() {
          var option = checkWindowWidth();
          setItemHeight(option);
        });
      }
    }
  }

})(jQuery, Drupal, this, this.document);
