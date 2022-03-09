#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <math.h>
#include <time.h>
#include "menu.h"

#define tx 700
#define ty 700
#define SIZE_GRID 100
/*
void fin(){

    int x1,y1;
    int c=0;
    InitialiserGraphique();
    CreerFenetre(100,50,tx,ty);

    //Arrière-Plan
    ChargerImage("Images/papier.jpeg",0,0,0,0,700,700);

    //Logo Blocus
    ChargerImage("Images/blocus.png",0,50,0,0,700,700);

    //Boutons Choix Nombre  Joueurs
    ChargerImage("Images/rejouer.png",206.5,300,0,0,700,700);
    ChargerImage("Images/sortir.png",206.5,400,0,0,700,700);

    while (c<1) {
        if(SourisCliquee()) {
            SourisPosition();
        	x1=_X;
            y1=_Y;
            if ((206.5<x1 && x1<493.5) && (300<y1 && y1<360)) {
                
                printf("rejouer\n");
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


void jeuia(int nb_ligne_colonne){

	int V0=0;
	int Z0=0;
	int q=0;



	int plateau [nb_ligne_colonne] [nb_ligne_colonne]; //tableau verifiant état de la case
	int joueur=0; //changement J1_J2
	
	int tour=1;
	double PclicX=0;
	double PclicY=0;
	int avclicx=-1;
	int avclicy=0;
	int size_x=0;
	int size_y=0;
	int P1=0;
	int C1=1;
	int tableauX=0;
	int tableauY=0;

	int i, j;


	int P2=0;
	int C2=1;
	double PclicX2=0;
	double PclicY2=0;
	int avclicx2=-1;
	int avclicy2=0;
	int size_x2=0;
	int size_y2=0;
	int tableauX2=0;
	int tableauY2=0;

	int testv=0;
//affiche le tableau au départ
for(int i=0;i<nb_ligne_colonne;i++) {
	for (int j=0;j<nb_ligne_colonne;j++) {
		plateau[i][j] = 0;
		printf("%d|",plateau[i][j]);
	}
	printf("\n");
}





//Placement du joueur
	



	if (nb_ligne_colonne<=6) {
		printf("%d\n", nb_ligne_colonne);
		while(tour) {
			testv=0;
				if (tour>1) {
					for (i=avclicx-1; i<= avclicx+1; i++) {
			   			for (j=avclicy-1; j<= avclicy+1; j++) {
				    		if (plateau[i][j]==1) {
			   		    		testv++;
			   		    		if (avclicx==0 || avclicy==nb_ligne_colonne-1) {
			   			    		if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   				    		if (testv==4) {
			   					    		printf("joueur2 vainqueur \n");
			   					    		FermerGraphique();
			   					    		fin();
			   				    		}
			   			    		} else {
			   				   			if (testv==6) {
				   					    printf("joueur2 vainqueur \n");
				   					    FermerGraphique();
				   					    fin();
				   				    }
			   			  		}
			   		   		} else if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   			   		if (testv==6) {
			   						printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	} else {
			   			    	if (testv==9) {
			   				    	printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	}
			   	    	}
			    	}
	  	    	}
			}
			testv=0;
			while(P1<1) {
				DEB:
				if (SourisCliquee()) {
					PclicX = (double) _X;
					PclicY = (double) _Y;
					PclicX=PclicX/SIZE_GRID;
					PclicY=PclicY/SIZE_GRID;
					PclicX=floor(PclicX);
					PclicY=floor(PclicY);
					tableauX=PclicX; //int pour remplir le tableau
					tableauY=PclicY; //int pour remplir le tableau
					if (avclicx != -1) {
						size_x = tableauX-avclicx;
						size_y = tableauY-avclicy;
						if (size_x>1 || size_x<-1) {
							printf("case trop loin sur les X.");
							goto DEB;
						}else if (size_y>1 || size_y<-1) {
							printf("case trop loin sur les Y.");
							goto DEB;
						}
					}
					if(plateau[tableauX][tableauY]==0) {
						if(tour>1) {
							ChoisirCouleurDessin(CouleurParNom("white"));
							RemplirRectangle((avclicx*SIZE_GRID+1),(avclicy*SIZE_GRID+1),SIZE_GRID-2,SIZE_GRID-2);
							plateau[avclicx][avclicy]=0;
							printf("%d,%d\n",tableauX, tableauY );
							for(i=0;i<nb_ligne_colonne;i++) {
								for (j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}

						}
							if(plateau[tableauX][tableauY]==0) {
						ChargerImage("./Images/pion_police.png",(tableauX*SIZE_GRID),(tableauY*SIZE_GRID),0,0,SIZE_GRID,SIZE_GRID);
						P1++;
						plateau[tableauX][tableauY]=1;
						avclicx=tableauX;
						avclicy=tableauY;	
						for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}	
						}				

					} 

					}
				}

				while(C1<1) {
					if(SourisCliquee()) {
						SourisPosition();
						PclicX = (double) _X;
						PclicY = (double) _Y;
						PclicX=PclicX/SIZE_GRID;
						PclicY=PclicY/SIZE_GRID;
						PclicX=floor(PclicX);
						PclicY=floor(PclicY);
						tableauX=PclicX; //int pour remplir le tableau
						tableauY=PclicY; //int pour remplir le tableau
						if(plateau[tableauX][tableauY]==0) {
							ChargerImage("./Images/croix_police.png",(tableauX*SIZE_GRID),(tableauY*SIZE_GRID),0,0,SIZE_GRID,SIZE_GRID);
							plateau[tableauX][tableauY]=1;
							C1++;
							printf("\n");
							for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}
						} else {
							printf("case occupée\n");
						}
					}


				}
				testv=0;
				if (tour>1) {
					for (i=avclicx-1; i<= avclicx+1; i++) {
			   			for (j=avclicy-1; j<= avclicy+1; j++) {
				    		if (plateau[i][j]==1) {
			   		    		testv++;
			   		    		if (avclicx==0 || avclicy==nb_ligne_colonne-1) {
			   			    		if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   				    		if (testv==4) {
			   					    		printf("joueur2 vainqueur \n");
			   					    		FermerGraphique();
			   					    		fin();
			   				    		}
			   			    		} else {
			   				   			if (testv==6) {
				   					    printf("joueur2 vainqueur \n");
				   					    FermerGraphique();
				   					    fin();
				   				    }
			   			  		}
			   		   		} else if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   			   		if (testv==6) {
			   						printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	} else {
			   			    	if (testv==9) {
			   				    	printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	}
			   	    	}
			    	}
	  	    	}
			}
			testv=0;
			
			
			while(P2<1) {
				testv=0;
				if (tour>1) {
					for (i=avclicx2-1; i<= avclicx2+1; i++) {
			    		for (j=avclicy2-1; j<= avclicy2+1; j++) {
				    		if (plateau[i][j]==1) {
			   		    		testv++;
			   		    		if (avclicx2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    		if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   				    		if (testv==4) {
			   					    		printf("joueur1 vainqueur \n");
			   					    		FermerGraphique();
			   					    		fin();
			   				   			}
			   			    		} else {
			   				    		if (testv==6) {
			   					    	printf("joueur1 vainqueur \n");
			   					    	FermerGraphique();
			   					    	fin();
			   				    		}
			   			    		}
			   		    		} else if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   			   		if (testv==6) {
			   				    	printf("joueur1 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	} else {
			   			    	if (testv==9) {
			   				    	printf("joueur1 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	}
			   	    	}
			    	}
	  	    	}
			}
			testv=0;

				DEB2:
				if (V0==0) {
					int MAX = nb_ligne_colonne-1;
			        int MIN = 0;
			        srand(time(NULL));
			        int PclicX2 = rand()%(MAX+1-MIN)+MIN;
			        int PclicY2 = rand()%(MAX+1-MIN)+MIN;
			        printf("%d\t",PclicX2);
			        printf("%d\n",PclicY2);

			        
					tableauX2=PclicX2; //int pour remplir le tableau
					tableauY2=PclicY2; //int pour remplir le tableau
					if (avclicx2 != -1) {
						size_x2 = PclicX2-avclicx2;
						size_y2 = PclicY2-avclicy2;
						if (size_x2>1 || size_x2<-1) {
							printf("case trop loin sur les X.\n");
							goto DEB2;
						}
						if (size_y2>1 || size_y2<-1) {
							printf("case trop loin sur les Y.\n");
							goto DEB2;
						}
					}
					if(plateau[tableauX2][tableauY2]==0) {
						if(tour>1) {
							ChoisirCouleurDessin(CouleurParNom("white"));
							RemplirRectangle((avclicx2*SIZE_GRID+1),(avclicy2*SIZE_GRID+1),SIZE_GRID-2,SIZE_GRID-2);
							plateau[avclicx2][avclicy2]=0;
						}
						if(plateau[tableauX2][tableauY2]==0) {
						ChargerImage("./Images/pion_voleur.png",(tableauX2*SIZE_GRID),(tableauY2*SIZE_GRID),0,0,SIZE_GRID,SIZE_GRID);
						P2++;
						plateau[tableauX2][tableauY2]=1;
						avclicx2=tableauX2;
						avclicy2=tableauY2;	
						for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}
						}					

					} else if (avclicx2==tableauX2 && avclicy2==tableauY2){
						printf("pion deja la ! \n");
						goto DEB2;
					} else {
						printf("case occupé\n");
						goto DEB2;
					}

					V0++;
				}
			}
				
				while(C2<1) {
					IA:
					if(Z0==0) {
						printf("boucle\n");
						
						printf("%d\t",tableauX2);
				        printf("%d\n",tableauY2);
				        printf("%d\n",plateau[tableauX2][tableauY2]);


				        while(q < 1) {
				        int MAX = nb_ligne_colonne-1;
				        int MIN = 0;
				        srand(time(NULL));
				        int PclicX2 = rand()%(MAX+1-MIN)+MIN;
				        int PclicY2 = rand()%(MAX+1-MIN)+MIN;
				        tableauX2=PclicX2; //int pour remplir le tableau
						tableauY2=PclicY2; //int pour remplir le tableau
							if(plateau[tableauX2][tableauY2]==0) {
								printf("boucle\n");
								ChargerImage("./Images/croix_voleur.png",(tableauX2*SIZE_GRID),(tableauY2*SIZE_GRID),0,0,SIZE_GRID,SIZE_GRID);
								C2++;
								plateau[tableauX2][tableauY2]=3;
								q=2;
								for(int i=0;i<nb_ligne_colonne;i++) {
									for (int j=0;j<nb_ligne_colonne;j++) {
										
										printf("%d|",plateau[j][i]);
									}
									printf("\n");
									
								}
							} else if (avclicx2==tableauX2 && avclicy2==tableauY2){
								printf("CHUI LA \n");
								goto IA;

							} else {
								printf("case occupé\n");
								goto IA;
							}

						}
					Z0++;
					}



				}
				testv=0;
		if (tour>1) {
			for (i=avclicx2-1; i<= avclicx2+1; i++) {
			    for (j=avclicy2-1; j<= avclicy2+1; j++) {
				    if (plateau[i][j]==1) {
			   		    testv++;
			   		    if (avclicx2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   				    if (testv==4) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    } else {
			   				    if (testv==6) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    }
			   		    } else if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (testv==6) {
			   				    printf("joueur1 vainqueur \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    } else {
			   			    if (testv==9) {
			   				    printf("joueur1 vainqueur \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    }
			   	    }
			    }
	  	    }
		}
		testv=0;
			
		tour++;
		q=0;
		Z0=0;
		V0=0;
		P1=0;
		C1=0;
		P2=0;
		C2=0;
		}
	}
	if (nb_ligne_colonne>6) {
		printf("%d\n", nb_ligne_colonne);
		while(tour) {
			testv=0;
				if (tour>1) {
					for (i=avclicx-1; i<= avclicx+1; i++) {
			   			for (j=avclicy-1; j<= avclicy+1; j++) {
				    		if (plateau[i][j]==1) {
			   		    		testv++;
			   		    		if (avclicx==0 || avclicy==nb_ligne_colonne-1) {
			   			    		if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   				    		if (testv==4) {
			   					    		printf("joueur2 vainqueur \n");
			   					    		FermerGraphique();
			   					    		fin();
			   				    		}
			   			    		} else {
			   				   			if (testv==6) {
				   					    printf("joueur2 vainqueur \n");
				   					    FermerGraphique();
				   					    fin();
				   				    }
			   			  		}
			   		   		} else if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   			   		if (testv==6) {
			   						printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	} else {
			   			    	if (testv==9) {
			   				    	printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	}
			   	    	}
			    	}
	  	    	}
			}
			testv=0;
			while(P1<1) {
				DEB8:
				if (SourisCliquee()) {
					PclicX = (double) _X;
					PclicY = (double) _Y;
					PclicX=PclicX/(SIZE_GRID/1.5);
					PclicY=PclicY/(SIZE_GRID/1.5);
					PclicX=floor(PclicX);
					PclicY=floor(PclicY);
					tableauX=PclicX; //int pour remplir le tableau
					tableauY=PclicY; //int pour remplir le tableau
					if (avclicx != -1) {
						size_x = tableauX-avclicx;
						size_y = tableauY-avclicy;
						if (size_x>1 || size_x<-1) {
							printf("case trop loin sur les X.");
							goto DEB8;
						}else if (size_y>1 || size_y<-1) {
							printf("case trop loin sur les Y.");
							goto DEB8;
						}
					}
					if(plateau[tableauX][tableauY]==0) {
						if(tour>1) {
							ChoisirCouleurDessin(CouleurParNom("white"));
							RemplirRectangle((avclicx*(SIZE_GRID/1.5)+1),(avclicy*(SIZE_GRID/1.5)+1),(SIZE_GRID/1.5)-2,(SIZE_GRID/1.5)-2);
							plateau[avclicx][avclicy]=0;
							printf("%d,%d\n",tableauX, tableauY );
							for(i=0;i<nb_ligne_colonne;i++) {
								for (j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}

						}
							if(plateau[tableauX][tableauY]==0) {
						ChargerImage("./Images/pion_police6.png",(tableauX*(SIZE_GRID/1.5)),(tableauY*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
						P1++;
						plateau[tableauX][tableauY]=1;
						avclicx=tableauX;
						avclicy=tableauY;	
						for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}	
						}				

					} 

					}
				}

				while(C1<1) {
					if(SourisCliquee()) {
						SourisPosition();
						PclicX = (double) _X;
						PclicY = (double) _Y;
						PclicX=PclicX/(SIZE_GRID/1.5);
						PclicY=PclicY/(SIZE_GRID/1.5);
						PclicX=floor(PclicX);
						PclicY=floor(PclicY);
						tableauX=PclicX; //int pour remplir le tableau
						tableauY=PclicY; //int pour remplir le tableau
						if(plateau[tableauX][tableauY]==0) {
							ChargerImage("./Images/croix_police6.png",(tableauX*(SIZE_GRID/1.5)),(tableauY*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
							plateau[tableauX][tableauY]=1;
							C1++;
							printf("\n");
							for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}
						} else {
							printf("case occupée\n");
						}
					}


				}
				testv=0;
				if (tour>1) {
					for (i=avclicx-1; i<= avclicx+1; i++) {
			   			for (j=avclicy-1; j<= avclicy+1; j++) {
				    		if (plateau[i][j]==1) {
			   		    		testv++;
			   		    		if (avclicx==0 || avclicy==nb_ligne_colonne-1) {
			   			    		if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   				    		if (testv==4) {
			   					    		printf("joueur2 vainqueur \n");
			   					    		FermerGraphique();
			   					    		fin();
			   				    		}
			   			    		} else {
			   				   			if (testv==6) {
				   					    printf("joueur2 vainqueur \n");
				   					    FermerGraphique();
				   					    fin();
				   				    }
			   			  		}
			   		   		} else if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   			   		if (testv==6) {
			   						printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	} else {
			   			    	if (testv==9) {
			   				    	printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	}
			   	    	}
			    	}
	  	    	}
			}
			testv=0;
			
			
			while(P2<1) {
				testv=0;
				if (tour>1) {
					for (i=avclicx2-1; i<= avclicx2+1; i++) {
			    		for (j=avclicy2-1; j<= avclicy2+1; j++) {
				    		if (plateau[i][j]==1) {
			   		    		testv++;
			   		    		if (avclicx2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    		if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   				    		if (testv==4) {
			   					    		printf("joueur1 vainqueur \n");
			   					    		FermerGraphique();
			   					    		fin();
			   				   			}
			   			    		} else {
			   				    		if (testv==6) {
			   					    	printf("joueur1 vainqueur \n");
			   					    	FermerGraphique();
			   					    	fin();
			   				    		}
			   			    		}
			   		    		} else if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   			   		if (testv==6) {
			   				    	printf("joueur1 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	} else {
			   			    	if (testv==9) {
			   				    	printf("joueur1 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	}
			   	    	}
			    	}
	  	    	}
			}
			testv=0;

				DEB10:
				if (V0==0) {
					int MAX = nb_ligne_colonne-1;
			        int MIN = 0;
			        srand(time(NULL));
			        int PclicX2 = rand()%(MAX+1-MIN)+MIN;
			        int PclicY2 = rand()%(MAX+1-MIN)+MIN;
			        printf("%d\t",PclicX2);
			        printf("%d\n",PclicY2);

			        
					tableauX2=PclicX2; //int pour remplir le tableau
					tableauY2=PclicY2; //int pour remplir le tableau
					if (avclicx2 != -1) {
						size_x2 = PclicX2-avclicx2;
						size_y2 = PclicY2-avclicy2;
						if (size_x2>1 || size_x2<-1) {
							printf("case trop loin sur les X.\n");
							goto DEB10;
						}
						if (size_y2>1 || size_y2<-1) {
							printf("case trop loin sur les Y.\n");
							goto DEB10;
						}
					}
					if(plateau[tableauX2][tableauY2]==0) {
						if(tour>1) {
							ChoisirCouleurDessin(CouleurParNom("white"));
							RemplirRectangle((avclicx2*(SIZE_GRID/1.5)+1),(avclicy2*(SIZE_GRID/1.5)+1),(SIZE_GRID/1.5)-2,(SIZE_GRID/1.5)-2);
							plateau[avclicx2][avclicy2]=0;
						}
						if(plateau[tableauX2][tableauY2]==0) {
						ChargerImage("./Images/pion_voleur6.png",(tableauX2*(SIZE_GRID/1.5)),(tableauY2*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
						P2++;
						plateau[tableauX2][tableauY2]=1;
						avclicx2=tableauX2;
						avclicy2=tableauY2;	
						for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}
						}					

					} else if (avclicx2==tableauX2 && avclicy2==tableauY2){
						printf("pion deja la ! \n");
						goto DEB10;
					} else {
						printf("case occupé\n");
						goto DEB10;
					}

					V0++;
				}
			}
				
				while(C2<1) {
					IA10:
					if(Z0==0) {
						printf("boucle\n");
						
						printf("%d\t",tableauX2);
				        printf("%d\n",tableauY2);
				        printf("%d\n",plateau[tableauX2][tableauY2]);


				        while(q < 1) {
				        int MAX = nb_ligne_colonne-1;
				        int MIN = 0;
				        srand(time(NULL));
				        int PclicX2 = rand()%(MAX+1-MIN)+MIN;
				        int PclicY2 = rand()%(MAX+1-MIN)+MIN;
				        tableauX2=PclicX2; //int pour remplir le tableau
						tableauY2=PclicY2; //int pour remplir le tableau
							if(plateau[tableauX2][tableauY2]==0) {
								printf("boucle\n");
								ChargerImage("./Images/croix_voleur6.png",(tableauX2*(SIZE_GRID/1.5)),(tableauY2*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
								C2++;
								plateau[tableauX2][tableauY2]=3;
								q=2;
								for(int i=0;i<nb_ligne_colonne;i++) {
									for (int j=0;j<nb_ligne_colonne;j++) {
										
										printf("%d|",plateau[j][i]);
									}
									printf("\n");
									
								}
							} else if (avclicx2==tableauX2 && avclicy2==tableauY2){
								printf("CHUI LA \n");
								goto IA10;

							} else {
								printf("case occupé\n");
								goto IA10;
							}

						}
					Z0++;
					}



				}
				testv=0;
		if (tour>1) {
			for (i=avclicx2-1; i<= avclicx2+1; i++) {
			    for (j=avclicy2-1; j<= avclicy2+1; j++) {
				    if (plateau[i][j]==1) {
			   		    testv++;
			   		    if (avclicx2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   				    if (testv==4) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    } else {
			   				    if (testv==6) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    }
			   		    } else if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (testv==6) {
			   				    printf("joueur1 vainqueur \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    } else {
			   			    if (testv==9) {
			   				    printf("joueur1 vainqueur \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    }
			   	    }
			    }
	  	    }
		}
		testv=0;
			
		tour++;
		q=0;
		Z0=0;
		V0=0;
		P1=0;
		C1=0;
		P2=0;
		C2=0;
		}
	}




	Touche();
	}





void jeu(int nb_ligne_colonne){
	int plateau [nb_ligne_colonne] [nb_ligne_colonne]; //tableau verifiant état de la case
	int joueur=0; //changement J1_J2
	
	int tour=1;
	double PclicX=0;
	double PclicY=0;
	int avclicx=-1;
	int avclicy=0;
	int size_x=0;
	int size_y=0;
	int P1=0;
	int C1=1;
	int tableauX=0;
	int tableauY=0;

	int i, j;


	int P2=0;
	int C2=1;
	double PclicX2=0;
	double PclicY2=0;
	int avclicx2=-1;
	int avclicy2=0;
	int size_x2=0;
	int size_y2=0;
	int tableauX2=0;
	int tableauY2=0;

	int testv=0;
//affiche le tableau au départ
for(int i=0;i<nb_ligne_colonne;i++) {
	for (int j=0;j<nb_ligne_colonne;j++) {
		plateau[i][j] = 0;
		printf("%d|",plateau[i][j]);
	}
	printf("\n");
}





//Placement du joueur
	


//ecrire tableau 
	/*plateau[tabxJ2C][tabyJ2C]=4;
	printf("\n");
	for(int i=0;i<nb_ligne_colonne;i++) {
		for (int j=0;j<nb_ligne_colonne;j++) {
			printf("%d|",plateau[j][i]);
		}
		printf("\n");
	}*/

	//rotation J1/J2 + rotation Pion/Croix
	/*if (joueur==1) {
		joueur=2;
	} else {
		joueur=1;
	}*/

	// grille <= 6
