/*6) Hacer un programa que permita guardar en un archivo binario (autos.bin), una estructura
llamada AUTOS con los siguiente campos:
Marca: EJ: Ford
Modelo: EJ: Fiesta
Dominio: EJ: CEM321
Precio: EJ: 120000

El programa deberá tener un menú de opciones para:
1) Añadir nuevos autos al final
2) Listar todos los registros
3) Buscar x marca o modelo
4) Vaciar archivo
5) Salir

✓ Cada opción debe llamar a una función.
✓ Añadir: Implic agregar nuevos autos. Se deben ingresar por teclado y guardar
en el archivo autos.txt
✓ Listar: implica contar la cantidad de registros que existen. Leerlos desde el
archivo y mostrarlos en pantalla.
✓ Buscar x marca o modelo: implica ingresar una cadena de texto a buscar.
Implementar función strstr () de C.el resultado es buscar un texto por ej: BMW
(y que muestre en pantalla todo lo que se encuentra en el archivo con esa
frase).

✓ Vaciar Archivo: Implica borrar el contenido del archivo (OJO; no se pide borrar
el archivo sino su contenido).
✓ Salir: Sale del programa. Mientras no se pulse otra opción, el menú debe
aparecer siempre*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char marca[30];
    char modelo[30];
    char dominio[50];
    float precio;
} Auto;

void Agregar(FILE *archivo, const char *nombreArch);
void Mostrar(FILE *archivo, const char *nombreArch);
void BuscarxMarcaModelo(FILE *archivo, const char *nombreArch);
void VaciarArchivo(FILE *archivo, const char *nombreArch);

int main() {
    int opcion;
    char *nombreArch = "Autos.bin";
    FILE *archivo = NULL;

    do {
        // Mostrar el menú principal
        printf("MENU PRINCIPAL\n");
        printf("1. Agregar autos al archivo\n");
        printf("2. Mostrar autos del archivo\n");
        printf("3. Buscar auto por marca o modelo\n");
        printf("4. Vaciar archivo\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("cls");
                Agregar(archivo, nombreArch);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                Mostrar(archivo, nombreArch);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                BuscarxMarcaModelo(archivo, nombreArch);
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                VaciarArchivo(archivo, nombreArch);
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 5);

    if (archivo != NULL) {
        fclose(archivo);
    }

    return 0;
}

void Agregar(FILE *archivo, const char *nombreArch) {
    Auto a;

    archivo = fopen(nombreArch, "ab");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("\nIngrese la marca del auto: ");
    fflush(stdin);
    gets(a.marca);

    printf("\nIngrese el modelo del auto: ");
    fflush(stdin);
    gets(a.modelo);

    printf("\nIngrese el dominio del auto: ");
    fflush(stdin);
    gets(a.dominio);

    printf("\nIngrese el precio del auto: ");
    scanf("%f", &a.precio);

    // Escribir el struct en el archivo
    fwrite(&a, sizeof(Auto), 1, archivo);

    printf("Auto agregado al archivo.\n");

    fclose(archivo);
}

void Mostrar(FILE *archivo, const char *nombreArch) {
    Auto a;
    int countItems = 0;

    archivo = fopen(nombreArch, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("Autos en el archivo:\n");

    // Leer y mostrar los productos del archivo
    while (fread(&a, sizeof(Auto), 1, archivo) == 1) {
        printf("Marca: %s\n", a.marca);
        printf("Modelo: %s\n", a.modelo);
        printf("Dominio: %s\n", a.dominio);
        printf("Precio: $%.2f\n\n", a.precio);
        countItems++;
    }

    printf("\nHay %d registros en el archivo\n", countItems);

    fclose(archivo);
}

void BuscarxMarcaModelo(FILE *archivo, const char *nombreArch) {
    Auto a;

    char nombreBuscado[30];
    int encontrado = 0;

    archivo = fopen(nombreArch, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("\nIngrese marca o modelo del auto a buscar: ");
    fflush(stdin);
    gets(nombreBuscado);

    while (fread(&a, sizeof(Auto), 1, archivo) == 1) {
        if (strstr(a.marca, nombreBuscado) || strstr(a.modelo, nombreBuscado)) {
            printf("Auto encontrado:\n");
            printf("Marca: %s\n", a.marca);
            printf("Modelo: %s\n", a.modelo);
            printf("Dominio: %s\n", a.dominio);
            printf("Precio: $%.2f\n\n", a.precio);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Auto no encontrado.\n");
    }

    fclose(archivo);
}

void VaciarArchivo(FILE *archivo, const char *nombreArch) {
    archivo = fopen(nombreArch, "wb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    fclose(archivo);

    printf("Archivo vaciado correctamente.\n");
}
