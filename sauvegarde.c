#include <stdio.h>

#define N 2
#define M 4

void sauvegarder(char grille[N][M], char * liste[2]){
  FILE * fichier;
  char nom_fichier[20] = "sauvegarde.txt";
  int i,j;


  fichier = fopen(nom_fichier,"w");

  //sauvegarde matrice remplie
  fprintf(fichier, "%s","Matrice sauvegardée : \n");
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      fprintf(fichier, "%c ",grille[i][j]);
    }
    fprintf(fichier, "\n");
  }
  fprintf(fichier, "\n");

  //sauvegarde Liste :
  fprintf(fichier, "%s","Liste sauvegardée : \n");

  for(i=0;i<2;i++){
    fprintf(fichier, "%s\n",liste[i]);
  }


  fclose(fichier);
}
