/**
 * \file fonctionGrille.c
 * \brief Contient toutes les fonctions utiles à gestion la grille de jeu
 * \author Asmae Bouhandi
 * \version 1
 * \date 01 avril 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#include "../lib/commun.h"
#include "../lib/fonctionGrille.h"

#define NORD 0
#define OUEST 1
#define EST 2
#define SUD 3
// #define NORDOUEST 4
// #define NORDEST 5
// #define SUDOUEST 6
// #define SUDEST 7

//int N = 8 ;

/**
 * \fn void initGrille(char matrice[N_TEST][N_TEST])
 * \brief Remplit une matrice du caractère avec le caractère '*'
 * \param char matrice[N_TEST][N_TEST]
 * \return rien
 */
void initGrille(char matrice[N_TEST][N_TEST]){
	int i, j ;

	for(i=0; i<N_TEST; i++)
	{
		for(j=0; j<N_TEST; j++)
		{
			matrice[i][j] = '.' ;
		}
	}
}

/**
 * \fn void affGrille(char matrice[N_TEST][N_TEST])
 * \brief Affiche la matrice passé en paramètre.
 * \param char matrice[N_TEST][N_TEST]
 * \return rien
 */
void affGrille(char matrice[N_TEST][N_TEST]){
	int i, j ;

	for(i=0; i<N_TEST; i++)
	{
		for(j=0; j<N_TEST; j++)
		{
			printf(" %c ", matrice[i][j]) ;
		}
		printf("\n");
	}
}

/**
 * \fn int nombreAleatoire(int limMax)
 * \brief Renvoie un nombre entre 0 et limMax-1
 * \param int limMax
 * \return Valeur entière entre 0 et limMas-1
 */
int nombreAleatoire(int limMax){
	return (rand() % limMax);
}

/**
 * \fn void voidToChar(char matrice[N_TEST][N_TEST])
 * \brief Remplace chaque caractère '.' d'une matrice de caractère par une lettre minuscule aléatoire
 * \param char matrice[N_TEST][N_TEST]
 * \return rien
 */
void voidToChar(char matrice[N_TEST][N_TEST])
{
    //printf("--> RemplirCaseMatVide <--\n");

    int i, j ;
    srand((unsigned)time(NULL));
    for(i=0 ; i<N_TEST ; i++)
    {
        for(j=0 ; j<N_TEST ; j++)
        {
            if(matrice[i][j] == '.')
            {
                matrice[i][j] = 'A'+rand()%26;
            }
        }
    }
}


/**
 * \fn int tirerMot(char * nomFichier, char * motTire)
 * \brief affecte à un pointeur sur char un mot du fichier * nomFichier
 * \param char * nomFichier, char * motTire
 * \return 1 si un problème survient, 0 sinon
 */
int TirerMot(char *nomFichier, char *motTire){
	FILE * fichier = NULL ;
	int nbrMots = 0, numMot = 0, charLu ;
	int indiceMot ;
	fichier = fopen(nomFichier, "r") ;

	/*Vérifie si le fichier est ouvrable*/
	if (fichier == NULL){
		printf("Problème à l'ouverture du fichier\n");
		return 1;
	}

	/* Comptage du nombre de mot dans le fichier, Stocké dans nbrMots */
	do{
		charLu = fgetc(fichier);
		if (charLu == '\n')
		{
			nbrMots++;
		}
	} while(charLu != EOF);
	//printf("Il y a %i mots dans la bibliothèque\n", nbrMots);

	numMot = nombreAleatoire(nbrMots);
	indiceMot=numMot;

	rewind(fichier);

	while (numMot > 0){
		charLu = fgetc(fichier);
		if (charLu == '\n'){
			numMot--;
		}
	}

	fgets(motTire, 100, fichier);
	//printf("Le mot numéro %i est %s", indiceMot+1, motTire);
	fclose(fichier);
	return indiceMot;
}

