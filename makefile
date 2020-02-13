testMenu: menuAccueil.o fonction.o menuSolo.o menuCLM.o
	gcc menuAccueil.o menuSolo.o fonction.o menuCLM.o -o testMenu

menuAccueil.o: menuAccueil.c fonction.h menuSolo.h menuCLM.h
	gcc -o menuAccueil.o -c menuAccueil.c

fonction.o: fonction.c
	gcc -o fonction.o -c fonction.c

menuSolo.o: menuSolo.c fonction.h
	gcc -o menuSolo.o -c menuSolo.c

menuCLM.o: menuCLM.c fonction.h
	gcc -o menuCLM.o -c menuCLM.c

clean:
	rm -rf *.o

mrproper: clean
