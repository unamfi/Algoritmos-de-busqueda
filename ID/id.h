/*

Iterative Deppening

*/
#include "N-Puzzle.h"
#include "pila.h"
#include "cola.h"
#include "lista.h"
Lista lista = NULL;			//Lista donde se almacenan los edos explorados
Pila agenda = NULL;			//Pila donde se almacenan los edos a explorar
Pila listaS = NULL;			//lista donde se almacenan los edos que llevan a la solucion
int expandidos=0;			//Se almacena el numer de edos expandidos
pNodo primero = NULL, ultimo = NULL;
estadop generic;

//Funcion que verifica si un edo fue expandido o no
//envia un uno si ha sido expandido si no regresa un cero
int expandido(estadop edo){
	if(!ListaVacia(lista))
		return(BuscaElemento(lista,edo));
}
//Funcion que compara dos edos, si son iguales regresa un uno
//si son diferentes regresa un cero
int compara_edos(estadop edo1, estadop edo2){
	int i,j,f=0;
	for(i=0;i<filas;i++){
			for(j=0;j<columnas;j++)
				if(edo1.puzzle[i][j]!=edo2.puzzle[i][j])
					return 0;
		}
			return 1;
}
//Funcion que almacena los padres en una lista tipo pila
//para despues poder ser mostrada
int enlistarCamino(estadop meta){
	estadop *ptr;
	ptr = &meta;
	//imprimeMatriz(ptr->puzzle);
	Push(&listaS, *ptr);
	while((ptr->padre!=NULL)){
		ptr = (ptr->padre);
		Push(&listaS, *ptr);
	}
}
//Funcion que expade un edo dependiendo si los movimientos estan habilitados
//por su cuadro vacio, llama a la funcion genera hijo y le envia el corres-
//pondiente identificador de movimiento. Ademas de que modifica el apuntador
//al padre actual e inserta en la lista de expandidos
int expandir(estadop edo){
	int i,j,hijos_gen=0;
	expandidos++;
	apadre = &edo;
	Insertar(&lista, edo);   //insertar en lista 
	for(i=1;i<=4;i++){
		localizarVacio(edo);
		activaMov();
		switch(i){
			 case 1:
				if(vacio.mov.arriba){
				  Anadir(&primero, &ultimo, generaHijo(i));
				  hijos_gen++;
				}  
				break;
			 case 2:
				if(vacio.mov.abajo){
				  Anadir(&primero, &ultimo, generaHijo(i));
				  hijos_gen++;
				}
				break;
			 case 3:
				if(vacio.mov.izquierda){
				  Anadir(&primero, &ultimo, generaHijo(i));
				  hijos_gen++;
				}
				break;
			 case 4:
				if(vacio.mov.derecha){
				  Anadir(&primero, &ultimo, generaHijo(i));
				  hijos_gen++;
				}
				break;
			 }
	}
	return hijos_gen;
}
estadop DLS(estadop edo, estadop final, int profundidad_corte){
	int i, hijos;// numero de hijos generados
	if(profundidad_corte>=0){
		if(compara_edos(edo,final)){
			enlistarCamino(edo);//enlista el camino solucion
			muestrapila(&listaS);//nos muestra la solucion
			printf("Solucion encontrada en la profundidad %i \n",profundidad_corte);
			system("pause");
			generic = edo;
		}
		else{ 
			hijos = expandir(edo);
			DLS(Leer(&primero,&ultimo),final,profundidad_corte-1);
		}
	}
	return edo;
}

//Funcion que realiza la busqueda del edo final
estadop ID(estadop edo, estadop final){
	int profundidad_max,profundidad_corte=0,i;
	estadop meta;
	printf("\n\nProfundidad maxima de corte: ");
	scanf("%i",&profundidad_max);
	generic = edo;
	while(!compara_edos(generic,final)){
		DLS(edo, final,profundidad_corte);
		if(profundidad_max > profundidad_corte)
			profundidad_corte++;
		else{
			printf("\n\nNo se encontro solucion en esa profundidad\n");
			break;
		}
		if(!compara_edos(generic,final)){
			lista = NULL;
			agenda = NULL;
		}
	}
	return meta;
}


