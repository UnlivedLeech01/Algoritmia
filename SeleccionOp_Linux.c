#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tiempo.h"

int i, k;  
void Seleccion(int* A, int n); 

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
	Seleccion(A, n);
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
	//printf("\n\n El tiempo de ordemaniento es de: %.8f segundos.", t_intervalo);  
	return 0;		
}


void Seleccion(int* A, int n)
{
	int p, temp;  
	for (k=0;k<=n-2;k++)  
	{
		p=k;
		for(i=k+1;i<=n-1; i++)
		{
			if(A[i]<A[p])  
			p=i;	
		}
		temp=A[p];
		A[p]=A[k];
		A[k]=temp;	
	}
}

