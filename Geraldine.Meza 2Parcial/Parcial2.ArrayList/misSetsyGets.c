#include "misSetsyGets.h"
#include "misFunciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int usuarios_setId(S_Usuario* this,int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->idUsuario = id;
        retorno = 0;
    }
    return retorno;
}

int usuarios_setName(S_Usuario* this,char* name)
{
    int retorno = -1;

    if(this != NULL && strlen(name) > 0)
    {
        strcpy(this->nombre,name);
        retorno = 0;
    }
    return retorno;
}

int usuarios_setEmail(S_Usuario* this,char* email)
{
    int retorno = -1;

    if(this != NULL && strlen(email) > 0)
    {
        strcpy(this->email,email);
        retorno = 0;
    }
    return retorno;
}

int usuarios_getId(S_Usuario* this)
{
    int retorno = -1;

    if(this != NULL )
    {
        retorno = this->idUsuario;
    }
    return retorno;
}

char* usuarios_getName(S_Usuario* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
       retorno = this->nombre;
    }
    return retorno;
}

char* usuarios_getEmail(S_Usuario* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->email;
    }
    return retorno;
}
