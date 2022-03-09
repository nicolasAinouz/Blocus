#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <math.h>
#include <time.h>
#include "fin.h"
#include "grilleia.h"
#include "jeux.h"

#define tx 700
#define ty 700
#define SIZE_GRID 100
void jeuia(int nb_ligne_colonne){

	int V0=0;
	int Z0=0;
	int q=0;



	int plateau [nb_ligne_colonne] [nb_ligne_colonne]; /*tableau verifiant état de la case*/

	
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
/*affiche le tableau au départ*/
for(i=0;i<nb_ligne_colonne;i++) {
	for (j=0;j<nb_ligne_colonne;j++) {
		plateau[i][j] = 0;
		printf("%d|",plateau[i][j]);
	}
	printf("\n");
}





/*Placement du joueur*/

	



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
					tableauX=PclicX; /*int pour remplir le tableau*/

					tableauY=PclicY; /*int pour remplir le tableau*/

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
						for(i=0;i<nb_ligne_colonne;i++) {
								for (j=0;j<nb_ligne_colonne;j++) {
									
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
						tableauX=PclicX; /*int pour remplir le tableau*/

						tableauY=PclicY; /*int pour remplir le tableau*/

						if(plateau[tableauX][tableauY]==0) {
							ChargerImage("./Images/croix_police.png",(tableauX*SIZE_GRID),(tableauY*SIZE_GRID),0,0,SIZE_GRID,SIZE_GRID);
							plateau[tableauX][tableauY]=1;
							C1++;
							printf("\n");
							for(i=0;i<nb_ligne_colonne;i++) {
								for (j=0;j<nb_ligne_colonne;j++) {
									
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
			        PclicX2 = (int)rand()%(MAX+1-MIN)+MIN;
			        PclicY2 = (int)rand()%(MAX+1-MIN)+MIN;
			        printf("%f\t",PclicX2);
			        printf("%f\n",PclicY2);

			        
					tableauX2=PclicX2; /*int pour remplir le tableau*/

					tableauY2=PclicY2; /*int pour remplir le tableau*/

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
						for(i=0;i<nb_ligne_colonne;i++) {
								for (j=0;j<nb_ligne_colonne;j++) {
									
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
				        PclicX2 = (int)rand()%(MAX+1-MIN)+MIN;
				        PclicY2 = (int)rand()%(MAX+1-MIN)+MIN;
				        tableauX2=PclicX2; /*int pour remplir le tableau*/

						tableauY2=PclicY2; /*int pour remplir le tableau*/

							if(plateau[tableauX2][tableauY2]==0) {
								printf("boucle\n");
								ChargerImage("./Images/croix_voleur.png",(tableauX2*SIZE_GRID),(tableauY2*SIZE_GRID),0,0,SIZE_GRID,SIZE_GRID);
								C2++;
								plateau[tableauX2][tableauY2]=3;
								q=2;
								for(i=0;i<nb_ligne_colonne;i++) {
									for (j=0;j<nb_ligne_colonne;j++) {
										
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
					tableauX=PclicX; /*int pour remplir le tableau*/

					tableauY=PclicY; /*int pour remplir le tableau*/

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
						for(i=0;i<nb_ligne_colonne;i++) {
								for (j=0;j<nb_ligne_colonne;j++) {
									
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
						tableauX=PclicX; /*int pour remplir le tableau*/

						tableauY=PclicY; /*int pour remplir le tableau*/

						if(plateau[tableauX][tableauY]==0) {
							ChargerImage("./Images/croix_police6.png",(tableauX*(SIZE_GRID/1.5)),(tableauY*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
							plateau[tableauX][tableauY]=1;
							C1++;
							printf("\n");
							for(i=0;i<nb_ligne_colonne;i++) {
								for (j=0;j<nb_ligne_colonne;j++) {
									
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
			        PclicX2 = (int)rand()%(MAX+1-MIN)+MIN;
			        PclicY2 = (int)rand()%(MAX+1-MIN)+MIN;
			        printf("%f\t",PclicX2);
			        printf("%f\n",PclicY2);

			        
					tableauX2=PclicX2; /*int pour remplir le tableau*/

					tableauY2=PclicY2; /*int pour remplir le tableau*/

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
						for(i=0;i<nb_ligne_colonne;i++) {
								for (j=0;j<nb_ligne_colonne;j++) {
									
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
				        PclicX2 = (int)rand()%(MAX+1-MIN)+MIN;
				        PclicY2 = (int)rand()%(MAX+1-MIN)+MIN;
				        tableauX2=PclicX2; /*int pour remplir le tableau*/

						tableauY2=PclicY2; /*int pour remplir le tableau*/

							if(plateau[tableauX2][tableauY2]==0) {
								printf("boucle\n");
								ChargerImage("./Images/croix_voleur6.png",(tableauX2*(SIZE_GRID/1.5)),(tableauY2*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
								C2++;
								plateau[tableauX2][tableauY2]=3;
								q=2;
								for(i=0;i<nb_ligne_colonne;i++) {
									for (j=0;j<nb_ligne_colonne;j++) {
										
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
