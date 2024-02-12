<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Auto Creator</title>
    <link rel="stylesheet" href="css/stylecreator.css">
</head>
<body>
<?php 
        include "nuage.php";
        include "icone.php";
?>

    <div class="modecrea">


		<div id="uniquecreator"></div>


		<div id="buttonjs">
			<div class = "buttonsCrea">
				<button id="reset" class="boutoncrea" onClick="resetcrea()">Reset Map</button>
				<button id="Save" class="boutoncrea" onClick="Save()">Save</button>
                <button id="workshop" class="boutoncrea" onClick="window.location.href='php/levels.php';">Go to WORKSHOP</button>
			</div>
		</div>
        <div id="creator">
        <div class= "title"> AUTO CREATOR</div>
			<div id="dim">
				<fieldset class="range__field">
				<div class = "dimT"> Dimension </div>
			   <input class="range" id="zoneDeSaisie"type="range" min="8" max="13">
			   <svg role="presentation" width="100%" height="10" xmlns="http://www.w3.org/2000/svg">
				  <rect class="range__tick" x="0%" y="3" width="1" height="10"></rect>
				  <rect class="range__tick" x="20%" y="3" width="1" height="10"></rect>
				  <rect class="range__tick" x="40%" y="3" width="1" height="10"></rect>
				  <rect class="range__tick" x="60%" y="3" width="1" height="10"></rect>
				  <rect class="range__tick" x="80%" y="3" width="1" height="10"></rect>
				  <rect class="range__tick" x="100%" y="3" width="1" height="10"></rect>
			   </svg>
			   <svg role="presentation" width="100%" height="14" xmlns="http://www.w3.org/2000/svg">
				  <text class="range__point" x="0%" y="14" text-anchor="start">8x8</text>
				  <text class="range__point" x="20%" y="14" text-anchor="middle">9x9</text>
				  <text class="range__point" x="40%" y="14" text-anchor="middle">10x10</text>
				  <text class="range__point" x="60%" y="14" text-anchor="middle">11x11</text>
				  <text class="range__point" x="80%" y="14" text-anchor="middle">12x12</text>
				  <text class="range__point" x="100%" y="14" text-anchor="end">13x13</text>
			   </svg>
			</fieldset>
			</div>
			<button id="bouton" > ENTER </button>


			 <input type="button"  id="bouton2" value="Change dimensions" onClick="window.location.reload();">


			<p style="color: red;" id="erreur"></p>


			<div class = "buttonsCrea">
				<button id="Auto" class="boutoncrea" onClick="auto()">NEW MAP</button>
			</div

            </div>


        </div>

    </div>

        <div class="modejeu invisible">

            <div class = "buttonsJeu">
                <button id="verif" class="boutonjeu" onClick="verif()">Verify</button>
                <button id="reset" class="boutonjeu" onClick="resetJeu()">Reset</button>
                <button class="boutonjeu" onClick="GoCrea()">Creator</button>
            </div>

            <div id="uniquejeu"></div>

            <div id="inventaire">
                <h2>INVENTORY</h2>
                <div>
                <div id="nbrail1" class="case count"></div>
                <div id ='select1' class = "case rail1"></div>
                </div>
                <div>
                <div id= "nbrail2" class=" case count"></div>
                <div id= 'select2' class = "case railt1"></div>
                </div>
                <div>
                <div class="count">Current</div>
                <div id="currentJeu"></div>
                </div>
            </div>

        </div>
    <div id="test"></div>
    <div id="test2"></div>

    <script src="https://code.jquery.com/jquery-3.3.1.min.js"></script>
    <script src="js/autocreator.js"></script>
</body>
</html>
