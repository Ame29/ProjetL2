/**
 * \file liste.h
 * \brief
 * \author Asmae Bouhandi
 * \version 1
 * \date 13 mai 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../lib/commun.h"

/**
* \struct mot_liste
*/
typedef struct mot_liste mot_liste ;
struct mot_liste{
	char mot[N_TEST];
	point debut ;
	point fin ;
};
