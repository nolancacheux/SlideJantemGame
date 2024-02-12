<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <title>Slide Jantem</title>
    <link rel="stylesheet" href="css/styleDida2.css">
    <script src="js/script.js"></script>

</head>


<audio controls="controls" autoplay="autoplay" style="display:none;">
    <source src="./dida2.2.mp3" type="audio/mpeg">

</audio>
<body class="backDida">

    <?php 
        include "nuage.php";
    ?>  
    <div class="jantem">
        <img src="image/Jantem.gif" alt="">
    </div>

    <div id="typedtext"> </div>

    <div id="continue">
    <img src="image/keys.gif" alt="">
    <a onclick="out('game.php?map=1&w=1')" class="eightbit-btn eightbit-btn--reset">Play</a>
</div> 


</body>


<script src="js/typing2.js"></script>
</html>