#include <stdlib.h>
#include <stdio.h>
/*
typedef struct _nodo {
   estadop estado;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
*/
/* Funciones con colas: */
void Anadir(pNodo *primero, pNodo *ultimo, estadop v);
estadop Leer(pNodo *primero, pNodo *ultimo);
 /*
int main()
{
   pNodo primero = NULL, ultimo = NULL;

   Anadir(&primero, &ultimo, 20);
   printf("A�adir(20)\n");
   Anadir(&primero, &ultimo, 10);
   printf("A�adir(10)\n");
   printf("Leer: %d\n", Leer(&primero, &ultimo));
   Anadir(&primero, &ultimo, 40);
   printf("A�adir(40)\n");
   Anadir(&primero, &ultimo, 30);
   printf("A�adir(30)\n");
   printf("Leer: %d\n", Leer(&primero, &ultimo));
   printf("Leer: %d\n", Leer(&primero, &ultimo));
   Anadir(&primero, &ultimo, 90);
   printf("A�adir(90)\n");
   printf("Leer: %d\n", Leer(&primero, &ultimo));
   printf("Leer: %d\n", Leer(&primero, &ultimo));

   system("PAUSE");
   return 0;
}*/

void Anadir(pNodo *primero, pNodo *ultimo, estadop v)
{
   pNodo nuevo;
 
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->estado = v;
   /* Este ser� el �ltimo nodo, no debe tener siguiente */
   nuevo->siguiente = NULL;
   /* Si la cola no estaba vac�a, a�adimos el nuevo a continuaci�n de ultimo */
   if(*ultimo) (*ultimo)->siguiente = nuevo;
   /* Ahora, el �ltimo elemento de la cola es el nuevo nodo */
   *ultimo = nuevo;
   /* Si primero es NULL, la cola estaba vac�a, ahora primero apuntar� tambi�n al nuevo nodo */
   if(!*primero) *primero = nuevo;
}

estadop Leer(pNodo *primero, pNodo *ultimo)
{
   pNodo nodo; /* variable auxiliar para manipular nodo */
   estadop v;      /* variable auxiliar para retorno */
   
   /* Nodo apunta al primer elemento de la pila */
   nodo = *primero;
   //if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a primero la direcci�n del segundo nodo */
   *primero = nodo->siguiente;
   /* Guardamos el estado de retorno */
   v = nodo->estado; 
   /* Borrar el nodo */
   //free(nodo);
   /* Si la cola qued� vac�a, ultimo debe ser NULL tambi�n*/
   if(!*primero) *ultimo = NULL;
   return v;
}
estadop revisaTopec(pNodo *primero){
	return ((*primero)->estado);
}
void muestraCola(pNodo *primero){
	pNodo nodo;
	nodo = *primero;
	while(nodo){
		imprimeMatriz(nodo->estado.puzzle);
		nodo = nodo->siguiente;
	}
}
