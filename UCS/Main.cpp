#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ucs.h"

estadop leerArchivo(int tipo){
   	FILE *f;     
   	int i,j;
   	estadop edo;
   	
   	if(tipo == 1)f = fopen("config.ini","r");
    else f = fopen("final.mat","r");
       	
   	if(f == NULL){
	     if(tipo)printf("ERROR al abrir archivo config.ini\n");
	     else printf("ERROR al abrir archivo final.mat\n");
	     system("pause");
         exit(1);
         }
    else{
         if(tipo)fscanf(f,"%i\n",&filas);
         if(tipo)fscanf(f,"%i",&columnas);
 	     edo.puzzle = (int**) calloc(filas,sizeof(int*));
	     for(i=0; i<filas; i++)
		          edo.puzzle[i] = (int*) calloc(columnas,sizeof(int));
		
	     for(i=0; i<filas; i++)
		          for(j=0; j<columnas; j++)
			               fscanf(f,"%i",&edo.puzzle[i][j]); 
    } 
    fclose(f);
    return edo;
}

main(){
	estadop inicial, final,meta;
	
    inicial = leerArchivo(1);
    inicial.padre = NULL;
    inicial.mov_origen = 0;
	inicial.profundidad=0;
	final = leerArchivo(0);
	localizarVacio(inicial);
	activaMov();
	printf("Uniform Cost Search\n\nProcesando...\n\n");
	system("pause");
	Anadir(&primero,&ultimo,inicial);
	meta = UCS(inicial,final);
	printf("\nSe expandieron %i estados \n",expandidos);
	printf("Se generaron %i estados \n",generados);
	
	system("pause");
}
