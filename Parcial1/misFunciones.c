#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#include "misValidaciones.h"
#define DISPONIBLE 0
#define NO_DISPONIBLE 1
#define ALTA 1
#define BAJA -1
#define VACIO 0

int cont_usuarios;
int cont_publicaciones;
int cont_producto;
int cont_stock;

int menuOpcion(void)
{
    int opcion;
    printf("MENU DE OPCIONES:\n1.ALTA USUARIO.\n2.MODIFICAR DATOS DE USUARIO.\n3.BAJA DE USUARIO.\n4.PUBLICAR PRODUCTO\n5.MODIFICAR PUBLICACION\n6.CANCELAR PUBLICACION\n7.COMPRAR PRODUCTO\n8.LISTAR PUBLICACIONES DE USUARIO\n9.LISTAR PUBLICACIONES\n10.LISTAR USUARIOS\nEliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

void inicializarArray_usuario(S_Usuario ficha[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        ficha[i].estado = DISPONIBLE;
    }
}

void inicializarArray_producto(S_Producto prod[],int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        prod[i].estado = DISPONIBLE;
    }
}

int obtenerEspacioLibre_usuario(S_Usuario ficha[],int cant)
{
    int retorno;

    for(cont_usuarios=0; cont_usuarios<cant; cont_usuarios++)
    {
        if(ficha[cont_usuarios].estado == DISPONIBLE)
        {
            retorno = cont_usuarios;
            break;
        }
    }
    return retorno;
}

int obtenerEspacioLibre_producto(S_Producto prod[],int cant)
{
    int retorno;

    for(cont_producto = 0; cont_producto<cant; cont_producto++)
    {
        if(prod[cont_producto].estado == DISPONIBLE)
        {
            retorno = cont_producto;
            break;
        }
    }
    return retorno;
}

void alta_usuario(S_Usuario ficha[],int cant)
{
    int flag = 0,i;
    char nombre[30], password[10];

    i = obtenerEspacioLibre_usuario(ficha,cant);

    printf("El primer espacio libre es: %d\n",i);

    while(flag == 0)
    {
        if(!getStringLetras("Ingrese nombre: ",nombre))
        {
            printf("Reingrese!!\n");
        }
        else
            flag = 1;
    }
    flag = 0;
    while(flag == 0)
    {
        if(!getStringLetras("Ingrese password: ",password))
        {
            printf("Reingrese!!\n");
        }
        else
            flag = 1;
    }

    strcpy(ficha[i].nombre,nombre);
    strcpy(ficha[i].password,password);
    ficha[i].idUsuario = cont_usuarios;
    ficha[i].estado = ALTA;
}

void modificar_usuario(S_Usuario ficha[])
{
    int i,flag = 0,id;
    char id_str[5];
    char nombre[30], password[10];

    if(!getStringNumeros("Ingrese id a modificar: ",id_str))
    {
        printf("El id debe contener letras!!");
    }
    else
    {
        id = atoi(id_str);
        for(i=0; i<cont_usuarios+1; i++)
        {
            if(id == ficha[i].idUsuario && ficha[i].estado == ALTA)
            {
                while(flag == 0)
                {
                    if(!getStringLetras("Ingrese password: ",password))
                    {
                        printf("Reingrese!!\n");
                    }
                    else
                        flag = 1;
                }
                flag = 0;

                strcpy(ficha[i].nombre,nombre);
                strcpy(ficha[i].password,password);
                ficha[i].idUsuario= cont_usuarios;
                ficha[i].estado = ALTA;
                break;
            }
            else
                printf("El id ingresado no existe o no esta dado de alta!! \n");
                break;
        }
    }
}

void baja_usuario(S_Usuario ficha[])
{
    int i;
    int id;

    printf("Ingrese el id a dar de baja: ");
    scanf("%d",&id);

    for(i=0; i<cont_usuarios+1; i++)
    {
        if(id == ficha[i].idUsuario && ficha[i].estado == ALTA)
        {
            ficha[i].estado = BAJA;
            break;
        }
        else
            printf("El id ingresado no existe!!\n");
            break;
    }
}

void publicar_producto(S_Producto prod[],S_Usuario ficha[],int cant)
{
    int flag = 0,i,j;
    int precio, stock,idU;
    char nombre[30],precio_str[5],stock_str[10],id_str[5];

    i = obtenerEspacioLibre_producto(prod,cant);

    while(flag==0)
    {
        if(!getStringNumeros("Ingrese id del usuario: ",id_str))
        {
            printf("El id debe contener letras!!");
        }
        else
            flag = 1;
    }
    flag = 0;
    idU = atoi(id_str);
    //recorro id
    for(j=0;j<cont_usuarios+1;j++)
    {
        if(idU == ficha[j].idUsuario)
        {
            while(flag == 0)
            {
                if(!getStringLetras("Ingrese nombre: ",nombre))
                {
                    printf("Reingrese!!\n");
                }
                else
                    flag = 1;
            }
            flag = 0;
            while(flag == 0)
            {
                if(!getStringNumeros("Ingrese precio: ",precio_str))
                {
                    printf("Reingrese!\n");
                }
                else
                    flag = 1;
            }
            flag = 0;
            while(flag == 0)
            {
                if(!getStringNumeros("Ingrese numero de stock: ",stock_str))
                {
                    printf("Reingrese!\n");
                }
                else
                    flag = 1;
            }
        }
    }

    precio = atoi(precio_str);
    stock = atoi(stock_str);

    strcpy(prod[i].nombre,nombre);
    prod[i].precio = precio;
    prod[i].stock = stock;
    prod[i].idProducto = i;
    prod[i].estado = ALTA;
    ficha[i].contProducto = i+1;

}

void modificar_publicacion(S_Producto prod[],S_Usuario ficha[])
{
    int idP,idU,precio,stock;
    int i,flag = 0;
    char id_str[5],precio_str[5],stock_str[5];

    while(flag==0)
    {
        if(!getStringNumeros("Ingrese id del usuario: ",id_str))
        {
            printf("El id debe ser numerico!!\n");
        }
        else
            flag = 1;
    }
    flag = 0;

    idU = atoi(id_str);
    //recorro id de usuarios
    for(i=0;i<cont_usuarios+1;i++)
    {
        if(idU == ficha[i].idUsuario)
        {
            printf("Campos del producto:\nid: %d\nNombre: %s\nPrecio: %d\nStock: %d\nCantidad vendida: %d\n",prod[idU].idProducto,prod[idU].nombre,prod[idU].precio,prod[idU].stock,prod[idU].cantVendida);
        }
        else
            printf("No se encuentra el id ingresado\n");
    }
    //recorro id de productos
    while(flag == 0)
    {
        if(!getStringNumeros("Ingrese id del producto: ",id_str))
        {
            printf("El id debe ser numerico!!\n");
        }
        else
            flag = 1;
    }
    flag = 0;
    idP = atoi(id_str);

    for(i=0;i<cont_producto+1;i++)
    {
        if(idP == prod[i].idProducto)
        {
             while(flag == 0)
            {
                if(!getStringNumeros("Ingrese nuevo precio: ",precio_str))
                {
                    printf("Reingrese!\n");
                }
                else
                    flag = 1;
            }
            flag = 0;
            while(flag == 0)
            {
                if(!getStringNumeros("Ingrese nuevo numero de stock: ",stock_str))
                {
                    printf("Reingrese!\n");
                }
                else
                    flag = 1;
            }
            break;
        }
        else if(cont_producto + 1 == i)
        {
            printf("El id no existe!!");
        }
    }

    precio = atoi(precio_str);
    stock = atoi(stock_str);

    prod[idP].precio = precio;
    prod[idU].stock = stock;

}

void cancelar_publicacion(S_Producto prod[],S_Usuario ficha[])
{
    char id_str[5];
    int i,idU,idP;
    int flag = 0;

    if(!getStringNumeros("Ingrese id del usuario: ",id_str))
    {
        printf("El id debe ser numerico!!\n");
    }
    idU = atoi(id_str);
    //recorro id de usuarios
    for(i=0;i<cont_usuarios+1;i++)
    {
        if(idU == ficha[i].idUsuario)
        {
            printf("Campos del producto:\nid: %d\nNombre: %s\nPrecio: %d\nStock: %d\nCantidad vendida: %d\n",prod[idU].idProducto,prod[idU].nombre,prod[idU].precio,prod[idU].stock,prod[idU].cantVendida);
        }
        else
            printf("No se encuentra el id ingresado\n");
    }
    //recorro id de productos
    while(flag == 0)
    {
         if(!getStringNumeros("Ingrese id del producto que desea cancelar: ",id_str))
        {
            printf("El id debe ser numerico!!\n");
        }
        else
            flag = 1;
    }
    flag = 0;

    idP = atoi(id_str);

    for(i=0;i<cont_producto+1;i++)
    {
        if(idP == prod[i].idProducto)
        {
            prod[idP].estado = BAJA;
            break;
        }
        else if(cont_producto + 1 == i)
        {
            printf("El id no existe!!");
        }
    }
    while(flag==0)
    {
            if(!getStringNumeros("Ingrese id del producto que desea cancelar: ",id_str))
            {
                printf("El id debe ser numerico!!\n");
            }
            else
                flag = 1;
    }

    idP = atoi(id_str);

    for(i=0;i<cont_producto+1;i++)
    {
        if(idP == prod[i].idProducto)
        {
            prod[idP].estado = BAJA;
            break;
        }
        else if(cont_producto + 1 == i)
        {
            printf("El id no existe!!");
        }
    }
}
void comprar_producto(S_Producto prod[],S_Usuario ficha[])
{
    char id_str[5],calificacion_str[5];
    int i,idP,calificacion,flag = 0;
    while(flag ==0)
    {
        if(!getStringNumeros("Ingrese id del producto : ",id_str))
        {
            printf("El id debe ser numerico!!\n");
        }
        else
            flag = 1;
    }

    idP = atoi(id_str);

    for(i=0;i<cont_producto+1;i++)
    {
        if(idP == prod[i].idProducto && prod[i].stock > 0)
        {
            while(flag == 0)
            {
                if(!getStringNumeros("Ingrese calificacion para el vendedor: ",calificacion_str))
                {
                    printf("Debe ser numerico!!\n");
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        else if(cont_producto + 1 == i)
        {
            printf("El id no existe!!");
        }
    }
    calificacion = atoi(calificacion_str);
    prod[i].cantVendida = i+1;
    prod[i].stock = prod[i].stock - 1;
    ficha[i].calificacion = calificacion;
}

void listar_public_usuario(S_Usuario ficha[])
{
    char id_str[5];
    int idU,i,j;
    int flag = 0;

    while(flag == 0)
    {
        if(!getStringNumeros("Ingrese id del usuario: ",id_str))
        {
            printf("El id debe ser numerico!!\n");

        }
        else
            flag = 1;
    }

    idU = atoi(id_str);
    //recorro id de usuarios
    for(i=0;i<cont_usuarios+1;i++)
    {
        if(idU == ficha[i].idUsuario)
        {
            for(j=0;j<ficha[idU].contProducto;j++)
            {
                printf("Campos del producto:\nid: %d\nNombre: %s\nPrecio: %d\nStock: %d\nCantidad vendida: %d\n\n",ficha[idU].producto.idProducto,ficha[idU].producto.nombre,ficha[idU].producto.precio,ficha[idU].producto.stock,ficha[idU].producto.cantVendida);
            }
        }
        else if (cont_usuarios + 1 == i)
            printf("No se encuentra el id ingresado\n");
    }
}

void listar_public(S_Usuario ficha[])
{
    int i;

    for(i=0;i<cont_producto;i++)
    {
        printf("ID: %d\nProducto: %s\nPrecio: %d\nCantidad Vendida: %d\nStock: %d\nNombre de Usuario: %s",ficha[i].producto.idProducto,ficha[i].producto.nombre,ficha[i].producto.precio,ficha[i].producto.cantVendida,ficha[i].producto.stock,ficha[i].nombre);
    }
}
