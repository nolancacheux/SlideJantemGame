<?php

if( isset($_GET["dim"]) && isset($_GET["nbFichiers"]) ){
		
	$dim = $_GET['dim'];
	$nbFichiers = $_GET['nbFichiers'];
	exec ( "CreatorAuto.exe $dim $nbFichiers" ,$output);
}

?>

