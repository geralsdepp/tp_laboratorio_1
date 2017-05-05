#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"
#define USUARIOS 100
#define PRODUCTOS 1000
#define ALTA 1
#define BAJA -1
#define VACIO 0

int main()
{
    char seguir = 's';
    int opcion;
    S_Usuario ficha[USUARIOS];
    S_Producto prod[PRODUCTOS];

    inicializarArray_usuario(ficha,USUARIOS);
    inicializarArray_producto(prod,PRODUCTOS);

    do
    {
        opcion = menuOpcion();

        switch(opcion)
        {
        case 1:
            alta_usuario(ficha,USUARIOS);
            break;
        case 2:
            modificar_usuario(ficha);
            break;
        case 3:
            baja_usuario(ficha);
            break;
        case 4:
            publicar_producto(prod,ficha,PRODUCTOS);
            break;
        case 5:
            modificar_publicacion(prod,ficha);
            break;
        case 6:
            cancelar_publicacion(prod,ficha);
            break;
        case 7:
            comprar_producto(prod,ficha);
            break;
        case 8:
            listar_public_usuario(ficha);
            break;
        case 9:
            listar_public(ficha);
            break;
        case 10:
            break;
        case 11:
            seguir = 'n';
            break;
        }
        system("cls");
    }while(seguir == 's');
    return 0;
}
