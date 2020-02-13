#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 5

/*
* Fonction qui initialise la grille de mots avec un caracterere
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
void affiche_grille(char grille[N][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%c ",grille[i][j]);
		}
	printf("\n");
	}
}



void placer_mot(char grille[N][N]){
	int i,j;
	char mot;
	// On commence par initialiser le générateur de nombre pseudo-aléatoires.
	srand(time(NULL));

	// Nombre aléatoires  pour les lignes de la matrice entre 0 et 9
	int nb = rand () % 10;
	printf("nombre = %d\n",nb);
	// Nombre aléatoires  pour les colonnes de la matrice entre 0 et 9
	int nba = rand () % 10;
	printf("nombre = %d\n",nba);


	FILE * fichier;
/*	char mots[N];= {'a','a','a','a','a','a','a','a','a'};*/
	char car;
//	char mot1[M]={'c','h','i','e','n'};
	fichier=fopen("mot2s.txt","r");
	/*

	if(fichier==NULL)
		printf("Fichier Inexistant !\n");
	else{
		fscanf(fichier,"%i",&ent);
	*/

	/*
	* placement du mot chien dans la grille
	*/
	/*
	for(i=0; i< M;i++){
		int j=0;
		printf("%c",mot1[i]);

	grille[i][i]=mot1[i]; /* affiche en diagonale */
	//	grille[i][j]=mot1[i];
	//		j++;
	//	}

	/* Nombre aléatoire possibles :0 1 2 ou 3 */
	/* Pour choisir si on place le mots de facon :
		-1 -> verticalement
		-2 -> horizontalement
		-3 -> en diagonale
		-4 -> en arriere
		voir a ajouté en arriere verticalement et en diagonale
		*/
	int alea  = 0;
	//= rand () % 4;
	printf("Nombre choix placement = %d",alea);
	int taille=0;
			while(!(feof(fichier))){
		//	printf("%c ",car);
			if(car != '\n')
				taille++;


			printf("taille = %d",taille);
			fscanf(fichier,"%c ",&car);
			//car =fgetc(fichier);

			/*
			int  cpt=0;
			if(car != '\n')
					cpt++;
			printf("%d",cpt);
			*/
			//mots[i++]=car;

				printf("\nC = %c\n",car);
		 /* Fesable avec un switch */

		 if(alea == 0){
			 /* Place les mots horizontalement */

					grille[nb][nba++]=car;
		 }
		 if(alea == 1){
			 /* Place les mots verticalement */

	//		if(nb <= N && nba <= N && nb+taille<N && nba+taille<N )
	 		grille[nb++][nba]=car;
		 }
		 if(alea == 2){
			 /* Place les mots en diagonale */
	//		 if(nb <= N && nba <= N && nb+taille<N && nba+taille<N )
 		 	grille[nb++][nba++]=car;
	 		 }
			if(alea == 3){
				/* Place les mots en marche arriere */
	//			if(nb <= N && nba <= N && nb+taille<N && nba+taille<N )
			 grille[nb][nba--]=car;
			}




				//		printf("%c",mots[1]);
					//	printf("%c",mots[2]);
		}

		fclose(fichier);
		// fermeture fichier

}
/*
*	 fonction de tests pour placer les mots dans la grille
*
*/
/*
int est_valide(int x,int y,char tab[N][N]){


}
*/


/*
*		fonction qui place un mots de facon horizontale
*
*/
void placer_mot_horizontal(char grille[N][N]){
	srand(time(NULL));
	FILE * fichier;
	fichier=fopen("mot2s.txt","r");

	char car;



	// Nombre aléatoires  pour les lignes de la matrice entre 0 et 9
	int nb = rand () % 10;
	printf("nombre = %d\n",nb);
	// Nombre aléatoires  pour les colonnes de la matrice entre 0 et 9
	int nba = rand () % 10;
	printf("nombre = %d\n",nba);



	while(!(feof(fichier))){
	fscanf(fichier,"%c ",&car);



	/*	printf("\nC = %c\n",car); */
//	printf("nb -> %d\n",nb);
//	printf("nba -> %d\n",nba);


			grille[nb][nba++]=car;




	}
		fclose(fichier);


}






/*
*		fonction qui place un mots de facon verticale
*
*/
void placer_mot_vertical(char grille[N][N]){
	// Nombre aléatoires  pour les lignes de la matrice entre 0 et 9
	int nb = rand () % 10;
	printf("nombre = %d\n",nb);
	// Nombre aléatoires  pour les colonnes de la matrice entre 0 et 9
	int nba = rand () % 10;
	printf("nombre = %d\n",nba);



}
/*
*		fonction qui place un mots en diagonale
*
*/
void placer_mot_endiagonale(char grille[N][N]){
	// Nombre aléatoires  pour les lignes de la matrice entre 0 et 9
	int nb = rand () % 10;
	printf("nombre = %d\n",nb);
	// Nombre aléatoires  pour les colonnes de la matrice entre 0 et 9
	int nba = rand () % 10;
	printf("nombre = %d\n",nba);




}






int main(){
	char grille[N][N];

	initialiser_grille(grille);
	// initialise la grille avec les caractereres '*'
	affiche_grille(grille);
	// affichage de la grille au départ
	placer_mot(grille);
	affiche_grille(grille);
return 0;
}
