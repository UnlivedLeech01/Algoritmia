#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include "tiempo.h"

int Quicksort (int *A , int p, int r); //Declaracion de variables 
int Pivot (int* A, int p, int r);
void Intercambiar (int* A, int j, int i);

int main(int arc, char* argv[]) 
{	
	clock_t t_inicio, t_final;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i; //Variables para loops
	int* A; 
	int inicio, fin; 

	if(arc!=2) 
		exit (1);
	}	

	n=atoi (argv[1]); 
	A=malloc(n*sizeof(int)); 

	if(A==NULL) 
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(2);
	}

	for (i=0;i<n; i++)  //Rellenar el algoritmo con los numeros
		scanf ("%d", &A[i]);

	inicio=0; //?
	fin=n-1;
	
	//t_inicio = clock();		
	uswtime(&utime0, &stime0, &wtime0);
	Quicksort (A, inicio, fin);
	uswtime(&utime1, &stime1, &wtime1);
	//t_final = clock();
	//t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;

	for (i=0;i<n; i++) 
		printf ("%d\n", A[i]);
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
	//printf("\n\n El tiempo de ordemaniento es de: %.8f segundos.", t_intervalo);	
	
	return 0;		
}

int Quicksort(int *A, int p, int r)
{
	int j;
	if(p<r)
	{
		j= Pivot(A, p, r);
		Quicksort(A, p, j-1);
		Quicksort(A, j+1, r);
	}
}

int Pivot(int* A, int p, int r)
{
	int piv, j, i;
	piv=A[p], i=p, j=r;
	while (i<j)
	{
	
		while ((A[i]<= piv)&&(i<r))
			i++;
		
		while (A[j] > piv)
			j--;
		
		if(i<j)
		Intercambiar (A, i, j);	
		
	}
	Intercambiar (A, p, j);
	return j;
}

void Intercambiar (int* A, int j, int i)
{
	int temp;
	temp= A[j];
	A[j]= A[i];
	A[i]= temp;
}

