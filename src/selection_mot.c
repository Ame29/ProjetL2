#include <stdio.h>

void selection_mot(){
    char tab[10][10];
    int x_joueur;
    int y_joueur;
    
    typedef struct mot_s{
        char mot[5];
        int x_debut;
        int y_debut;
        int x_fin;
        int y_fin;
        int taille_mot;
    }mot_t;
    
    tab[0][0]='s';
    tab[0][1]='a';
    tab[0][2]='l';
    tab[0][3]='u';
    tab[0][4]='t';
    
    struct mot_t word;
    word.mot="Salut";
    word.taille=5;
    word.x_début=0;
    word.y_debut=0;
    word.x_fin=0;
    word.y_fin=4;
    printf("Vous avez trouvez un mot ? Entrez les coordonnées de la première lettre : ");
    scanf("%d %d",&x_joueur, &y_joueur);
    printf("X de début : %d\n",x_joueur);
    printf("Y de début : %d\n",y_joueur);
}