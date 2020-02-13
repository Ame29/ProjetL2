#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#define FACILE 10
#define MOYEN 14
#define DIFFICILE 18

void menuSoloTheme(){
	int choix;	// Choix de l'utilisateur

	do{	// Affichage du menu
		printf("\n	Choisir un Thème:\n\n");
		printf(" 1 - Animaux\n");
		printf(" 2 - Nourriture\n");
		printf(" 3 - Ville\n");
		printf(" 4 - Metier\n");
		printf(" 5 - Retour\n");
		printf("Votre choix : ");
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
		printf("\n	Choisir la difficulté :\n\n");
		printf(" 1 - Facile\n");
		printf(" 2 - Moyen\n");
		printf(" 3 - Difficile\n");
		printf(" 4 - Retour\n");
		printf("Votre choix : ");
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
		printf("\n Vous avez choisi le mode solo.\n\n");
		printf(" 1 - Règles\n");
		printf(" 2 - Nouvelle partie\n");
		printf(" 3 - Charger une partie\n");
		printf(" 4 - Retour\n");
		printf("Votre choix : ");
		scanf("%i", &choix);
    printf("\n");
	  system("clear");

		//Traitement du choix de l'utilisateur
		switch(choix){
      case 1: WorkInProgress(); break;
			case 2: menuSoloDifficulte(); break;
			case 3:	WorkInProgress(); break;
			case 4: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
		}
	}
	while(choix!=4);
}
