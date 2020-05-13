/**
 * \file fonctionGrille.h
 * \brief header contenant les prototype des fonctions utiles à la génération de la grille de jeu.
 * \author Asmae Bouhandi
 * \version 1
 * \date 01 avril 2020
 */

#ifndef GRILLE
#define GRILLE

#include "../lib/commun.h"

typedef struct mot_tire mot_tire ;
struct mot_tire{
	char mot[N_TEST] ;
	int x1 ;
	int y1 ;
	int x2 ;
	int y2 ;
};

void initGrille(char matrice[N_TEST][N_TEST]);
void affGrille(char matrice[N_TEST][N_TEST]);
int nombreAleatoire(int limMax);
void voidToChar(char matrice[N_TEST][N_TEST]);
int TirerMot(char * nomFichier, char * mot);
void PlacerMot(char matrix[N_TEST][N_TEST], char *themefile, mot_tire liste_mot[N_TEST+1]);


#endif
