#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <math.h>
#include"menu.h"

#define tx 700
#define ty 700
#define SIZE_GRID 100


int main(int argc , char ** argv) {




	menu();
	FermerGraphique();



	return EXIT_SUCCESS;
}








/*A montrer dans le rapport */
	/*int i=0;
	int x=0;
	int y=0;
	int xx=0;
	int yy=700;
	for (i=0;i<nb_ligne_colonne-1;i++){
		x=x+(700/nb_ligne_colonne);
		xx=xx+(700/nb_ligne_colonne);
		DessinerSegment(x,y,xx,yy);
	}

	i=0;
	x=0;
	y=0;
	xx=700;
	yy=0;

	for (i=0;i<nb_ligne_colonne-1;i++){
		y=y+(700/nb_ligne_colonne);
		yy=yy+(700/nb_ligne_colonne);
		DessinerSegment(x,y,xx,yy);
	}

	Touche();*/