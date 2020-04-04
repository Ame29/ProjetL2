/**
 * \file fonctionGrille.h
 * \brief header contenant les prototype des fonctions utiles à la génération de la grille de jeu.
 * \author Quentin Bellanger
 * \version 1
 * \date 01 avril 2020
 */

#ifndef GRILLE
#define GRILLE

#include "commun.h"

void initGrille(char matrice[N_TEST][N_TEST]);
void affGrille(char matrice[N_TEST][N_TEST]);
int nombreAleatoire(int limMax);
void voidToChar(char matrice[N_TEST][N_TEST]);
int TirerMot(char * nomFichier);
void PlacerMot(char matrix[N_TEST][N_TEST]);


#endif
