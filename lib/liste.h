#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../lib/commun.h"

typedef struct mot_liste mot_liste ;
struct mot_liste{
	char mot[N_TEST];
	point debut ;
	point fin ;
};