#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANTIDAD 20


int main()
{
    char seguir='s';
    int opcion=0;

    EPersona lista[CANTIDAD];

    inicializarArray(lista,CANTIDAD);

    do
    {
        opcion = menuOpcion();

        switch(opcion)
        {
            case 1:
                agregarPersona(lista,CANTIDAD);
                break;
            case 2:
                borrarPersona(lista);
                break;
            case 3:
                ordenarStr(lista);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');

    return 0;
}
