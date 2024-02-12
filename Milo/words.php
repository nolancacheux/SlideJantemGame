<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <title>Words</title>
    <link rel="stylesheet" href="css/stylewords.css">
    <script src="js/script.js"></script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
</head>
<?php 
    include "nuage.php";
    include "icone.php";
?>
<body>
    <div class="title">Choose a world !</div>
    <div class="main">
        <div class = "word word1" onclick="out('levels.php?w=1')"> 
            <div></div>
        </div>
        <div class = "word word2" onclick="out('levels.php?w=2')"> 
            <div></div>
        </div>
        <div class = "word word3" onclick="out('levels.php?w=3')"> 
            <div></div>
        </div>
        <div class = "word word4" onclick="out('levels.php?w=4')"> 
            <div></div>
        </div>
    </div>

</body>
<script>
$(".word").on("mouseover",function(){
  $(".word").not(this).css("filter","brightness(0.5)");
});
$(".word").on("mouseout",function(){
  $(".word").css("filter","brightness(1)");
});</script>
</html>
