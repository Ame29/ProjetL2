#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../lib/commun.h"

/*Remplit une matrice de Taille N*/
void initGrille(char matrice[N_TEST][N_TEST]){
	int i, j ;

	for(i=0; i<N_TEST; i++)
	{
		for(j=0; j<N_TEST; j++)
		{
			matrice[i][j] = '*' ;
		}
	}
}

/*Affiche la matrice "matrice" */
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

/*Renvoie un nombre aléatoire entre 0 et "limMax-1" */
int nombreAleatoire(int limMax){

	return (rand() % limMax);
}

/* Remplace tous les caractère "*" par des lettre minuscule quelconque */
void voidToChar(char matrice[N_TEST][N_TEST]){
	int i, j ;

	for(i=0 ; i<N_TEST ; i++)
	{
		for(j=0 ; j<N_TEST ; j++)
		{
			if(matrice[i][j] == '*')
			{
				matrice[i][j] = 'a'+nombreAleatoire(26);
			}
		}
	}
}

/*
int DifficulteGrille(){
  int level;
	printf("Quel niveau de difficulté désirez-vous ? ==Level 1, 2 ou 3==") ;
	scanf("%i", &level) ;
	switch (level)
	{
		case 1: N=10;break;
		case 2: N=12;break;
		case 3: N=14;break;
		default: DifficulteGrille();break;
	}
	return N;
}
*/

/* Récupère un mot dans le fichier texte "nomFichier" */
int tirerMot(char * nomFichier, char * motTire){
	FILE * fichier = NULL;
	int nbrMots = 0, numMot = 0, charLu;
	int indiceMot ;
	fichier = fopen(nomFichier, "r");

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
	printf("Il y a %i mots dans la bibliothèque\n", nbrMots);

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
	printf("Le mot numéro %i est %s\n", indiceMot+1, motTire);
	fclose(fichier);
	return 0 ;
}

/* Place un mot dans la grille dans n'importe quel sens */
void PlacerMot(char matrix[N_TEST][N_TEST]){
    int i, j, k = 0;
		int compteur;
    int random_i, random_j, random_choix = 0;
    char word[100];
    int lenght=0;

		random_i = rand() % N_TEST;
		random_j = rand() % N_TEST;


		/* Récupère un mot de taille inférieur ou égale à celle de la grille */
		do{
        tirerMot("../themes/test.txt",word);
        lenght=strlen(word)-1;
    }while(lenght>N_TEST);
    random_choix = (rand() % 8)+1;;
    switch(random_choix){

        case 0:/*Nord-Ouest*/
            while(random_i-lenght<0||random_j-lenght<0)
            {
                random_i = rand() % N_TEST;
                random_j = rand() % N_TEST;
            }

            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i-- ;
                random_j-- ;
                k ++ ;
                compteur++;
            }
						printf("Nord-Ouest\n");
            break;

        case 1:/*Sud-Ouest*/
            while(random_i+lenght>N_TEST||random_j-lenght<0){
                random_i = rand() % N_TEST;
                random_j = rand() % N_TEST;
            }

            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i++ ;
                random_j-- ;
                k ++ ;
                compteur++;
            }
						printf("Sud-Ouest\n");
            break;

        case 2:/*Nord-Est*/
            while(random_i-lenght<0||random_j+lenght>N_TEST)
            {
                random_i = rand() % N_TEST;
                random_j = rand() % N_TEST;
            }
            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i-- ;
                random_j++ ;
                k ++ ;
                compteur++;
            }
						printf("Nord-Est\n");
            break;

        case 3:/*Sud-Est*/
            while(random_i+lenght>N_TEST || random_j+lenght>N_TEST)
            {
                random_i = rand() % N_TEST;
                random_j = rand() % N_TEST;
            }
            while(k<lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i++ ;
                random_j++ ;
                k ++ ;
                compteur++;
            }
						printf("Sud-Est\n");
            break;

        case 4:/*Ouest*/
            while(random_j-lenght<0)
            {
                random_j = rand() % N_TEST;
            }
                while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
                {
                    matrix[random_i][random_j]= word[k] ;
                    random_j-- ;
                    k ++ ;
                    compteur++;
                }
						printf("Ouest\n");
            break;

        case 5:/*Nord*/
            while(random_i-lenght<0)
            {
                random_i = rand() % N_TEST;
            }
            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i-- ;
                k ++ ;
                compteur++;
            }
						printf("Nord\n");
            break;

        case 6:/*Sud*/
            while(random_i+lenght>N_TEST)
           {
                random_i = rand() % N_TEST;
            }
            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i++ ;
                k ++ ;
                compteur++;
            }
						printf("Sud\n");
            break;
        case 7:/*Est*/
            while(random_j+lenght>N_TEST)
            {
                random_j = rand() % N_TEST;
            }
            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_j++ ;
                k ++ ;
                compteur++;
            }
						printf("Est\n");
            break;

        default: break;

    }
    affGrille(matrix);
		printf("\n");
}
