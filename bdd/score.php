<?php
    session_start();
    $id = ($_SESSION["ID"]);
    $score = $_GET["score"];
    $idmap = $_GET["map"];
    // $id = $_GET["user"];


    $map = "map".$idmap;

    // Récupération score déjà rentré
    $req = "SELECT $map FROM game WHERE ID=$id";
    require("connectDB.php");
    $resultat = mysqli_query($connexion,$req); //Executer la requete
    while($row = mysqli_fetch_assoc($resultat)){
        $lastscore =  $row[$map];
    }
    // echo $lastscore;


    // si le nouveau score > l'ancien, on update le score et le score général
    if ($score > $lastscore){
        $request ="UPDATE game SET $map = $score WHERE ID=$id";
        require("connectDB.php");
        $resultat = mysqli_query($connexion,$request); //Executer la requete
        


        $request ="SELECT * FROM game WHERE ID=$id";  //EXCEPT (ID,username)
        require("connectDB.php");
        $resultat = mysqli_query($connexion,$request); //Executer la requete
        $nbmap = 1;
        $somme = 0;
        while($row = mysqli_fetch_assoc($resultat)){
            for ($i=1; $i < 21; $i++) {
                $map = "map".$i;
                $somme += $row[$map];
                ++$nbmap;
            }
        }
        // echo $somme;
        $request ="UPDATE game SET score = $somme WHERE ID=$id";
        $resultat = mysqli_query($connexion,$request); //Executer la requete
    }
?>