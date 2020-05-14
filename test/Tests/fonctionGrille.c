/**
 * \file fonctionGrille.c
 * \brief Contient toutes les fonctions utiles à l'initialisation de la grille de jeu
 * \author Asmae Bouhandi
 * \version 1
 * \date 01 avril 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#include "../lib/commun.h"
#include "../lib/fonctionGrille.h"

#define NORD 0
#define OUEST 1
#define EST 2
#define SUD 3
// #define NORDOUEST 4
// #define NORDEST 5
// #define SUDOUEST 6
// #define SUDEST 7

//int N = 8 ;

/**
 * \fn void initGrille(char matrice[N_TEST][N_TEST])
 * \brief Remplit une matrice du caractère avec le caractère '*'
 * \param char matrice[N_TEST][N_TEST]
 * \return rien
 */
void initGrille(char matrice[N_TEST][N_TEST]){
	int i, j ;

	for(i=0; i<N_TEST; i++)
	{
		for(j=0; j<N_TEST; j++)
		{
			matrice[i][j] = '.' ;
		}
	}
}

/**
 * \fn void affGrille(char matrice[N_TEST][N_TEST])
 * \brief Affiche la matrice passé en paramètre.
 * \param char matrice[N_TEST][N_TEST]
 * \return rien
 */
void affGrille(char matrice[N_TEST][N_TEST]){
	int i, j ;

	for(i=0; i<N_TEST; i++)
	{
		for(j=0; j<N_TEST; j++)
		{
			printf(" %c ", matrice[i][j]) ;
		}
		printf("\n");
	}
}

/**
 * \fn int nombreAleatoire(int limMax)
 * \brief Renvoie un nombre entre 0 et limMax-1
 * \param int limMax
 * \return Valeur entière entre 0 et limMas-1
 */
int nombreAleatoire(int limMax){
	return (rand() % limMax);
}

/**
 * \fn void voidToChar(char matrice[N_TEST][N_TEST])
 * \brief Remplace chaque caractère '.' d'une matrice de caractère par une lettre minuscule aléatoire
 * \param char matrice[N_TEST][N_TEST]
 * \return rien
 */
void voidToChar(char matrice[N_TEST][N_TEST])
{
    //printf("--> RemplirCaseMatVide <--\n");

    int i, j ;
    srand((unsigned)time(NULL));
    for(i=0 ; i<N_TEST ; i++)
    {
        for(j=0 ; j<N_TEST ; j++)
        {
            if(matrice[i][j] == '.')
            {
                matrice[i][j] = 'A'+rand()%26;
            }
        }
    }
}


/**
 * \fn int tirerMot(char * nomFichier, char * motTire)
 * \brief affecte à un pointeur sur char un mot du fichier * nomFichier
 * \param char * nomFichier, char * motTire
 * \return 1 si un problème survient, 0 sinon
 */

int TirerMot(char *nomFichier, char *motTire){
	FILE * fichier = NULL ;
	int nbrMots = 0, numMot = 0, charLu ;
	int indiceMot ;
	fichier = fopen(nomFichier, "r") ;

	/*Vérifie si le fichier est ouvrable*/
	if (fichier == NULL){
		printf("Problème à l'ouverture du fichier\n");
		return 1;
	}

	/* Comptage du nombre de mot dans le fichier, Stocké dans nbrMots */
	do{
		charLu = fgetc(fichier);
		if (charLu == '\n')
		{
			nbrMots++;
		}
	} while(charLu != EOF);
	//printf("Il y a %i mots dans la bibliothèque\n", nbrMots);

	numMot = nombreAleatoire(nbrMots);
	indiceMot=numMot;

	rewind(fichier);

	while (numMot > 0){
		charLu = fgetc(fichier);
		if (charLu == '\n'){
			numMot--;
		}
	}

	fgets(motTire, 100, fichier);
	//printf("Le mot numéro %i est %s", indiceMot+1, motTire);
	fclose(fichier);
	return indiceMot;
}