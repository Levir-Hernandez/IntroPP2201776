#include <stdio.h>
#include <math.h>
#include "omp.h"

double sumaFibonacciArreglo(long n) // O(n)
{
    double suma=0, f[2*n + 1];
    f[0] = 0; f[1] = 1;
    for(int i=2; i <= 2*n; i++)
    {
        f[i] = f[i-1] + f[i-2];
        if(i%2 == 0) suma += f[i];
    }
    return suma;
}

double fibonacciMatematico(long n) // O(log n)
{
    double nAureo = (1.0 + sqrt(5.0)) / 2.0;
    return (pow(nAureo, n) - pow(1-nAureo, n)) / sqrt(5.0);
}

double sumaFibonacciMatematico(long n) // O(n log n)
{
    double suma = 0.0;
    for(int i=0; i <= 2*n; i+=2)
        suma += fibonacciMatematico(i);
    return suma;
}

int main()
{
    long n = 50000;
    double suma, ti, tf;

    printf("Version secuencial (n = %d)\n", n);

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
