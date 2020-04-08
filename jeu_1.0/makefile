
OPTS=-Wall

MotsMeles : manipMatrice.o manipFichier.o manipDirectionPlacement.o manipHasard.o main.o
	gcc manipMatrice.o manipFichier.o manipDirectionPlacement.o manipHasard.o main.o -o MotsMeles ${OPTS}
main.o : main.c
	gcc -c main.c ${OPTS}
manipfichier.o : manipFichier.c 
	gcc -c manipFichier.c ${OPTS}
manipmatrice.o : manipMatrice.c
	gcc -c manipMatrice.c ${OPTS}
manipDirectionPlacement.o : manipDirectionPlacement.c
	gcc -c manipDirectionPlacement.c ${OPTS}
maniphasard.o : manipHasard.c
	gcc -c manipHasard.c ${OPTS}
	
