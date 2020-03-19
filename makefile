
OPTS=-Wall

MotsMeles : manipmatrice.o  manipDirectionPlacement.o maniphasard.o main.o
	gcc manipmatrice.o  manipDirectionPlacement.o maniphasard.o main.o -o MotsMeles ${OPTS}
main.o : ./src/MainPlacementUnMot.c
	gcc -c ./src/MainPlacementUnMot.c ${OPTS}
manipmatrice.o : /src/ManipMatrice.c
	gcc -c /src/ManipMatrice.c ${OPTS}
manipDirectionPlacement.o : /src/ManipDirectionPlacement.c
	gcc -c /src/ManipDirectionPlacement.c ${OPTS}
maniphasard.o : /src/ManipHasard.c
	gcc -c /src/ManipHasard.c ${OPTS}
	
