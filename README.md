# IntroPP2201776

En la carpeta OpenMP se encuentran los archivos "codigoSecuencial.c" y "codigoParalelo.c", realizados para el ejercicio de Suma de números de Fibonacci en índices pares hasta N términos.

# Instrucciones de compilación y ejecución
Para compilar tanto el archivo secuencial como paralelo en GUANE se debe realizar de la siguiente forma:

        gcc -Wall -fopenmp -std=c99 codigoSecuencial.c -o salidaSecuencial -lm
        gcc -Wall -fopenmp -std=c99 codigoParalelo.c -o salidaParalela -lm

Y para su posterior ejecución con los comandos:

        ./salidaSecuencial
        ./salidaParalela

**Nota:** El valor de N está dado de forma fija en el código, si desea modificarla puede usar un editor como vim o nano para modificar su valor en el código fuente.
Estos códigos fueron compilados y ejecutados en una máquina ***"AMD Ryzen 3 3200G with Radeon Vega Graphics, 3600 Mhz, con 4 procesadores principales, 4 procesadores lógicos y 8GB de RAM de tipo DDR4"*** con sistema operativo ***"Microsoft Windows 10 Education"***.

# Comparaciones de tiempos de ejecución al aumentar la escala
Se consideraron dos soluciones para abordar el problema. La primera se centró en el uso de un arreglo para calcular todos los números de Fibonacci y, posteriormente, realizar una suma paralelizada de los índices. Esta solución tenía una complejidad tanto temporal como espacial de O(n).

La segunda solución se basó en el empleo de una fórmula matemática que implicaba llamadas a la función "pow". Esta función tiene una complejidad de O(log n), por ello se paralelizaron simultáneamente los dos llamados a la función y, posteriormente, se realizó una suma paralelizada de los índices pares. Esta segunda solución tuvo una complejidad temporal de O(n log n) y una complejidad espacial de O(1).

Al realizar las ejecuciones con tamaños más grandes de N se nota como la solución matemática deja de ser viable, sin embargo teóricamente debería ser mejor que la versión con arreglo hasta cierto N pequeño, pero debido a la velocidad de la máquina esta mejora no es perceptible, por lo tanto se concluye que aunque la paralelización ayuda a reducir el tiempo de ejecución no cambia su tendencia final, por ello en este caso es mejor usar la versión con arreglos a pesar de que requiera más memoria.

![image](https://github.com/Levir-Hernandez/IntroPP2201776/assets/145631783/819cb5ce-527e-496f-bb2e-cef76b6edb27)

**Nota:** Si la imagen con la comparación de tiempos de ejecución no se puede visualizar en este "README.md", dentro de la carpeta OpenMP se incluyó el archivo "Comparaciones de tiempos de ejecución.png".
