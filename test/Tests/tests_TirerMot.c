#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#define N_TEST 10
int  nombreAleatoire ( int limMax) {
	return ( rand ()% limMax);
}
/**
 * \fn int tirerMot(char * nomFichier, char * motTire)
 * \brief affecte à un pointeur sur char un mot du fichier * nomFichier
 * \param char * nomFichier, char * motTire
 * \return 1 si un problème survient, 0 sinon
 */
int TirerMot(char *nomFichier, char *motTire){
	FILE * fichier = NULL ;
	int nbrMots = 0, numMot = 0, charLu ;
	int indiceMot ;
	fichier = fopen(nomFichier, "r") ;

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
	//printf("Il y a %i mots dans la bibliothèque\n", nbrMots);

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
	//printf("Le mot numéro %i est %s", indiceMot+1, motTire);
	fclose(fichier);
	return indiceMot;
}
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
	int temp=0;
	int x=0,i,j;
	char mot[100];
	char matrice[N_TEST][N_TEST];
	FILE * fichier = NULL ;
	int nbrMots = 0, numMot = 0, charLu ;
	int indiceMot ;
	fichier = fopen("villes.txt", "r");

	//agir
	TirerMot("villes.txt",mot);


	//auditer
	for(i=0; i<N_TEST; i++)
	{
		for(j=0; j<N_TEST; j++)
		{

		if(fichier== NULL){
			printf("Le test a échoué! \n");
		}
		else
            temp=1;
		}
	}
	if(temp){
		printf("Le test n'a pas rencontré d'erreurs pour ce test!\n");
	}




	return 0;
}
