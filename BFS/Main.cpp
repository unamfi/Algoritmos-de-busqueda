#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "bfs.h"
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
	
	
   	//inicial = generaRandom(inicial);
	printf("\n\n");
	//imprimeMatriz(final);
	printf("\n\n");
	//system("pause");
	printf("Breadth First Search\n\nProcesando...");
	//if(agenda==NULL)
	Anadir(&primero,&ultimo,inicial);
	meta = BFS(inicial,final);
	printf("Se expandieron %i estados \n",expandidos);
	printf("Se generaron %i estados \n",generados);
	//imprimeMatriz(meta.puzzle);
	/*estadop *aux2;
	  aux2 = &meta;
	  aux2 = aux2->padre;
	  imprimeMatriz(aux2->puzzle);

	while((ptr->padre!=NULL)){
		ptr = (ptr->padre);
		imprimeMatriz(ptr->puzzle);
	}*/
	//printf("\nprof: %i\n",meta.profundidad);
	system("pause");
	//muestraCamino(meta);
	/*
	Insertar(&lista, inicial);
	Insertar(&lista, generaHijo(2,inicial));
	Insertar(&lista, generaHijo(4,inicial));
	MostrarLista(lista);
	if(expandido(generaHijo(3,inicial)))
		printf("el nodo se encuentra en la lista");
	else
		printf("el nodo no se encuentra en la lista");
	*/
		
	/*if(compara_edos(inicial, final))
		printf("son iguales");
	else
		printf("son diferentes");*/
		
		
	/*Push(&agenda,inicial);
	expandir();
		printf("lo expandi");
	while(agenda!=NULL){
		imprimeMatriz(Pop(&agenda));
		printf("\n\n");
	}*/
	//meta = DFS(inicial,final);
		
	/*imprimeMatriz(meta);
	printf("\nllegue a la meta\n");
	system("pause");
	printf("\agenda\n");
	while(agenda!=NULL){
		imprimeMatriz(Pop(&agenda));
		printf("\n\n");
	}
	system("pause");
	printf("\nLista\n");
	*/
	//MostrarLista(lista);
}
