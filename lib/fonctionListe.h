/**
 * \file fonctionListe.h
 * \brief header contenant les prototype des fonctions utiles à la liste.
 * \author Quentin Bellanger
 * \version 1
 * \date 01 avril 2020
 */
#ifndef LISTE
#define LISTE

void afficher_liste(char ** liste_de_mot, int * nb_element);
int mot_dans_liste(char ** liste_de_mot, char * mot, int * nb_element);
void destruction_mot(char ** liste_de_mot, char * mot, int * nb_element);

#endif
