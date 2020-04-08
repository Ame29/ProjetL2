#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "manipHasard.h"
#include "manipMatrice.h"

#define NORD 0
#define OUEST 1
#define EST 2
#define SUD 3
// #define NORDOUEST 4
// #define NORDEST 5
// #define SUDOUEST 6
// #define SUDEST 7

int RechercheTableau(int *tab, int N, int n)
{
    for(int i = 0 ; i < N ; i ++)
    {
        if (tab[i] == n)
        {
            return 1 ;
        }
    }
    return 0 ;
}

void PlacerMot(int N, char matrix[N][N])
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

    while(compteur < N+3)
    {
        tirer_mot:
            //printf("Word n°%d\n", compteur) ;

            do{
                a = TirerMot(word);
                lenght = strlen(word)-1;
            }while((lenght>N) || RechercheTableau(deja_utilises, N, a));

            // if(RechercheTableau(deja_utilises, N, a))
            // {
            //     printf("Ce mot est déjà utilisé!\n");
            // }

            //printf("Random numbers\n");
            random_i = rand() % N;
            random_j = rand() % N;

            random_choix = (rand() % 4)+1;
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
                    k = 0 ;
                    while(random_i-lenght<0)
                    {
                        random_i = rand() % N;
                    }

                    int i = random_i ;
                    while(k < lenght)
                    {
                        if (matrix[i][random_j] == '.')
                        {
                            //printf("NORD (%i - %i)!\n", i, random_j);
                            //printf("on avance !\n");
                        }
                        else if (matrix[i][random_j] == word[k])
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
                    while(k < lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == word[k]))
                    {
                        //printf("word[%i] = %c\n", k, word[k]);
                        matrix[random_i][random_j]= word[k] ;
                        random_i-- ;
                        k ++ ;
                    }
                    compteur++;
                    deja_utilises[compteur] = a ;
                    break;
                    
                case OUEST:
                    k = 0 ;
                    while(random_j-lenght<0)
                    {
                        random_j = rand() % N;
                    }

                    int j = random_j ;
                    while(k < lenght)
                    {
                        if (matrix[random_i][j] == '.')
                        {
                            //printf("OUEST (%i - %i)!\n", random_i, j);
                            //printf("on avance !\n");
                        }
                        else if (matrix[random_j][j] == word[k])
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
                    while(k < lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == word[k]))
                    {
                        //printf("word[%i] = %c\n", k, word[k]);
                        matrix[random_i][random_j]= word[k] ;
                        random_j-- ;
                        k ++ ;
                    }
                    compteur++;
                    deja_utilises[compteur] = a ;
                    break;
                    
                case EST:
                    k = 0 ;
                    while(random_j+lenght>N)
                    {
                        random_j = rand() % N;
                    }

                    j = random_j ;
                    while(k < lenght)
                    {
                        if (matrix[random_i][j] == '.')
                        {
                            //printf("EST (%i - %i)!\n", random_i, j);
                            //printf("on avance !\n");
                        }
                        else if (matrix[random_j][j] == word[k])
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
                    while(k < lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == word[k]))
                    {
                        //printf("word[%i] = %c\n", k, word[k]);
                        matrix[random_i][random_j]= word[k] ;
                        random_j++ ;
                        k ++ ;
                    }
                    compteur++;
                    deja_utilises[compteur] = a ;
                    break;

                case SUD:
                    k = 0 ;
                    while(random_i+lenght>N)
                    {
                        random_i = rand() % N;
                    }

                    i = random_i ;

                    while(k < lenght)
                    {
                        if (matrix[i][random_j]=='.')
                        {
                            //printf("SUD (%i - %i)!\n", i, random_j);
                            //printf("on avance !\n");
                        }
                        else if (matrix[i][random_j] == word[k])
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
                    while(k < lenght && (matrix[random_i][random_j]=='.' || matrix[random_i][random_j] == word[k]))
                    {
                        //printf("word[%i] = %c\n", k, word[k]);
                        matrix[random_i][random_j]= word[k] ;
                        random_i++ ;
                        k ++ ;
                    }
                    compteur++;
                    deja_utilises[compteur] = a ;
                    break;
                    
                default: break;

            }

    }
    AfficherGrille(N, matrix) ;

}