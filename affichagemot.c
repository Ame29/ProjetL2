

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 5

void affichemot(){

	
	FILE * fichier;
	fichier=fopen("mot2s.txt","r");
	char car;
	
	if(fichier == NULL)
			printf("Le fichier n'existe pas !");



	while(!(feof(fichier))){
		fscanf(fichier,"%c",&car);
		if(car == '\n')
			printf("%c\n",car);
		else
			printf("%c",car);
	}
		fclose(fichier);
}




int main(void){
  char grille[N][N];
	int choix;
	do{
// Affichage du menu et saisie du choix
		printf("\nMenu :\n");
		printf(" 1 - Affichage des mots du dictionnaire \n");
		printf(" 2 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

// Traitement du choix de l'utilisateur
		switch(choix){
			case 1: affichemot(); break;
			case 2:break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 1\n");
		}
	}
	while(choix!=2);

	printf("Au revoir !\n");
	return EXIT_SUCCESS;
}
