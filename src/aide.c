#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 10

/**
 * \file aide.c
 * \brief Systeme d'aide au joueur
 * \author Guillaume Briffault
 * \version 1
 * \date 10 mai 2020
 */

int nombreAleatoire(int nbrMot)
{
	srand(time(NULL));
	return (rand() % nbrMot);
}
void initialiserGrille(char matrice[N][N])
{
	int i, j ;
	//char caractere;
	/*printf("Avec quoi voulez-vous initialiser votre matrice ?\n") ;
	scanf("%c", &caractere);*/

	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			/*matrice[i][j] = caractere ;*/
			matrice[i][j] = '*';
		}
	}
}

void afficherGrille(char matrice[N][N]){
	int i, j ;

	for(i=0; i<N; i++)
	{
		
		for(j=0; j<N; j++)
		{
			printf(" %c ", matrice[i][j]);
		}
		printf("\n");
	}
}

int TirerMot(char *motTire)
{
	FILE* fichier = NULL;
	int nbrMots = 0, numMot = 0, charLu = 0;
	int n ;
	fichier = fopen("villes.txt", "r");

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
	printf("le mot numero %i est %s\n", n+1, motTire);
	//motTire[strlen(motTire) - 1] = '\0'; // inutile, fgets le fait pour nous !!

	printf("#%s#\n", motTire);

	fclose(fichier);

	return 0 ;
}

/*  Mots a trouver !
AIX
APT
ARLES
AUBAGNE
AUPS
AVIGNON
BANDOL
CANNES
CASSIS
DIGNE
FREJUS
HYERES
LUNEL
MIRAMAS
NICE
ORANGE
SALON
SORGUES
TOULON
VENCE
*/
/* ---------------------------------------------------------------------------------------------- */

/* void aide_mot(char matrice[N][N]);
* Fonction aide au joueur prenant en parametre la grille de mots croisés 
* Cette fonction donne de l'aide au joueur lorsqu'il n'arrive pas a trouver d'autre mots
* Elle indique au joueur la premiere lettre d'un mot qu'il n'a pas encore trouvé
*/

void aide_mot(char matrice[N][N]){

	int i,j;
	
	char mot[100];
	TirerMot(mot);

	/* Parcours pour trouver un mot et afficher de l'aide pour le trouver */ 
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
		
			/* Mot diagonale a l'endroit */
			/* AIX */
			if((matrice[i][j]==mot[0] && matrice[i+1][j+1]==mot[1] && matrice[i+2][j+2]==mot[2]) || (matrice[i][j]==mot[0] && matrice[i-1][j+1]==mot[1] && matrice[i-2][j+2]==mot[2])){
				/* Indice de la premiere lettre d'un mot non trouvé */

				/* tolower() fonction qui convertie les majuscules en minuscules */
				matrice[i][j]=tolower(mot[0]);
			
			}

			/* Mot diagonale a l'envers */
			/*     SORGUE    */
			else if((matrice[i][j]==mot[0] && matrice[i+1][j-1]==mot[1] && matrice[i+2][j-2]==mot[2]) || (matrice[i][j]==mot[0] && matrice[i-1][j-1]==mot[1] && matrice[i-2][j-2]==mot[2])){
				matrice[i][j]=tolower(mot[0]);
				
			}

			/* Mot horizontale a l'endroit */
			/*  BAGNE */
			else if(matrice[i][j]==mot[0] && matrice[i][j+1]==mot[1] && matrice[i][j+2]==mot[2]){
				matrice[i][j]=tolower(mot[0]);
			
			}
			
			/* Mots horizontale a l'envers */
			/* FRESJUS ou CASSIS */
			else if(matrice[i][j]==mot[0] && matrice[i][j-1]==mot[1] && matrice[i][j-2]==mot[2]){
				matrice[i][j]=tolower(mot[0]);
			
			}

			/* Mot verticale a l'endroit */
			/* NICE */
			else if(matrice[i][j]==mot[0] && matrice[i+1][j]==mot[1] && matrice[i+2][j]==mot[2]){
				matrice[i][j]=tolower(mot[0]);
			
			}

				/* Mot verticale a l'envers */
				/* ARLES */
			else if(matrice[i][j]==mot[0] && matrice[i-1][j]==mot[1] && matrice[i-2][j]==mot[2]){
				matrice[i][j]=tolower(mot[0]);
			
			}

		
		}
	}




}

	

