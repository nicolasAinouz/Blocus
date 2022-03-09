CC = gcc

#---------------------------------------------------------------------------------
# options de compilation
#---------------------------------------------------------------------------------
CFLAGS = -Wall -g -ansi -pedantic

EXE = main.out
OFILES = main.o menu.o grille.o grilleia.o fin.o jeuia.o jeux.o 

LIBS = -lgraph -lm

but : ${EXE}

main.o : main.h
menu.o : menu.h
grilleia.o : grilleia.h
grille.o : grille.h
jeuia.o : jeuia.h
jeux.o: jeux.h
fin.o : fin.h


${EXE} : ${OFILES}
	${CC} ${CFLAGS} -o ${EXE} ${OFILES} ${LIBS}

clean :
	-rm -f ${OFILES}
	-rm -f ${EXE}

run:
	make
	./main.out

.PHONY : but clean run