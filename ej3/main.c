/*3) Hacer un programa que guarde en un archivo binario 500 n�meros aleatorios entre 0 y
1000. Al finalizar, se debe indicar el tama�o total del archivo en bytes.

NOTA: Utilizar las funciones fseek() y ftell() para resolver el problema. Se debe comprobar
que el resultado midiendo el tama�o del archivo desde el sistema operativo*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char *nombreArch = "Numeros.bin";

    FILE *archivo = fopen(nombreArch, "wb");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    for (int i = 0; i < 500; i++) {
        int numero = rand() % 1001; // N�meros entre 0 y 1000
        fwrite(&numero, sizeof(int), 1, archivo);
    }

    // Calcular el tama�o del archivo usando fseek() y ftell()
    fseek(archivo, 0, SEEK_END); // Ir al final del archivo
    long tamanio = ftell(archivo); // Obtener la posici�n actual(tama�o del archivo -bytes- xq es el final). devuelve un LONG!!!!

    // Cerrar el archivo
    fclose(archivo);

    printf("Tama�o del archivo en bytes: %ld\n", tamanio);

    return 0;
}
