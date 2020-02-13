#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//affiche un message avertissant de l'indisponibilité d'une fonctionnalité
void WorkInProgress(void){

	printf("Work in progress !\n");
	printf("Cette fonctionnalité n'est pas encore disponible revenez plus tard.\n\n");
	usleep(5000000) ;
	system("clear");

}
