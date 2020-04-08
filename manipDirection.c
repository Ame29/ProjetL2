#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int N;

int HasardSensNbr()
{
	//printf("--> HasardSensNbr <--\n");
	
	srand(time(NULL));
	return (rand() % 8);
}



