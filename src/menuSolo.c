/**
 * \file menuSolo.c
 * \brief Sous menu du mode "solo"
 * \author Quentin Bellanger
 * \version 1
 * \date 01 avril 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/commun.h"
#include "../lib/fonctionMenu.h"

int difficulte ;
char themefile[50] ;

/**
 * \fn void menuSoloTheme(void)
 * \brief Sous-menu des thèmes du mode "solo"
 * \return rien
 */
void menuSoloTheme(){
	int choix;	// Choix de l'utilisateur

	do{	// Affichage du menu
		printf("\tChoisir un Thème:\n\n");
		printf("\t1 - Animaux\n");
		printf("\t2 - Nourriture\n");
		printf("\t3 - Ville\n");
		printf("\t4 - Metier\n");
		printf("\t5 - Retour\n");
		printf("\tVotre choix : ");
		scanf("%i", &choix);
    printf("\n");
	  system("clear");

		//Traitement du choix de l'utilisateur
		switch(choix){
      		case 1: strcpy(themefile, "./themes/theme_animal.txt") ; break;
			case 2: strcpy(themefile, "./themes/theme_nourriture.txt") ; break;
			case 3:	strcpy(themefile, "./themes/theme_ville.txt") ; break;
			case 4:	strcpy(themefile, "./themes/theme_metier.txt") ; break;
			case 5: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 5\n");
		}
	}
	while(choix>5 || choix<1);

	Game(themefile, difficulte) ;
}

/**
 * \fn void menuSoloDifficulte(void)
 * \brief Sous-menu de la difficulté du mode "solo"
 * \return rien
 */
void menuSoloDifficulte(){
	int choix;	// Choix de l'utilisateur

	do{	// Affichage du menu
		printf("\tChoisir la difficulté :\n\n");
		printf("\t1 - Facile\n");
		printf("\t2 - Moyen\n");
		printf("\t3 - Difficile\n");
		printf("\t4 - Retour\n");
		printf("\tVotre choix : ");
		scanf("%i", &choix);
    printf("\n");
	  system("clear");

		//Traitement du choix de l'utilisateur
		switch(choix){
      		case 1:
      			difficulte = FACILE ;
      			menuSoloTheme(); break;
			case 2:
				difficulte = MOYEN ;
				menuSoloTheme(); break;
			case 3:
				difficulte = DIFFICILE ;
				menuSoloTheme(); break;
			case 4: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
		}
	}
	while(choix>4 || choix<1);
}

/**
 * \fn void menuSoloSauvegarde(void)
 * \brief Premier sous-menu du mode "solo"
 * \return rien
 */
void menuSoloSauvegarde(){
	int choix;	// Choix de l'utilisateur

	do{	// Affichage du menu
		printf("\tVous avez choisi le mode solo.\n\n");
		printf("\t1 - Règles\n");
		printf("\t2 - Nouvelle partie\n");
		printf("\t3 - Charger une partie\n");
		printf("\t4 - Retour\n");
		printf("\tVotre choix : ");
		scanf("%i", &choix);
    printf("\n");
	  system("clear");

		//Traitement du choix de l'utilisateur
		switch(choix){
      		case 1: descriptionSolo(); break;
			case 2: menuSoloDifficulte(); break;
			case 3:	WorkInProgress(); break;
			case 4: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
		}
	}
	while(choix!=4);
}
