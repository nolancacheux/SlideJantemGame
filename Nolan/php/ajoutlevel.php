

<?php
	require "connexion.php";
	
	$requete = "INSERT INTO ".$table." VALUES (null,'".$levelMap."')";
		
	$resultat = mysqli_query($connexion,$requete ); //Executer la requete 
		
	if ( $resultat == FALSE ){echo "<p>Erreur d'exécution de la requete :".mysqli_error($connexion)."</p>" ;}
		
	mysqli_close($connexion); //Fermer la connexion
		
	header("Location:creator.html");//Redirection vers la page TP4.php 
	

?>
