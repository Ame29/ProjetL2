#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void afficher_liste(char ** liste_de_mot, int * nb_element){
	int i;
	for(i=0; i < *(nb_element); i++)
		printf("%s\n", *(liste_de_mot+i));
			
}

//vérifie la présence de la chaine de caractère "mot" dans "le tableau "liste_de_mot" de taille "nb_element", renvoie 1 si l'élément est présent, 0 sinon. 	
int mot_dans_liste(char ** liste_de_mot, char * mot, int * nb_element){
	int i;
	for(i=0; i < *(nb_element); i++)
		if(!strcmp(*(liste_de_mot+i),mot))
			return 1;
	return 0;
}

//détruit la chaine de caractère "mot" dans le tableau "liste_de_mot" de taille "nb_element" décrémente "nb_element" de 1
void destruction_mot(char ** liste_de_mot, char * mot, int  *nb_element){
	int i;
	int j;
	printf("%s",mot);
	for(i=0; i < *(nb_element); i++){
		printf("mot=%s\n",mot);
		printf("mot dans liste=%s\n", *(liste_de_mot+i));
		if(!strcmp(*(liste_de_mot+i),mot)){
			printf("rentré dans le int");
			for(j=i; j<*(nb_element)-1, j++;)
				strcpy(*(liste_de_mot+j),*(liste_de_mot+j+1));	
		}
	}
	*nb_element--;
*/
	printf("nb_element= %d",*nb_element); 
}

//Test des fonctions mot_dans_liste, destruction_mot
int main(){
	int * nb_elem= malloc(sizeof(int));
	*nb_elem=3;
	char mot[20];
	char * T_mot[3]= {"chien","poule","canard"};
	afficher_liste(T_mot,nb_elem);
	printf("Saisir un mot :");
	scanf("%s", mot);
	switch(mot_dans_liste(T_mot, mot, nb_elem)){
		case 0: printf("Le mot n'est pas présent dans la liste. \n"); break;
		case 1: printf("Le mot est présent dans la liste. \n"); break;
		default: printf("ERREUR !\n");
	}
	afficher_liste(T_mot,nb_elem);
	printf("Saisir un mot à supprimer de la liste :");
	scanf("%s", mot);
	destruction_mot(T_mot, mot, nb_elem);
	
}
