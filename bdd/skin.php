<?php
    session_start();
    $id = ($_SESSION["ID"]);
    $player = $_GET["player"];
    $trail = $_GET["trail"];
    // $id = $_GET["user"];

    if ($player < 0){
        $player = $player + 8;
    }
    if ($trail < 0){
        $trail = $trail + 8;
    }

    $request ="UPDATE game SET player = $player WHERE ID=$id";
    require("connectDB.php");
    $resultat = mysqli_query($connexion,$request); //Executer la requete

    $request ="UPDATE game SET trail = $trail WHERE ID=$id";
    require("connectDB.php");
    $resultat = mysqli_query($connexion,$request); //Executer la requete

    header("location:../Milo/accueil.php");
?>