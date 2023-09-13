#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void Agregar();
void Mostrar();

int main() {
    int opcion;

    do {
        // Mostrar el menú principal
        printf("MENU PRINCIPAL\n");
        printf("1. Agregar alumnos al archivo\n");
        printf("2. Mostrar alumnos del archivo\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("cls");
                Agregar();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                Mostrar();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}

void Agregar() {
    char nombre[50];
    char *nombreArch = "Alumnos.txt";
    FILE *archivo;

    // Abrir el archivo en modo de escritura (agregar al final)
    archivo = fopen(nombreArch, "a");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("Ingrese el nombre del alumno: ");
    scanf("%s", nombre);

    // Escribir el nombre en el archivo
    fprintf(archivo, "%s\n", nombre);

    printf("Nombre agregado al archivo.\n");

    // Cerrar el archivo
    fclose(archivo);
}

void Mostrar() {
    char nombre[50];
    FILE *archivo;

    // Abrir el archivo en modo de lectura
    archivo = fopen("Alumnos.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("Nombres de los alumnos en el archivo:\n");

    // Leer y mostrar los nombres del archivo
    while (fgets(nombre, sizeof(nombre), archivo)) {
        printf("%s", nombre);
    }

    // Cerrar el archivo
    fclose(archivo);
}