/**
 * \fn int RechercheTableau(int *tab, int n)
 * \brief Recherche l'entier n dans le tableau tab
 * \param int *tab, int n
 * \return 0 ou 1
 */
int RechercheTableau(int *tab, int n)
{
    int N = 30 ;
    for(int i = 0 ; i < N ; i ++)
    {
        if (tab[i] == n)
        {
            return 1 ;
        }
    }
    return 0 ;
}

/**
 * \fn void ajoutListe(mot_tire liste_mot[N_TEST+1], char *mot)
 * \brief ajoute à la liste un mot
 * \param mot_tire liste_mot[N_TEST+1], char *mot
 * \return rien
 */
void ajoutListe(mot_tire liste_mot[N_TEST+1], char *mot)
{
    int i = 0 ;
    while(liste_mot[i].mot == "\0")
    {
        i++ ;
    }
    strcpy(liste_mot[i].mot, mot) ;
}

/**
 * \fn void upper_string(char *s)
 * \brief Fait passer un chaine de caractère de minuscule vers majuscule
 * \param char *s
 * \return rien
 */
void upper_string(char *s) {
   int c = 0;

   while (s[c] != '\0') {
      if (s[c] >= 'a' && s[c] <= 'z') {
         s[c] = s[c] - 32;
      }
      c++;
   }
}

/**
 * \fn void PlacerMot(char matrix[N_TEST][N_TEST])
 * \brief place un mot dans la grille
 * \param char matrix[N_TEST][N_TEST]
 * \return rien
 */
