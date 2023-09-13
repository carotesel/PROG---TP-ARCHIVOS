#include <stdio.h>
#include <stdlib.h>

/*5) Modificar el programa anterior para agregar una nueva función que permita buscar en el
archivo por producto y que muestre todos los datos asociados al producto.
*/

typedef struct
{
    char tipo[30];
    char marca[30];
    int tamanio; // TAMANIO EN G!!!!!!
    float precio;
    int stock;
} Producto;

void Agregar();
void Mostrar();
void BuscarProducto();

int main() {
    int opcion;

    do {
        // Mostrar el menú principal
        printf("MENU PRINCIPAL\n");
        printf("1. Agregar productos al archivo\n");
        printf("2. Mostrar productos del archivo\n");
        printf("3. Buscar producto\n");
        printf("4. Salir\n");
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
                BuscarProducto();
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

void Agregar() {
    char *nombreArch = "Products.bin";
    FILE *archivo = NULL;
    Producto p;

    archivo = fopen(nombreArch, "ab");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("\nIngrese el tipo del producto: ");
    fflush(stdin);
    gets(p.tipo);

    printf("\nIngrese la marca del producto: ");
    fflush(stdin);
    gets(p.marca);

    printf("\nIngrese el tamanio del producto (en grs.): ");
    scanf("%d", &p.tamanio);

    printf("\nIngrese el precio del producto: ");
    scanf("%f", &p.precio);

    printf("\nIngrese el stock del producto: ");
    scanf("%d", &p.stock);

    // Escribir el struct en el archivo
    fwrite(&p, sizeof(Producto), 1, archivo);

    printf("Producto agregado al archivo.\n");

    fclose(archivo);
}

void Mostrar() {
    char *nombreArch = "Products.bin";
    FILE *archivo = NULL;
    Producto p;

    // Abrir el archivo en modo de lectura
    archivo = fopen(nombreArch, "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("Productos en el archivo:\n");

    // Leer y mostrar los productos del archivo
    while (fread(&p, sizeof(Producto), 1, archivo) == 1) {
        printf("Tipo: %s\n", p.tipo);
        printf("Marca: %s\n", p.marca);
        printf("Tamaño: %d grs.\n", p.tamanio);
        printf("Precio: $%.2f\n", p.precio);
        printf("Stock: %d\n\n", p.stock);
    }

    // Cerrar el archivo
    fclose(archivo);
}
void BuscarProducto() {
    char *nombreArch = "Products.bin";
    FILE *archivo = NULL;
    Producto p;
    char nombreBuscado[30];
    int encontrado = 0;

    archivo = fopen(nombreArch, "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("\nIngrese el tipo del producto a buscar: ");
    fflush(stdin);
    gets(nombreBuscado);

    while (fread(&p, sizeof(Producto), 1, archivo) == 1) {
        if (strcmp(strlwr(nombreBuscado), strlwr(p.tipo)) == 0) {
            printf("Producto encontrado:\n");
            printf("Tipo: %s\n", p.tipo);
            printf("Marca: %s\n", p.marca);
            printf("Tamanio: %d grs.\n", p.tamanio);
            printf("Precio: $%.2f\n", p.precio);
            printf("Stock: %d\n\n", p.stock);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }

    fclose(archivo);
}
