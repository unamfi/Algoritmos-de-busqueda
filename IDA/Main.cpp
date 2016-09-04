#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "IDAs.h"
main(){
	estadop inicial, final,meta;
	char opc;
	inicial.padre = NULL;
    do{
		printf("Dame la cantidad de filas: ");
		scanf("%i",&filas);
	}while(filas <= 2);

	printf("\n");
	do{
		printf("Dame la cantidad de columnas: ");  
		scanf("%i",&columnas);
	}while(columnas <= 2); 
	inicial = inicializaEdo(inicial);
	final = inicializaEdo(final);
	finall = final;
	localizarVacio(inicial);
	activaMov();
	while(1){
			 int i=1, subopc;
			 if(opc=='q')break;
             system("CLS");
			 printf("dame el estado inicial del Puzzle   (presiona 'q' para salir)\n\n");
             switch(opc){
                         case 'w':
							if(vacio.mov.abajo){
                              subopc =2;
							  inicial.puzzle = moverVacio(subopc,inicial.puzzle);
							}
							break;
							
                         case 's':
                            if(vacio.mov.arriba){  
							  subopc =1;
							  inicial.puzzle = moverVacio(subopc,inicial.puzzle);
                            }  
							break;
                         case 'a':
							if(vacio.mov.derecha){
                              subopc =4;
							  inicial.puzzle = moverVacio(subopc,inicial.puzzle);
                            }
							break;
                         case 'd':
							if(vacio.mov.izquierda){
                              subopc =3;
							  inicial.puzzle = moverVacio(subopc,inicial.puzzle);
                             }
							break;
                         }
             imprimeMatriz(inicial);
			 opc=getch();
    }
	
	
   	//inicial = generaRandom(inicial);
	printf("\n\n");
	//imprimeMatriz(final);
	printf("\n\n");
	//system("pause");
	printf("A*\n\nProcesando...");
	//if(agenda==NULL)
    meta = IDAs(inicial,final);
	printf("Solucion encontrada en la profundidad %i \n",profunSol);
	printf("Se expandieron %i estados \n",expandidos);
	printf("Se generaron %i estados \n",generados);
	
	system("pause");
}
