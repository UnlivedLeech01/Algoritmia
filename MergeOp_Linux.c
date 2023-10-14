#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include <math.h>
#include "tiempo.h"

int i, j, k, l, p, q, r, n; 
void Merge (int *A, int p, int q, int r); 
void MergeSort (int* A, int p, int r);

int main(int arc, char* argv[]) 
{	
	clock_t t_inicio, t_final;  
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i; //Variables para loops
	int* A;
    int* C;
	
	if(arc!=2) //Argumento para ejecutar
	{
		exit (1);
	}	
	n=atoi (argv[1]);//Conversion de cadena a entero
	A=malloc(n*sizeof(int)); //Memoria dinamica
	
	if(A==NULL || C==NULL)  
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(2);
	}

	for (i=0;i<n; i++) 
		scanf ("%d", &A[i]);
	
	p=0;
	r=n-1;
	
	//t_inicio = clock();	
	uswtime(&utime0, &stime0, &wtime0);
	MergeSort (A, p, r);
	uswtime(&utime1, &stime1, &wtime1);
	//t_final = clock();
	//t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;

	for (i=0;i<n; i++) 
		printf ("\n%d", A[i]);
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
	//printf("\n\nEl tiempo de ordemaniento es de: %.8f segundos.", t_intervalo);
	
	return 0;		
}

void MergeSort (int* A, int p, int r) //Función principal de Merge Sort
{
	if (p < r) //Condición de parada para la recursión
	{
		q = ((p+r)/2); //Calcula el punto medio del rango p-r, para dividir el arreglo en dos mitades
		MergeSort(A, p, q);	//se llama a MergeSort de manera recursiva para ordenar la primera mitad del arreglo
		
		MergeSort(A, q+1, r);
		
		Merge(A, p, q, r);
 	}
}


void Merge (int* A, int p, int q, int r)
{
	int *C;
	C=malloc(n*sizeof(int));
	l=r-p+1, i=p, j=q+1;
	for(k=0; k<=l ; k++)
	{
		if ((i<=q)&&(j<=r))
		{
			if(A[i]<A[j])
			{
			
				C[k]=A[i];
				i++;
				//k++;
			}
			else
			{
			
				C[k]=A[j];
				j++;
				//k++;
			}				
		}
		else if (i<=q)
		{
			
			C[k]=A[i];
			i++;
		}
		else
		{
			C[k]=A[j];
			j++;
		}
	}
	for (k=p, i=0;k<=r;k++, i++)
		A[k]=C[i];	
}

