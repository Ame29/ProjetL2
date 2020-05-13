/**
 * \file fonctionMenu.c
 * \brief Contient toutes les fonctions utiles pour les menus
 * \author Quentin Bellanger
 * \version 1
 * \date 01 avril 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "../lib/commun.h"
#include "../lib/fonctionGrille.h"

/**
 * \fn void WorkInProgress(void)
 * \brief Affiche un message d'erreur
 * \param void
 * \return rien
 */
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

/**
 * \fn void Game(char themefile[100], int difficulte)
 * \brief lance une partie
 * \param char themefile[100], int difficulte
 * \return rien
 */
void Game(char themefile[100], int difficulte)
{
	srand(time(NULL));
	int i;
	//char themefile[50] = "./themes/theme_animal.txt" ;

	// char mot[20] ;
	// TirerMot(themefile, mot) ;

	char mat[difficulte][difficulte];

	initGrille(mat);

	PlacerMot(mat, themefile);
	affGrille(mat);
	printf("\n");

	voidToChar(mat);
	affGrille(mat);
}

/**
 * \fn void descriptionSolo(void)
 * \brief Décrit le fonctionnement du mode de jeu "solo"
 * \param void
 * \return rien
 */
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

/**
 * \fn void descriptionCLM(void)
 * \brief Décrit le fonctionnement du mode de jeu "contre la montre"
 * \param void
 * \return rien
 */
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
