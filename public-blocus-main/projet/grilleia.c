#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <math.h>
#include "grilleia.h"
#include "menu.h"
#include "jeuia.h"
#define tx 700
#define ty 700
#define SIZE_GRID 100


void grilleia(int nb_ligne_colonne) {

		int i,j;

		if(nb_ligne_colonne<=6){  
		InitialiserGraphique();
		CreerFenetre(100,50,SIZE_GRID*nb_ligne_colonne,SIZE_GRID*nb_ligne_colonne);  
		for ( i = 0; i < nb_ligne_colonne; i++){
			for (j = 0; j < nb_ligne_colonne; j++) {
				DessinerRectangle(j * (SIZE_GRID), i * (SIZE_GRID), SIZE_GRID, SIZE_GRID);
			}
		}
	}

	if(nb_ligne_colonne>6){
		InitialiserGraphique();
		CreerFenetre(100,50,(SIZE_GRID/1.5)*nb_ligne_colonne,(SIZE_GRID/1.5)*nb_ligne_colonne);
		for (i = 0; i < nb_ligne_colonne; i++){
			for (j = 0; j < nb_ligne_colonne; j++) {       
				DessinerRectangle(j * (SIZE_GRID/1.5), i * (SIZE_GRID/1.5), SIZE_GRID/1.5, SIZE_GRID/1.5);
			}
		}
	}


	jeuia(nb_ligne_colonne);
}
