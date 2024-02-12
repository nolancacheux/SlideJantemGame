


// --------- Play / pause musique

var track = document.getElementById('track');

var controlBtn = document.getElementById('play-pause');

function playPause() {
  if (track.paused) {
    track.play();
    controlBtn.className = "pause";
  } 
  else { 
    track.pause();
    controlBtn.className = "play";
}
}

controlBtn.addEventListener("click", playPause);
track.addEventListener("ended", function() {
  controlBtn.className = "play";
});



function out(href){
  var element = document.getElementById("left");
  element.classList.remove("left");
  element.classList.add("leftt");

  element = document.getElementById("right");
  element.classList.remove("right");
  element.classList.add("rightt");

  element = document.getElementById("loader");
  element.classList.remove("loader");
  element.classList.add("loaderr");
  
  setTimeout(function() { 
      window.location.href = href
  }, 1300)
}