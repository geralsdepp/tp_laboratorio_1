#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abm.h"
#include "misFunciones.h"
#include "misValidaciones.h"
#define ALTA 1
#define BAJA -1

int agregarPelicula(S_Movie* pMovie)
{
    int retorno = 0;
    char titulo_str[50],genero_str[30],duracion_str[5],descripcion_str[100],puntaje_str[5],linkImagen_str[500],id_str[5];
    int puntaje,id;
    float duracion;
    int flag = 0;

        while(!getStringNumeros("Ingrese id: ",id_str))
        {
            printf("El id debe ser numérico!!\n");
        }

        while(flag == 0)
        {
            getString("Ingrese titulo: ",titulo_str);
            if(!alfanumerico(titulo_str))
            {
                printf("El titulo solo puede contener letras y numeros!!\n");
            }
            else
                flag = 1;
        }

        while(!getStringLetras("Ingrese genero: ",genero_str))
        {
            printf("Solo puede contener letras!!\n");
        }
        while(!getStringNumerosFlotantes("Ingrese duración: ",duracion_str))
        {
            printf("Solo puede contener numeros decimales!!\n");
        }
        getString("Ingrese descripcion de la pelicula: ",descripcion_str);

        while(!getStringNumeros("Ingrese puntaje: ",puntaje_str))
        {
            printf("Solo puede contener numeros enteros!!\n");
        }
        getString("Ingrese link de imagen: ",linkImagen_str);

        puntaje = atoi(puntaje_str);
        duracion = atof(duracion_str);
        id = atoi(id_str);

        strcpy(pMovie->titulo,titulo_str);
        strcpy(pMovie->descripcion,descripcion_str);
        strcpy(pMovie->genero,genero_str);
        strcpy(pMovie->linkDeImagen,linkImagen_str);
        pMovie->duracion = duracion;
        pMovie->puntaje = puntaje;
        pMovie->id = id;
        pMovie->estado = ALTA;
        //contador_pelis = contador_pelis+1;

        retorno = 1/*contador_pelis*/;
    return retorno;
}

int borrarPelicula(S_Movie* pMovie)
{
    int i;
    int id;
    int retorno = 0;
    char id_str[5];
    while(!getStringNumeros("Ingrese id de la pelicula a borrar: ",id_str))
    {
        printf("El id debe ser numerico!!\n");
    }
    id = atoi(id_str);

    for(i=0;i<10;i++)
    {
        if(pMovie[i].id == id && pMovie[i].estado == ALTA)
        {
            pMovie[i].estado = BAJA;
            printf("El id: %d ha sido borrado!!\n",pMovie[i].id);
            retorno = 1;
            break;
        }
    }
    return retorno;
}

int modificarPelicula(S_Movie* pMovie)
{
    int i;
    int id,flag = 0;
    int retorno = 0;
    char id_str[5],titulo_str[50],genero_str[30],duracion_str[5],descripcion_str[100],puntaje_str[5],linkImagen_str[500];
    int puntaje;
    float duracion;

    while(!getStringNumeros("Ingrese id de la pelicula a modificar: ",id_str))
    {
        printf("El id debe ser numerico!!\n");
    }
    id = atoi(id_str);

    for(i=0;i<10;i++)
    {
        if(pMovie[i].id == id && pMovie[i].estado == ALTA)
        {
            while(flag == 0)
            {
                getString("Ingrese titulo: ",titulo_str);
                if(!alfanumerico(titulo_str))
                {
                    printf("El titulo solo puede contener letras y numeros!!\n");
                }
                else
                    flag = 1;
            }
            while(!getStringLetras("Ingrese genero: ",genero_str))
            {
                printf("Solo puede contener letras!!\n");
            }
            while(!getStringNumerosFlotantes("Ingrese duración: ",duracion_str))
            {
                printf("Solo puede contener numeros decimales!!\n");
            }
            getString("Ingrese descripcion de la pelicula: ",descripcion_str);

            while(!getStringNumeros("Ingrese puntaje: ",puntaje_str))
            {
                printf("Solo puede contener numeros enteros!!\n");
            }
            getString("Ingrese link de imagen: ",linkImagen_str);

            puntaje = atoi(puntaje_str);
            duracion = atof(duracion_str);

            strcpy(pMovie[i].titulo,titulo_str);
            strcpy(pMovie[i].descripcion,descripcion_str);
            strcpy(pMovie[i].genero,genero_str);
            strcpy(pMovie[i].linkDeImagen,linkImagen_str);
            pMovie[i].duracion = duracion;
            pMovie[i].puntaje = puntaje;
            retorno = 1;
            break;
        }
    }
    return retorno;
}
