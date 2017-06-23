#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#include "ArrayList.h"
#include "misSetsyGets.h"
#include "misValidaciones.h"


int menuOpcion(){
    int opcion;
    printf("MENU DE OPCIONES:\n");
    printf("1.CARGAR DESTINATARIOS.\n");
    printf("2.CARGAR LISTA NEGRA.\n");
    printf("3.DEPURAR.\n");
    printf("4.LISTAR\n");
    printf("5.SALIR\n");
    printf("Eliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

S_Usuario* usuarios_new()
{
    S_Usuario* returnAux = NULL;
    returnAux = (S_Usuario*)malloc(sizeof(S_Usuario));
    return returnAux;
}

ArrayList* inicializar_lista(ArrayList* lista)
{
    lista = (ArrayList*)calloc(lista->reservedSize,sizeof(ArrayList));
    return lista;
}

int get_nextID(ArrayList* this,int estructura)
{
    int i;
    int indiceMaximo = 0;

    S_Usuario* auxUsuario = NULL;
    auxUsuario = usuarios_new();

    if(this != NULL)
    {
        if(estructura == 1 && auxUsuario != NULL)
        {
            for(i=0; i<this->len(this); i++) //si i es menor al tamaño del arraylist
            {
               auxUsuario = this->get(this,i); //obtengo el puntero del indice "i"
               if(auxUsuario->idUsuario > indiceMaximo)
               {
                   indiceMaximo = auxUsuario->idUsuario;
               }
            }
        }
    }
    return indiceMaximo+1;
}

void cargar_destinatarios(ArrayList* this)
{
    char nombre[30];
    S_Usuario* auxUsuario = NULL;
    auxUsuario = usuarios_new();
    FILE* pFile;
    int len = al_len(this);

    getString("Ingrese nombre del archivo : ",nombre);

    pFile = fopen(nombre,"r");
    parserEmployee(pFile,this,&len);
    imprimir_usuarios(this);
    this->add(this,auxUsuario);
}

void cargar_listaNegra(ArrayList* this)
{
    char nombre[30];
    S_Usuario* auxUsuario = NULL;
    auxUsuario = usuarios_new();
    FILE* pFile;
    int len = al_len(this);

    getString("Ingrese nombre del archivo : ",nombre);

    pFile = fopen(nombre,"r");
    parserEmployee(pFile,this,&len);
    imprimir_usuarios(this);
    this->add(this,auxUsuario);
}

void imprimir_usuarios(ArrayList* lista_usuarios)
{
    S_Usuario* auxUsuario = NULL;

    int j,longitudUsuarios;
    longitudUsuarios = lista_usuarios->len(lista_usuarios);
    for(j=0; j<longitudUsuarios;j++)
    {
        auxUsuario = (S_Usuario*)lista_usuarios->get(lista_usuarios,j);
        printf("Nombre: %s | email: %s\n",usuarios_getName(auxUsuario),usuarios_getEmail(auxUsuario));
    }
    system("pause");
}

int parserEmployee(FILE* pFile,ArrayList* lista, int* len)
{
    S_Usuario* auxUsuario;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            auxUsuario = (S_Usuario*)malloc(sizeof(S_Usuario)); //asigno memoria por cada empleado
            fscanf(pFile,"%[^,],%[^\n]",auxUsuario->nombre,auxUsuario->email);
            al_add(lista,(void*)auxUsuario);
        }
        fclose(pFile);
    }
    return 0;
}

void depurar(ArrayList* lista_destinatarios, ArrayList* lista_negra, ArrayList* lista_depuracion)
{
    int i,j;
    int longitudDestinatarios = lista_destinatarios->len(lista_destinatarios);
    int longitudBlack = lista_negra->len(lista_negra);
    int flag = 0;
    S_Usuario* auxUsuario = NULL;
    S_Usuario* auxUsuario2 = NULL;

    for(i=0; i<longitudDestinatarios; i++)
    {
        flag = 0;
        for(j=0; j<longitudBlack; j++)
        {
            auxUsuario = (S_Usuario*)lista_destinatarios->get(lista_destinatarios,i);
            auxUsuario2 = (S_Usuario*)lista_negra->get(lista_negra,j);
            if(compare(auxUsuario,auxUsuario2)== 1)
                flag = 1;
        }
        if(flag == 0)
        {
            al_add(lista_depuracion,auxUsuario);
        }
    }
    //lista_depuracion = al_clone(lista_destinatarios);
    al_containsAll(lista_destinatarios,lista_depuracion);
}

int compare(S_Usuario* pUsuarioA,S_Usuario* pUsuarioB)
{
    int retorno;
    //S_Usuario* auxiliarA = (S_Usuario*)pUsuarioA;
    //S_Usuario* auxiliarB = (S_Usuario*)pUsuarioB;

    if(strcmp(pUsuarioA->email,pUsuarioB->email) == 0)
        retorno = 1;
    else if(strcmp(pUsuarioA->email,pUsuarioB->email) != 0)
        retorno = -1;
    else
        retorno = 0;

    return retorno;
}

