// METTRE LE TEXTE A LA PLACE EN DESSOUS
// QUAND YA UNE VIRGULE CA ATTEND QUELQUES SECONDES (2sec) je peux changer ca aussi
var aText = new Array(
    "Are you ready to join the adventure ?",
    "Let's start !",
    "To move yourself and paint the map, use the arrow keys on your keyboard"
  

);




var iSpeed = 45; // time delay of print out
var iIndex = 0; // start printing array at this posision
var iArrLength = aText[0].length; // the length of the text array
var iScrollAt = 20; // start scrolling up at this many lines

var iTextPos = 0; // initialise text position
var sContents = ''; // initialise contents variable
var iRow; // initialise current row

function typewriter() {
    sContents = ' ';
    iRow = Math.max(0, iIndex - iScrollAt);
    var destination = document.getElementById("typedtext");

    while (iRow < iIndex) {
        sContents += aText[iRow++] + '<br />';
    }

    var cursor = "<span class='cursor'>|</span>"
    destination.innerHTML = sContents + aText[iIndex].substring(0, iTextPos) + cursor;
    if (iTextPos++ == iArrLength) {
        iTextPos = 0;
        iIndex++;
        if (iIndex != aText.length) {
            iArrLength = aText[iIndex].length;
            setTimeout("typewriter()", 1250);
        }
    } else {
        setTimeout("typewriter()", iSpeed);
    }
}


typewriter();