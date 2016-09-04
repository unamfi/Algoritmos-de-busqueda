#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "dfs.h"

main(){
	estadop inicial, final,meta;

	inicial.padre = NULL;
	inicial.profundidad=0;
	
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
	localizarVacio(inicial);
	activaMov();
    while(1){
			 int i=1, subopc;
             system("CLS");
			 printf("dame el estado inicial del Puzzle   (presiona 'q' para salir)\n\n");
             if(opc=='q')break;
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
						 //estado = moverVacio(subopc,estado);
             //printf("\n\naqui llego\n\n");
             imprimeMatriz(inicial);
			 opc=getch();
             //imprimeMatriz(estado->padre);
    }
	imprimeMatriz(inicial);

	printf("\n\n");
	printf("\n\n");
	printf("DFS\n\nProcesando...\n\n");
	Push(&agenda,inicial);
	meta = DFS(inicial,final);
	printf("Se expandieron %i estados \n",expandidos);
	printf("Se generaron %i estados \n",generados);
	
	system("pause");

}
