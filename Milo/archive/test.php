<?php
function countFiles()
{
    $nbFichiers = 0;
    $repertoire = opendir("../map/");

    while ($fichier = readdir($repertoire))
    {
        $nbFichiers += 1;
    }

    return (int) $nbFichiers-2;
}
echo countFiles();
?>