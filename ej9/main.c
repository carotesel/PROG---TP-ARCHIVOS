#include <stdio.h>
#include <stdlib.h>

/*9) Hacer un programa que permita crear una estructura de productos en MEMORIA
DINAMICA, y que nos permita almacenar la informacion en un archivo binario. Visualizar el
archivo creado. Utilizar funciones para todo.*/

typedef struct
{
    char tipo[50];
    char marca[50];
    float precio;
}Producto;


void agregarProducto();
void listarProductos();

int main()
{
    int opcion;

    do {
        // Mostrar el menú principal
        printf("MENU PRINCIPAL\n");
        printf("1. Agregar producto al archivo\n");
        printf("2. Listar Productos\n");
        printf("3. Salir\n\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("cls");
                agregarProducto();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                listarProductos();
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


void agregarProducto()
{
    Producto *p;
    FILE *archivo = NULL;
    char *nombreArchivo = "productos.bin";
    p = (Producto *)malloc(sizeof(Producto)); // asignar memoria dinamica

    archivo = fopen(nombreArchivo, "ab");
    if(archivo == NULL)
    {
        printf("\n Error");
        return -1;
    }
    printf("\n Ingresar el tipo producto: ");
    fflush(stdin);
    gets(p->tipo);

    printf("\n Ingresar la marca del producto: ");
    fflush(stdin);
    gets(p->marca);

    printf("\n Ingresar el precio del producto: ");
    scanf("%f",&p->precio);

    fwrite(&*p,sizeof(Producto),1,archivo);

    fclose(archivo);
    free(p);

    printf("\n PRODUCTO AGREGADO \n");

}

void listarProductos()
{
    Producto *p;
    FILE *archivo = NULL;
    char *nombreArchivo = "productos.bin";
    p = (Producto *)malloc(sizeof(Producto));

    archivo = fopen(nombreArchivo, "rb");
    if(archivo == NULL)
    {
        printf("\n Error");
        return -1;
    }
    while(fread(&(*p),sizeof(Producto),1,archivo)==1)
    {
        printf("\n Tipo: %s", p->tipo);
        printf("\n Marca: %s", p->marca);
        printf("\n Precio: %f\n", p->precio);
    }
    fclose(archivo);
    free(p);
}
