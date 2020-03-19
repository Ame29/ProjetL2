#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int N;

int main()
{	
	N = 10; // Difficulté

	srand(time(NULL));
	
	//DifficulteGrille();

	char mat[N][N];

	int i = 0 ;

	char mot ;

	InitialiserGrille(mat);

	PlacerMot(mat);

	printf("\n") ;

	RemplirCaseMatVide(mat);

	AfficherGrille(mat);
	
}