void PlacerMot(char matrix[N_TEST][N_TEST], char *themefile, mot_tire liste_mot[N_TEST+1])
{
    //printf("--> PlacerMot <--\n");

    srand(time(NULL)) ;

    int k = 0 ;
    int a = 0 ;
    //int essai = 0 ;
    int compteur = 0 ;
    int random_i, random_j, random_choix = 0 ;
    char word[50] ;//="fjlskdjfldslqfj";
    int lenght = 0 ;

    int deja_utilises[30] = {0} ;

    //affGrille(matrix) ;

    while(compteur < N_TEST)
    {
        tirer_mot:
            //printf("Word n°%d\n", compteur) ;

            do{
                a = TirerMot(themefile, word);
                lenght = strlen(word)-1;
            }while((lenght>N_TEST) || RechercheTableau(deja_utilises, a));

            // if(RechercheTableau(deja_utilises, N, a))
            // {
            //     printf("Ce mot est déjà utilisé!\n");
            // }

            //printf("Random numbers\n");
            random_i = rand() % N_TEST;
            random_j = rand() % N_TEST;
            random_choix = (rand() % 4);

            //random_choix = 3 ;
            switch(random_choix){

                // case NORDOUEST:
                //     while(random_i-lenght<0||random_j-lenght<0)
                //     {
                //         random_i = rand() % N;
                //         random_j = rand() % N;
                //     }
                //     printf("NORDOUEST (%i - %i)!\n", random_i, random_j);

                //     while(k < lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == word[k]))
                //     {
                //         matrix[random_i][random_j]= word[k] ;
                //         random_i-- ;
                //         random_j-- ;
                //         k++ ;
                //         compteur++;
                //     }
                //     break;

                // case NORDEST:
                //     while(random_i+lenght<N||random_j-lenght>0){
                //         random_i = rand() % N;
                //         random_j = rand() % N;
                //     }
                //     printf("NORDEST (%i - %i)!\n", random_i, random_j);

                //     while(k < lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == word[k]))
                //     {
                //         matrix[random_i][random_j]= word[k] ;
                //         random_i++ ;
                //         random_j-- ;
                //         k ++ ;
                //         compteur++;
                //     }
                //     break;

                // case SUDOUEST:
                //     while(random_i-lenght<0||random_j+lenght>N)
                //     {
                //         random_i = rand() % N;
                //         random_j = rand() % N;
                //     }
                //     printf("SUDOUEST (%i - %i)!\n", random_i, random_j);

                //     while(k < lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == word[k]))
                //     {
                //         matrix[random_i][random_j]= word[k] ;
                //         random_i-- ;
                //         random_j++ ;
                //         k ++ ;
                //         compteur++;
                //     }
                //     break;

                // case SUDEST:
                //     while(random_i+lenght>N || random_j+lenght>N)
                //     {
                //         random_i = rand() % N;
                //         random_j = rand() % N;
                //     }
                //     printf("SUDEST (%i - %i)!\n", random_i, random_j);

                //     while(k<lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == word[k]))
                //     {
                //         matrix[random_i][random_j]= word[k] ;
                //         random_i++ ;
                //         random_j++ ;
                //         k ++ ;
                //         compteur++;
                //     }
                //     break;

                case NORD:
                //printf("NORD\n");
                    k = 0 ;
                    while(random_i-lenght+1<0)
                    {
                        random_i = rand() % N_TEST;
                        //printf("nord %i %i\n", random_i, random_j);
                    }

                    int i = random_i ;

                    while(k < lenght)
                    {
                        if (matrix[i][random_j] == '.')
                        {
                            //printf("NORD (%i - %i)!\n", i, random_j);
                            //printf("on avance !\n");
                        }
                        else if (matrix[i][random_j] == toupper(word[k]))
                        {
                            //printf("NORD (%i - %i)!\n", i, random_j);
                            //printf("on avance !\n");
                        }
                        else
                        {
                            //printf("NORD (%i - %i)!\n", i, random_j);
                            //printf("ça marche pas !\n");
                            goto tirer_mot ;
                        }
                        i -- ;
                        k ++ ;
                    }

                    //printf("NORD (%i - %i)!\n", random_i, random_j);

                    k = 0 ;
                    liste_mot[compteur].x1 = random_i ;
                    liste_mot[compteur].y1 = random_j ;
                    while(k < lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == word[k]))
                    {
                        //printf("word[%i] = %c\n", k, word[k]);
                        if(isalpha(word[k]))
                        {
                            matrix[random_i][random_j]= toupper(word[k]) ;
                            random_i-- ;
                        }
                        k ++ ;
                    }
                    //printf("compteur : %i | nord : %s\n", compteur, word);
                    upper_string(word) ;
                    strcpy(liste_mot[compteur].mot, word);
                    liste_mot[compteur].x2 = random_i ;
                    liste_mot[compteur].y2 = random_j ;
                    //ajoutListe(liste_mot,word) ;
                    compteur++;
                    deja_utilises[compteur] = a ;
                    break;

                case OUEST:
                //printf("OUEST\n");
                    k = 0 ;
                    while(random_j-lenght<0)
                    {
                        //random_j = rand() % N_TEST;
                        random_j++;
                        //printf("ouest %i - %i\n", random_i, random_j);
                    }

                    int j = random_j ;
                    while(k < lenght)
                    {
                        if (matrix[random_i][j] == '.')
                        {
                            //printf("OUEST (%i - %i)!\n", random_i, j);
                            //printf("on avance !\n");
                        }
                        else if (matrix[random_i][j] == toupper(word[k]))
                        {
                            //printf("OUEST (%i - %i)!\n", random_i, j);
                            //printf("on avance !\n");
                        }
                        else
                        {
                            //printf("OUEST (%i - %i)!\n", random_i, j);
                            //printf("ça marche pas !\n");
                            goto tirer_mot ;
                        }
                        j -- ;
                        k ++ ;
                    }

                    //printf("OUEST (%i - %i)!\n", random_i, random_j);

                    k = 0 ;
                    liste_mot[compteur].x1 = random_i ;
                    liste_mot[compteur].y1 = random_j ;
                    while(k < lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == word[k]))
                    {
                        if(isalpha(word[k]))
                        {
                            matrix[random_i][random_j]= toupper(word[k]) ;
                            //printf("Dans OUEST\n");
                            //printf("word[%i] = %c\n", k, word[k]);
                            //affGrille(matrix) ;
                            //printf("\n");
                            random_j-- ;
                        }
                        k++ ;
                    }
                    //printf("compteur : %i | ouest : %s\n", compteur, word);
                    upper_string(word) ;
                    strcpy(liste_mot[compteur].mot, word);
                    liste_mot[compteur].x2 = random_i ;
                    liste_mot[compteur].y2 = random_j ;
                    //ajoutListe(liste_mot,word) ;
                    compteur++;
                    deja_utilises[compteur] = a ;
                    break;

                case EST:
                //printf("EST\n");
                    k = 0 ;
                    while(random_j+lenght>N_TEST)
                    {
                        random_j = rand() % N_TEST;
                    }

                    j = random_j ;
                    while(k < lenght)
                    {
                        if (matrix[random_i][j] == '.')
                        {
                            //printf("EST (%i - %i)!\n", random_i, j);
                            //printf("on avance !\n");
                        }
                        else if (matrix[random_i][j] == toupper(word[k]))
                        {
                            //printf("EST (%i - %i)!\n", random_i, j);
                            //printf("on avance !\n");
                        }
                        else
                        {
                            //printf("EST (%i - %i)!\n", random_i, j);
                            //printf("ça marche pas !\n");
                            goto tirer_mot ;
                        }
                        j ++ ;
                        k ++ ;
                    }

                    //printf("EST (%i - %i)!\n", random_i, random_j);

                    k = 0 ;
                    liste_mot[compteur].x1 = random_i ;
                    liste_mot[compteur].y1 = random_j ;

                    while(k < lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == toupper(word[k])))
                    {
                        //printf("word[%i] = %c\n", k, word[k]);
                        if(isalpha(word[k]))
                        {
                            matrix[random_i][random_j]= toupper(word[k]) ;
                            random_j++ ;
                        }
                        k ++ ;
                    }
                    //printf("compteur : %i | est : %s\n", compteur, word);
                    upper_string(word) ;
                    strcpy(liste_mot[compteur].mot, word);
                    liste_mot[compteur].x2 = random_i ;
                    liste_mot[compteur].y2 = random_j ;
                    //ajoutListe(liste_mot,word) ;
                    compteur++;
                    deja_utilises[compteur] = a ;
                    break;

                case SUD:
                //printf("SUD\n");
                    k = 0 ;
                    while(random_i+lenght>N_TEST)
                    {
                        random_i = rand() % N_TEST;
                    }

                    i = random_i ;

                    while(k < lenght)
                    {
                        if (matrix[i][random_j]=='.')
                        {
                            //printf("SUD (%i - %i)!\n", i, random_j);
                            //printf("on avance !\n");
                        }
                        else if (matrix[i][random_j] == toupper(word[k]))
                        {
                            //printf("SUD (%i - %i)!\n", i, random_j);
                            //printf("on avance !\n");
                        }
                        else
                        {
                            //printf("SUD (%i - %i)!\n", i, random_j);
                            //printf("ça marche pas !\n");
                            goto tirer_mot ;
                        }
                        i ++ ;
                        k ++ ;
                    }

                    //printf("SUD (%i - %i)!\n", random_i, random_j);

                    k = 0 ;
                    liste_mot[compteur].x1 = random_i ;
                    liste_mot[compteur].y1 = random_j ;
                    while(k < lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == toupper(word[k])))
                    {
                        //printf("word[%i] = %c\n", k, word[k]);
                        if(isalpha(word[k]))
                        {
                            matrix[random_i][random_j]= toupper(word[k]) ;
                            random_i++ ;
                        }
                        k ++ ;
                    }
                    //printf("compteur : %i | sud : %s\n", compteur, word);
                    upper_string(word) ;
                    strcpy(liste_mot[compteur].mot, word);
                    liste_mot[compteur].x2 = random_i ;
                    liste_mot[compteur].y2 = random_j ;
                    //ajoutListe(liste_mot, word) ;
                    compteur++;
                    deja_utilises[compteur] = a ;
                    break;

                default: break;

            }

    }

    // affGrille(matrix) ;

}
