/*
Breadth First Search


*/
#include "N-Puzzle.h"
#include "pila.h"
#include "lista.h"
#include "cola.h"
Lista listaI = NULL;			//Lista donde se almacenan los edos explorados
Lista listaF = NULL;
pNodo primeroI = NULL, ultimoI = NULL;
pNodo primeroF = NULL, ultimoF = NULL;
Pila listaA = NULL;
Pila listaB = NULL;
Pila listaS = NULL;			//lista donde se almacenan los edos que llevan a la solucion	
int expandidos=0;			//Se almacena el numer de edos expandidos
estadop BIDF(estadop edo);

//Funcion que verifica si un edo fue expandido o no
//envia un uno si ha sido expandido si no regresa un cero
int expandidoF(estadop edo){
	if(!ListaVacia(listaF))
		return(BuscaElemento(listaF,edo));
}
int expandidoI(estadop edo){
	if(!ListaVacia(listaI))
		return(BuscaElemento(listaI,edo));
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
int enlistarCaminoI(estadop meta){
	estadop *ptr;
	estadop *edo_u,*aux;
	ptr = &meta;
	edo_u = &edoUni;
	aux = edo_u->padre;
	edo_u->padre = ptr;
	while(aux->padre!=NULL){
		edo_u = aux;
		aux = edo_u->padre;
		aux->padre = edo_u;
	}
	Push(&listaS, *edo_u);
	while((edo_u->padre!=NULL)){
		edo_u = (edo_u->padre);
		Push(&listaS, *edo_u);
	}
	
}
int enlistarCaminoF(estadop meta){
	estadop *ptr,aux;
	ptr = &edoUni;
	int a=0,i;
	while((ptr->padre!=NULL)){
		a++;
		ptr = (ptr->padre);
		Push(&listaA, *ptr);
	}
	for(i=0;i<=a;i++){
		aux = Pop(&listaA);
		Push(&listaB, aux);
	}
	ptr = &meta;
	//imprimeMatriz(ptr->puzzle);
	Push(&listaS, *ptr);
	while((ptr->padre!=NULL)){
		ptr = (ptr->padre);
		Push(&listaS, *ptr);
	}
}
/*int enlistarCaminoF(estadop meta){
	estadop *ptr;
	estadop *edo_u,*aux;
	edo_u = &meta;
	aux = edo_u->padre;
	edo_u->padre = &edoUni;
	printf("\nuni\n");
	imprimeMatriz(edoUni.puzzle);
	while(aux->padre!=NULL){
		edo_u = aux;
		aux = edo_u->padre;
		aux->padre = edo_u;
	}
	Push(&listaS, *edo_u);
	while((edo_u->padre!=NULL)){
		edo_u = (edo_u->padre);
		Push(&listaS, *edo_u);
	}
}
*/
//Funcion que expade un edo dependiendo si los movimientos estan habilitados
//por su cuadro vacio, llama a la funcion genera hijo y le envia el corres-
//pondiente identificador de movimiento. Ademas de que modifica el apuntador
//al padre actual e inserta en la lista de expandidos
void expandirI(estadop edo){
	int i,j;
	expandidos++;
	apadreI = &edo;
	Insertar(&listaI, edo);   //insertar en lista 
	for(i=1;i<=4;i++){
		localizarVacio(edo);
		activaMov();
		switch(i){
			 case 1:
				if(vacio.mov.arriba){
				  Anadir(&primeroI, &ultimoI, generaHijo(i,1));
				}  
				break;
			 case 2:
				if(vacio.mov.abajo){
				  Anadir(&primeroI, &ultimoI, generaHijo(i,1));
				}
				break;
			 case 3:
				if(vacio.mov.izquierda){
				  Anadir(&primeroI, &ultimoI, generaHijo(i,1));
				}
				break;
			 case 4:
				if(vacio.mov.derecha){
				  Anadir(&primeroI, &ultimoI, generaHijo(i,1));
				}
				break;
			 }
 		 
	}
}void expandirF(estadop edo){
	int i,j;
	expandidos++;
	apadreF = &edo;
	Insertar(&listaF, edo);   //insertar en lista 
	for(i=1;i<=4;i++){
		localizarVacio(edo);
		activaMov();
		switch(i){
			 case 1:
				if(vacio.mov.arriba){
				  Anadir(&primeroF, &ultimoF, generaHijo(i,0));
				}  
				break;
			 case 2:
				if(vacio.mov.abajo){
				  Anadir(&primeroF, &ultimoF, generaHijo(i,0));
				}
				break;
			 case 3:
				if(vacio.mov.izquierda){
				  Anadir(&primeroF, &ultimoF, generaHijo(i,0));
				}
				break;
			 case 4:
				if(vacio.mov.derecha){
				  Anadir(&primeroF, &ultimoF, generaHijo(i,0));
				}
				break;
			 }
 		 
	}
}
//Funcion que realiza la busqueda del edo final
estadop BIDI(estadop edo){
	if(Busca(primeroF,edo)){
	//una vez que entra al if a encontrado el edo final
		enlistarCaminoI(edo);//enlista el camino solucion
		muestrapila(&listaS);//nos muestra la solucion
		return edo;
	}
	else
		if(expandidoF(edo))
		//si el estado ha sido expandido se descarta y se saca un nuevo edo de la agenda
			BIDF(Leer(&primeroF, &ultimoF));
		else{
		//de lo contrario se expande el estado del tope de la agenda y se realiza de nuevo
		//el algoritmo con el estado que se encuentra en el tope de la agenda
			expandirF(Leer(&primeroF, &ultimoF));
			
			BIDF(primeroF->estado);
		}
}
estadop BIDF(estadop edo){
	if(Busca(primeroI,edo)){
	//una vez que entra al if a encontrado el edo final
		enlistarCaminoF(edo);//enlista el camino solucion
		muestrapila(&listaS);//nos muestra la solucion
		return edo;
	}
	else
		if(expandidoI(edo))
		//si el estado ha sido expandido se descarta y se saca un nuevo edo de la agenda
			BIDI(Leer(&primeroI, &ultimoI));
		else{
		//de lo contrario se expande el estado del tope de la agenda y se realiza de nuevo
		//el algoritmo con el estado que se encuentra en el tope de la agenda
			expandirI(Leer(&primeroI, &ultimoI));
			BIDI(primeroI->estado);
		}
}