/* grille remplie pour faire les tests */
void grilleRemplie(char grille[N][N]){
    char occ;
    int i,j;
/* S S S A U B A G N E */
    grille[0][0]='S';
    grille[0][1]='S';
    grille[0][2]='S';
    grille[0][3]='A';
    grille[0][4]='U';
    grille[0][5]='B';
    grille[0][6]='A';
    grille[0][7]='G';
    grille[0][8]='N';
    grille[0][9]='E';
/* E P A A M V E N C E */
	 grille[1][0]='E';
    grille[1][1]='P';
    grille[1][2]='A';
    grille[1][3]='A';
    grille[1][4]='M';
    grille[1][5]='V';
    grille[1][6]='E';
    grille[1][7]='N';
    grille[1][8]='C';
    grille[1][9]='E';
/* L U L M I R A M A S */
	 grille[2][0]='L';
    grille[2][1]='U';
    grille[2][2]='L';
    grille[2][3]='M';
    grille[2][4]='I';
    grille[2][5]='R';
    grille[2][6]='A';
    grille[2][7]='M';
    grille[2][8]='A';
    grille[2][9]='S';
/* R A O G E X A C O E */
	 grille[3][0]='R';
    grille[3][1]='A';
    grille[3][2]='O';
    grille[3][3]='G';
    grille[3][4]='E';
    grille[3][5]='X';
    grille[3][6]='A';
    grille[3][7]='C';
    grille[3][8]='O';
    grille[3][9]='E';
/*A L N E G N A R O R */ 
	 grille[4][0]='A';
	grille[4][1]='L';
	grille[4][2]='N';
	grille[4][3]='E';
	grille[4][4]='G';
	grille[4][5]='N';
	grille[4][6]='A';
	grille[4][7]='R';
	grille[4][8]='O';
	grille[4][9]='E';
/* T O U L O N G L R E */
	 grille[5][0]='T';
	grille[5][1]='O';
	grille[5][2]='U';
	grille[5][3]='L';
	grille[5][4]='O';
	grille[5][5]='N';
	grille[5][6]='G';
	grille[5][7]='L';
	grille[5][8]='R';
	grille[5][9]='E';
/* N D S T N U E I E Y */
	 grille[6][0]='N';
	grille[6][1]='D';
	grille[6][2]='S';
	grille[6][3]='T';
	grille[6][4]='N';
	grille[6][5]='U';
	grille[6][6]='E';
	grille[6][7]='I';
	grille[6][8]='E';
	grille[6][9]='Y';
/* I N P E E N I L D H */
	 grille[7][0]='I';
	grille[7][1]='N';
	grille[7][2]='P';
	grille[7][3]='E';
	grille[7][4]='E';
	grille[7][5]='N';
	grille[7][6]='I';
	grille[7][7]='L';
	grille[7][8]='D';
	grille[7][9]='H';
/* C A S S U J E R F L */
	 grille[8][0]='C';
	grille[8][1]='A';
	grille[8][2]='S';
	grille[8][3]='S';
	grille[8][4]='U';
	grille[8][5]='J';
	grille[8][6]='E';
	grille[8][7]='R';
	grille[8][8]='F';
	grille[8][9]='L';
/* E B E L S I S S A C */
	grille[9][0]='E';
	grille[9][1]='B';
	grille[9][2]='E';
	grille[9][3]='L';
	grille[9][4]='S';
	grille[9][5]='I';
	grille[9][6]='S';
	grille[9][7]='S';
	grille[9][8]='A';
	grille[9][9]='C';

}

int main(){
    char grille[N][N];
/
/* Initialisation de la grille */ 
    initialiserGrille(grille);
/* Affichage de la grille */ 
    afficherGrille(grille);
/* Remplissage de la grille  */ 
    grilleRemplie(grille);
/* Affichage de la grille */ 
    afficherGrille(grille);
/*Systeme d'aide au joueur */
	aide_mot(grille);
/* Affichage de la grille avec l'aide */
afficherGrille(grille);

   
	return 0;
}
