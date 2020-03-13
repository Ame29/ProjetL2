#include <stdio.h>
#include <stdlib.h>
#include "fonctionMenu.h"
#define FACILE 10
#define MOYEN 14
#define DIFFICILE 18

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
      case 1: WorkInProgress(); break;
			case 2: WorkInProgress(); break;
			case 3:	WorkInProgress(); break;
			case 4:	WorkInProgress(); break;
			case 5: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 5\n");
		}
	}
	while(choix!=5);
}

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
      case 1: menuSoloTheme(); break;
			case 2: menuSoloTheme(); break;
			case 3:	menuSoloTheme(); break;
			case 4: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
		}
	}
	while(choix!=4);
}
// Programme principal
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
