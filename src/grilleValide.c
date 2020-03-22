#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/fonctionGrille.h"
#include "../lib/commun.h"

int main(void)
{


	srand(time(NULL));

	//DifficulteGrille();

	char mat[N_TEST][N_TEST];

	int i = 0 ;

	char mot ;

	initGrille(mat);

	//PlacerMot(mat);

	//printf("\n") ;

	//RemplirCaseMatVide(mat);

	affGrille(mat);

}
