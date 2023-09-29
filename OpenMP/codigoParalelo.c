#include <stdio.h>
#include <math.h>
#include "omp.h"

double sumaFibonacciArreglo(long n) // O(n)
{
    double suma=0, f[2*n + 1];
    f[0] = 0; f[1] = 1;
    for(int i=2; i <= 2*n; i++)
        f[i] = f[i-1] + f[i-2];

    #pragma omp parallel for reduction(+:suma)
    for(int i=0; i <= 2*n; i+=2)
        suma += f[i];

    return suma;
}

double fibonacciMatematico(long n) // O(log n)
{
    double suma = 0.0, nAureo = (1.0 + sqrt(5.0)) / 2.0;
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            #pragma omp atomic
            suma += pow(nAureo, n) / sqrt(5.0);
        }

        #pragma omp section
        {
            #pragma omp atomic
            suma -= pow(1-nAureo, n) / sqrt(5.0);
        }
    }
    return suma;
}

double sumaFibonacciMatematico(long n) // O(n log n)
{
    double suma = 0.0;
    #pragma omp parallel for reduction(+:suma)
    for(int i=0; i <= 2*n; i+=2)
        suma += fibonacciMatematico(i);
    return suma;
}

const int nHilos = 4;

int main()
{
    omp_set_num_threads(nHilos);

    long n = 100000;
    double suma, ti, tf;

    printf("Version paralela (n = %d)\n", n);

    // Solucion mediante Arreglo
    ti = omp_get_wtime();
    suma = sumaFibonacciArreglo(n);
    tf = omp_get_wtime();

    printf("\nFibonacci Arreglo:\n");
    printf("tiempo = %.3f [ms]\n", (tf-ti)*10000.0);
    printf("suma = %0.f\n", suma);

    // Solucion mediante formula Matematica
    ti = omp_get_wtime();
    suma = sumaFibonacciMatematico(n);
    tf = omp_get_wtime();

    printf("\nFibonacci Matematico:\n");
    printf("tiempo = %.3f [ms]\n", (tf-ti)*10000.0);
    printf("suma = %0.f\n", suma);
    return 0;
}
