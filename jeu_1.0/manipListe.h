#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char mot[40] ;
    int coord_x1 ;
    int coord_y1 ;
    int coord_x2 ;
    int coord_y2 ;
}t_mot ;

int insertion(t_mot *liste, int nb_mots, char *mot, int coord_x1, int coord_y1, int coord_x2, int coord_y2);
void afficherListe(t_mot *liste, int nb_mots);
void supprimerElement(char *mot, int coord_x1, int coord_y1, int coord_x2, int coord_y2);