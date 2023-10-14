#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include <math.h>
#include "tiempo.h"

int ProcedimientoShell (int *A , int n,int i); 

int main(int arc, char* argv[]) 
{	
	clock_t t_inicio, t_final; 
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i; //Variables para loops
	int* A; 

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
	uswtime(&utime0, &stime0, &wtime0);
	ProcedimientoShell (A, n, i);
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
	//******************************************************************
	//printf("\n\nTiempo medido: %.8f segundos.", t_intervalo);
	
	return 0;		
}

int ProcedimientoShell (int *A,  int n,int i)
{
	int b, k, temp;	 
	b=0;
	k=trunc (n/2); //Da el entero mayor mas cercano
	
	while (k >=1)
	{	b=1;
		while (b!=0)
		{
		 b=0;
			for ( i=k; i<=n-1; i++)
			{
				if (A[i-k]>A[i])
				{
					temp= A[i];
					A[i]=A[i-k];
					A[i-k]=temp;
					b=b+1;
				}
			}
		}
		k=trunc(k/2);
	}	
}

