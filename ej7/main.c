#include <stdio.h>
#include <stdlib.h>

/*7) Hacer una agenda telefónica, utilizando funciones y archivos binarios que permita:
1) Ingresar datos de amigos
2) Listar a los amigos
3) Buscar por nombre
4) Informar la cantidad de amigos existentes
5) Vaciar el archivo
6) Eliminar el archivo
7) Salir*/

typedef struct
{
    char nombre[30];
    char apellido[30];
    int telefono;
} Amigo;

void Agregar();
void Mostrar();
void BuscarxNombre();
void VaciarArchivo();
void ContarAmigos();
void BorrarArchivo();


int main() {
    int opcion;

    do {
        // Mostrar el menú principal
        printf("MENU PRINCIPAL\n");
        printf("1. Agregar amigo al archivo\n");
        printf("2. Mostrar amigos del archivo\n");
        printf("3. Buscar amigo por nombre\n");
        printf("4. Informar cantidad de amigos existentes\n");
        printf("5. Vaciar el archivo\n");
        printf("6. Eliminar el archivo\n");
        printf("7. Salir\n");
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
                BuscarxNombre();
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                ContarAmigos();
                system("pause");
                system("cls");
                break;

            case 5:
                system("cls");
                VaciarArchivo();
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                BorrarArchivo();
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}

void Agregar() {
    char *nombreArch = "Agenda.bin";
    FILE *archivo = NULL;
    Amigo a;

    archivo = fopen(nombreArch, "ab");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(a.nombre);

    printf("\nIngrese apellido: ");
    fflush(stdin);
    gets(a.apellido);

    printf("\nIngrese telefono: ");
    scanf("%d", &a.telefono);

    // Escribir el struct en el archivo
    fwrite(&a, sizeof(Amigo), 1, archivo);

    printf("Amigo agregado al archivo.\n");

    fclose(archivo);
}

void Mostrar() {
    char *nombreArch = "Agenda.bin";
    FILE *archivo = NULL;
    Amigo a;

    // Abrir el archivo en modo de lectura
    archivo = fopen(nombreArch, "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("Amigos en el archivo:\n");

    // Leer y mostrar los productos del archivo
    while (fread(&a, sizeof(Amigo), 1, archivo) == 1) {
        printf("Nombre: %s\n", a.nombre);
        printf("Apellido: %s\n", a.apellido);
        printf("Telefono: %d\n\n", a.telefono);
    }

    // Cerrar el archivo
    fclose(archivo);
}
void BuscarxNombre()
{
    char *nombreArch = "Agenda.bin";
    FILE *archivo = NULL;
    Amigo a;

    char nombreBuscado[30];
    int encontrado = 0;

    archivo = fopen(nombreArch, "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("\nIngrese nombre del amigo a buscar: ");
    fflush(stdin);
    gets(nombreBuscado);

    while (fread(&a, sizeof(Amigo), 1, archivo) == 1) {
        if ((strcmp(strlwr(nombreBuscado), strlwr(a.nombre)) == 0))  {
            printf("Nombre: %s\n", a.nombre);
            printf("Apellido: %s\n", a.apellido);
            printf("Telefono: %d\n\n", a.telefono);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }

    fclose(archivo);
}

void ContarAmigos(){
Amigo amigoLeido;
char *nombreArch = "Agenda.bin";
FILE *archivo = NULL;
Amigo a;
int contador = 0;

    archivo = fopen(nombreArch, "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    // Contar amigos en el archivo
    while (fread(&amigoLeido, sizeof(Amigo), 1, archivo) == 1) {
        contador++;
    }

    fclose(archivo);

    printf("\nHay %d amigos en la agenda\n", contador);
}

void VaciarArchivo() {
    char *nombreArch = "Agenda.bin";
    FILE *archivo = NULL;

    // Reabrir el archivo en modo de escritura truncando su contenido
    archivo = fopen(nombreArch, "wb");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    fclose(archivo);

    printf("Archivo vaciado correctamente.\n");
}

void BorrarArchivo() {
if (remove("Agenda.bin") == 0) {
        printf("Archivo eliminado.\n");
    } else {
        perror("Error al eliminar el archivo");
    }
}

