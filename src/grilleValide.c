/**
 * \file grilleValide.c
 * \brief test des fonction d'initialisation de la grille
 * \author Quentin Bellanger
 * \version 1
 * \date 01 avril 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/fonctionGrille.h"
#include "../lib/commun.h"

/**
 * \fn int main(void))
 * \brief entrée du programme
 * \return rien
 */
int main(void){
	srand(time(NULL));
	int i;
	char mat[N_TEST][N_TEST];
	initGrille(mat);
	PlacerMot(mat);
}