void listar(ArrayList* lista_destinatarios)
{
    int len = lista_destinatarios->len(lista_destinatarios);
    int i;
    S_Usuario* auxUsuario;

    for(i=0; i<len;i++)
    {
        auxUsuario = (S_Usuario*)al_get(lista_destinatarios,i);
        printf("Nombre: %s | Email: %s \n", auxUsuario->nombre,auxUsuario->email);
    }
}
/*void saveFile(ArrayList* this,)
{
    S_Usuario* auxUsuario = NULL;
    auxUsuario = usuarios_new();
    FILE *pArchivo;
    int i = 0, cantidad;
    f = fopen("Materias.dat", "wb");
    if(f != NULL)
    {
        if (auxMateria != NULL)
        {
            cantidad = this->len(this);
            for(i=0; i<cantidad; i++)
            {
                auxMateria = this->get(this, i);
                fwrite((Materias*)this->get(this, i), sizeof(Materias),1,f);

            }
            fclose(f);
            printf("Archivo guardado con exito\n\n");
        }
    }
    else
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }

 void listar_public_usuario(ArrayList* lista_usuarios, ArrayList* lista_productos)
{
    char id_str[5];
    int idU,i;
    int flag = 0;
    S_Producto* auxProducto = NULL;

    do
    {
        if(!getStringNumeros("Ingrese id del usuario: ",id_str))
        {
            printf("El id debe ser numerico!!\n");
        }
        else
        {
            flag = 1;
            idU = atoi(id_str);
            int indexU = idU - 1;
            int longitud = lista_productos->len(lista_productos);

            if(lista_usuarios->contains(lista_usuarios,lista_usuarios->get(lista_usuarios,indexU)) == 1)
            {
                for(i=0;i<longitud;i++)
                {
                    auxProducto = lista_productos->get(lista_productos,i);
                    if(producto_getIdUsuario(auxProducto) == idU)
                    {
                        printf("Campos del producto:\n\n");
                        printf("id: %d\n", producto_getId(auxProducto));
                        printf("  Nombre: %s\n",producto_getName(auxProducto));
                        printf("  Precio: %d\n",producto_getPrecio(auxProducto));
                        printf("  Cantidad vendida: %d\n",producto_getCantidadVendida(auxProducto));
                        printf("  Stock: %d\n",producto_getStock(auxProducto));
                    }
                }
                system("pause");
                system("cls");
            }
            else
            {
                printf("No se encuentra el id ingresado\n");
                break;
            }

        }
    }while(flag == 0);
}

void listar_public(ArrayList* lista_productos,ArrayList* lista_usuarios)
{
    S_Producto* auxProducto = NULL;
    S_Usuario* auxUsuario = NULL;

    int i,j,longitud,longitudUsuarios;
    longitud = lista_productos->len(lista_productos);
    longitudUsuarios = lista_usuarios->len(lista_usuarios);
    for(j=0; j<longitudUsuarios;j++)
    {
        for(i=0; i<longitud;i++)
        {
            auxProducto = (S_Producto*)lista_productos->get(lista_productos,i);

            printf("ID: %d\n",producto_getId(auxProducto));
            printf("  Nombre: %s\n",producto_getName(auxProducto));
            printf("  Precio: %d\n",producto_getPrecio(auxProducto));
            printf("  Cantidad Vendida: %d\n",producto_getCantidadVendida(auxProducto));
            printf("  Stock: %d\n",producto_getStock(auxProducto));
            if(producto_getIdUsuario(auxProducto) == usuarios_getId(auxUsuario))
            {
                auxUsuario = (S_Usuario*)lista_usuarios->get(lista_usuarios,j);
                printf("  Nombre de usuario: %s\n",usuarios_getName(auxUsuario));
            }
        }
    }
    system("pause");
}

void listar_usuario(ArrayList* lista_usuarios, ArrayList* lista_calif)
{
    int i;
    float prom = 0;
    S_Usuario* auxUsuario = NULL;
    S_Calificacion* auxCalif = NULL;
    int longUsuario = lista_usuarios->len(lista_usuarios);

    for(i=0; i<longUsuario; i++)
    {
        if(lista_usuarios->contains(lista_usuarios,lista_usuarios->get(lista_usuarios,i))==1)
        {
            auxCalif = lista_calif->get(lista_calif,i);
            auxUsuario = lista_usuarios->get(lista_usuarios,i);
            if(puntuacion_getIdUsuario(auxCalif) == i)
            {
                prom = promedio(lista_calif,auxCalif,i);
                printf("id: %d",usuarios_getId(auxUsuario));
                printf("  Nombre: %s",usuarios_getName(auxUsuario));
                printf("  Password: %s",usuarios_getPassword(auxUsuario));
                printf("  Calificacion promedio: %.2f",prom);
            }

        }else printf("error");
    }
}
*/

