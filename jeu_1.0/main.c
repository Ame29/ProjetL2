#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include "manipMatrice.h"
#include "manipDirection.h"
#include "manipDirectionPlacement.h"
#include "manipFichier.h"
#include "manipHasard.h"
#include "manipListe.h"

int N;

int main()
{
	srand(time(NULL));
	
	int N = DifficulteGrille();
	//printf("N = %i\n", N);
	char mat[N][N];
	InitialiserGrille(N, mat);
	printf("\n") ;
	PlacerMot(N, mat);
	//RemplirCaseMatVide(N, mat);
	printf("-----MAIN-----\n");
	RemplirCaseMatVide(N, mat);
	AfficherGrille(N, mat);
	
}
