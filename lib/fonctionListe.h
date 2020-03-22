#ifndef LISTE
#define LISTE

void afficher_liste(char ** liste_de_mot, int * nb_element);
int mot_dans_liste(char ** liste_de_mot, char * mot, int * nb_element);
void destruction_mot(char ** liste_de_mot, char * mot, int * nb_element);

#endif
