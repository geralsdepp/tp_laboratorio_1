#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"
#include "ArrayList.h"

int main()
{
    int opcion;
    char seguir = 's';

ArrayList* lista_destinatarios = al_newArrayList();
inicializar_lista(lista_destinatarios);
ArrayList* lista_negra = al_newArrayList();
inicializar_lista(lista_negra);
ArrayList* lista_depuracion = al_newArrayList();
inicializar_lista(lista_depuracion);

    do
    {
        opcion = menuOpcion();

        switch(opcion)
        {
        case 1:
            cargar_destinatarios(lista_destinatarios);
            break;
        case 2:
            cargar_listaNegra(lista_negra);
            break;
        case 3:
            depurar(lista_destinatarios,lista_negra,lista_depuracion);
            break;
        case 4:
            listar(lista_depuracion);
            break;
        case 5:
            seguir = 'n';
            break;
        }
        system("pause");
        system("cls");
    }while(seguir == 's');
    return 0;
}
