#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#define FACILE 10
#define MOYEN 14
#define DIFFICILE 18

void menuCLMTheme(){
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

void menuCLMDifficulte(){
	int choix;	// Choix de l'utilisateur

	do{	// Affichage du menu
		printf("\n	Choisir la difficulté :\n\n");
		printf(" 1 - Facile (4:00)\n");
		printf(" 2 - Moyen (2:30)\n");
		printf(" 3 - Difficile(1:00)\n");
		printf(" 4 - Retour\n");
		printf("Votre choix : ");
		scanf("%i", &choix);
    printf("\n");
	  system("clear");

		//Traitement du choix de l'utilisateur
		switch(choix){
      case 1: menuCLMTheme(); break;
			case 2: menuCLMTheme(); break;
			case 3:	menuCLMTheme(); break;
			case 4: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
		}
	}
	while(choix!=4);
}
// Programme principal
void menuCLMSauvegarde(){
	int choix;	// Choix de l'utilisateur

	do{	// Affichage du menu
		printf("\n Vous avez choisi le mode contre-la-montre.\n\n");
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
			case 2: menuCLMDifficulte(); break;
			case 3:	WorkInProgress(); break;
			case 4: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
		}
	}
  while(choix!=4);
}
