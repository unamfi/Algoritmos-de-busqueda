#include <stdlib.h>
#include <stdio.h>

#define ASCENDENTE 1 //de menor a mayor
#define DESCENDENTE 0

typedef struct _nodol {
   int h;
   estadop estado;
   struct _nodol *siguiente;
   struct _nodol *anterior;
} tipoNodol;

typedef tipoNodol *pNodol;
typedef tipoNodol *Listad;

/* Funciones con listas: */
void Insertar(Listad *l, estadop v);
void Borrar(Listad *l, estadop v);
int calcula_h(estadop edo);
void BorrarLista(Listad *);
void MostrarLista(Listad l, int orden);

/*
int main()
{
   Lista lista = NULL;
   pNodol p;

   Insertar(&lista, 20);
   Insertar(&lista, 10);
   Insertar(&lista, 40);
   Insertar(&lista, 30);

   MostrarLista(lista, ASCENDENTE);
   MostrarLista(lista, DESCENDENTE);

   Borrar(&lista, 10);
   Borrar(&lista, 15);
   Borrar(&lista, 45);
   Borrar(&lista, 30);

   MostrarLista(lista, ASCENDENTE);
   MostrarLista(lista, DESCENDENTE);

   BorrarLista(&lista);

   system("PAUSE");
   return 0;
}
*/
void Insertar(Listad *lista, estadop v)
{
   pNodol nuevo, actual;
   int heuristica_nuevo = calcula_h(v);
   /* Crear un nodo nuevo */
   nuevo = (pNodol)malloc(sizeof(tipoNodol));
   nuevo->h = heuristica_nuevo;
   nuevo->estado = v;
   /* Colocamos actual en la primera posición de la lista */
   actual = *lista;
   if(actual) 
		while(actual->anterior){
			actual = actual->anterior;
		}
   /* Si la lista está vacía o el primer miembro es mayor que el nuevo*/
   if(!actual || actual->h > heuristica_nuevo) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = actual; 
      nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!*lista) *lista = nuevo;
   }
   else {
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga 
         un h mayor que v */
      while(actual->siguiente && actual->siguiente->h <= heuristica_nuevo) 
         actual = actual->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

void Borrar(Listad *lista, int v)
{
   pNodol nodo;
   
   /* Buscar el nodo de h v */
   nodo = *lista;
   while(nodo && nodo->h < v) nodo = nodo->siguiente;
   while(nodo && nodo->h > v) nodo = nodo->anterior;

   /* El h v no está en la lista */
   if(!nodo || nodo->h != v) return;
   
   /* Borrar el nodo */
   /* Si lista apunta al nodo que queremos borrar, apuntar a otro */
   if(nodo == *lista)
     if(nodo->anterior) *lista = nodo->anterior;
     else *lista = nodo->siguiente;
   
   if(nodo->anterior) /* no es el primer elemento */
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente) /* no es el último nodo */
      nodo->siguiente->anterior = nodo->anterior;
   free(nodo);
}
void BorrarLista(Listad *lista)
{
   pNodol nodo, actual;

   actual = *lista;
   while(actual->anterior) actual = actual->anterior;

   while(actual) {
      nodo = actual;
      actual = actual->siguiente;
      free(nodo);
   }
   *lista = NULL;
}

void MostrarLista(Listad lista, int orden)
{
   pNodol nodo = lista;

   if(!lista) printf("Lista vacía");

   nodo = lista;
   if(orden == ASCENDENTE) {
      while(nodo->anterior) nodo = nodo->anterior;
      while(nodo) {
		 imprimeMatriz(nodo->estado.puzzle);
         printf("\n%d -> ", nodo->h);
         nodo = nodo->siguiente;
      }
   }
   else {
      while(nodo->siguiente) nodo = nodo->siguiente;
      printf("Orden descendente: ");
      while(nodo) {
         printf("%d -> ", nodo->h);
         nodo = nodo->anterior;
      }
   }
   
   printf("\n");
}
estadop BorrarPrim(Listad *lista){
	pNodol nodo = *lista;
	if(!lista) printf("Lista vacía");
	while(nodo->anterior)
		nodo = nodo->anterior;
	nodo->siguiente->anterior = NULL;
	return(nodo->estado);
}
