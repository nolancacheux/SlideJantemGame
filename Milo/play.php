<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <title>Play</title>
    <link rel="stylesheet" href="css/stylePlay.css">
    <script src="js/script.js"></script>
</head>

<body class="backplay">

        <?php 
            include "nuage.php";
            include "icone.php";
        ?>

    <div class="parent">
        <?php
        if(!isset($_SESSION["ID"])){
            if(isset($_POST["login"])){
                if(($_POST["login"]) != ""){
                    require("../bdd/main.php");
                    $userlist = getUsers();
                    if (!(in_array($_POST["login"], $userlist))) {
                        adduser($_POST["login"]);
                        header('Location: dida.php');
                    }
                $id = getId($_POST["login"]);
                $_SESSION["ID"] = $id;
                // print_r($_SESSION["ID"]);
                }
            }
        }
        ?>
        <div class="div1"> </div>
        <div class="div2">
        </div>
        <div class="div3">
            <a class="levels" onclick="out('words.php')">STORY</a>
        </div>
        <div class="div4">
            <a class="create" onclick="out('../Nolan/php/levels.php')">WORKSHOP</a>
        </div>
        <div class="div5">
            <a class="create2" onclick="out('../Nolan/creator.php')">CREATE MAP</a>
        </div>
        <div class="div6"> </div>

    </div>

</body>
</html>