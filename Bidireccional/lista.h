#include <stdlib.h>
#include <stdio.h>
/*
typedef struct _nodo {
   estadop estado;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;
*/
/* Funciones con listas: */
typedef tipoNodo *Lista;
estadop Insertar(Lista *l, estadop v);

int BuscaElemento(Lista *l,estadop edo);

int ListaVacia(Lista l);

void BorrarLista(Lista *);
void MostrarLista(Lista l);
/*
estadop main()
{
   Lista lista = NULL;
   pNodo p;

   Insertar(&lista, 20);
   Insertar(&lista, 10);
   Insertar(&lista, 40);
   Insertar(&lista, 30);

   MostrarLista(lista);

   Borrar(&lista, 10);
   Borrar(&lista, 15);
   Borrar(&lista, 45);
   Borrar(&lista, 30);
   Borrar(&lista, 40);

   MostrarLista(lista);
   
   BorrarLista(&lista);

   system("PAUSE");
   return 0;
}*/
estadop Insertar(Lista *lista, estadop v)
{
   pNodo nuevo, anterior;

   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->estado = v;
   
   /* Si la lista está vacía */
   if(ListaVacia(*lista)) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = *lista; 
      /* Ahora, el comienzo de nuestra lista es en nuevo nodo */
      *lista = nuevo;
   }
   else {
      /* Buscar el nodo de valor menor a v */
      anterior = *lista;
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga 
         un valor mayor que v */
      while(anterior->siguiente) 
         anterior = anterior->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = anterior->siguiente;
      anterior->siguiente = nuevo;
   }
   return nuevo->estado;
}

int ListaVacia(Lista lista)
{
   return (lista == NULL);
}

void BorrarLista(Lista *lista)
{
   pNodo nodo;

   while(*lista) {
      nodo = *lista;
      *lista = nodo->siguiente;
      free(nodo);
   }
}

void MostrarLista(Lista lista)
{
   pNodo nodo = lista;
   if(ListaVacia(lista)) printf("Lista vacía\n");
   else {
      while(nodo) {
		 imprimeMatriz(nodo->estado.puzzle);
		 printf("\n\n");
         nodo = nodo->siguiente;
     }
     printf("\n");
   }
}
int BuscaElemento(Lista lista, estadop edo){
	int i,j,f=0;
	pNodo nodo = lista;
	if(ListaVacia(lista)) printf("Lista vacía\n");
	else {
		while(nodo){
			f=0;
			for(i=0;i<filas;i++){
				for(j=0;j<columnas;j++)
					if((*nodo).estado.puzzle[i][j]!=edo.puzzle[i][j]){
						f=1;
						break;	
					}
				if(f)
					break;
			}
			if(!f)
				return 1;
			nodo = nodo->siguiente;
		}
		return 0;
	}
	return 0;
}

