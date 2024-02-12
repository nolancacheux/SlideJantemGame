<?php
    $hostname="remotemysql.com:3306"; //nom du serveur (localhost)
    $username="d6xINafhrw";//nom d'utilisateur pour accéder au serveur (root)
    $password="eIrGNoQDXP"; //mot de passe pour accéder au serveur (root)
    $dbname="d6xINafhrw"; //nom de la base de données
    
    $connexion = mysqli_connect($hostname, $username, $password, $dbname);

    if (!$connexion) {
        echo "Erreur de connexion".mysqli_connect_errno();
        return(-1);

    }
    return($connexion);
?>