<?php
	
	
	if(isset($_GET["array"]) && isset($_GET["nbFichiers"])){
		$array = $_GET["array"];
		$nbFichiers = $_GET["nbFichiers"];
		$newarray = str_replace(",","",$array);
		//echo $array;
		$map = explode("|", $newarray); 
		print_r ($map);
		# Chemin vers fichier texte
		$file ="manualmaps/map$nbFichiers.txt";
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

		$array2 = $array;
		$newarray2 = str_replace(",","",$array2);
		//echo $array;
		$map2 = explode("|", $newarray2); 
		print_r ($map2);
		# Chemin vers fichier texte
		$file2 ="map.txt";
		# Ouverture en mode écriture
		$fileopen2=(fopen("$file2",'a'));
		# suppression du contenu précédant
		file_put_contents("".$file2."", "");
		
		$sizeX2 = count($map2);
		$sizeY2 = $sizeX2;
		$sizeX2 = sprintf("%02d", $sizeX2);
		$sizeY2 = sprintf("%02d", $sizeY2);

		# Ecriture de "Début du fichier" dans le fichier texte
		fwrite($fileopen2,"".$sizeX2."");
		fwrite($fileopen2,"".$sizeY2."");
		for ($i2=0; $i2 < $sizeY2; $i2++) { 
			for ($j2=0; $j2 < $sizeX2; $j2++) { 
				fwrite($fileopen2,"".$map2[$i2][$j2]."");
			}
			// fwrite($fileopen,"\n");
		}

		# On ferme le fichier proprement
		fclose($fileopen2);
	}
	
?>