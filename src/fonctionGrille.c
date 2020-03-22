#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../lib/commun.h"

//Remplit une matrice de Taille N
void initGrille(char matrice[N_TEST][N_TEST])
{
	int i, j ;


	for(i=0 ; i<N_TEST ; i++)
	{
		for(j=0 ; j<N_TEST ; j++)
		{
			matrice[i][j] = '*' ;
		}
	}
}

void affGrille(char matrice[N_TEST][N_TEST]){
	int i, j ;

	for(i=0 ; i<N_TEST ; i++)
	{
		for(j=0 ; j<N_TEST ; j++)
		{
			printf(" %c ", matrice[i][j]) ;
		}
		printf("\n");
	}
}

//Fonction renvoyant un nombre aléatoire entre 1 et 8.
int tirageRDM8()
{
	srand(time(NULL));
	return (rand() % 8);
}


/*
int DifficulteGrille()
{
    int level;
	printf("Quel niveau de difficulté désirez-vous ? ==Level 1, 2 ou 3==") ;
	scanf("%i", &level) ;
	switch (level)
	{
		case 1: N=4;break;
		case 2: N=16;break;
		case 3: N=32;break;
		default: DifficulteGrille();break;
	}
	return N;
}
*/

void RemplirCaseMatVide(char matrice[N_TEST][N_TEST])
{
	int i, j ;
	srand((unsigned)time(NULL));
	for(i=0 ; i<N_TEST ; i++)
	{
		for(j=0 ; j<N_TEST ; j++)
		{
			if(matrice[i][j] == '*')
			{
				matrice[i][j] = 'A'+rand()%26;
			}
		}
	}
}

int nombreAleatoire(int nbrMot)
{
	return (rand() % nbrMot);
}



int TirerMot(char *motTire)
{
	FILE* fichier = NULL;
	int nbrMots = 0, numMot = 0, charLu = 0;
	int n ;
	fichier = fopen("bibliotheque.txt", "r");

	if (fichier == NULL)
	{
		printf("Problème à l'ouverture du fichier\n");
		return 0;
	}

	// on compte le nombre de mots de la bibliothèque
	do
	{
		charLu = fgetc(fichier);
		if (charLu == '\n')
		{
			nbrMots++;
		}
	} while(charLu != EOF);
	printf("il y a %i mots dans la bibliothèque\n", nbrMots);

	numMot = nombreAleatoire(nbrMots);
	n=numMot;

	rewind(fichier);

	while (numMot > 0)
	{
		charLu = fgetc(fichier);
		if (charLu == '\n')
		{
			numMot--;
		}
	}

	fgets(motTire, 100, fichier);
	printf("le mot numero %i est %s\n", n, motTire);
	//motTire[strlen(motTire) - 1] = '\0'; // inutile, fgets le fait pour nous !!

	printf("#%s#\n", motTire);

	fclose(fichier);

	return 0 ;
}

void PlacerMot(char matrix[N_TEST][N_TEST])
{
    srand(time(NULL));
    int i, j, k = 0 ;
		int compteur ;
    int random_i, random_j, random_choix = 0 ;
    char word[100] ;//="fjlskdjfldslqfj";
    int lenght=0;

   do{
        TirerMot(&word);
        lenght=strlen(word)-1;
    }while(lenght>N_TEST);


    for(i=0; i<N_TEST ; i++)
    {
        for(j=0; j<N_TEST ; j++)
        {
            matrix[i][j]= '*' ;
        }
    }

    random_i = rand() % N_TEST;
    random_j = rand() % N_TEST;

    random_choix = (rand() % 8)+1;
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
            break;

        case 1:/*Nord-Est*/
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
            break;

        case 2:/*Sud-Ouest*/
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
            break;

        case 4:/*Nord*/
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
            break;

        case 5:/*Ouest*/
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
            break;

        case 6:/*Est*/
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
            break;
        case 7:/*Sud*/
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
            break;

        default: break;

    }


    for(i=0 ; i<N_TEST ; i++)
	{
		for(j=0 ; j<N_TEST ; j++)
		{
			printf(" %c ", matrix[i][j]) ;
		}
		printf("\n");
	}
}
