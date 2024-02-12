#pragma once
/*

Idée pour le projet :

Rapidité solveur : Voir commentaire direction (8)

*/


/******************************************************************
/* Référence des nombres dans tableaux ou direction			     **
/*																 **
/*																 **
/* 0 = Sol														 **
/* 1 = mur														 **
/* 2 = peinture													 **
/* 3 = personnage												 **
/* 4 = téléporteur												 **
/*																 **
/* Affichage tableau											 **
/* Nord = tab[posx - 1][posY] ;    0                             **
/* est  = tab[posx][posY + 1] ;    2                             **
/* ouest  = tab[posx][posY - 1] ;  3                             **
/* sud  = tab[posX + 1][posY] ;  1                               **
/******************************************************************/

// Map de 8


// Affichage de la map 
void affichertab(int(*tab)[8], unsigned hauteur, unsigned largeur)
{
	for (unsigned i = 0; i < hauteur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			printf("%d |", tab[i][j]);
		}
		printf_s("\n");
	}
}


bool sud = false;
bool est = false;
bool ouest = false;
bool nord = false;

// Permet d'effectuer le déplacement en fonction de la direction (contrainte lié au téléporteur)
void deplacement(int(*tab)[8], int direction, int posX, int posY) {
	if (direction == 1) { // SUD
		while (tab[posX + 1][posY] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posX = posX + 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 8; i++) {
					for (unsigned j = 0; j < 8; j++) {
						if (tab[i][j] == 2 &&  trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								trouve = true;
								tab[posX][posY] = 2;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				sud = true;
			}
			else {
				tab[posX + 1][posY] = 3;
			}
		}
	}
	if (direction == 2) { // EST
		while (tab[posX][posY + 1] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (sud == true) {
					tab[posX][posY] = 2;
					sud = false;
				}
				else if (est == true) {
					tab[posX][posY] = 2;
					est = false;
				}
				else if (ouest == true) {
					tab[posX][posY] = 2;
					ouest = false;
				}
				else if (nord == true) {
					tab[posX][posY] = 2;
					nord = false;
				}
				else { tab[posX][posY] = 4; }
			}
			posY = posY + 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 8; i++) {
					for (unsigned j = 0; j < 8; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX][posY + 1] == 1) {
				tab[posX][posY] = 3;
				est = true;
			}
			else {
				tab[posX][posY + 1] = 3;
			}
		}
	}
	else if (direction == 3) { // OUEST
		while (tab[posX][posY - 1] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posY = posY - 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 8; i++) {
					for (unsigned j = 0; j < 8; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								trouve = true;
								tab[posX][posY] = 2;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX][posY - 1] == 1) {
				tab[posX][posY] = 3;
				ouest = true;
			}
			else {
				tab[posX][posY - 1] = 3;
			}
		}
	}
	else if (direction == 0) { // NORD
		bool trouve = false;
		while (tab[posX - 1][posY] != 1) {
			if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
			}
			posX = posX - 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 8; i++) {
					for (unsigned j = 0; j < 8; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX - 1][posY] == 1) {
				tab[posX][posY] = 3;
				nord = true;
			}
			else {
				tab[posX - 1][posY] = 3;
			}
		}
	}
}

