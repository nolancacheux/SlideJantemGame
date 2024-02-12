<?php
function countFiles()
{
    $nbFichiers = 0;
    $repertoire = opendir("automaps/");

    while ($fichier = readdir($repertoire))
    {
        $nbFichiers += 1;
    }

    return (int) $nbFichiers-1;
}
echo countFiles();
?>
