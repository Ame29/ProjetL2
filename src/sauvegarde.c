/**
 * \file sauvegarde.c
 * \brief sauvegarde/chargement d'une partie
 * \author Guillaume Derrien
 * \version 1
 * \date 01 avril 2020
 */

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


  printf("Sauvegarde terminee ! \n");

  fclose(fichier);
}

void charger_sauvegarde(char grille[N][M], char * liste[2]){
    FILE * fichier;
    char nom_fichier[20] = "sauvegarde.txt";
    int i,j;
    char trash[50];
    char caracActuel;
    char motActuel;
    
    fichier = fopen(nom_fichier,"r");
    if(fichier == NULL){
        printf("Erreur le fichier n'existe pas");
    }else{
        fgets(trash,25,fichier);
        
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                fscanf(fichier,"%c ",&caracActuel);
                grille[i][j] = caracActuel;
            }
        }
        
        fgets(trash,22,fichier);
        i=0;
        

        while(!feof(fichier)){
            fscanf(fichier,"%s",&motActuel);
            printf("%s \n",&motActuel);
            i++;
            liste[i]=&motActuel;
        }
    }
    fclose(fichier);
}
