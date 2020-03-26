#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/fonctionGrille.h"
#include "../lib/commun.h"

int main(void){
	srand(time(NULL));
	int i;
	char mat[N_TEST][N_TEST];
	initGrille(mat);
	PlacerMot(mat);
	PlacerMot(mat);
}
