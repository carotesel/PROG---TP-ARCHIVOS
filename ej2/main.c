#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/*2) Hacer un programa que permita armar una estructura Proveedor con los siguientes datos:
a. Nombre: Ej: Microsoft
b. CUIT: 309765329
c. Condición: Ej: activo
Ingresar 20 registros y Almacenarlos en un archivo binario.
El programa debe pedir que número de registro buscar. Ej: 5. El programa deberá mostrar
el proveedor ubicado en la posición ingresada por teclado.*/

typedef struct
{
    char nombre[30];
    int CUIT;
    char condicion[30];
}Proveedor;

int main()
{
    Proveedor p[MAX];
    FILE *archivo1 = NULL;
    char *nombreArch1 = "Proveedores.bin";

    for (int i=0; i<MAX; i++){
        printf("\nDatos proveedor %d\n", i + 1);
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(p[i].nombre);

        printf("\nIngrese CUIT: ");
        scanf("%d", &p[i].CUIT);

        printf("\nIngrese condicion: ");
        fflush(stdin);
        gets(p[i].condicion);
    }

    archivo1 = fopen(nombreArch1, "wb");

    if(archivo1 == NULL){
        printf("Error al abrir el archivo.\n");
    return -1;
    }

    fwrite(p, sizeof(Proveedor), MAX, archivo1);
    printf("\nDatos almacenados en el archivo");
    fclose(archivo1);

    int numero_registro;
    printf("\nIngrese numero de registro a buscar: ");
    scanf("%d", &numero_registro);

    archivo1 = fopen(nombreArch1, "rb");
  if (archivo1 == NULL) {
    printf("Error al abrir el archivo.\n");
    return -1;
  }

  // BUSCA REGISTRO EN LA POSICION SOLICITADA Y LO ALMCENA EN UN NUEVO STRUCT PARA MOSTRARLO
  if (numero_registro >= 1 && numero_registro <= MAX) {
        fseek(archivo1, (numero_registro - 1) * sizeof(Proveedor), SEEK_SET);
        Proveedor pEncontrado;
        fread(&pEncontrado, sizeof(Proveedor), 1, archivo1);
        printf("Proveedor en la posicion %d:\n", numero_registro);
        printf("Nombre: %s\n", pEncontrado.nombre);
        printf("CUIT: %llu\n", pEncontrado.CUIT);
        printf("Condicion: %s\n", pEncontrado.condicion);
    } else {
        printf("Número de registro fuera de rango.\n");
    }


    return 0;
}
