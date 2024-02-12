<?php
function adduser($user){
    // $username = 'mylow';
    $request ="INSERT INTO game (username) VALUES ('$user')";
    require("connectDB.php");
    $resultat = mysqli_query($connexion,$request); //Executer la requete
}
function getId($user){   // score Général
    $request ="SELECT * FROM game WHERE username='$user'";
    require("connectDB.php");
    $resultat = mysqli_query($connexion,$request); //Executer la requete
    while($row = mysqli_fetch_assoc($resultat)){
        $ID = $row['ID'];
        return $ID;
    }
}
function getUsername($id){   // score Général
    $request ="SELECT username FROM game WHERE ID=$id";
    require("connectDB.php");
    $resultat = mysqli_query($connexion,$request); //Executer la requete
    while($row = mysqli_fetch_assoc($resultat)){
        $user = $row['username'];
        return $user;
    }
}
// function getRanking($id){
//     $request = "SELECT count(*)+1 AS rank FROM game WHERE score > (SELECT score FROM game WHERE id = $id)"; 
//     require("connectDB.php");
//     $resultat =mysqli_query($connexion,$request); //Executer la requete	
//     while($row = mysqli_fetch_assoc($resultat)){
//         $rank = $row['rank'];
//         return $rank;
//     }
// }
function getRanking($id){
    $request = "SELECT ID,username,score FROM game ORDER BY score DESC"; 
    require("connectDB.php");
    $resultat =mysqli_query($connexion,$request); //Executer la requete	
    $i = 1;
    $final = array();
    while($row = mysqli_fetch_assoc($resultat)){
        $username = $row['username'];
        $score = $row['score'];
        $idd = $row['ID'];

        $result = [$i,$username,$score,$idd];
        array_push($final, $result);

        ++$i;
    }

    $len = count($final);
    for ($i = 0; $i < $len; $i++) {
        if (($final[$i][3]) == $id){
            return $final[$i][0];
        }
    }
    return "error";
}

function getUsers(){
    $request = "SELECT username FROM game ORDER BY score ASC"; 
    require("connectDB.php");
    $resultat =mysqli_query($connexion,$request); //Executer la requete	
    $final = array();
    while($row = mysqli_fetch_assoc($resultat)){
        $user = $row['username'];
        array_push($final, $user);
    }
    return ($final);
}


function somme($id){
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
function addscore($id,$idmap,$score){
    $map = "map".$idmap;
    $request ="UPDATE game SET $map = $score WHERE ID=$id";
    require("connectDB.php");
    $resultat = mysqli_query($connexion,$request); //Executer la requete
    somme($id);
}


function scoreG($id){   // score Général
    $request ="SELECT score FROM game WHERE ID=$id;";
    require("connectDB.php");
    $resultat = mysqli_query($connexion,$request); //Executer la requete
    while($row = mysqli_fetch_assoc($resultat)){
        $score = $row['score'];
        return $score;
    }
}
function scoreM($id,$idmap){   // score par Map
    $map = "map".$idmap;
    $request ="SELECT $map FROM game WHERE ID=$id;";
    require("connectDB.php");
    $resultat = mysqli_query($connexion,$request); //Executer la requete
    while($row = mysqli_fetch_assoc($resultat)){
        $score = $row[$map];
        return $score;
    }
}


function ranking(){
    $request = "SELECT username,score FROM game ORDER BY score DESC"; 
    require("connectDB.php");
    $resultat =mysqli_query($connexion,$request); //Executer la requete	
    $i = 1;
    $final = array();
    while($row = mysqli_fetch_assoc($resultat)){
        $username = $row['username'];
        $score = $row['score'];

        $result = [$i,$username,$score];
        array_push($final, $result);

        ++$i;
    }
    return ($final);
}


// adduser("oui");
// addscore(3,9,2000);
// header('location:../ajouterNote.php');

// echo score(3);
// somme(4);
// ranking();

// echo getId('mylow');

?>