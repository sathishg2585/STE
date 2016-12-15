	jQuery(window).load(function() {

    // load perfect scrollbar jquery plugin
    jQuery("#scrollwrapper").perfectScrollbar();
    jQuery("#tabcontent").perfectScrollbar();
    jQuery("#video-scroll").perfectScrollbar();
    
    jQuery('.fyc-award-tabs .sub_nav .link:first-child a').addClass("current");
    
    jQuery('.fyc-award-tabs .sub_nav a').click(function() {
      jQuery('.fyc-award-tab-content').css('display', 'none');
      jQuery('.fyc-award-tabs .sub_nav a.current').removeClass("current");
      var tabClassName = jQuery(this).attr("class");
      jQuery(this).addClass("current");
      jQuery('.'+tabClassName+'-tab-content').css('display', 'block');
      jQuery("#tabcontent").perfectScrollbar('update');
    });
  
	});
  
	var _Log = new function() {
		this.info = function( msg, obj ){
			if(typeof window.console != 'undefined' && typeof window.console.log != 'undefined') {
				if (typeof obj !== 'undefined'){
					console.log("LOG :: "+msg, obj);
				} else {
					console.log("LOG :: ", msg);
				}
			}
		};
	
		this.error = function( msg, obj ){
			if(typeof window.console != 'undefined' && typeof window.console.error != 'undefined') {
				if (typeof obj !== 'undefined'){
					console.error("ERR :: "+msg, obj);
				} else {
					console.log("ERR :: ", msg);			
				}
			}
		};
	
		this.assert = function (exp, message) {
		  if (!exp) {
		  	this.error( message + ' ::', exp );
		  } else {
		  	this.info( message + ' ::', exp );
		  }
		};
	};
  (function($) {
    $(window).load(function() {
      if($('.slider li').length > 1) {
        $('.slider').flexslider({
          animation: 'slide'
        });
      }
    });
  })(jQuery);
