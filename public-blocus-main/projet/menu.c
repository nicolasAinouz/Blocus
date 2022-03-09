#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <math.h>

#include "grilleia.h"
#include "grille.h"

#define tx 700
#define ty 700
#define SIZE_GRID 100

void menu(void) {


	/*Déclaration Variables Fond d'écran*/
	couleur couleur1;
	/*Déclaration Varaibles Souris*/

	int x1,y1,x2,y2;
	int c1=0;
	int c2=0;
	int nb_ligne_colonne;
	

	InitialiserGraphique();
	CreerFenetre(100,100,tx,ty);

	/*Arrière-Pla*/
	ChargerImage("./Images/papier.jpeg",0,0,0,0,700,700);

	 /*Logo */
	ChargerImage("./Images/blocus.png",0,50,0,0,700,700);

	/*Boutons Choix Nombre  Joueurs*/
	ChargerImage("./Images/J1vJ2.png",206.5,300,0,0,700,700);
	ChargerImage("./Images/J1vIA.png",206.5,400,0,0,700,700);

	/*phraseaccueil*/
	ChargerImage("./Images/phrase.png",130,225,0,0,700,700);

	/*Designed by*/
	couleur1=CouleurParNom("black");
	ChoisirCouleurDessin(couleur1);
	EcrireTexte(242,675,"Design by Corentin R. and Nicolas A.",0);

	/*Zone de cli*/ 
	while(c1==0){
		if(SourisCliquee()) {
			SourisPosition();
			x1=_X;
			y1=_Y;

			if ((206.5<x1 && x1<493.5) && (300<y1 && y1<360)) {
				printf("1vs1\n"); /*1VS1*/

			

				/*Affichage boutons Taille plateau*/

				ChargerImage("./Images/3.png",80,500,0,0,700,700);
				ChargerImage("./Images/4.png",232,500,0,0,700,700);
				ChargerImage("./Images/5.png",384,500,0,0,700,700);
				ChargerImage("./Images/6.png",536,500,0,0,700,700);
				ChargerImage("./Images/7.png",158,575,0,0,700,700);
				ChargerImage("./Images/8.png",310,575,0,0,700,700);
				ChargerImage("./Images/9.png",462,575,0,0,700,700);
				while(c2==0){ /*attente d'un deuxième clic sur nombre de case*/
				while(c2==0) {
					if(SourisCliquee()) {
						SourisPosition();
						x2=_X;
						y2=_Y;
						/*création zone clic boutons taille plateau*/

						if((80<x2 && x2<151)&&(500<y2 && y2<579)) {
							nb_ligne_colonne=3;
							
						}
						if((232<x2 && x2<301)&&(500<y2 && y2<579)) {
							printf("bouton 4\n");
							nb_ligne_colonne=4;
						}
						if((384<x2 && x2<455)&&(500<y2 && y2<579)) {
							printf("bouton 5\n");
							nb_ligne_colonne=5;
						}	
						if((536<x2 && x2<607)&&(500<y2 && y2<579)) {
							printf("bouton 6\n");
							nb_ligne_colonne=6;
						}
						if((158<x2 && x2<229)&&(575<y2 && y2<654)){
							printf("bouton 7\n");
							nb_ligne_colonne=7;
						}
						if((310<x2 && x2<381)&&(575<y2 && y2<654)){
							printf("bouton 8\n");
							nb_ligne_colonne=8;
						}
						if((462<x2 && x2<533)&&(575<y2 && y2<654)){
							printf("bouton 9\n");
							nb_ligne_colonne=9;
						}
						c2++;
					}
				}
						FermerGraphique();
					grille(nb_ligne_colonne);
				
				}
		
			} else if ((206.5<x1 && x1<493.5) && (400<y1 && y1<460)) { /*1JVSIA*/

				printf("1vsIA\n");

				

				/*Affichage boutons Taille plateau*/

				ChargerImage("./Images/3.png",80,500,0,0,700,700);
				ChargerImage("./Images/4.png",232,500,0,0,700,700);
				ChargerImage("./Images/5.png",384,500,0,0,700,700);
				ChargerImage("./Images/6.png",536,500,0,0,700,700);
				ChargerImage("./Images/7.png",158,575,0,0,700,700);
				ChargerImage("./Images/8.png",310,575,0,0,700,700);
				ChargerImage("./Images/9.png",462,575,0,0,700,700);


				while(c2==0) {
					if(SourisCliquee()) {
						SourisPosition();
						x2=_X;
						y2=_Y;
						/*création zone clic boutons taille plateau*/

						if((80<x2 && x2<151)&&(500<y2 && y2<579)) {
							nb_ligne_colonne=3;
							
						}
						if((232<x2 && x2<301)&&(500<y2 && y2<579)) {
							printf("bouton 4\n");
							nb_ligne_colonne=4;
						}
						if((384<x2 && x2<455)&&(500<y2 && y2<579)) {
							printf("bouton 5\n");
							nb_ligne_colonne=5;
						}	
						if((536<x2 && x2<607)&&(500<y2 && y2<579)) {
							printf("bouton 6\n");
							nb_ligne_colonne=6;
						}
						if((158<x2 && x2<229)&&(575<y2 && y2<654)){
							printf("bouton 7\n");
							nb_ligne_colonne=7;
						}
						if((310<x2 && x2<381)&&(575<y2 && y2<654)){
							printf("bouton 8\n");
							nb_ligne_colonne=8;
						}
						if((462<x2 && x2<533)&&(575<y2 && y2<654)){
							printf("bouton 9\n");
							nb_ligne_colonne=9;
						}
						c2++;
					}
				}
				FermerGraphique();
				grilleia(nb_ligne_colonne);

				
			}	
			c1++;		
		}
	}


	}

