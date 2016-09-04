/*
Breadth First Search


*/
#include "N-Puzzle.h"
#include "pila.h"
#include "lista.h"
#include "cola.h"
Lista lista = NULL;			//Lista donde se almacenan los edos explorados
pNodo primero = NULL, ultimo = NULL;
Pila listaS = NULL;			//lista donde se almacenan los edos que llevan a la solucion
int expandidos=0;			//Se almacena el numer de edos expandidos

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
void expandir(estadop edo){
	int i,j;
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
				}  
				break;
			 case 2:
				if(vacio.mov.abajo){
				  Anadir(&primero, &ultimo, generaHijo(i));
				}
				break;
			 case 3:
				if(vacio.mov.izquierda){
				  Anadir(&primero, &ultimo, generaHijo(i));
				}
				break;
			 case 4:
				if(vacio.mov.derecha){
				  Anadir(&primero, &ultimo, generaHijo(i));
				}
				break;
			 }
 		 
	}
}
//Funcion que realiza la busqueda del edo final
estadop BFS(estadop edo, estadop final){
	if(compara_edos(edo,final)){
	//una vez que entra al if a encontrado el edo final
		enlistarCamino(edo);//enlista el camino solucion
		muestrapila(&listaS);//nos muestra la solucion
		return edo;
	}
	else
		if(expandido(edo))
		//si el estado ha sido expandido se descarta y se saca un nuevo edo de la agenda
			BFS(Leer(&primero, &ultimo), final);
		else{
		//de lo contrario se expande el estado del tope de la agenda y se realiza de nuevo
		//el algoritmo con el estado que se encuentra en el tope de la agenda
			expandir(Leer(&primero, &ultimo));
			BFS(revisaTopec(&primero),final);
		}
}


