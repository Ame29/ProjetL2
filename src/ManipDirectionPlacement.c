#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int N;
int compteur ;

void PlacerMot(char matrix[N][N])
{
    srand(time(NULL));
    int i, j, k = 0 ;
    int random_i, random_j, random_choix = 0 ;
    char word[100] ;//="fjlskdjfldslqfj";
    int lenght=0;

   do{
        TirerMot(&word);
        lenght=strlen(word)-1;
    }while(lenght>N);
    

    for(i=0; i<N ; i++)
    {
        for(j=0; j<N ; j++)
        {
            matrix[i][j]= '*' ;
        }
    }

    random_i = rand() % N;
    random_j = rand() % N;

    random_choix = (rand() % 8)+1;
    switch(random_choix){
    
        case 0:/*Nord-Ouest*/
            while(random_i-lenght<0||random_j-lenght<0)
            {
                random_i = rand() % N;
                random_j = rand() % N;
            }

            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i-- ;
                random_j-- ;
                k ++ ;
                compteur++;
            }
            break;
            
        case 1:/*Nord-Est*/
            while(random_i+lenght>N||random_j-lenght<0){
                random_i = rand() % N;
                random_j = rand() % N;
            }

            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i++ ;
                random_j-- ;
                k ++ ;
                compteur++;
            }
            break;
            
        case 2:/*Sud-Ouest*/
            while(random_i-lenght<0||random_j+lenght>N)
            {
                random_i = rand() % N;
                random_j = rand() % N;
            }
            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i-- ;
                random_j++ ;
                k ++ ;
                compteur++;
            }
            break;
            
        case 3:/*Sud-Est*/
            while(random_i+lenght>N || random_j+lenght>N)
            {
                random_i = rand() % N;
                random_j = rand() % N;
            }
            while(k<lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i++ ;
                random_j++ ;
                k ++ ;
                compteur++;
            }
            break;
            
        case 4:/*Nord*/
            while(random_j-lenght<0)
            {
                random_j = rand() % N;
            }
                while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
                {
                    matrix[random_i][random_j]= word[k] ;
                    random_j-- ;
                    k ++ ;
                    compteur++;
                }
            break;
            
        case 5:/*Ouest*/
            while(random_i-lenght<0)
            {
                random_i = rand() % N;
            }
            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i-- ;
                k ++ ;
                compteur++;
            }
            break;
            
        case 6:/*Est*/
            while(random_i+lenght>N)
           {
                random_i = rand() % N;
            }
            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_i++ ;
                k ++ ;
                compteur++;
            }
            break;
        case 7:/*Sud*/
            while(random_j+lenght>N)
            {
                random_j = rand() % N;
            }
            while(k < lenght && (matrix[random_i][random_j]=='*' || matrix[random_i][random_j] == word[k]))
            {
                matrix[random_i][random_j]= word[k] ;
                random_j++ ;
                k ++ ;
                compteur++;
            }
            break;
            
        default: break;

    }


    for(i=0 ; i<N ; i++)
	{
		for(j=0 ; j<N ; j++)
		{
			printf(" %c ", matrix[i][j]) ;
		}
		printf("\n");
	}
}


