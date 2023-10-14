#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i;
int cont=0;
struct nodo {
    int valor;
    struct nodo* izquierda;
    struct nodo* derecha;
};

// Función para crear un nuevo nodo
struct nodo* crear_nodo(int valor) {
    struct nodo* nodo_nuevo = (struct nodo*)malloc(sizeof(struct nodo));
    nodo_nuevo->valor = valor;
    nodo_nuevo->izquierda = NULL;
    nodo_nuevo->derecha = NULL;
    return nodo_nuevo;
}

// Función para insertar un nuevo nodo en el árbol
struct nodo* insertar(struct nodo* raiz, int valor) {
    // Si la raíz es nula, crea un nuevo nodo y lo convierte en la raíz
    if (raiz == NULL) {
        return crear_nodo(valor);
    }

    // Si el valor a insertar es menor que el valor de la raíz, inserta en la rama izquierda
    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    }
    // Si el valor a insertar es mayor que el valor de la raíz, inserta en la rama derecha
    else if (valor > raiz->valor) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    // Retorna la raíz sin cambios
    return raiz;
}

// Función para imprimir los nodos en orden
void inorden(struct nodo* raiz,int n, int * A) {
    if (raiz != NULL) {
        inorden(raiz->izquierda,n, A);
		i++;
        A[cont]=raiz -> valor;
		cont++;
        inorden(raiz->derecha,n, A);
    }
}
int i, j;
void TreeSort (int *A, int n);

int main(int arc, char* argv[]) 
{	
	int* A;   
	int n; 

	if(arc!=2) 
	{
		exit (1);
	}	

	n=atoi (argv[1]);
	A=malloc(n*sizeof(int));

	if(A==NULL) 
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(2);
	}

	for (i=0;i<n; i++) 
		scanf ("%d", &A[i]);
		
	//t_inicio = clock();

	TreeSort (A,n);
	


	//printf("\n\n El tiempo de ordemaniento es de: %.8f segundos.", t_intervalo);
	//Cálculo del tiempo de ejecución del programa
	
	
	//Mostrar los tiempos en formato exponecial

	
	for (i=0;i<n; i++) 
		printf ("%d. %d\n",i , A[i]);
	return 0;	
	

} 

void TreeSort (int *A, int n)
	{
		struct nodo* raiz = NULL;
		
		for (i=0;i<n;i++)
		{
			raiz = insertar(raiz, A[i]);
		}	
		inorden(raiz,n, A);	
	}
