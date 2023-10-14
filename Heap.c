//Practica 1
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"
#include <math.h>

void HeapSort(int* A, int n);
void Push(int* h, int n, int j);
int Pop(int* h);
void Balance(int* h, int i, int n);

int main(int argc, char* argv[]) {
    clock_t t_inicio, t_final;  
    double utime0, stime0, wtime0,utime1, stime1, wtime1;
    int* A;
    int n, i;

    if (argc != 2) //Argumento para ejecutar
	{
        exit(1);
    }

	n=atoi (argv[1]); //Conversion de cadena a entero
	A=malloc(n*sizeof(int)); //Memoria dinamica

    if (A == NULL) {
        printf("\nError al intentar reservar memoria para %d elementos\n", n);
        exit(2);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    uswtime(&utime0, &stime0, &wtime0);   
    HeapSort(A, n);
    uswtime(&utime1, &stime1, &wtime1);
    for (i = 0; i < n; i++) {
        printf("%d. %d\n", i, A[i]);
    }
    //Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
    return 0;
}

void HeapSort(int* A, int n) 
{
    int* h;
    int i, m;
    m=n+1;
       
    h = malloc(m * sizeof(int));//Memoria dinamica
    if (h == NULL) {
        printf("\nError al intentar reservar memoria para %d elementos\n", n);
        exit(2);
    }
    h[0] = 0;

    for (i = 0; i < n; i++) //Hace recorrido y manda a llamar a la funcion de Push
	{    
        Push(h, A[i], 1);
        h[0]++;
       // printf("\n%d %d\n",i, h[0]);
    }

    for (i = 0; i < n; i++) //Hace recorrido y manda a llamar a la funcion de Push
	{
        A[i] = Pop(h);
    }
    free(h);
}


void Push(int *h, int n, int j)
{
	int temp;

    if(h[j]==0) //
        h[j]=n;
	
    else if(h[j]>n)//Si el elemto que pusheamos en menor a la raiz los intercambiamos y pusheamos el elemento que estaba en la raiz
    {
        temp=h[j];
        h[j]=n;
        Push(h, temp, j);
    }
    else
    {
        if(h[2*j]==0)//Preguntamos por el hijo izquierdo
            h[2*j]=n;

        else if(h[2*j+1]==0)//preguntamos por el derecho
            h[2*j+1]=n;
        
        else  
            Push(h, n, j+1);//Pusheamos pero desde el hermano derecho    
    }
    return ;
}

int Pop(int* h) {
    int root;
    root = h[1];
    int n = h[0];
    h[1] = h[n];
    h[0]--;

    Balance(h, 1, n - 1);

    return root;
}

void Balance(int* h, int i, int n) //busca el elemento más chikito y lo intercambia con la raiz
{
    int j = 2 * i; 

    while (j <= n) {
        if (j < n && h[j + 1] < h[j]) {
            j++;
        }

        if (h[i] <= h[j]) {
            break;
        }

        int temp = h[i];
        h[i] = h[j];
        h[j] = temp;
        i = j;
        j = 2 * i;
    }
}