// Choisir la direction dans la quel se deplacera le personnage(3)
/*int Ladirection(int(*tab)[8], int nord, int est, int sud, int ouest) {
	int direction;
	int choix = 0;
	bool pNord = false;
	bool pEst = false;
	bool pSud = false;
	bool pOuest = false;
	if (nord == 1) {
		pNord = true;
	}
	if (est == 1) {
		pEst = true;
	}
	if (sud == 1) {
		pSud = true;
	}
	if (ouest == 1) {
		pOuest = true;
	}
	if (pNord == true && pEst == true && pSud == true) {
		direction = 3;
	}
	if (pNord == true && pEst == true && pOuest == true) {
		direction = 1;
	}
	if (pNord == true && pOuest == true && pSud == true) {
		direction = 2;
	}
	if (pOuest == true && pEst == true && pSud == true) {
		direction = 0;
	}
	if (pNord == true && pEst == true) {
		choix = rand() % 2;
		// Ajouter condition de random (si une voix a déjà des 4 aller a l'autre si les deux en ont on random entre les deux (intégrer les positions
		// A la fonction pour pouvoir tester les cases. (faire une sauvegarde avant)
		if (choix == 0) {
			direction = 3;
		}
		else {
			direction = 1;
		}
	}
	else if (pNord == true && pSud == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 3;
		}
		else {
			direction = 2;
		}
	}
	else if (pNord == true && pOuest == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 2;
		}
		else {
			direction = 1;
		}
	}
	else if (pEst == true && pOuest == true) {
		choix = rand() % 2;
		direction = choix;
	}
	if (pEst == true && pSud == true) {
		choix = rand() % 2;
		if (choix == 1) {
			direction = 3;
		}
		else {
			direction = 0;
		}
	}
	else if (pSud == true && pOuest == true) {
		choix = rand() % 2;
		if (choix == 1) {
			direction = 2;
		}
		else {
			direction = choix;
		}
	}
	else {
		direction = rand() % 4;
	}

	return direction;
}*/
int Ladirection(int(*tab)[8], int nord, int est, int sud, int ouest) {
	int direction;
	int choix = 0;
	bool pNord = false;
	bool pEst = false;
	bool pSud = false;
	bool pOuest = false;
	if (nord == 1) {
		pNord = true;
	}
	if (est == 1) {
		pEst = true;
	}
	if (sud == 1) {
		pSud = true;
	}
	if (ouest == 1) {
		pOuest = true;
	}
	if (pNord == true && pEst == true) {
		if (ouest == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pNord == true && pSud == true) {
		if (ouest == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 2;
			}
		}
	}
	else if (pNord == true && pOuest == true) {
		if (est == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && est != 4) {
			direction = 2;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 2;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pEst == true && pOuest == true) {
		if (nord == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			direction = choix;
		}
	}
	else if (pEst == true && pSud == true) {
		if (ouest == 4 && nord != 4) {
			direction = 0;
		}
		else if (nord == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 3;
			}
			else {
				direction = 0;
			}
		}
	}
	else if (pSud == true && pOuest == true) {
		if (nord == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 2;
			}
			else {
				direction = choix;
			}
		}
	}
	if (pSud == true && pOuest == true && pNord == true) {
		direction = 2;
	}
	else if (pSud == true && pOuest == true && pEst == true) {
		direction = 0;
	}
	else if (pSud == true && pEst == true && pNord == true) {
		direction = 3;
	}
	else if (pNord == true && pOuest == true && pEst == true) {
		direction = 1;
	}
	else {
		direction = rand() % 4;
	}
	return direction;
}
// Relie les différentes fonctions entre elle afin d'éxecuter le programme tant qu'une solution n'est pas trouvé
// Elle s'arrete si aucune solution n'est trouvée
void solveurbrut(int(*tab)[8], unsigned longueur, unsigned largeur) {

	int trouv = 0;
	int tour = 0;
	int compteur0 = 0;
	int compteur2 = 0;

	for (unsigned i = 0; i < longueur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			if (tab[i][j] == 0) {
				compteur0 = compteur0 + 1;
			}
		}
	}
	int compt = 0;
	int direction;
	int posX = 0;
	int posY = 0;

	do {
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 3) {
					posX = i;
					posY = j;
				}
			}
		}
		direction = Ladirection(tab, tab[posX - 1][posY], tab[posX][posY + 1], tab[posX + 1][posY], tab[posX][posY - 1]);
		deplacement(tab, direction, posX, posY);
		/*affichertab(tab, 8, 8);
		printf("%d", direction);
		printf("\n");*/
		
		compteur2 = 0;
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 4) {
					compteur2 = compteur2 + 1;
				}
			}
		}
		compt++;
		tour++;
	} while ((compteur2 < compteur0) && (tour < 100000));
	if (compteur2 >= compteur0) {
		printf("%d", 1);
		printf(" %d", compt);
	}
	if (tour >= 100000) {
		printf("%d", 0);
	}
}

// Map de 9

void affichertab9(int(*tab)[9], unsigned hauteur, unsigned largeur)
{
	for (unsigned i = 0; i < hauteur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			printf("%d |", tab[i][j]);
		}
		printf_s("\n");
	}
}

void dep9(int(*tab)[9], int direction, int posX, int posY) {
	if (direction == 1) { // SUD
		while (tab[posX + 1][posY] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posX = posX + 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 9; i++) {
					for (unsigned j = 0; j < 9; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				sud = true;
			}
			else {
				tab[posX + 1][posY] = 3;
			}
		}
	}
	if (direction == 2) { // EST
		while (tab[posX][posY + 1] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posY = posY + 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 9; i++) {
					for (unsigned j = 0; j < 9; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				est = true;
			}
			else {
				tab[posX][posY + 1] = 3;
			}
		}
	}
	else if (direction == 3) { // OUEST
		while (tab[posX][posY - 1] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posY = posY - 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 9; i++) {
					for (unsigned j = 0; j < 9; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								trouve = true;
								tab[posX][posY] = 2;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				ouest = true;
			}
			else {
				tab[posX][posY - 1] = 3;
			}
		}
	}
	else if (direction == 0) { // NORD
		bool trouve = false;
		while (tab[posX - 1][posY] != 1) {
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posX = posX - 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 9; i++) {
					for (unsigned j = 0; j < 9; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				nord = true;
			}
			else {
				tab[posX - 1][posY] = 3;
			}
		}
	}
}

