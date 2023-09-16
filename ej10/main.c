#include <stdio.h>
#include <stdlib.h>

/*10) Hacer un programa que permita cargar datos en una estructura empleado, la cual debe
contener los siguientes miembros:
long ID_Empleado
char nombre[20]
char apellido[20]
float sueldo
int status // 0 inactivo, 1 empleado activo

*utilice memoria dinámica en lugar de la memoria estática para almacenar todos los
registros que se quieran de empleados. El programa deberá tener un menú de opciones.

1) Cargar nuevo empleados // carga datos en la estructura y los almacena en archivo
binario
2) buscar empleados inactivos // busca empleados inactivos y los muestra en pantalla
3) exportar datos
4) Salir

Exportar datos: Almacena en un archivo .TXT los datos de los empleados con estado 0
(Inactivo) Los datos de los empleados (cargados en la estructura) deben estar en un
archivo binario llamado empleados.bin

PD: recuerde realizar las comprobaciones de asignación de memoria y de apertura de
archivos, en todos los casos que corresponda, así como también, implementar funciones
de fclose() y free() cuando sea necesario.*/

typedef struct {
long int ID;
char nombre[20];
char apellido[20];
float sueldo;
int status;
}Empleado;

void agregarEmpleado();
void buscarEmpleadosInactivos();
void exportarDatos();

int main()
{

int opcion;

    do {
        // Mostrar el menú principal
        printf("MENU PRINCIPAL\n");
        printf("1. Agregar empleado al archivo\n");
        printf("2. Buscar empleados inactivos\n");
        printf("3. Exportar datos\n");
        printf("4. Salir\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("cls");
                agregarEmpleado();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                buscarEmpleadosInactivos();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                exportarDatos();
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}

void agregarEmpleado(){
FILE* archivo = NULL;
char* nombreArchivo ="empleados.bin";
Empleado *e;

e =(Empleado*)malloc(sizeof(Empleado));

archivo = fopen(nombreArchivo, "ab");

if (archivo == NULL){
    printf("\n Error");
        return -1;
}

    printf("\n Ingresar el ID del empleado: ");
    scanf("%ld",&e->ID);

    printf("\n Ingresar el nombre: ");
    fflush(stdin);
    gets(e->nombre);

    printf("\n Ingresar el apellido: ");
    fflush(stdin);
    gets(e->apellido);

    printf("\n Ingresar el sueldo del empleado: ");
    scanf("%f",&e->sueldo);

    do {
    printf("\n Ingresar el status del empleado (0 para inactivo, 1 para activo): ");
    scanf("%d", &e->status);

    if (e->status != 0 && e->status != 1) {
        printf("\nStatus no definido. Ingrese 0 para inactivo o 1 para activo.\n");
    }
} while (e->status != 0 && e->status != 1);

    fwrite(&*e,sizeof(Empleado),1,archivo);

    printf("\nEmpleado agregado al archivo.\n");

    fclose(archivo);
    free(e);
}

void buscarEmpleadosInactivos(){
    FILE* archivo = NULL;
    char* nombreArchivo ="empleados.bin";
    Empleado *e;
    int encontrado = 0;

    e = (Empleado *)malloc(sizeof(Empleado));

    archivo = fopen(nombreArchivo, "rb");
    if(archivo == NULL)
    {
        printf("\n Error");
        return -1;
    }
    while(fread(&(*e),sizeof(Empleado),1,archivo)==1)
    {
        if(e->status == 0){
        printf("\n ID: %ld", e->ID);
        printf("\n Nombre: %s", e->nombre);
        printf("\n Apellido: %s", e->apellido);
        printf("\n Status: %d\n", e->status);
        encontrado = 1;
        }
    }

        if (!encontrado) {
        printf("No se encontraron empleados inactivos\n");
    }


    fclose(archivo);
    free(e);
}

void exportarDatos(){
    FILE* archivo = NULL, *arch2= NULL;
    char* nombreArchivo ="empleados.bin", *nombreArch2 ="empleados.txt";
    Empleado *e;
    int encontrado = 0;

    e = (Empleado *)malloc(sizeof(Empleado));

    archivo = fopen(nombreArchivo, "rb");
    arch2 = fopen(nombreArch2, "w");

    if(archivo == NULL || arch2 == NULL)
    {
        printf("\n Error");
        return -1;
    }
    while(fread(&(*e),sizeof(Empleado),1,archivo)==1)
    {
        if(e->status == 0){
        fprintf(arch2,"\n ID: %ld", e->ID);
        fprintf(arch2,"\n Nombre: %s", e->nombre);
        fprintf(arch2,"\n Apellido: %s", e->apellido);
        fprintf(arch2,"\n Status: %d\n", e->status);
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
    free(e);

}



