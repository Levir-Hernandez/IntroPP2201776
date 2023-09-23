# IntroPP2201495

En la carpeta OpenMP se encuentran los archivos "codigoSecuencial.c" y "codigoParalelo.c", realizados para el ejercicio de Suma de números de Fibonacci en índices pares hasta N términos.

# Instrucciones de compilación y ejecución
Para compilar tanto el archivo secuencial como paralelo en GUANE se debe realizar de la siguiente forma:

        gcc -Wall -fopenmp -std=c99 codigoSecuencial.c -o salidaSecuencial -lm
        gcc -Wall -fopenmp -std=c99 codigoParalelo.c -o salidaParalela -lm

Y para su posterior ejecución con los comandos:

        ./salidaSecuencial
        ./salidaParalela

**Nota:** El valor de N esta dado de forma fija en el código, si desea modificarla puede usar un editor como vim o nano para modificar su valor en el codigo fuente.
Estos códigos fueron compilados y ejecutados en una máquina de 4 núcleos con sistema operativo Windows 10. 