/*int Ladirection9(int(*tab)[9], int nord, int est, int sud, int ouest) {
	int direction;
	int choix = 0;
	bool pNord = false;
	bool pEst = false;
	bool pSud = false;
	bool pOuest = false;
	if (nord == 1) {
		pNord = true;
	}
	if (est == 1) {
		pEst = true;
	}
	if (sud == 1) {
		pSud = true;
	}
	if (ouest == 1) {
		pOuest = true;
	}
	if (pNord == true && pEst == true && pSud == true) {
		direction = 3;
	}
	if (pNord == true && pEst == true && pOuest == true) {
		direction = 1;
	}
	if (pNord == true && pOuest == true && pSud == true) {
		direction = 2;
	}
	if (pOuest == true && pEst == true && pSud == true) {
		direction = 0;
	}
	if (pNord == true && pEst == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 3;
		}
		else {
			direction = 1;
		}
	}
	else if (pNord == true && pSud == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 3;
		}
		else {
			direction = 2;
		}
	}
	else if (pNord == true && pOuest == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 2;
		}
		else {
			direction = 1;
		}
	}
	else if (pEst == true && pOuest == true) {
		choix = rand() % 2;
		direction = choix;
	}
	if (pEst == true && pSud == true) {
		choix = rand() % 2;
		if (choix == 1) {
			direction = 3;
		}
		else {
			direction = 0;
		}
	}
	else if (pSud == true && pOuest == true) {
		choix = rand() % 2;
		if (choix == 1) {
			direction = 2;
		}
		else {
			direction = choix;
		}
	}
	else {
		direction = rand() % 4;
	}

	return direction;
}*/

int Ladirection9(int(*tab)[9], int nord, int est, int sud, int ouest) {
	int direction;
	int choix = 0;
	bool pNord = false;
	bool pEst = false;
	bool pSud = false;
	bool pOuest = false;
	if (nord == 1) {
		pNord = true;
	}
	if (est == 1) {
		pEst = true;
	}
	if (sud == 1) {
		pSud = true;
	}
	if (ouest == 1) {
		pOuest = true;
	}
	if (pNord == true && pEst == true) {
		if (ouest == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pNord == true && pSud == true) {
		if (ouest == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 2;
			}
		}
	}
	else if (pNord == true && pOuest == true) {
		if (est == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && est != 4) {
			direction = 2;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 2;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pEst == true && pOuest == true) {
		if (nord == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			direction = choix;
		}
	}
	else if (pEst == true && pSud == true) {
		if (ouest == 4 && nord != 4) {
			direction = 0;
		}
		else if (nord == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 3;
			}
			else {
				direction = 0;
			}
		}
	}
	else if (pSud == true && pOuest == true) {
		if (nord == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 2;
			}
			else {
				direction = choix;
			}
		}
	}
	if (pSud == true && pOuest == true && pNord == true) {
		direction = 2;
	}
	else if (pSud == true && pOuest == true && pEst == true) {
		direction = 0;
	}
	else if (pSud == true && pEst == true && pNord == true) {
		direction = 3;
	}
	else if (pNord == true && pOuest == true && pEst == true) {
		direction = 1;
	}
	else {
		direction = rand() % 4;
	}
	return direction;
}

void solv9(int(*tab)[9], unsigned longueur, unsigned largeur) {

	int trouv = 0;
	int tour = 0;
	int compteur0 = 0;
	int compteur2 = 0;
	for (unsigned i = 0; i < longueur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			if (tab[i][j] == 0) {
				compteur0 = compteur0 + 1;
			}
		}
	}
	int compt = 0;
	int direction;
	int posX = 0;
	int posY = 0;
	do {
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 3) {
					posX = i;
					posY = j;
				}
			}
		}
		direction = Ladirection9(tab, tab[posX - 1][posY], tab[posX][posY + 1], tab[posX + 1][posY], tab[posX][posY - 1]);
		dep9(tab, direction, posX, posY);
		/*affichertab9(tab, 9, 9);
		printf("%d", direction);
		printf("\n");*/

		compteur2 = 0;
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 4) {
					compteur2 = compteur2 + 1;
				}
			}
		}
		compt++;
		tour++;
	} while ((compteur2 < compteur0) && (tour < 100000));
	if (compteur2 >= compteur0) {
		printf("%d", 1);
		printf(" %d", compt);
	}
	if (tour >= 100000) {
		printf("%d", 0);
	}
}

// Map de 10

void affichertab10(int(*tab)[10], unsigned hauteur, unsigned largeur)
{
	for (unsigned i = 0; i < hauteur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			printf("%d |", tab[i][j]);
		}
		printf_s("\n");
	}
}

void dep10(int(*tab)[10], int direction, int posX, int posY) {
	if (direction == 1) { // SUD
		while (tab[posX + 1][posY] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posX = posX + 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 10; i++) {
					for (unsigned j = 0; j < 10; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				sud = true;
			}
			else {
				tab[posX + 1][posY] = 3;
			}
		}
	}
	if (direction == 2) { // EST
		while (tab[posX][posY + 1] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posY = posY + 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 10; i++) {
					for (unsigned j = 0; j < 10; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				est = true;
			}
			else {
				tab[posX][posY + 1] = 3;
			}
		}
	}
	else if (direction == 3) { // OUEST
		while (tab[posX][posY - 1] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posY = posY - 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 10; i++) {
					for (unsigned j = 0; j < 10; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								trouve = true;
								tab[posX][posY] = 2;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				ouest = true;
			}
			else {
				tab[posX][posY - 1] = 3;
			}
		}
	}
	else if (direction == 0) { // NORD
		bool trouve = false;
		while (tab[posX - 1][posY] != 1) {
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posX = posX - 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 10; i++) {
					for (unsigned j = 0; j < 10; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				nord = true;
			}
			else {
				tab[posX - 1][posY] = 3;
			}
		}
	}
}

