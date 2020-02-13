#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "menuSolo.h"
#include "menuCLM.h"
// Programme principal
int main(void){
	int choix;	// Choix de l'utilisateur

	do{	// Affichage du menu
		printf("\n	Meli Melo :\n\n Veuillez choisir un mode de jeu: \n\n");
		printf(" 1 - Solo\n");
		printf(" 2 - Contre-la-montre\n");
		printf(" 3 - Multijoueur\n");
		printf(" 4 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i",&choix);
    printf("\n");
		system("clear");

		//Traitement du choix de l'utilisateur
		switch(choix){
			case 1: menuSoloSauvegarde(); break;
			case 2: menuCLMSauvegarde(); break;
			case 3:	WorkInProgress(); break;
			case 4: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 4\n");
		}
	}
	while(choix!=4);
	printf("Merci d'avoir jouer à une prochaine fois!\n");
	return 0;
}
