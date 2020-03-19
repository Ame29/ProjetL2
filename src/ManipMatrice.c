#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int N;

void InitialiserGrille(char matrice[N][N])
{
	int i, j ;
	//char caractere;
	/*printf("Avec quoi voulez-vous initialiser votre matrice ?\n") ;
	scanf("%c", &caractere);*/

	for(i=0 ; i<N ; i++)
	{
		for(j=0 ; j<N ; j++)
		{
			/*matrice[i][j] = caractere ;*/
			matrice[i][j] = '*' ;
		}
	}
}


void AfficherGrille(char matrice[N][N]){
	int i, j ;

	for(i=0 ; i<N ; i++)
	{
		for(j=0 ; j<N ; j++)
		{
			printf(" %c ", matrice[i][j]) ;
		}
		printf("\n");
	}
}


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
