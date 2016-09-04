/*

Pila.h 

*/
//Estructura con la que se manipula los estados
typedef struct _nodo {
   estadop estado;
   struct _nodo *siguiente;
} tipoNodo;
int tamano=0;
typedef tipoNodo *pNodo;
typedef tipoNodo *Pila; 
/* Funciones con pilas: */
void Push(Pila *l, estadop v);
estadop Pop(Pila *l);
 
void Push(Pila *pila, estadop v)
{
	tamano++;
   pNodo nuevo;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->estado = v;
   
   /* Añadimos la pila a continuación del nuevo nodo */
   nuevo->siguiente = *pila;
   /* Ahora, el comienzo de nuestra pila es en nuevo nodo */
   *pila = nuevo;
}
//Funcion que muestra como se encuentra la pila y que estados 
//son los que se encuentran en ella
void muestrapila(Pila *pila){
	pNodo nodo;
	nodo = *pila;
	while(nodo){
		imprimeMatriz(nodo->estado.puzzle);
		nodo = nodo->siguiente;
	}
}
estadop Pop(Pila *pila)
{
   pNodo nodo; /* variable auxiliar para manipular nodo */
   estadop v;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo = *pila;
   /* Asignamos a pila toda la pila menos el primer elemento */
   *pila = nodo->siguiente;
   /* Guardamos el estado de retorno */
   v = nodo->estado; 
   return nodo->estado;
}
//Regresa el estado que se encuentra en el tope de la pila
estadop revisaTope(Pila *pila){
	return((*pila)->estado);	
}
estadop EliminaElemento(Pila pila, int id){
   int i;
   estadop aux;
   
   pNodo nodo = pila;
   if(id==1){
		aux = Pop(&pila);
	}
	else
		if(id==tamano){
			while(nodo->siguiente)
				nodo = nodo->siguiente;
			aux = nodo->estado;
			nodo->siguiente= NULL;
		}
		else{
			for(i=0;i<(tamano - id -1);i++)
				nodo = nodo->siguiente;
			aux = nodo->estado;
			nodo->siguiente = (nodo->siguiente)->siguiente;
		}
	tamano--;
	printf("\npila en elimina\n");
	muestrapila(&pila);
	system("pause");
	return aux;
}
