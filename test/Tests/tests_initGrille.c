#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#define N_TEST 10


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


int main(){

	// arranger
	int i=0,j=0;
	int temp=0;
	char matrice[N_TEST][N_TEST];

	//agir 
	initGrille(matrice);


	//auditer
	for(i=0; i<N_TEST; i++)
	{
		for(j=0; j<N_TEST; j++)
		{
		if(matrice[i][j]!= '.')
			printf(" Le test a échoué! \n");
		else
			temp=1;
		}
	}
	if(temp){
		printf("Le test n'a pas rencontré d'erreurs pour ce test!\n");
	}



	return 0;
}



