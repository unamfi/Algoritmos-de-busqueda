/*Proyecto Inteligencia Artificial "N-puzzle"  UNAM

Desarrolladores:
Romero Cordero Adrián
Rojas Jiménez Vladimir
Medina Osorio Pedro

Movimientos
1- arriba
2- abajo
3- izquierda
4- derecha

*/
//Vector de Movimientos asignado al espacio vacio
struct movimiento{
	int arriba;      //0 inactivo  1 activo
	int abajo;       //0 inactivo  1 activo
	int izquierda;   //0 inactivo  1 activo
	int derecha;     //0 inactivo  1 activo
};

//Estructura de espacio vacio con posición sobre el 0
struct cuadrovacio{
	int x,y; //0 es cuadro vacio
	movimiento mov;
	//textura, plano, etc..
}vacio;

//Estructura para manejar los estados del Puzzle 
typedef struct estadop{
	int **puzzle; 			// Matriz actual del puzzle
	int profundidad;		// profundidad a la que se encuentra el edo	
	struct estadop *padre;	//Referencia al padre del edo
}estadop;

int filas,columnas;			//Dimensiones del Puzzle
estadop *apadre;			//Apuntador para saber el padre mas reciente
int generados=0;			//se almacena el No de hijos generados

//Funcion que inicializa un estado, este estado sera el de solucion
estadop inicializaEdo(estadop estado){
	int n,i,j;
	n = 0;
	estado.padre = NULL;
	estado.profundidad=0;
	estado.puzzle = (int**) calloc(filas,sizeof(int*));
	for(i=0; i<filas; i++)
		estado.puzzle[i] = (int*) calloc(columnas,sizeof(int));	
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			n++;
			if (n == filas*columnas){
				estado.puzzle[i][j]= 0;
				vacio.mov.arriba=1;
				vacio.mov.abajo=0;
				vacio.mov.izquierda=1;
				vacio.mov.derecha=0;
			}
			else
			estado.puzzle[i][j] = n;
		}
	}
	return estado;
}
//Funcion que imprime un matriz y la imprime en pantalla
void imprimeMatriz(int **a){
	int i,j;
	for(i=0; i<filas; i++){
		printf("\n");
		for(j=0; j<columnas; j++)
			printf("[%3d]",a[i][j]);
	}
	printf("\n\n");
}
//Funcion querecibe un edo e imprime su matriz-puzzle en pantalla
void imprimeMatriz(estadop est){
	int i,j;
	for(i=0; i<filas; i++){
		printf("\n");
		for(j=0; j<columnas; j++)
			printf("[%3d]",est.puzzle[i][j]);
	}
}
//Funcion que recibe un edo y configura la estructura de cuadro vacio
//para poder manilpularlo
int localizarVacio(estadop edo){
	int i,j;
	for(i=0;i<filas;i++){
		for(j=0; j<columnas; j++)
			if(edo.puzzle[i][j] == 0){
				vacio.x=i;
				vacio.y=j;
		}
	}
	//printf("\nEl vacio esta en la posicion (%3i,%3i)",pos[0]+1,pos[1]+1);
}
//Funcion que, a partir de la posicion del cuadro vacio, habilita los
//posibles movimientos realizables.
void activaMov(){
        vacio.mov.arriba = 1;
		vacio.mov.abajo = 1;
		vacio.mov.izquierda = 1;
		vacio.mov.derecha = 1;
	if(!vacio.x){
		vacio.mov.arriba = 0;
		if(!vacio.y)
			vacio.mov.izquierda = 0;	
		else if(vacio.y==columnas-1)
			vacio.mov.derecha = 0;
	}
	else { 
          if(vacio.x==filas-1)
			vacio.mov.abajo = 0;
          if(!vacio.y)
				vacio.mov.izquierda = 0;	
			else if(vacio.y==columnas-1)
				vacio.mov.derecha = 0;
    }
}
//Funcion que realiza el movimiento del cuadro vacio a partir de in identificador
//de movimiento y lo realiza solo si el movimiento es valido
int** moverVacio(int id,int** matriz){
     switch(id){
         case 1://arriba
              if(vacio.mov.arriba){
                 matriz[vacio.x][vacio.y]=matriz[vacio.x-1][vacio.y];
                 matriz[vacio.x-1][vacio.y]=0;
                 vacio.x=vacio.x-1;
                 activaMov();
              }
              /*else
                 printf("\nNo se puede mover arriba");*/
              break;
         case 2://abajo
              if(vacio.mov.abajo){
                 matriz[vacio.x][vacio.y]=matriz[vacio.x+1][vacio.y];
                 matriz[vacio.x+1][vacio.y]=0;
                 vacio.x=vacio.x+1;
                 activaMov();
              }
              /*else
                 printf("\nNo se puede mover abajo");*/
              break;
         case 3://iquierda
              if(vacio.mov.izquierda){
                 matriz[vacio.x][vacio.y]=matriz[vacio.x][vacio.y-1];
                 matriz[vacio.x][vacio.y-1]=0;
                 vacio.y=vacio.y-1;
                 activaMov();
              }
              /*else
                 printf("\nNo se puede mover a la izquierda");*/
              break;
         case 4://derecha
              if(vacio.mov.derecha){
                 matriz[vacio.x][vacio.y]=matriz[vacio.x][vacio.y+1];
                 matriz[vacio.x][vacio.y+1]=0;
                 vacio.y=vacio.y+1;
                 activaMov();
              }
              /*else
                 printf("\nNo se puede mover a la derecha");*/
              break;
     }
     return matriz;
}
//Funcion que genera 1 hijo a partir del movimiento indicado por id
//donde el padre es el estado al que esta apuntando el identificador
// 'apadre', copia toda su configuracion y a partir de ella realiza 
//el movimiento, asigna profundidad, y la referencia a su padre
estadop generaHijo(int id){
	int i,j;
	estadop hijo;
	generados++;
	hijo.profundidad = apadre->profundidad +1;
	hijo.puzzle = (int**) calloc(filas,sizeof(int*));
	for(i=0; i<filas; i++)
		hijo.puzzle[i] = (int*) calloc(columnas,sizeof(int));
	for(i=0; i<filas; i++)
		for(j=0; j<columnas; j++)
			hijo.puzzle[i][j] = apadre->puzzle[i][j];
	hijo.padre = (estadop *)calloc(1,sizeof(estadop));
	*(hijo.padre) = *apadre;
	localizarVacio(hijo);
	hijo.puzzle = moverVacio(id,hijo.puzzle);
	return hijo;
}

//Funcion que recibe un edo y mueve el cuadro vacio de dicho
//edo aleatoriamente.
estadop generaRandom(estadop estado){
     srand(time(0));
	 int id;
	 localizarVacio(estado);
	 activaMov();
     for(int i=0; i < 1000; i++){
	 	 id = (rand () % 5 + 1);	
		 estado.puzzle = moverVacio(id ,estado.puzzle);
	 }
	 return estado;
}