/*int Ladirection10(int(*tab)[10], int nord, int est, int sud, int ouest) {
	int direction;
	int choix = 0;
	bool pNord = false;
	bool pEst = false;
	bool pSud = false;
	bool pOuest = false;
	if (nord == 1) {
		pNord = true;
	}
	if (est == 1) {
		pEst = true;
	}
	if (sud == 1) {
		pSud = true;
	}
	if (ouest == 1) {
		pOuest = true;
	}
	if (pNord == true && pEst == true && pSud == true) {
		direction = 3;
	}
	if (pNord == true && pEst == true && pOuest == true) {
		direction = 1;
	}
	if (pNord == true && pOuest == true && pSud == true) {
		direction = 2;
	}
	if (pOuest == true && pEst == true && pSud == true) {
		direction = 0;
	}
	if (pNord == true && pEst == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 3;
		}
		else {
			direction = 1;
		}
	}
	else if (pNord == true && pSud == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 3;
		}
		else {
			direction = 2;
		}
	}
	else if (pNord == true && pOuest == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 2;
		}
		else {
			direction = 1;
		}
	}
	else if (pEst == true && pOuest == true) {
		choix = rand() % 2;
		direction = choix;
	}
	if (pEst == true && pSud == true) {
		choix = rand() % 2;
		if (choix == 1) {
			direction = 3;
		}
		else {
			direction = 0;
		}
	}
	else if (pSud == true && pOuest == true) {
		choix = rand() % 2;
		if (choix == 1) {
			direction = 2;
		}
		else {
			direction = choix;
		}
	}
	else {
		direction = rand() % 4;
	}

	return direction;
}*/

int Ladirection10(int(*tab)[10], int nord, int est, int sud, int ouest) {
	int direction;
	int choix = 0;
	bool pNord = false;
	bool pEst = false;
	bool pSud = false;
	bool pOuest = false;
	if (nord == 1) {
		pNord = true;
	}
	if (est == 1) {
		pEst = true;
	}
	if (sud == 1) {
		pSud = true;
	}
	if (ouest == 1) {
		pOuest = true;
	}
	if (pNord == true && pEst == true) {
		if (ouest == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pNord == true && pSud == true) {
		if (ouest == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 2;
			}
		}
	}
	else if (pNord == true && pOuest == true) {
		if (est == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && est != 4) {
			direction = 2;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 2;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pEst == true && pOuest == true) {
		if (nord == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			direction = choix;
		}
	}
	else if (pEst == true && pSud == true) {
		if (ouest == 4 && nord != 4) {
			direction = 0;
		}
		else if (nord == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 3;
			}
			else {
				direction = 0;
			}
		}
	}
	else if (pSud == true && pOuest == true) {
		if (nord == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 2;
			}
			else {
				direction = choix;
			}
		}
	}
	if (pSud == true && pOuest == true && pNord == true) {
		direction = 2;
	}
	else if (pSud == true && pOuest == true && pEst == true) {
		direction = 0;
	}
	else if (pSud == true && pEst == true && pNord == true) {
		direction = 3;
	}
	else if (pNord == true && pOuest == true && pEst == true) {
		direction = 1;
	}
	else {
		direction = rand() % 4;
	}
	return direction;
}

void solv10(int(*tab)[10], unsigned longueur, unsigned largeur) {

	int trouv = 0;
	int tour = 0;
	int compteur0 = 0;
	int compteur2 = 0;
	for (unsigned i = 0; i < longueur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			if (tab[i][j] == 0) {
				compteur0 = compteur0 + 1;
			}
		}
	}
	int compt = 0;
	int direction;
	int posX = 0;
	int posY = 0;
	do {
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 3) {
					posX = i;
					posY = j;
				}
			}
		}
		direction = Ladirection10(tab, tab[posX - 1][posY], tab[posX][posY + 1], tab[posX + 1][posY], tab[posX][posY - 1]);
		dep10(tab, direction, posX, posY);
		/*affichertab(tab, 8, 8);
		printf("%d", direction);
		printf("\n");
		*/
		compteur2 = 0;
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 4) {
					compteur2 = compteur2 + 1;
				}
			}
		}
		compt++;
		tour++;
	} while ((compteur2 < compteur0) && (tour < 100000));
	if (compteur2 >= compteur0) {
		printf("%d", 1);
		printf(" %d", compt);
	}
	if (tour >= 100000) {
		printf("%d", 0);
	}
}


// Map de 11

void affichertab11(int(*tab)[11], unsigned hauteur, unsigned largeur)
{
	for (unsigned i = 0; i < hauteur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			printf("%d |", tab[i][j]);
		}
		printf_s("\n");
	}
}

