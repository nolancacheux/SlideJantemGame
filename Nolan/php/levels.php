<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>Levels</title>
    <link rel="stylesheet" href="../css/styleLevels.css">
    <script src="../js/script.js"></script>
</head>
    <?php 
        include "nuage.php";
        include "icone.php";
    ?>


<body class="backlevels">

<div class="contleft">
    <div class = "title">Auto Creations</div>     
    <div class = "tableau">
        <div class = "levels"> 
            <?php
            function countFiles()
            {
                $nbFichiers = 0;
                $repertoire = opendir("automaps/");
            
                while ($fichier = readdir($repertoire))
                {
                    $nbFichiers += 1;
                }
            
                return (int) $nbFichiers-2;
            }
            $nbFichiers = countFiles();
            if ($nbFichiers == 0){
                echo"<div class='container2'>
                    <span>No Levels</span>     
                </div>";
            }
            else{
            for ($i = 0; $i < $nbFichiers; $i++) {
                echo"<button onclick="."out('../../Milo/game.php?mapc=".$i."&manu=0')"." class='big-button'>".($i+1)."</button>";
            }
            }
        ?>
        </div>
    </div>
</div>


<div class="contright">
    <div class = "title">Manual Creations</div>       
    <div class = "tableau">
        <div class = "levels"> 
            <?php
            function countFiles2()
            {
                $nbFichiers = 0;
                $repertoire = opendir("manualmaps/");
            
                while ($fichier = readdir($repertoire))
                {
                    $nbFichiers += 1;
                }
            
                return (int) $nbFichiers-2;
            }
            $nbFichiers = countFiles2();
            if ($nbFichiers == 0){
                echo"<div class='container2'>
                    <span>No Levels</span>     
                </div>";
            }
            else{
            for ($i = 0; $i < $nbFichiers; $i++) {
                echo"<button onclick="."out('../../Milo/game.php?mapc=".$i."&manu=1')"." class='big-button'>".($i+1)."</button>";
                }
            }
            ?>
        </div>
    </div>
</div>

</body>
</html>
