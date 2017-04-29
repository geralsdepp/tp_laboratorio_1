#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"
#define DISPONIBLE 0
#define NO_DISPONIBLE 1

int cont_personas;

int menuOpcion(void)
{
    int opcion;
    printf("MENU DE OPCIONES:\n1.AGREGAR UNA PERSONA.\n2.BORRAR UNA PERSONA.\n3.IMPRIMIR LISTA ORDENADA POR NOMBRE.\n4.IMPRIMIR GRAFICO DE EDADES\n5.SALIR\nEliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

void inicializarArray(EPersona lista[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        lista[i].estado = DISPONIBLE;
    }
}

int obtenerEspacioLibre(EPersona lista[],int cant)
{
    int i;
    int retorno;

    for(i=0; i<cant; i++)
    {
        if(lista[i].estado == DISPONIBLE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void agregarPersona(EPersona lista[],int cant)
{
    int edad;
    long int dni;
    char aux[20];
    int i,flag = 0;

    i = obtenerEspacioLibre(lista,cant);

    printf("El primer espacio libre es: %d\n",i);
    while(flag == 0)
    {
        if(!getStringLetras("Ingrese nombre: ",aux))
        {
            printf("El nombre debe contener letras!!\n");
        }
        else
        {
            flag = 1;
        }
    }

        edad = obtenerInt("Ingrese edad: ","Edad incorrecta: la edad debe ser entre 0 y 100\n","99","00");

        dni = obtenerDni("Ingrese dni: ","Debe ingresar un dni correcto!!\n","99999999","00000001");

        strcpy(lista[i].nombre,aux);
        lista[i].edad = edad;
        lista[i].dni = dni;
        lista[i].estado = NO_DISPONIBLE;
        cont_personas = i+1;
}
void borrarPersona(EPersona lista[])
{
    long int dni;
    int indice;

    printf("Ingrese DNI a ser borrado: ");
    fflush(stdin);
    scanf("%ld",&dni);

    indice = buscarPorDni(lista,dni);

    lista[indice].estado = DISPONIBLE;

    if(lista[indice].estado == DISPONIBLE)
    {
        printf("BORRADO\n");
    }
}

int buscarPorDni(EPersona lista[], long int dni)
{
    int i;
    int retorno;

    for(i=0; i<cont_personas; i++)
    {
        if(dni == lista[i].dni)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
void ordenarStr(EPersona lista[])
{
    int i;
    char str[30];
    for(i=0;i<cont_personas-1;i++)
    {
        if(strcmp(lista[i].nombre,lista[i+1].nombre) > 0)
        {
            strcpy(str,lista[i].nombre);
            strcpy(lista[i].nombre,lista[i+1].nombre);
            strcpy(lista[i+1].nombre,str);
        }
    }

    for(i=0; i<cont_personas; i++)
    {
        printf("%s\n",lista[i].nombre);
    }
}

void mostrarGrafico(EPersona lista[])
{
    int i, hasta18=3, de19a35=5, mayorDe35=7, flag=0, mayor;
    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }
    else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
            mayor = mayorDe35;
        }
    }
    for(i=mayor; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);
        if(i<= hasta18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);
}
