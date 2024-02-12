<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>Levels</title>
    <link rel="stylesheet" href="css/styleLevels.css">
    <script src="js/script.js"></script>
</head>
<?php 
        include "nuage.php";
        include "icone.php";
?>


<?php
$w = $_GET["w"];
echo '<body style="background: url(\'img/map/'.$w.'.gif\')no-repeat center center fixed; background-size: cover;">';
?>
    <div class = "tableau">
        <div class = "levels"> 
            <button onclick="out('../Milo/game.php?map=1&w=<?php echo $w;?>')" class="big-button">1</button>
            <button onclick="out('../Milo/game.php?map=2&w=<?php echo $w;?>')" class="big-button">2</button>
            <button onclick="out('../Milo/game.php?map=3&w=<?php echo $w;?>')" class="big-button">3</button>
            <button onclick="out('../Milo/game.php?map=4&w=<?php echo $w;?>')" class="big-button">4</button>
            <button onclick="out('../Milo/game.php?map=5&w=<?php echo $w;?>')" class="big-button">5</button>        
        </div>
    </div>


</body>
</html>
