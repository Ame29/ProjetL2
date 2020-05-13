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
	char themefile[50] = "./themes/theme_animal.txt" ;

	// char mot[20] ;
	// TirerMot(themefile, mot) ;

	char mat[N_TEST][N_TEST];

	initGrille(mat);
	//affGrille(mat);
	//printf("\n");

	PlacerMot(mat, themefile);
	affGrille(mat);
	printf("\n");

	voidToChar(mat);
	affGrille(mat);
}