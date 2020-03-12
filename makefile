
testMenu: menuAccueil.o fonctionMenu.o menuSolo.o menuCLM.o
	gcc menuAccueil.o menuSolo.o fonctionMenu.o menuCLM.o -o testMenu

menuAccueil.o: menuAccueil.c fonctionMenu.h menuSolo.h menuCLM.h
	gcc -o menuAccueil.o -c menuAccueil.c

fonctionMenu.o: fonctionMenu.c
	gcc -o fonctionMenu.o -c fonctionMenu.c

menuSolo.o: menuSolo.c fonctionMenu.h
	gcc -o menuSolo.o -c menuSolo.c

menuCLM.o: menuCLM.c fonctionMenu.h
	gcc -o menuCLM.o -c menuCLM.c

clean:
	rm -rf *.o

mrproper: clean
