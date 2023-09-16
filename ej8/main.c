#include <stdio.h>
#include <stdlib.h>

/*8) Implementando funciones, y archivos binarios en C se pide:
Crear una estructura de datos ALUMNO y guardarla en un archivo binario. La estructura debe
contener:
Nombre CHAR 30
Apellido CHAR 20
Edad int
A�o int
Promedio Acad�mico float

El programa debe tener un men� de opciones para:
a) Cargar Alumnos
b) Listar Alumnos con edad >= 20 a�os
c) Listar todo
d) Export
e) Salir

Cargar alumnos: debe permitir agregar nuevos alumnos al archivo. Si el archivo no existe se debe
crear. Los datos se colocaran al final.
Listar Alumnos con edad >= 20 a�os: se debe recorrer el archivo y mostrar en pantalla todos los
alumnos que tengan edad >= 20 a�os, mostrando �nicamente el Nombre Apellido y edad
Listar todo: se debe mostrar en pantalla todo el contenido del archivo
Salir: termina el programa. Hasta que no se seleccione esta opci�n, el programa no deber�
terminar (luego de cada opci�n muestra nuevamente el men�)

Export: es una funci�n que permite buscar todas las notas superiores a 9. Deber� tomar el
nombre, apellido y nota de cada alumno que cumpla esa condici�n y guardar esos datos en otro
archivo llamado �export.txt�.
*/

typedef struct
{
    char nombre[30];
    char apellido[30];
    int edad;
    int anio;
    float promedio;
} Alumno;

void Agregar();
void MostrarAlumnosSpecific();
void MostrarAlumnos();
void VaciarArchivo();
void ExportarArchivo();

int main() {
    int opcion;

    do {
        // Mostrar el men� principal
        printf("MENU PRINCIPAL\n");
        printf("1. Agregar alumno al archivo\n");
        printf("2. Listar Alumnos con edad >= 20 a�os\n");
        printf("3. Listar todos los alumnos\n");
        printf("4. Export\n");
        printf("5. Salir\n\n");
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
                MostrarAlumnosSpecific();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                MostrarAlumnos();
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                ExportarArchivo();
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

    return 0;
}

void Agregar() {
    char *nombreArch = "Alumnos.bin";
    FILE *archivo = NULL;
    Alumno a;

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

    printf("\nIngrese edad: ");
    scanf("%d", &a.edad);

    printf("\nIngrese anio: ");
    scanf("%d", &a.anio);

    printf("\nIngrese promedio academico: ");
    scanf("%f", &a.promedio);

    // Escribir el struct en el archivo
    fwrite(&a, sizeof(Alumno), 1, archivo);

    printf("Alumno agregado al archivo.\n");

    fclose(archivo);
}

void MostrarAlumnos() {
    char *nombreArch = "Alumnos.bin";
    FILE *archivo = NULL;
    Alumno a;

    // Abrir el archivo en modo de lectura
    archivo = fopen(nombreArch, "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("Amigos en el archivo:\n");

    // Leer y mostrar los productos del archivo
    while (fread(&a, sizeof(Alumno), 1, archivo) == 1) {
        printf("Nombre: %s\n", a.nombre);
        printf("Apellido: %s\n", a.apellido);
        printf("Edad: %d\n", a.edad);
        printf("Anio: %d\n", a.anio);
        printf("Promedio: %.2f\n\n", a.promedio);
    }

    // Cerrar el archivo
    fclose(archivo);
}

void MostrarAlumnosSpecific()
{
    char *nombreArch = "Alumnos.bin";
    FILE *archivo = NULL;
    Alumno a;

    int encontrado = 0;

    archivo = fopen(nombreArch, "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    while (fread(&a, sizeof(Alumno), 1, archivo) == 1) {
        if (a.edad >= 20)  {
            printf("Nombre: %s\n", a.nombre);
            printf("Apellido: %s\n", a.apellido);
            printf("Edad: %d\n\n", a.edad);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron alumnos con edad >= 20\n");
    }

    fclose(archivo);
}

void ExportarArchivo() {
    char *nombreArch = "Alumnos.bin";
    char *nombreArxh2 = "Alumnos.txt"; // Cambi� el nombre del archivo de destino
    FILE *archivo = NULL;
    FILE *arch2 = NULL;
    Alumno a;

    int encontrado = 0;

    archivo = fopen(nombreArch, "rb");
    arch2 = fopen(nombreArxh2, "w");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    if (arch2 == NULL) {
        printf("No se pudo abrir el archivo de exportaci�n.\n");
        return;
    }

    while (fread(&a, sizeof(Alumno), 1, archivo) == 1) {
        if (a.promedio > 9) {
            fprintf(arch2, "Nombre: %s\n", a.nombre); // Usar fprintf para pasar cosa x cosa al archivo export
            fprintf(arch2, "Apellido: %s\n", a.apellido);
            fprintf(arch2, "Promedio: %.2f\n\n", a.promedio);
            encontrado = 1;
        }
    }

    if (encontrado) {
        printf("Archivo exportado correctamente\n");
    } else {
        printf("No se encontraron alumnos con promedio mayor a 9 para exportar\n");
    }

    fclose(archivo);
    fclose(arch2);
}
