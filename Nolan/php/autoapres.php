<?php
	
	if(isset($_GET["array"]) && isset($_GET["nbFichiers"])){
		$array = $_GET["array"];
		$nbFichiers = $_GET["nbFichiers"];
		$newarray = str_replace(",","",$array);
		//echo $array;
		$map = explode("|", $newarray); 
		print_r ($map);
		# Chemin vers fichier texte
		$file ="automaps/map$nbFichiers.txt";
		# Ouverture en mode écriture
		$fileopen=(fopen("$file",'a'));
		# suppression du contenu précédant
		file_put_contents("".$file."", "");
		
		$sizeX = count($map);
		$sizeY = $sizeX;
		$sizeX = sprintf("%02d", $sizeX);
		$sizeY = sprintf("%02d", $sizeY);

		# Ecriture de "Début du fichier" dans le fichier texte
		fwrite($fileopen,"".$sizeX."");
		fwrite($fileopen,"".$sizeY."");
		for ($i=0; $i < $sizeY; $i++) { 
			for ($j=0; $j < $sizeX; $j++) { 
				fwrite($fileopen,"".$map[$i][$j]."");
			}
			// fwrite($fileopen,"\n");
		}

		# On ferme le fichier proprement
		fclose($fileopen);
	}
	
?>