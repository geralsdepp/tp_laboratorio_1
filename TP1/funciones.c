#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma(float a, float b)
{
    float total;
    total = a+b;
    return total;
}
float resta(float a,float b)
{
    float total;
    total = a-b;
    return total;
}
float division(float a,float b)
{
    float total;

    if(b != 0)
    {
        total = a/b;
    }
    else
        printf("No se puede dividir por cero\n");

    return total;
}
float multiplicacion(float a,float b)
{
    float total;
    total = a*b;
    return total;
}
int factorial(int fact)
{
    int resp;

    if(fact==1)
    {
        return 1;
    }
    resp = fact * factorial(fact-1);
    return resp;
}
