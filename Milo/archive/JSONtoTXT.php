<?php
// Explication:
// enregistrement des valeurs depuis un fichier JSON vers TXT pour résolution solveur
// sous la forme:
// 00112222222222222..
// avec 00 et 11 les tailles en X et Y et ensuite le tableau


// ouverture du fichier JSON
$map_json = file_get_contents('map1.json');
$decoded_json = json_decode($map_json, false);
$map = $decoded_json->map;
$sizeX = $decoded_json->SizeX;
$sizeY = $decoded_json->SizeY;
$sizeX = sprintf("%02d", $sizeX);
$sizeY = sprintf("%02d", $sizeY);
// echo $map[1][1];


# Chemin vers fichier texte
$file ="../map/1/map.txt";
# Ouverture en mode écriture
$fileopen=(fopen("$file",'a'));
# suppression du contenu précédant
file_put_contents("".$file."", "");

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


header("location:index.html")
?>