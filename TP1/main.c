#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float aux1,aux2,sumar,restar,dividir,producto;
    int facto,factoriales;


    while(seguir=='s')
    {

        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
            case 1:

                printf("Ingrese el primer operando: ");
                fflush(stdin);
                scanf("%f",&aux1);
                break;
            case 2:
                printf("Ingrese el segundo operando: ");
                fflush(stdin);
                scanf("%f",&aux2);
                break;
            case 3:
                sumar = suma(aux1,aux2);
                printf("La suma es: %f",sumar);
                break;
            case 4:
                restar = resta(aux1,aux2);
                printf("La resta es: %.2f",restar);
                break;
            case 5:
                dividir = division(aux1,aux2);
                printf("La division es: %.2f",dividir);
                break;
            case 6:
                producto = multiplicacion(aux1,aux2);
                printf("El producto es: %.2f",producto);
                break;
            case 7:
                printf("Ingrese numero: ");
                fflush(stdin);
                scanf("%d",&facto);
                factoriales = factorial(facto);
                printf("El factorial es: %d",factoriales);
                break;
            case 8:
                sumar = suma(aux1,aux2);
                printf("La suma es: %.2f\n",sumar);

                restar = resta(aux1,aux2);
                printf("La resta es: %.2f\n",restar);

                dividir = division(aux1,aux2);
                printf("La division es: %.2f\n",dividir);

                producto = multiplicacion(aux1,aux2);
                printf("El producto es: %.2f\n",producto);

                printf("Ingrese numero: ");
                scanf("%d",&facto);
                factoriales = factorial(facto);
                printf("El factorial es: %d\n",factoriales);

                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
