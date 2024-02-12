#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<locale.h>
#include "fonctions.h"
#define _CRT_SECURE_NO_DEPRECATE

int main() {


	FILE* lire;
	lire = fopen("map.txt", "r");
	
	char c;

	// Calcul longueur 

	c = fgetc(lire);
	int l1 = (c-48) * 10;
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

	if (lon == 8) {
		int test2[8][8];
		for (int i = 0; i < lon; i++) {
			for (int j = 0; j < lar; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
			}
		}
		solveurbrut(test2, 8, 8);
	}
	if (lon == 9) {
		int test2[9][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
			}
		}
		solv9(test2, 9, 9);
	}
	if (lon == 10) {
		int test2[10][10];
		for (int i = 0; i < lon; i++) {
			for (int j = 0; j < lar; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
			}
		}
		solv10(test2, 10, 10);
	}
	if (lon == 11) {
		int test2[11][11];
		for (int i = 0; i < lon; i++) {
			for (int j = 0; j < lar; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
			}
		}
		solv11(test2, 11, 11);
	}
	if (lon == 12) {
		int test2[12][12];
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
			}
		}
		av12(test2, 12, 12);
	}
	if (lon == 13) {
		int test2[13][13];
		for (int i = 0; i < lon; i++) {
			for (int j = 0; j < lar; j++) {
				c = fgetc(lire);
				int temp = c - 48;
				test2[i][j] = temp;
			}
		}
		solv13(test2, 13, 13);
	}

	// ****  Print dans un fichier texte si nécessaire ****
}