/*
	if (nb_ligne_colonne<=6) {
		printf("%d\n", nb_ligne_colonne);
		while(tour) {
			testv=0;
				if (tour>1) {
					for (i=avclicx-1; i<= avclicx+1; i++) {
			   			for (j=avclicy-1; j<= avclicy+1; j++) {
				    		if (plateau[i][j]==1) {
			   		    		testv++;
			   		    		if (avclicx==0 || avclicy==nb_ligne_colonne-1) {
			   			    		if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   				    		if (testv==4) {
			   					    		printf("joueur2 vainqueur \n");
			   					    		FermerGraphique();
			   					    		fin();
			   				    		}
			   			    		} else {
			   				   			if (testv==6) {
				   					    printf("joueur2 vainqueur \n");
				   					    FermerGraphique();
				   					    fin();
				   				    }
			   			  		}
			   		   		} else if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   			   		if (testv==6) {
			   						printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	} else {
			   			    	if (testv==9) {
			   				    	printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	}
			   	    	}
			    	}
	  	    	}
			}
			testv=0;
			while(P1<1) {
				DEB:
				if (SourisCliquee()) {
					PclicX = (double) _X;
					PclicY = (double) _Y;
					PclicX=PclicX/SIZE_GRID;
					PclicY=PclicY/SIZE_GRID;
					PclicX=floor(PclicX);
					PclicY=floor(PclicY);
					tableauX=PclicX; //int pour remplir le tableau
					tableauY=PclicY; //int pour remplir le tableau
					if (avclicx != -1) {
						size_x = tableauX-avclicx;
						size_y = tableauY-avclicy;
						if (size_x>1 || size_x<-1) {
							printf("case trop loin sur les X.");
							goto DEB;
						}else if (size_y>1 || size_y<-1) {
							printf("case trop loin sur les Y.");
							goto DEB;
						}
					}
					if(plateau[tableauX][tableauY]==0) {
						if(tour>1) {
							ChoisirCouleurDessin(CouleurParNom("white"));
							RemplirRectangle((avclicx*SIZE_GRID+1),(avclicy*SIZE_GRID+1),SIZE_GRID-2,SIZE_GRID-2);
							plateau[avclicx][avclicy]=0;
							printf("%d,%d\n",tableauX, tableauY );
							for(i=0;i<nb_ligne_colonne;i++) {
								for (j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}

						}
							if(plateau[tableauX][tableauY]==0) {
						ChargerImage("./Images/pion_police.png",(tableauX*SIZE_GRID),(tableauY*SIZE_GRID),0,0,SIZE_GRID,SIZE_GRID);
						P1++;
						plateau[tableauX][tableauY]=1;
						avclicx=tableauX;
						avclicy=tableauY;	
						for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}	
						}				

					} 

					}
				}

				while(C1<1) {
					if(SourisCliquee()) {
						SourisPosition();
						PclicX = (double) _X;
						PclicY = (double) _Y;
						PclicX=PclicX/SIZE_GRID;
						PclicY=PclicY/SIZE_GRID;
						PclicX=floor(PclicX);
						PclicY=floor(PclicY);
						tableauX=PclicX; //int pour remplir le tableau
						tableauY=PclicY; //int pour remplir le tableau
						if(plateau[tableauX][tableauY]==0) {
							ChargerImage("./Images/croix_police.png",(tableauX*SIZE_GRID),(tableauY*SIZE_GRID),0,0,SIZE_GRID,SIZE_GRID);
							plateau[tableauX][tableauY]=1;
							C1++;
							for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}
						} else {
							printf("case occupée\n");
						}
					}


				}
				testv=0;
				if (tour>1) {
					for (i=avclicx-1; i<= avclicx+1; i++) {
			   			for (j=avclicy-1; j<= avclicy+1; j++) {
				    		if (plateau[i][j]==1) {
			   		    		testv++;
			   		    		if (avclicx==0 || avclicy==nb_ligne_colonne-1) {
			   			    		if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   				    		if (testv==4) {
			   					    		printf("joueur2 vainqueur \n");
			   					    		FermerGraphique();
			   					    		fin();
			   				    		}
			   			    		} else {
			   				   			if (testv==6) {
				   					    printf("joueur2 vainqueur \n");
				   					    FermerGraphique();
				   					    fin();
				   				    }
			   			  		}
			   		   		} else if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   			   		if (testv==6) {
			   						printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	} else {
			   			    	if (testv==9) {
			   				    	printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	}
			   	    	}
			    	}
	  	    	}
			}
			testv=0;
			
			
			while(P2<1) {
				testv=0;
		if (tour>1) {
			for (i=avclicx2-1; i<= avclicx2+1; i++) {
			    for (j=avclicy2-1; j<= avclicy2+1; j++) {
				    if (plateau[i][j]==1) {
			   		    testv++;
			   		    if (avclicx2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   				    if (testv==4) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    } else {
			   				    if (testv==6) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    }
			   		    } else if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (testv==6) {
			   				    printf("joueur1 vainqueur \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    } else {
			   			    if (testv==9) {
			   				    printf("joueur1 vainqueur \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    }
			   	    }
			    }
	  	    }
		}
		testv=0;
				DEB2:
				if (SourisCliquee()) {
					PclicX2 = (double) _X;
					PclicY2 = (double) _Y;
					PclicX2=PclicX2/SIZE_GRID;
					PclicY2=PclicY2/SIZE_GRID;
					PclicX2=floor(PclicX2);
					PclicY2=floor(PclicY2);
					tableauX2=PclicX2; //int pour remplir le tableau
					tableauY2=PclicY2; //int pour remplir le tableau
					if (avclicx2 != -1) {
						size_x2 = PclicX2-avclicx2;
						size_y2 = PclicY2-avclicy2;
						if (size_x2>1 || size_x2<-1) {
							printf("case trop loin sur les X.");
							goto DEB2;
						}
						if (size_y2>1 || size_y2<-1) {
							printf("case trop loin sur les Y.");
							goto DEB2;
						}
					}
					if(plateau[tableauX2][tableauY2]==0) {
						if(tour>1) {
							ChoisirCouleurDessin(CouleurParNom("white"));
							RemplirRectangle((avclicx2*SIZE_GRID+1),(avclicy2*SIZE_GRID+1),SIZE_GRID-2,SIZE_GRID-2);
							plateau[avclicx2][avclicy2]=0;
						}
						if(plateau[tableauX2][tableauY2]==0) {
						ChargerImage("./Images/pion_voleur.png",(tableauX2*SIZE_GRID),(tableauY2*SIZE_GRID),0,0,SIZE_GRID,SIZE_GRID);
						P2++;
						plateau[tableauX2][tableauY2]=1;
						avclicx2=tableauX2;
						avclicy2=tableauY2;	
						for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}
						}					

					} else {
						printf("case occupée\n");
					}
				}
			}

				while(C2<1) {
					if(SourisCliquee()) {
						PclicX2 = (double) _X;
						PclicY2 = (double) _Y;
						PclicX2=PclicX2/SIZE_GRID;
						PclicY2=PclicY2/SIZE_GRID;
						PclicX2=floor(PclicX2);
						PclicY2=floor(PclicY2);
						tableauX2=PclicX2; //int pour remplir le tableau
						tableauY2=PclicY2; //int pour remplir le tableau
						if(plateau[tableauX2][tableauY2]==0) {
							ChargerImage("./Images/croix_voleur.png",(tableauX2*SIZE_GRID),(tableauY2*SIZE_GRID),0,0,SIZE_GRID,SIZE_GRID);
							
							C2++;
								plateau[tableauX2][tableauY2]=1;
							for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}
						} else {
							printf("case occupée\n");
						}
					}



				}		testv=0;
		if (tour>1) {
			for (i=avclicx2-1; i<= avclicx2+1; i++) {
			    for (j=avclicy2-1; j<= avclicy2+1; j++) {
				    if (plateau[i][j]==1) {
			   		    testv++;
			   		    if (avclicx2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   				    if (testv==4) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    } else {
			   				    if (testv==6) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    }
			   		    } else if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (testv==6) {
			   				    printf("joueur1 vainqueur \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    } else {
			   			    if (testv==9) {
			   				    printf("joueur1 vainqueur \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    }
			   	    }
			    }
	  	    }
		}
		testv=0;
			
		tour++;
		P1=0;
		C1=0;
		P2=0;
		C2=0;
		}
	}
	if (nb_ligne_colonne>6) {
			while(tour) {
				testv=0;
				if (tour>1) {
					for (i=avclicx-1; i<= avclicx+1; i++) {
			   			for (j=avclicy-1; j<= avclicy+1; j++) {
				    		if (plateau[i][j]==1) {
			   		    		testv++;
			   		    		if (avclicx==0 || avclicy==nb_ligne_colonne-1) {
			   			    		if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   				    		if (testv==4) {
			   					    		printf("joueur2 vainqueur \n");
			   					    		FermerGraphique();
			   					    		fin();
			   				    		}
			   			    		} else {
			   				   			if (testv==6) {
				   					    printf("joueur2 vainqueur \n");
				   					    FermerGraphique();
				   					    fin();
				   				    }
			   			  		}
			   		   		} else if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   			   		if (testv==6) {
			   						printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	} else {
			   			    	if (testv==9) {
			   				    	printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	}
			   	    	}
			    	}
	  	    	}
			}
			testv=0;
				while(P1<1) {
					DEB3:
					if (SourisCliquee()) {
						PclicX = (double) _X;
						PclicY = (double) _Y;
						PclicX=PclicX/(SIZE_GRID/1.5);
						PclicY=PclicY/(SIZE_GRID/1.5);
						PclicX=floor(PclicX);
						PclicY=floor(PclicY);
						tableauX=PclicX; //int pour remplir le tableau
						tableauY=PclicY; //int pour remplir le tableau
						if (avclicx != -1) {
							size_x = tableauX-avclicx;
							size_y = tableauY-avclicy;
							if (size_x>1 || size_x<-1) {
								printf("case trop loin sur les X.\n");
								goto DEB3;
							}else if (size_y>1 || size_y<-1) {
								printf("case trop loin sur les Y.\n");
								goto DEB3;
							}
						}
						if(plateau[tableauX][tableauY]==0) {
							if(tour>1) {
								ChoisirCouleurDessin(CouleurParNom("white"));
								RemplirRectangle((avclicx*(SIZE_GRID/1.5)+1),(avclicy*(SIZE_GRID/1.5)+1),(SIZE_GRID/1.5)-2,(SIZE_GRID/1.5)-2);
								plateau[avclicx][avclicy]=0;
								printf("\n");
								for(int i=0;i<nb_ligne_colonne;i++) {
									for (int j=0;j<nb_ligne_colonne;j++) {
										printf("%d|",plateau[j][i]);
									}
									printf("\n");
								}

							}
							if(plateau[tableauX][tableauY]==0) {
								ChargerImage("./Images/pion_police6.png",(tableauX*(SIZE_GRID/1.5)),(tableauY*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
								P1++;
								plateau[tableauX][tableauY]=1;
								avclicx=tableauX;
								avclicy=tableauY;	
								printf("\n");
								for(int i=0;i<nb_ligne_colonne;i++) {
									for (int j=0;j<nb_ligne_colonne;j++) {
										
										printf("%d|",plateau[j][i]);
									}
									printf("\n");
								}	
							}				

						} else {
							printf("case occupée\n");
						}

					}
				}

				while(C1<1) {
					if(SourisCliquee()) {
						SourisPosition();
						PclicX = (double) _X;
						PclicY = (double) _Y;
						PclicX=PclicX/(SIZE_GRID/1.5);
						PclicY=PclicY/(SIZE_GRID/1.5);
						PclicX=floor(PclicX);
						PclicY=floor(PclicY);
						tableauX=PclicX; //int pour remplir le tableau
						tableauY=PclicY; //int pour remplir le tableau
						if(plateau[tableauX][tableauY]==0) {
							ChargerImage("./Images/croix_police6.png",(tableauX*(SIZE_GRID/1.5)),(tableauY*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
							plateau[tableauX][tableauY]=3;
							C1++;
							printf("\n");
							for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}

						} else {
							printf("case occupée\n");
						}
					}

				}
			testv=0;
				if (tour>1) {
					for (i=avclicx-1; i<= avclicx+1; i++) {
			   			for (j=avclicy-1; j<= avclicy+1; j++) {
				    		if (plateau[i][j]==1) {
			   		    		testv++;
			   		    		if (avclicx==0 || avclicy==nb_ligne_colonne-1) {
			   			    		if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   				    		if (testv==4) {
			   					    		printf("joueur2 vainqueur \n");
			   					    		FermerGraphique();
			   					    		fin();
			   				    		}
			   			    		} else {
			   				   			if (testv==6) {
				   					    printf("joueur2 vainqueur \n");
				   					    FermerGraphique();
				   					    fin();
				   				    }
			   			  		}
			   		   		} else if (avclicy==0 || avclicy==nb_ligne_colonne-1) {
			   			   		if (testv==6) {
			   						printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	} else {
			   			    	if (testv==9) {
			   				    	printf("joueur2 vainqueur \n");
			   				    	FermerGraphique();
			   				    	fin();
			   			    	}
			   		    	}
			   	    	}
			    	}
	  	    	}
			}
			testv=0;
			
			while(P2<1) {
				testv=0;
		if (tour>1) {
			for (i=avclicx2-1; i<= avclicx2+1; i++) {
			    for (j=avclicy2-1; j<= avclicy2+1; j++) {
				    if (plateau[i][j]==1) {
			   		    testv++;
			   		    if (avclicx2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   				    if (testv==4) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    } else {
			   				    if (testv==6) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    }
			   		    } else if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (testv==6) {
			   				    printf("joueur1 vainqueur \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    } else {
			   			    if (testv==9) {
			   				    printf("joueur1 vainqueur \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    }
			   	    }
			    }
	  	    }
		}
		testv=0;
				DEB4:
				if (SourisCliquee()) {
					PclicX2 = (double) _X;
					PclicY2 = (double) _Y;
					PclicX2=PclicX2/(SIZE_GRID/1.5);
					PclicY2=PclicY2/(SIZE_GRID/1.5);
					PclicX2=floor(PclicX2);
					PclicY2=floor(PclicY2);
					tableauX2=PclicX2; //int pour remplir le tableau
					tableauY2=PclicY2; //int pour remplir le tableau
					if (avclicx2 != -1) {
						size_x2 = PclicX2-avclicx2;
						size_y2 = PclicY2-avclicy2;
						if (size_x2>1 || size_x2<-1) {
							printf("case trop loin sur les X.\n");
							goto DEB4;
						}
						if (size_y2>1 || size_y2<-1) {
							printf("case trop loin sur les Y.\n");
							goto DEB4;
						}
					}
					if(plateau[tableauX2][tableauY2]==0) {
						if(tour>1) {
							ChoisirCouleurDessin(CouleurParNom("white"));
							RemplirRectangle((avclicx2*(SIZE_GRID/1.5)+1),(avclicy2*(SIZE_GRID/1.5)+1),(SIZE_GRID/1.5)-2,(SIZE_GRID/1.5)-2);
							plateau[avclicx2][avclicy2]=0;
						}
						if(plateau[tableauX2][tableauY2]==0) {
							ChargerImage("./Images/pion_voleur6.png",(tableauX2*(SIZE_GRID/1.5)),(tableauY2*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
							P2++;
							plateau[tableauX2][tableauY2]=2;
							avclicx2=tableauX2;
							avclicy2=tableauY2;	
							printf("\n");
							for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
										
									printf("%d|",plateau[j][i]);
								}
									printf("\n");
							}
						}					

					} else {
						printf("case occupée\n");
					}
				}
			}

				while(C2<1) {
					if(SourisCliquee()) {
						PclicX2 = (double) _X;
						PclicY2 = (double) _Y;
						PclicX2=PclicX2/(SIZE_GRID/1.5);
						PclicY2=PclicY2/(SIZE_GRID/1.5);
						PclicX2=floor(PclicX2);
						PclicY2=floor(PclicY2);
						tableauX2=PclicX2; //int pour remplir le tableau
						tableauY2=PclicY2; //int pour remplir le tableau
						if(plateau[tableauX2][tableauY2]==0) {
							ChargerImage("./Images/croix_voleur6.png",(tableauX2*(SIZE_GRID/1.5)),(tableauY2*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
							C2++;
							plateau[tableauX2][tableauY2]=3;
							printf("\n");
							for(int i=0;i<nb_ligne_colonne;i++) {
								for (int j=0;j<nb_ligne_colonne;j++) {
									
									printf("%d|",plateau[j][i]);
								}
								printf("\n");
							}
						} else {
							printf("case occupée\n");
						}
					}


				}
				testv=0;
		if (tour>1) {
			for (i=avclicx2-1; i<= avclicx2+1; i++) {
			    for (j=avclicy2-1; j<= avclicy2+1; j++) {
				    if (plateau[i][j]==1) {
			   		    testv++;
			   		    if (avclicx2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   				    if (testv==4) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    } else {
			   				    if (testv==6) {
			   					    printf("joueur1 vainqueur \n");
			   					    FermerGraphique();
			   					    fin();
			   				    }
			   			    }
			   		    } else if (avclicy2==0 || avclicy2==nb_ligne_colonne-1) {
			   			    if (testv==6) {
			   				    printf("joueur1 vainqueur \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    } else {
			   			    if (testv==9) {
			   				    printf("joueur vainqueur1 \n");
			   				    FermerGraphique();
			   				    fin();
			   			    }
			   		    }
			   	    }
			    }
	  	    }
		}
		testv=0;
			tour++;
			P1=0;
			C1=0;
			P2=0;
			C2=0;
		}
	}




	Touche();
}





void grille(int nb_ligne_colonne) {

	int x,y;
	int c=0;
	if(nb_ligne_colonne<=6){  
		InitialiserGraphique();
		CreerFenetre(100,50,SIZE_GRID*nb_ligne_colonne,SIZE_GRID*nb_ligne_colonne);  
		for (int i = 0; i < nb_ligne_colonne; i++){
			for (int j = 0; j < nb_ligne_colonne; j++) {
				DessinerRectangle(j * (SIZE_GRID), i * (SIZE_GRID), SIZE_GRID, SIZE_GRID);
			}
		}
	}

	if(nb_ligne_colonne>6){
		InitialiserGraphique();
		CreerFenetre(100,50,(SIZE_GRID/1.5)*nb_ligne_colonne,(SIZE_GRID/1.5)*nb_ligne_colonne);
		for (int i = 0; i < nb_ligne_colonne; i++){
			for (int j = 0; j < nb_ligne_colonne; j++) {       
				DessinerRectangle(j * (SIZE_GRID/1.5), i * (SIZE_GRID/1.5), SIZE_GRID/1.5, SIZE_GRID/1.5);
			}
		}
	}

	jeu(nb_ligne_colonne);
}
void grilleia(int nb_ligne_colonne) {

	int x,y;
	int c=0;
	if(nb_ligne_colonne<=6){  
		InitialiserGraphique();
		CreerFenetre(100,50,SIZE_GRID*nb_ligne_colonne,SIZE_GRID*nb_ligne_colonne);  
		for (int i = 0; i < nb_ligne_colonne; i++){
			for (int j = 0; j < nb_ligne_colonne; j++) {
				DessinerRectangle(j * (SIZE_GRID), i * (SIZE_GRID), SIZE_GRID, SIZE_GRID);
			}
		}
	}

	if(nb_ligne_colonne>6){
		InitialiserGraphique();
		CreerFenetre(100,50,(SIZE_GRID/1.5)*nb_ligne_colonne,(SIZE_GRID/1.5)*nb_ligne_colonne);
		for (int i = 0; i < nb_ligne_colonne; i++){
			for (int j = 0; j < nb_ligne_colonne; j++) {       
				DessinerRectangle(j * (SIZE_GRID/1.5), i * (SIZE_GRID/1.5), SIZE_GRID/1.5, SIZE_GRID/1.5);
			}
		}
	}

	jeuia(nb_ligne_colonne);
}



//dessine le meunu + appel fonction pour dessiner grille
void menu(void) {


	//Déclaration Variables Fond d'écran
	int couleur1, couleur2, couleur3, couleur4;

	//Déclaration Varaibles Souris
	char t[50];
	int x1,y1,x2,y2;
	int c1=0;
	int c2=0;
	int nb_ligne_colonne;
	int ia;

	InitialiserGraphique();
	CreerFenetre(100,100,tx,ty);

	//Arrière-Plan
	ChargerImage("./Images/papier.jpeg",0,0,0,0,700,700);

	//Logo Blocus
	ChargerImage("./Images/blocus.png",0,50,0,0,700,700);

	//Boutons Choix Nombre  Joueurs
	ChargerImage("./Images/J1vJ2.png",206.5,300,0,0,700,700);
	ChargerImage("./Images/J1vIA.png",206.5,400,0,0,700,700);

	//phraseaccueil
	ChargerImage("./Images/phrase.png",130,225,0,0,700,700);

	//Designed by
	couleur1=CouleurParNom("black");
	ChoisirCouleurDessin(couleur1);
	EcrireTexte(242,675,"Design by Corentin R. and Nicolas A.",0);

	//Zone de clic 
	while(c1==0){
		if(SourisCliquee()) {
			SourisPosition();
			x1=_X;
			y1=_Y;

			if ((206.5<x1 && x1<493.5) && (300<y1 && y1<360)) {
				printf("1vs1\n"); //1VS1

				ia=0;

				//Affichage boutons Taille plateau
				ChargerImage("./Images/3.png",80,500,0,0,700,700);
				ChargerImage("./Images/4.png",232,500,0,0,700,700);
				ChargerImage("./Images/5.png",384,500,0,0,700,700);
				ChargerImage("./Images/6.png",536,500,0,0,700,700);
				ChargerImage("./Images/7.png",158,575,0,0,700,700);
				ChargerImage("./Images/8.png",310,575,0,0,700,700);
				ChargerImage("./Images/9.png",462,575,0,0,700,700);
				while(c2==0){ //attente d'un deuxième clic sur nombre de case
					if(SourisCliquee()) {
						SourisPosition();
						x2=_X;
						y2=_Y;
						//création zone clic boutons taille plateau
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
							FermerGraphique();
						grille(nb_ligne_colonne);
				
						c2++;
					}
					
				}
		
			} else if ((206.5<x1 && x1<493.5) && (400<y1 && y1<460)) { //1JVSIA
				printf("1vsIA\n");

				ia=1;

				//Affichage boutons Taille plateau
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
						//création zone clic boutons taille plateau
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
						FermerGraphique();
						grilleia(nb_ligne_colonne);
						
				
						c2++;
					}
				}

				
			}	
			c1++;		
		}
	}


	}




/**/

int main(int argc , char ** argv) {




	menu();
	



	return EXIT_SUCCESS;
}








//A montrer dans le rapport 
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