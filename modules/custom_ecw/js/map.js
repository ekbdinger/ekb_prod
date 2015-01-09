Drupal.behaviors.map = function(context) {
  var initialZoom = true;
  
  mapInit();
};

function mapInit() {
  // alert('hii');
  // /* Get the markers variable set in PHP */
  var markers = Drupal.settings.markers;
  // var markers = new google.maps.Marker({
  // });
  var infowindow = new google.maps.InfoWindow();
  var myOptions = {
    //center: new google.maps.LatLng(38.268088, -98.657227),
    mapTypeId : google.maps.MapTypeId.ROADMAP,
    zoom : 4,
    scrollwheel : true,
    draggable : true,
    disableDefaultUI : false
  };
  var mapElement = document.getElementById("map");
  var map = new google.maps.Map(mapElement, myOptions);
  /* Loop through my markers and add them to the map */
  jQuery.each(markers, function(index, value) {
    var latlng = new google.maps.LatLng(value.latitude, value.longitude);
    var bounds = new google.maps.LatLngBounds();
    bounds.extend(latlng);
    var marker = new google.maps.Marker({
      position : latlng,
      map : map,
    });
    //map.setCenter(bounds.getCenter());
    //map.fitBounds(bounds);
    map.setZoom(6);
    map.panTo(marker.position);
    google.maps.event.addListener(marker, 'click', function() {
    infowindow.setContent('<p>'+value.title+'</p>');
    infowindow.open(map,marker);
});
  });
}

google.maps.event.addDomListener(window, 'load', mapInit);

