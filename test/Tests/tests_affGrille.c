/**
 * \file test_affGrille.c
 * \brief Jeu de test sur les fonction d'affichage de la grille.
 * \author Guillaume Briffault
 * \version 1
 * \date 14 mai 2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#define N_TEST 10

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
 * \fn int estMaj(char c)
 * \brief Vérifie qu'un caractère est une majuscule
 * \param char c
 * \return 1,-1
 */
int estMaj(char c){
    if((c >= 'A'&& c <= 'Z'))
        return 1;
    else
        return -1;
}
/**
 * \fn int estMin(char c)
 * \brief Vérifie qu'un caractère est une majuscule
 * \param char c
 * \return 1,-1
 */
int estMin(char c){
    if((c >= 'a'&& c <= 'z'))
        return 1;
    else
        return -1;
}
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


int main(){

	// arranger
	int i=0,j=0;
	int temp=0;
	int x=0;
	char matrice[N_TEST][N_TEST];
    initGrille(matrice);
	voidToChar(matrice);


	//agir
	affGrille(matrice);


	//auditer
	for(i=0; i<N_TEST; i++)
	{
		for(j=0; j<N_TEST; j++)
		{
		x=estMaj(matrice[i][j]);
		//x=estMin(matrice[i][j]);
		if(x!= 1){
			printf("Le test a échoué! \n");
			//printf("%c \n",matrice[i][j]);
		}

		else
            temp=1;
		}
	}
	if(temp){
		printf("Le test n'a pas rencontré d'erreurs pour ce test!\n");
	}


	//printf("%i",x);

	return 0;
}
