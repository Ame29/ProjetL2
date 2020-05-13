#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N_TEST 5

int main(int argc, char const *argv[])
{
    FILE *fp;

    fp = fopen("test.txt", "w");

    for(int i = 0; i < N_TEST; i++)
    {
        for(int j = 0; j < N_TEST; j++)
        {
            fprintf(fp, "%i", j);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    return 0;
}