void dep11(int(*tab)[11], int direction, int posX, int posY) {
	if (direction == 1) { // SUD
		while (tab[posX + 1][posY] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posX = posX + 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 11; i++) {
					for (unsigned j = 0; j < 11; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				sud = true;
			}
			else {
				tab[posX + 1][posY] = 3;
			}
		}
	}
	if (direction == 2) { // EST
		while (tab[posX][posY + 1] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posY = posY + 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 11; i++) {
					for (unsigned j = 0; j < 11; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				est = true;
			}
			else {
				tab[posX][posY + 1] = 3;
			}
		}
	}
	else if (direction == 3) { // OUEST
		while (tab[posX][posY - 1] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posY = posY - 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 11; i++) {
					for (unsigned j = 0; j < 11; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								trouve = true;
								tab[posX][posY] = 2;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				ouest = true;
			}
			else {
				tab[posX][posY - 1] = 3;
			}
		}
	}
	else if (direction == 0) { // NORD
		bool trouve = false;
		while (tab[posX - 1][posY] != 1) {
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posX = posX - 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 11; i++) {
					for (unsigned j = 0; j < 11; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				nord = true;
			}
			else {
				tab[posX - 1][posY] = 3;
			}
		}
	}
}

int Ladirection11(int(*tab)[11], int nord, int est, int sud, int ouest) {
	int direction;
	int choix = 0;
	bool pNord = false;
	bool pEst = false;
	bool pSud = false;
	bool pOuest = false;
	if (nord == 1) {
		pNord = true;
	}
	if (est == 1) {
		pEst = true;
	}
	if (sud == 1) {
		pSud = true;
	}
	if (ouest == 1) {
		pOuest = true;
	}
	if (pNord == true && pEst == true) {
		if (ouest == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pNord == true && pSud == true) {
		if (ouest == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 2;
			}
		}
	}
	else if (pNord == true && pOuest == true) {
		if (est == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && est != 4) {
			direction = 2;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 2;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pEst == true && pOuest == true) {
		if (nord == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			direction = choix;
		}
	}
	else if (pEst == true && pSud == true) {
		if (ouest == 4 && nord != 4) {
			direction = 0;
		}
		else if (nord == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 3;
			}
			else {
				direction = 0;
			}
		}
	}
	else if (pSud == true && pOuest == true) {
		if (nord == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 2;
			}
			else {
				direction = choix;
			}
		}
	}
	else {
		direction = rand() % 4;
	}
	return direction;
}


void solv11(int(*tab)[11], unsigned longueur, unsigned largeur) {

	int trouv = 0;
	int tour = 0;
	int compteur0 = 0;
	int compteur2 = 0;
	for (unsigned i = 0; i < longueur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			if (tab[i][j] == 0) {
				compteur0 = compteur0 + 1;
			}
		}
	}
	int compt = 0;
	int direction;
	int posX = 0;
	int posY = 0;
	do {
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 3) {
					posX = i;
					posY = j;
				}
			}
		}
		direction = Ladirection11(tab, tab[posX - 1][posY], tab[posX][posY + 1], tab[posX + 1][posY], tab[posX][posY - 1]);
		dep11(tab, direction, posX, posY);
		/*affichertab11(tab, 11, 11);
		printf("%d", direction);
		printf("\n");*/
		compteur2 = 0;
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 4) {
					compteur2 = compteur2 + 1;
				}
			}
		}
		compt++;
		tour++;
	} while ((compteur2 < compteur0) && (tour < 100000));
	if (compteur2 >= compteur0) {
		printf("%d", 1);
		printf(" %d", compt);
	}
	if (tour >= 100000) {
		printf("%d", 0);
	}
}

// Map de 12

void affichertab12(int(*tab)[12], unsigned hauteur, unsigned largeur)
{
	for (unsigned i = 0; i < hauteur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			printf("%d |", tab[i][j]);
		}
		printf_s("\n");
	}
}

