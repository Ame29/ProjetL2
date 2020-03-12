
OPTS=-Wall

MotsMeles : manipmatrice.o  manipDirectionPlacement.o maniphasard.o main.o
	gcc manipmatrice.o  manipDirectionPlacement.o maniphasard.o main.o -o MotsMeles ${OPTS}
main.o : main.c
	gcc -c main.c ${OPTS}
manipmatrice.o : manipmatrice.c
	gcc -c manipmatrice.c ${OPTS}
manipDirectionPlacement.o : manipDirectionPlacement.c
	gcc -c manipDirectionPlacement.c ${OPTS}
maniphasard.o : maniphasard.c
	gcc -c maniphasard.c ${OPTS}
	
