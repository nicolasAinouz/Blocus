#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <math.h>
#include"fin.h"

#include "menu.h"
#define tx 700
#define ty 700
#define SIZE_GRID 100

void fin(){

    int x1,y1;
    int c=0;
    InitialiserGraphique();
    CreerFenetre(100,50,tx,ty);

    /*Arrière-Plan*/
    ChargerImage("Images/papier.jpeg",0,0,0,0,700,700);

    /*Logo Blocus*/
    ChargerImage("Images/blocus.png",0,50,0,0,700,700);

    /*outons Choix Nombre  Joueurs*/
        ChargerImage("Images/rejouer.png",206.5,300,0,0,700,700);
        ChargerImage("Images/sortir.png",206.5,400,0,0,700,700);

        while (c<1) {
            if(SourisCliquee()) {
                SourisPosition();
                x1=_X;
                y1=_Y;
                if ((206.5<x1 && x1<493.5) && (300<y1 && y1<360)) {
                
                    printf("rejouer\n");

                    FermerGraphique();
                    menu();
                    c++;

                } else if ((206.5<x1 && x1<493.5) && (400<y1 && y1<460)) {
                    printf("fin\n");
                    FermerGraphique();
                    


        
                }
            }
            
        }
        FermerGraphique();
        
}