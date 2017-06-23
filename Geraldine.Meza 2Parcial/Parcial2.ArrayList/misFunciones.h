#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idUsuario;
    char nombre[20];
    char email[40];

}S_Usuario;


int get_nextID(ArrayList* this,int estructura);
int menuOpcion();
ArrayList* inicializar_lista(ArrayList* lista);

S_Usuario* usuarios_new();
void cargar_destinatarios(ArrayList* this);
void cargar_listaNegra(ArrayList* this);
void depurar(ArrayList* lista_destinatarios, ArrayList* lista_negra, ArrayList* lista_depuracion);
void listar(ArrayList* lista_destinatarios);

int parserEmployee(FILE* pFile,ArrayList* lista,int* len);
void imprimir_usuarios(ArrayList* lista_usuarios);
int compare(S_Usuario* pUsuarioA,S_Usuario* pUsuarioB);

#endif //USUARIOS_H_INCLUDED