void oper(int(*tab2)[12], int direction, int posX, int posY) {
	if (direction == 1) { // SUD
		while (tab2[posX + 1][posY] != 1) {
			bool trouve = false;
			if (tab2[posX][posY] != 2) {
				if (tab2[posX][posY] != 2) {
					if (sud == true) {
						tab2[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab2[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab2[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab2[posX][posY] = 2;
						nord = false;
					}
					else { tab2[posX][posY] = 4; }
				}
			}
			posX = posX + 1;
			if (tab2[posX][posY] == 2) {
				for (unsigned i = 0; i < 12; i++) {
					for (unsigned j = 0; j < 12; j++) {
						if (tab2[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab2[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab2[posX][posY] != 2) {
				tab2[posX][posY] = 3;
			}
			else if (tab2[posX][posY] == 2 && tab2[posX + 1][posY] == 1) {
				tab2[posX][posY] = 3;
				sud = true;
			}
			else {
				tab2[posX + 1][posY] = 3;
			}
		}
	}
	if (direction == 2) { // EST
		while (tab2[posX][posY + 1] != 1) {
			bool trouve = false;
			if (tab2[posX][posY] != 2) {
				if (tab2[posX][posY] != 2) {
					if (sud == true) {
						tab2[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab2[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab2[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab2[posX][posY] = 2;
						nord = false;
					}
					else { tab2[posX][posY] = 4; }
				}
			}
			posY = posY + 1;
			if (tab2[posX][posY] == 2) {
				for (unsigned i = 0; i < 12; i++) {
					for (unsigned j = 0; j < 12; j++) {
						if (tab2[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab2[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab2[posX][posY] != 2) {
				tab2[posX][posY] = 3;
			}
			else if (tab2[posX][posY] == 2 && tab2[posX + 1][posY] == 1) {
				tab2[posX][posY] = 3;
				est = true;
			}
			else {
				tab2[posX][posY + 1] = 3;
			}
		}
	}
	else if (direction == 3) { // OUEST
		while (tab2[posX][posY - 1] != 1) {
			bool trouve = false;
			if (tab2[posX][posY] != 2) {
				if (tab2[posX][posY] != 2) {
					if (sud == true) {
						tab2[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab2[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab2[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab2[posX][posY] = 2;
						nord = false;
					}
					else { tab2[posX][posY] = 4; }
				}
			}
			posY = posY - 1;
			if (tab2[posX][posY] == 2) {
				for (unsigned i = 0; i < 12; i++) {
					for (unsigned j = 0; j < 12; j++) {
						if (tab2[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								trouve = true;
								tab2[posX][posY] = 2;
							}
						}
					}
				}
			}
			if (tab2[posX][posY] != 2) {
				tab2[posX][posY] = 3;
			}
			else if (tab2[posX][posY] == 2 && tab2[posX + 1][posY] == 1) {
				tab2[posX][posY] = 3;
				ouest = true;
			}
			else {
				tab2[posX][posY - 1] = 3;
			}
		}
	}
	else if (direction == 0) { // NORD
		bool trouve = false;
		while (tab2[posX - 1][posY] != 1) {
			if (tab2[posX][posY] != 2) {
				if (tab2[posX][posY] != 2) {
					if (sud == true) {
						tab2[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab2[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab2[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab2[posX][posY] = 2;
						nord = false;
					}
					else { tab2[posX][posY] = 4; }
				}
			}
			posX = posX - 1;
			if (tab2[posX][posY] == 2) {
				for (unsigned i = 0; i < 12; i++) {
					for (unsigned j = 0; j < 12; j++) {
						if (tab2[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab2[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab2[posX][posY] != 2) {
				tab2[posX][posY] = 3;
			}
			else if (tab2[posX][posY] == 2 && tab2[posX + 1][posY] == 1) {
				tab2[posX][posY] = 3;
				nord = true;
			}
			else {
				tab2[posX - 1][posY] = 3;
			}
		}
	}
}

/* int dir12temp(int(*tab)[12], int nord, int est, int sud, int ouest) {
	int direction;
	int choix = 0;
	bool pNord = false;
	bool pEst = false;
	bool pSud = false;
	bool pOuest = false;
	if (nord == 1) {
		pNord = true;
	}
	if (est == 1) {
		pEst = true;
	}
	if (sud == 1) {
		pSud = true;
	}
	if (ouest = 1) {
		pOuest = true;
	}
	if (pNord == true && pEst == true && pSud == true) {
		direction = 3;
	}
	if (pNord == true && pEst == true && pOuest == true) {
		direction = 1;
	}
	if (pNord == true && pOuest == true && pSud == true) {
		direction = 2;
	}
	if (pOuest == true && pEst == true && pSud == true) {
		direction = 0;
	}
	if (pNord == true && pEst == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 3;
		}
		else {
			direction = 1;
		}
	}
	else if (pNord == true && pSud == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 3;
		}
		else {
			direction = 2;
		}
	}
	else if (pNord == true && pOuest == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 2;
		}
		else {
			direction = 1;
		}
	}
	else if (pEst == true && pOuest == true) {
		choix = rand() % 2;
		direction = choix;
	}
	if (pEst == true && pSud == true) {
		choix = rand() % 2;
		if (choix == 1) {
			direction = 3;
		}
		else {
			direction = 0;
		}
	}
	else if (pSud == true && pOuest == true) {
		choix = rand() % 2;
		if (choix == 1) {
			direction = 2;
		}
		else {
			direction = choix;
		}
	}
	else {
		direction = rand() % 4;
	}

	return direction;
}*/

int dir12(int(*tab)[12], int nord, int est, int sud, int ouest) {
	int direction;
	int choix = 0;
	bool pNord = false;
	bool pEst = false;
	bool pSud = false;
	bool pOuest = false;
	if (nord == 1) {
		pNord = true;
	}
	if (est == 1) {
		pEst = true;
	}
	if (sud == 1) {
		pSud = true;
	}
	if (ouest == 1) {
		pOuest = true;
	}
	if (pNord == true && pEst == true) {
		if (ouest == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pNord == true && pSud == true) {
		if (ouest == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 2;
			}
		}
	}
	else if (pNord == true && pOuest == true) {
		if (est == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && est != 4) {
			direction = 2;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 2;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pEst == true && pOuest == true) {
		if (nord == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			direction = choix;
		}
	}
	else if (pEst == true && pSud == true) {
		if (ouest == 4 && nord != 4) {
			direction = 0;
		}
		else if (nord == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 3;
			}
			else {
				direction = 0;
			}
		}
	}
	else if (pSud == true && pOuest == true) {
		if (nord == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 2;
			}
			else {
				direction = choix;
			}
		}
	}
	if (pSud == true && pOuest == true && pNord == true) {
		direction = 2;
	}
	else if (pSud == true && pOuest == true && pEst == true) {
		direction = 0;
	}
	else if (pSud == true && pEst == true && pNord == true) {
		direction = 3;
	}
	else if (pNord == true && pOuest == true && pEst == true) {
		direction = 1;
	}
	else {
		direction = rand() % 4;
	}
	return direction;
}

void av12(int(*tab)[12], unsigned longueur, unsigned largeur) {

	int trouv = 0;
	int tour = 0;
	int compteur0 = 0;
	int compteur2 = 0;
	for (unsigned i = 0; i < longueur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			if (tab[i][j] == 0) {
				compteur0 = compteur0 + 1;
			}
		}
	}
	int compt = 0;
	int direction;
	int posX = 0;
	int posY = 0;
	do {
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 3) {
					posX = i;
					posY = j;
				}
			}
		}
		direction = dir12(tab, tab[posX - 1][posY], tab[posX][posY + 1], tab[posX + 1][posY], tab[posX][posY - 1]);
		oper(tab, direction, posX, posY);
		/*affichertab12(tab, 12, 12);
		printf("%d", direction);
		printf("\n");
		*/
		compteur2 = 0;
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 4) {
					compteur2 = compteur2 + 1;
				}
			}
		}
		compt++;
		tour++;
	} while ((compteur2 < compteur0) && (tour < 10000000));
	if (compteur2 >= compteur0) {
		printf("%d", 1);
		printf(" %d", compt);
	}
	if (tour >= 10000000) {
		printf("%d", 0);
	}
}

// Map de 13

void affichertab13(int(*tab)[13], unsigned hauteur, unsigned largeur)
{
	for (unsigned i = 0; i < hauteur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			printf("%d |", tab[i][j]);
		}
		printf_s("\n");
	}
}

void dep13(int(*tab)[13], int direction, int posX, int posY) {
	if (direction == 1) { // SUD
		while (tab[posX + 1][posY] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posX = posX + 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 13; i++) {
					for (unsigned j = 0; j < 13; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				sud = true;
			}
			else {
				tab[posX + 1][posY] = 3;
			}
		}
	}
	if (direction == 2) { // EST
		while (tab[posX][posY + 1] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posY = posY + 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 13; i++) {
					for (unsigned j = 0; j < 13; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				est = true;
			}
			else {
				tab[posX][posY + 1] = 3;
			}
		}
	}
	else if (direction == 3) { // OUEST
		while (tab[posX][posY - 1] != 1) {
			bool trouve = false;
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posY = posY - 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 13; i++) {
					for (unsigned j = 0; j < 13; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								trouve = true;
								tab[posX][posY] = 2;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				ouest = true;
			}
			else {
				tab[posX][posY - 1] = 3;
			}
		}
	}
	else if (direction == 0) { // NORD
		bool trouve = false;
		while (tab[posX - 1][posY] != 1) {
			if (tab[posX][posY] != 2) {
				if (tab[posX][posY] != 2) {
					if (sud == true) {
						tab[posX][posY] = 2;
						sud = false;
					}
					else if (est == true) {
						tab[posX][posY] = 2;
						est = false;
					}
					else if (ouest == true) {
						tab[posX][posY] = 2;
						ouest = false;
					}
					else if (nord == true) {
						tab[posX][posY] = 2;
						nord = false;
					}
					else { tab[posX][posY] = 4; }
				}
			}
			posX = posX - 1;
			if (tab[posX][posY] == 2) {
				for (unsigned i = 0; i < 13; i++) {
					for (unsigned j = 0; j < 13; j++) {
						if (tab[i][j] == 2 && trouve == false) {
							if (i != posX || j != posY) {
								posX = i;
								posY = j;
								tab[posX][posY] = 2;
								trouve = true;
							}
						}
					}
				}
			}
			if (tab[posX][posY] != 2) {
				tab[posX][posY] = 3;
			}
			else if (tab[posX][posY] == 2 && tab[posX + 1][posY] == 1) {
				tab[posX][posY] = 3;
				nord = true;
			}
			else {
				tab[posX - 1][posY] = 3;
			}
		}
	}
}
/*
int Ladirection13(int(*tab)[13], int nord, int est, int sud, int ouest) {
	int direction;
	int choix = 0;
	bool pNord = false;
	bool pEst = false;
	bool pSud = false;
	bool pOuest = false;
	if (nord == 1) {
		pNord = true;
	}
	if (est == 1) {
		pEst = true;
	}
	if (sud == 1) {
		pSud = true;
	}
	if (ouest == 1) {
		pOuest = true;
	}
	if (pNord == true && pEst == true) {
		if (ouest == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pNord == true && pSud == true) {
		if (ouest == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 3;
			}
			else {
				direction = 2;
			}
		}
	}
	else if (pNord == true && pOuest == true) {
		if (est == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && est != 4) {
			direction = 2;
		}
		else {
			choix = rand() % 2;
			if (choix == 0) {
				direction = 2;
			}
			else {
				direction = 1;
			}
		}
	}
	else if (pEst == true && pOuest == true) {
		if (nord == 4 && sud != 4) {
			direction = 1;
		}
		else if (sud == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			direction = choix;
		}
	}
	else if (pEst == true && pSud == true) {
		if (ouest == 4 && nord != 4) {
			direction = 0;
		}
		else if (nord == 4 && ouest != 4) {
			direction = 3;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 3;
			}
			else {
				direction = 0;
			}
		}
	}
	else if (pSud == true && pOuest == true) {
		if (nord == 4 && est != 4) {
			direction = 2;
		}
		else if (est == 4 && nord != 4) {
			direction = 0;
		}
		else {
			choix = rand() % 2;
			if (choix == 1) {
				direction = 2;
			}
			else {
				direction = choix;
			}
		}
	}
	if (pSud == true && pOuest == true && pNord == true) {
		direction = 2;
	}
	else if (pSud == true && pOuest == true && pEst == true) {
		direction = 0;
	}
	else if (pSud == true && pEst == true && pNord == true) {
		direction = 3;
	}
	else if (pNord == true && pOuest == true && pEst == true) {
		direction = 1;
	}
	else {
		direction = rand() % 4;
	}
	return direction;
}
*/
int Ladirection13(int(*tab)[13], int nord, int est, int sud, int ouest) {
	int direction;
	int choix = 0;
	bool pNord = false;
	bool pEst = false;
	bool pSud = false;
	bool pOuest = false;
	if (nord == 1) {
		pNord = true;
	}
	if (est == 1) {
		pEst = true;
	}
	if (sud == 1) {
		pSud = true;
	}
	if (ouest == 1) {
		pOuest = true;
	}
	if (pNord == true && pEst == true && pSud == true) {
		direction = 3;
	}
	if (pNord == true && pEst == true && pOuest == true) {
		direction = 1;
	}
	if (pNord == true && pOuest == true && pSud == true) {
		direction = 2;
	}
	if (pOuest == true && pEst == true && pSud == true) {
		direction = 0;
	}
	if (pNord == true && pEst == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 3;
		}
		else {
			direction = 1;
		}
	}
	else if (pNord == true && pSud == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 3;
		}
		else {
			direction = 2;
		}
	}
	else if (pNord == true && pOuest == true) {
		choix = rand() % 2;
		if (choix == 0) {
			direction = 2;
		}
		else {
			direction = 1;
		}
	}
	else if (pEst == true && pOuest == true) {
		choix = rand() % 2;
		direction = choix;
	}
	if (pEst == true && pSud == true) {
		choix = rand() % 2;
		if (choix == 1) {
			direction = 3;
		}
		else {
			direction = 0;
		}
	}
	else if (pSud == true && pOuest == true) {
		choix = rand() % 2;
		if (choix == 1) {
			direction = 2;
		}
		else {
			direction = choix;
		}
	}
	else {
		direction = rand() % 4;
	}

	return direction;
}

void solv13(int(*tab)[13], unsigned longueur, unsigned largeur) {

	int trouv = 0;
	int tour = 0;
	int compteur0 = 0;
	int compteur2 = 0;
	for (unsigned i = 0; i < longueur; i++) {
		for (unsigned j = 0; j < largeur; j++) {
			if (tab[i][j] == 0) {
				compteur0 = compteur0 + 1;
			}
		}
	}
	int compt = 0;
	int direction;
	int posX = 0;
	int posY = 0;
	do {
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 3) {
					posX = i;
					posY = j;
				}
			}
		}
		direction = Ladirection13(tab, tab[posX - 1][posY], tab[posX][posY + 1], tab[posX + 1][posY], tab[posX][posY - 1]);
		dep13(tab, direction, posX, posY);
		/*affichertab13(tab, 13, 13);
		printf("%d", direction);
		printf("\n");*/
		compteur2 = 0;
		for (unsigned i = 0; i < longueur; i++) {
			for (unsigned j = 0; j < largeur; j++) {
				if (tab[i][j] == 4) {
					compteur2 = compteur2 + 1;
				}
			}
		}
		compt++;
		tour++;
	} while ((compteur2 < compteur0) && (tour < 100000));
	if (compteur2 >= compteur0) {
		printf("%d", 1);
		printf(" %d", compt);
	}
	if (tour >= 100000) {
		printf("%d", 0);
	}
}