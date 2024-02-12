<?php
    function getSkin($id){   // score Général
        $request ="SELECT player,trail FROM game WHERE ID=$id";
        require("connectDB.php");
        $resultat = mysqli_query($connexion,$request); //Executer la requete
        while($row = mysqli_fetch_assoc($resultat)){
            $_SESSION["player"] = $row['player'];
            $_SESSION["trail"]  = $row['trail'];
        }
    }
?>