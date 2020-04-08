#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int CompteurMots(){
	//printf("--> CompteurMots <--\n");

	FILE*fichier;
	char calcul;

	int NbMots = 0;
	fichier = fopen("biblioteque.txt","r");

	calcul = fgetc(fichier);
	if (fichier == NULL)
		printf("Problème à l'ouverture du fichier");
	else
	{
		while (!feof(fichier)){

			if(calcul =='\n')
				NbMots++;
		calcul = fgetc(fichier);
		}
	}
	fclose(fichier);
	
	//rintf("Il y a %i des mots dans la bibliothèque\n ",NbMots);
	
	return NbMots ;
}

void AjouterMots()
{
	//printf("--> AjouterMots <--\n");
	
	FILE*fichier;
	char mot[35];
	int i ;
	int nbrMots = 0 ;

	fichier = fopen("biblioteque.txt","r");

	if (fichier == NULL)
		printf("Problème à l'ouverture du fichier");
	else
	{
		printf("Combien de mots voulez-vous entrer dans la bibliotheque?");
		scanf("%i", &nbrMots);

		for(i=0; i<nbrMots; i++)
		{
			printf("Entrez votre mot : ") ;
			scanf("%s", mot) ;
			fputs("mot", fichier);
			printf("Le mot %s a été ajouté avec succès !\n", mot);
		}
	}
	fclose(fichier);
}
