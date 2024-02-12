#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<locale.h>
#include "fonctions.h"
#define _CRT_SECURE_NO_DEPRECATE

int main() {

	//FILE* fp;
	//fp = fopen("solveur.txt", "w");


	FILE* lire;
	lire = fopen("map.txt", "r");

	char c;

	// Calcul longueur 

	c = fgetc(lire);
	int l1 = (c - 48) * 10;
	c = fgetc(lire);
	int l2 = (c - 48);
	int lon = l1 + l2;

	// Calcul largeur

	c = fgetc(lire);
	int o1 = (c - 48) * 10;
	c = fgetc(lire);
	int o2 = (c - 48);
	int lar = o1 + o2;

	int taille = 8;
	int compteur = 0;
	int perso = 0;
	int telep = 0;

	if (lon == 8) {
		int test2[8][8];
		for (int i = 0; i < lon; i++) {
			for (int j = 0; j < lar; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
				if (temp == 3) {
					perso++;
				}
				if (temp == 2) {
					telep++;
				}
			}
		}
		if (perso == 1) {
			if (telep == 0 || telep == 2) {
				solveurbrut(test2, 8, 8);
			}
		}
		else {
			printf("%d", 0);
		}
	}
	if (lon == 9) {
		int test2[9][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
				if (temp == 3) {
					perso++;
				}
				if (temp == 2) {
					telep++;
				}
			}
		}
		if (perso == 1) {
			if (telep == 0 || telep == 2){
				solv9(test2, 9, 9);
			}
		}
		else {
			printf("%d", 0);
		}
	}
	if (lon == 10) {
		int test2[10][10];
		for (int i = 0; i < lon; i++) {
			for (int j = 0; j < lar; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
				if (temp == 3) {
					perso++;
				}
				if (temp == 2) {
					telep++;
				}
			}
		}
		if (perso == 1) {
			if (telep == 0 || telep == 2) {
				solv10(test2, 10, 10);
			}
		}
		else {
			printf("%d", 0);
		}
	}
	if (lon == 11) {
		int test2[11][11];
		for (int i = 0; i < lon; i++) {
			for (int j = 0; j < lar; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
				if (temp == 3) {
					perso++;
				}
				if (temp == 2) {
					telep++;
				}
			}
		}
		if (perso == 1 ) {
			if (telep == 0 || telep == 2) {
				solv11(test2, 11, 11);
			}
		}
		else {
			printf("%d", 0);
		}
	}
	if (lon == 12) {
		int test2[12][12];
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
				if (temp == 3) {
					perso++;
				}
				if (temp == 2) {
					telep++;
				}
			}
		}
		if (perso == 1) {
			if (telep == 0 || telep == 2) {
				av12(test2, 12, 12);
			}
		}
		else {
			printf("%d", 0);
		}
	}
	if (lon == 13) {
		int test2[13][13];
		for (int i = 0; i < lon; i++) {
			for (int j = 0; j < lar; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
				if (temp == 3) {
					perso++;
				}
				if (temp == 2) {
					telep++;
				}
			}
		}
		if (perso == 1) {
			if (telep == 0 || telep == 2) {
				solv13(test2, 13, 13);
			}
		}
		else {
			printf("%d", 0);
		}
	}


	// ****  Print dans un fichier texte si nécessaire ****

	//printf("\n%d", );
	/*
	for (unsigned i = 0; i < 7; i++) {
		for (unsigned j = 0; j < 7; j++) {
			fprintf(fp, "%d |", test2[i][j]);
		}
		fprintf(fp, "\n");
	}
	*/
	//fprintf(fp, "%d", trouv);
	//fclose(fp);
}