<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <title>Accueil Slide Jantem</title>
    <link rel="stylesheet" href="css/styleAccueil.css">
    <script src="js/script.js"></script>
</head>

<div class="anim">

    <body class="backindex">

        <?php 
            include "nuage.php";
            include "icone.php";
        ?>

        <div class="logo">
            <img src="image/oui.png" alt="">
        </div>

        
        <?php
        if(!isset($_SESSION["ID"])){
            echo "<form id='login' class='login' method='post' action='play.php'>
                    <input type='text' name='login' placeholder='Player Name' required>
                </form>";
        }
        else{
            // require("../bdd/main.php");
            $username = getUsername($_SESSION["ID"]);
            echo "<div class='logged'>Hey $username !</div>";
        }

        ?>
        <div class="button">
            <a <?php 
            if(!isset($_SESSION["ID"])){ 
                echo "onClick=\"out(document.forms['login'].submit())\"";
            }
            else{
                echo "onclick=\"out('play.php')\"";
            }?> 
            class="push_buttonP"> GO </a>

            
            <br>
            <a class="push_buttonR" onclick="out('records.php')"> RECORDS </a>
            <a class="push_buttonS" onclick="out('store.php')"> STORE </a>
        </div>


</div>
</body>
</div>

</html>