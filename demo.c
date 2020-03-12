#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 5
/*
* Fonction qui affiche la grille
*
*/
void initialiser_grille(char grille[N][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			grille[i][j]='*';
		}
	printf("\n");
	}


}
/*
* Fonction qui affiche la grille
*
*/

int valides(int i, int j,int taille){
// renvoie VRAI si i et j d�signent une case de la matrice
	return(i>0 && taille+i <= N && j>0 && j+taille <= N);
	
}

void affiche(char grille[N][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%c ",grille[i][j]);
		}
	printf("\n");
	}
}

/*
* Fonction qui affiche la grille
*
*/


void placer_mot_h(char grille[N][N]){

/*
* placer la premiere lettre du mot de facon aleatoire
* regarder si lon peut rajouter h,v en diago ou en arreiere la lettre
* regarder si il n'y deja pas une lettre
*  '-' nouveau tirage aléatoire
*
*
*/



	int taille=5;
	srand(time(NULL));
	FILE * fichier;
	fichier=fopen("mot2s.txt","r");
char car;
	/* chiffre de différence pour bien placer les mots dans la grille */
	int diff=0;
	int nbm=0;
	int x,y;
	x= rand()%10;
				y=rand()%10;
	/* Verification de l'existance du fichier texte */
	if(fichier == NULL)
			printf("Le fichier n'existe pas !");

	// Nombre aléatoires  pour les lignes de la matrice entre 0 et 9
	int nb = rand () % 10;
	printf("nb = %d\n",nb);
	// Nombre aléatoires  pour les colonnes de la matrice entre 0 et 9
	int nba = rand () % 10;
	printf("nba = %d\n",nba);

	int suivant=0;



	while(!(feof(fichier))){
		fscanf(fichier,"%c ",&car);
		printf("caracterere = %c\n",car);
		if(valides(nb,nba,taille))
			grille[nb][nba++]=car;
	/*	if(car == '-'){
			suivant=1;
		}
		
			if((suivant==1)&&(car!='-')){
				
				grille[x][y++]=car;
				suivant=0;
			}
			else{
			
			grille[nb][nba++]=car;
			printf("c----->%c\n",car);
			}
			
*/
	}
		fclose(fichier);
}




int main(void){
  char grille[N][N];
	int choix;
	do{
// Affichage du menu et saisie du choix
		printf("\nMenu :\n");
		printf(" 1 - Initialisation de la grille \n");
		printf(" 2 - Placement d'un mot horizontalement dans la grille\n");
    printf(" 3 - Fais nimporte quoi \n");
		printf(" 4 - Quitter\n");
		printf("Votre choix : ");
		scanf("%d",&choix);

// Traitement du choix de l'utilisateur
		switch(choix){
			case 1: initialiser_grille(grille),affiche(grille); break;
			case 2: placer_mot_h(grille),affiche(grille); break;
      case 3: printf("Essaye encore ! \n");break;
			case 4: break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}
	while(choix!=4);

	printf("Au revoir !\n");
	return EXIT_SUCCESS;
}
