#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <math.h>

#include "grille.h"
#include "fin.h"
#include "jeux.h"

#define tx 700
#define ty 700
#define SIZE_GRID 100
void jeu(int nb_ligne_colonne){
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
				if (SourisCliquee()) {
					PclicX2 = (double) _X;
					PclicY2 = (double) _Y;
					PclicX2=PclicX2/SIZE_GRID;
					PclicY2=PclicY2/SIZE_GRID;
					PclicX2=floor(PclicX2);
					PclicY2=floor(PclicY2);
					tableauX2=PclicX2; /*int pour remplir le tableau*/
					tableauY2=PclicY2; /*int pour remplir le tableau*/
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
						for(i=0;i<nb_ligne_colonne;i++) {
								for (j=0;j<nb_ligne_colonne;j++) {
									
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
						tableauX2=PclicX2; /*int pour remplir le tableau*/
						tableauY2=PclicY2; /*int pour remplir le tableau*/
						if(plateau[tableauX2][tableauY2]==0) {
							ChargerImage("./Images/croix_voleur.png",(tableauX2*SIZE_GRID),(tableauY2*SIZE_GRID),0,0,SIZE_GRID,SIZE_GRID);
							
							C2++;
								plateau[tableauX2][tableauY2]=1;
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
						tableauX=PclicX; /*int pour remplir le tableau*/
						tableauY=PclicY; /*int pour remplir le tableau*/
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
								printf("\n");
								for(i=0;i<nb_ligne_colonne;i++) {
									for (j=0;j<nb_ligne_colonne;j++) {
										
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
						tableauX=PclicX; /*int pour remplir le tableau*/
						tableauY=PclicY; /*int pour remplir le tableau*/
						if(plateau[tableauX][tableauY]==0) {
							ChargerImage("./Images/croix_police6.png",(tableauX*(SIZE_GRID/1.5)),(tableauY*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
							plateau[tableauX][tableauY]=3;
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
				DEB4:
				if (SourisCliquee()) {
					PclicX2 = (double) _X;
					PclicY2 = (double) _Y;
					PclicX2=PclicX2/(SIZE_GRID/1.5);
					PclicY2=PclicY2/(SIZE_GRID/1.5);
					PclicX2=floor(PclicX2);
					PclicY2=floor(PclicY2);
					tableauX2=PclicX2; /*int pour remplir le tableau*/
					tableauY2=PclicY2; /*int pour remplir le tableau*/
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
							for(i=0;i<nb_ligne_colonne;i++) {
								for (j=0;j<nb_ligne_colonne;j++) {
										
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
						tableauX2=PclicX2; /*int pour remplir le tableau*/
						tableauY2=PclicY2; /*int pour remplir le tableau*/
						if(plateau[tableauX2][tableauY2]==0) {
							ChargerImage("./Images/croix_voleur6.png",(tableauX2*(SIZE_GRID/1.5)),(tableauY2*(SIZE_GRID/1.5)),0,0,(SIZE_GRID/1.5),(SIZE_GRID/1.5));
							C2++;
							plateau[tableauX2][tableauY2]=3;
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

