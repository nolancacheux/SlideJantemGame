// METTRE LE TEXTE A LA PLACE EN DESSOUS
// QUAND YA UNE VIRGULE CA ATTEND QUELQUES SECONDES (2sec) je peux changer ca aussi
var aText = new Array(
    "Welcome to Slide Jantem !",
    "My name is Jantem. Nice to meet you.",

    "I'm a painter. Recently something happened. I cannot explain exactly what is wrong but I lost inspiration.",
    "Customers ask me to create new paintings but I can’t. I’m desperate.",
    
    "Have you ever heard about splatter paint art ?",
   
    "It's fun process art that is created by splashing, paint onto the canvas or paper instead of brushing it on with a paintbrush.",
    
    "What’s your mission ?",
    
    "By playing Slide Jantem, your are willing to paint different forms and accomplish different levels.",
    "I need fresh artists like you ! Young people ready to help me to become inspired again !",
    
    "By accomplishing different levels I’m expecting you to create new forms and who knows ?",
    "Maybe you are going to create THE painting that we need !",
   
    "Good luck !",
  

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