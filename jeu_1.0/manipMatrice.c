#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void InitialiserGrille(int N, char matrice[N][N])
{
	//printf("--> InitialiserGrille <--\n");
	int i, j ;
	//char caractere;
	/*printf("Avec quoi voulez-vous initialiser votre matrice ?\n") ;
	scanf("%c", &caractere);*/

	for(i=0 ; i<N ; i++)
	{
		for(j=0 ; j<N ; j++)
		{
			/*matrice[i][j] = caractere ;*/
			matrice[i][j] = '.' ;
		}
	}
}


void AfficherGrille(int N, char matrice[N][N])
{
	//printf("--> AfficherGrille <--\n");
	int i, j ;

	printf("    ");
	for(i=0 ; i<N ; i++)
	{
		printf("%i  ", i);
	}
	printf("\n");

	for(i=0 ; i<N ; i++)
	{
		printf("%2i ", i);
		for(j=0 ; j<N ; j++)
		{
			printf(" %c ", matrice[i][j]) ;
		}
		printf("\n");
	}
}


int DifficulteGrille()
{
	//printf("--> DifficulteGrille <--\n");

    int level ;
    int N ;
	printf("Quel niveau de difficulté désirez-vous ?\n[Level 1, 2 ou 3] : ") ;
	scanf("%i", &level) ;
	switch (level)
	{
		case 1: N = 8; break;
		case 2: N = 12; break;
		case 3: N = 20; break;
		default: DifficulteGrille(); break;
	}
	return N;
}