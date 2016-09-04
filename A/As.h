/*

A*

*/
#include "N-Puzzle.h"
#include "pila.h"
#include "lista.h"
#include "dobleenlace.h"
estadop finall;
Lista lista = NULL;			//Lista donde se almacenan los edos explorados
Pila listaS = NULL;			//lista donde se almacenan los edos que llevan a la solucion
int expandidos=0;			//Se almacena el numer de edos expandidos
Listad agenda = NULL;

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
	estadop aux;
	Insertar(&lista, edo);   //insertar en lista 
	for(i=1;i<=4;i++){
		localizarVacio(edo);
		activaMov();
		switch(i){
			 case 1:
				if(vacio.mov.arriba){
				  aux = generaHijo(i);
				  //if(!expandido(aux)){
					Insertar(&agenda, aux);
					hijos_gen++;
				  //}
				}  
				break;
			 case 2:
				if(vacio.mov.abajo){
				  aux = generaHijo(i);
				  //if(!expandido(aux)){
					Insertar(&agenda, aux);
					hijos_gen++;
				  //}
				}
				break;
			 case 3:
				if(vacio.mov.izquierda){
				  aux = generaHijo(i);
				  //if(!expandido(aux)){
					Insertar(&agenda, aux);
					hijos_gen++;
				  //}
				}
				break;
			 case 4:
				if(vacio.mov.derecha){
				  aux = generaHijo(i);
				  //if(!expandido(aux)){
					Insertar(&agenda, aux);
					hijos_gen++;
				  //}
				}
				break;
			 }
	}
	return hijos_gen;
}

int abs (int i){
    if (i < 0)
        return -i;
    else
        return i;
}
int calcula_h(estadop edo){
	int i,j,k,l,b,h=0;
	for(k=0;k<filas;k++)
		for(l=0;l<columnas;l++){
			b=0;
			for(i=0;i<filas;i++){
				for(j=0;j<columnas;j++)
					if(finall.puzzle[k][l]== edo.puzzle[i][j]){
						h+= abs((i - k)+(j - l));
						b=1;
						break;
					}
				if(b)
					break;
			}
		}

	return h;
}
estadop As(estadop edo, estadop final){
	if(agenda == NULL){
		expandir(edo);
	}
	if(compara_edos(edo,final)){
	//una vez que entra al if a encontrado el edo final
		enlistarCamino(edo);//enlista el camino solucion
		muestrapila(&listaS);//nos muestra la solucion
		return edo;
	}
	else{
		if(expandido(edo)){
			As(BorrarPrim(&agenda), final);
		}
		else{
			expandir(edo);
			As(BorrarPrim(&agenda), final);
		}
	}
}
