
OPTS=-Wall

MotsMeles : manipmatrice.o  manipDirectionPlacement.o maniphasard.o main.o
	gcc manipmatrice.o  manipDirectionPlacement.o maniphasard.o main.o -o MotsMeles ${OPTS}
main.o : src/MainPlacementUnMot.c
	gcc -c MainPlacementUnMot.c ${OPTS}
manipmatrice.o : ManipMatrice.c
	gcc -c ManipMatrice.c ${OPTS}
manipDirectionPlacement.o : ManipDirectionPlacement.c
	gcc -c ManipDirectionPlacement.c ${OPTS}
maniphasard.o : ManipHasard.c
	gcc -c ManipHasard.c ${OPTS}
	
