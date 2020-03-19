#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

int N;

void RemplirCaseMatVide(char matrice[N][N])
{
	int i, j ;
	srand((unsigned)time(NULL));
	for(i=0 ; i<N ; i++)
	{
		for(j=0 ; j<N ; j++)
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

	/* on compte le nombre de mots de la bibliothèque */
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

