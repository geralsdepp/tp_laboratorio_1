#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"
#include "abm.h"
#define MOVIES 10

int main()
{
    S_Movie Movies[MOVIES];
    S_Movie Movie;
    int opcion;
    char seguir = 's';
   // int contador_pelis;
    hardcodear(Movies,5);
    do
    {
        opcion = menuOpcion();
        switch(opcion)
        {
        case 1:
            if(agregarPelicula(&Movie)== 1)
            {
                printf("Se ha dado de alta!!\n");
                generarArchivoBinario(&Movie);
            }
            else
                printf("Error.No se puede dar de alta ésta película!!\n");

            system("pause");
            system("cls");

            break;
        case 2:
            /*if(borrarPelicula(pMovie) == 1)
                printf("Se ha borrado con exito!!\n");
            else
                printf("No se ha borrado con exito!!\n");

            system("pause");
            system("cls");*/
            break;
        case 3:
            /*if(modificarPelicula(pMovie) == 1)
                printf("Se ha modificado con exito!!\n");
            else
                printf("No se ha modificado con exito!!\n");

            system("pause");
            system("cls");
            break;*/
        case 4:
            crearArrayPelicula(Movies);
            if(generarHTML(Movies) == 1)
                printf("Se ha generado la pagina!!\n");
            else
                printf("No se ha podido generar la pagina!!\n");

            system("pause");
            system("cls");
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }while(seguir == 's');

    return 0;
}
