#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//affiche un message avertissant de l'indisponibilité d'une fonctionnalité
void WorkInProgress(void){
	int choix;
	do{
		system("clear");
		printf("\tWork in progress !\n");
		printf("\tCette fonctionnalité n'est pas encore disponible revenez plus tard.\n\n");
		printf("\t1 - Retour\n");
		scanf("%i",&choix);
	}while(choix!=1);
	system("clear");

}

void descriptionSolo(void){
	int choix;
	do{
		system("clear");
		printf("\tLe but du jeu est de trouver tous les mots d'une liste contenu dans un grille.\n");
		printf("\tLes mots sont lisibles dans n'importe quel sens et peuvent partager des lettres entre eux.\n");
		printf("\tPour selectionner un mot il faut rentrer les coordonnées de la premiere lettre et \n\tde la dernière lettre du mot.\n");
		printf("\tUne fois la grille vidée des mots de la liste, les lettres d'un dernier mot,\n\tdispersées à travers toute la grille restent et doivent être remis dans l'ordre.\n\n");
		printf("\t1 - Retour\n");
		scanf("%i",&choix);
	}while(choix!=1);
	system("clear");
}

void descriptionCLM(void){
	int choix;
	do{
		system("clear");
		printf("\tLe but du jeu est de trouver le plus de mot dans un grille de taille 14,\n");
		printf("\tdans le temps imparti (4, 2:30 ou 1 min selon la difficulté choisi).\n");
		printf("\tA la fin du temps la grille disparait laissant derriere elle le score du joueur.\n\n");
		printf("\t1 - Retour\n");
		scanf("%i",&choix);
	}while(choix!=1);
	system("clear");
}
