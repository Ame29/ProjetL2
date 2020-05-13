/**
 * \file fonctionListe.c
 * \brief Contient toutes les fonctions utiles à l'initialisation de la liste
 * \author Asmae Bouhandi
 * \version 1
 * \date 13 mai 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \fn void afficher_liste(char ** liste_de_mot, int * nb_element)
 * \brief affiche la matrice
 * \param char ** liste_de_mot, int * nb_element
 * \return rien
 */
void afficher_liste(char ** liste_de_mot, int * nb_element){
	int i;
	for(i=0; i < *(nb_element); i++)
		printf("[%i] %s\n",i+1, *(liste_de_mot+i));

}

/**
 * \fn int mot_dans_liste(char ** liste_de_mot, char * mot, int * nb_element)
 * \brief vérifie la présence de la chaine de caractère "mot" dans "le tableau "liste_de_mot" de taille "nb_element", renvoie 1 si l'élément est présent, 0 sinon
 * \param char ** liste_de_mot, char * mot, int * nb_element
 * \return 0 ou 1
 */
int mot_dans_liste(char ** liste_de_mot, char * mot, int * nb_element){
	int i;
	for(i=0; i < *(nb_element); i++)
		if(!strcmp(*(liste_de_mot+i),mot))
			return 1;
	return 0;
}

/**
 * \fn void destruction_mot(char ** liste_de_mot, char * mot, int * nb_element)
 * \brief détruit la chaine de caractère "mot" dans le tableau "liste_de_mot" de taille "nb_element" décrémente "nb_element" de 1
 * \param char ** liste_de_mot, char * mot, int * nb_element
 * \return rien
 */
void destruction_mot(char ** liste_de_mot, char * mot, int * nb_element){
	int i;
	int j;
	for(i=0; i < *(nb_element) && strcmp(*(liste_de_mot+i),mot); i++){
	}
	if(i != *(nb_element)){
		*(liste_de_mot+i) = *(liste_de_mot+(*nb_element)-1);
		*(nb_element)=*(nb_element)-1;
	}
	else{
		printf("ERREUR: %s n'est pas dans la liste.\n",mot);
	}
}

/**
 * \fn int main()
 * \brief Test des fonctions mot_dans_liste, destruction_mot
 * \param void
 * \return rien
 */
int main(){
	int * nb_elem= malloc(sizeof(int));
	*nb_elem=3;
	char mot[20];
	char * T_mot[3]= {"chien","poule","tekel"};
	afficher_liste(T_mot,nb_elem);
	/*
	printf("Saisir un mot :");
	scanf("%s", mot);
	switch(mot_dans_liste(T_mot, mot, nb_elem)){
		case 0: printf("Le mot n'est pas présent dans la liste. \n"); break;
		case 1: printf("Le mot est présent dans la liste. \n"); break;
		default: printf("ERREUR !\n");
	}
	*/
	printf("Saisir un mot à supprimer de la liste :");
	scanf("%s", mot);
	destruction_mot(T_mot, mot, nb_elem);
	afficher_liste(T_mot,nb_elem);
	free(nb_elem);

}
