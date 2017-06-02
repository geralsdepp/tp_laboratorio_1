#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "misFunciones.h"
#define VACIO 0
#define BAJA -1
#define ALTA 1

int contador;

int menuOpcion(void)
{
    int opcion;
    printf("MENU DE OPCIONES:\n");
    printf("1.AGREGAR PELICULA.\n");
    printf("2.BORRAR PELICULA.\n");
    printf("3.MODIFICAR PELICULA.\n");
    printf("4.GENERAR PAGINA WEB.\n");
    printf("5.SALIR\n");
    printf("Eliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

void hardcodear(S_Movie pMovie[],int array)
{
    contador = 0;
    char titulo[5][100] = {"Alguien tiene que ceder","Harry Potter y la piedra filosofal","Star Wars: Una Nueva Esperanza","Londres bajo fuego","Alicia en el pais de las maravillas"};
    char genero[5][100] = {"Comedia","Fantasia","Ciencia Ficcion","Accion","Fantasia"};
    float duracion[5] = {1.30,2.30,2.01,1.30,2.00}; //en horas
    char descripcion[5][500] = {"Un libertino en la cúspide de ser una persona mayor con un gusto por las mujeres jóvenes se enamora de una mujer cercana a su edad",
                             "Rescatado del abandono escandalosa de sus tíos, un joven con un gran destino demuestra su valía mientras asiste a la Escuela Hogwarts de Magia y Hechicería",
                             "Luke Skywalker une fuerzas con un Caballero Jedi, un piloto engreído, un wookie y dos droides para salvar la galaxia de la batalla de estación destruir el mundo del Imperio, y al mismo tiempo intentar rescatar a la princesa Leia del malvado Darth Vader",
                             "En Londres para el funeral del primer ministro, Mike Banning descubre un complot para asesinar a todos los líderes mundiales que asisten",
                             "Diecinueve años de edad, Alice regresa al mundo mágico de su aventura de la infancia, donde se reúne con sus viejos amigos y se entera de su verdadero destino: acabar con el reinado de terror de la Reina Roja"};
    int puntaje[5] = {7,10,10,7,9};
    char link_de_imagen[5][500] = {"https://images-na.ssl-images-amazon.com/images/M/MV5BODYyNmRlNDMtYzg1Zi00NzlhLWI4ZDMtZWUwOTQzMDZiYTQyXkEyXkFqcGdeQXVyNjE5MjUyOTM@._V1_.jpg",
                                "https://images-na.ssl-images-amazon.com/images/M/MV5BNjQ3NWNlNmQtMTE5ZS00MDdmLTlkZjUtZTBlM2UxMGFiMTU3XkEyXkFqcGdeQXVyNjUwNzk3NDc@._V1_.jpg",
                                "https://images-na.ssl-images-amazon.com/images/M/MV5BYzQ2OTk4N2QtOGQwNy00MmI3LWEwNmEtOTk0OTY3NDk2MGJkL2ltYWdlL2ltYWdlXkEyXkFqcGdeQXVyNjc1NTYyMjg@._V1_SY1000_CR0,0,664,1000_AL_.jpg",
                                "https://images-na.ssl-images-amazon.com/images/M/MV5BMTY1ODY2MTgwM15BMl5BanBnXkFtZTgwOTY3Nzc3NzE@._V1_SY1000_CR0,0,674,1000_AL_.jpg",
                                "https://images-na.ssl-images-amazon.com/images/M/MV5BMTMwNjAxMTc0Nl5BMl5BanBnXkFtZTcwODc3ODk5Mg@@._V1_.jpg"};
    int id[5] = {1,2,3,4,5};
    int estado[5] = {1,1,1,1,1};
    int i;

    for(i=0;i<array;i++)
    {
        strcpy(pMovie[i].titulo,titulo[i]);
        strcpy(pMovie[i].genero,genero[i]);
        pMovie[i].duracion = duracion[i];
        pMovie[i].puntaje = puntaje[i];
        strcpy(pMovie[i].descripcion,descripcion[i]);
        strcpy(pMovie[i].linkDeImagen,link_de_imagen[i]);
        pMovie[i].id = id[i];
        pMovie[i].estado = estado[i];
        contador = i+1;
        generarArchivoBinario(&pMovie[i]);
    }
}
/** \brief Genera un archivo binario
 *
 * \param pMovie  es el puntero a la pelicula
 * \return 1 si se cargo o 0 si no
 *
 */

int generarArchivoBinario(S_Movie* pMovie)
{
    FILE* pArchivo;
    int retorno=0;

    pArchivo = fopen("bin.dat","w+b");

    if(pArchivo == NULL)
    {
        printf("Error al abrir el archivo!!\n");
    }
    else
    {
        fwrite(pMovie,sizeof(S_Movie),1,pArchivo);
        fclose(pArchivo);
        retorno = 1;
    }
    return retorno;
}

void crearArrayPelicula(S_Movie pMovie[])
{
    S_Movie auxMovie;

    int i = 0;
    FILE* pArchivo;

    pArchivo = fopen("bin.dat","rb");
    if(pArchivo != NULL)
    {
        while((fread(&auxMovie,sizeof(S_Movie),1,pArchivo) != 0))
        {
            pMovie[i] = auxMovie;
            i++;
        }
    }
}

int generarHTML(S_Movie pMovie[])
{
    FILE* pArchivo,*bin;
    int i = 0;
    int retorno = 0;
    int cantidad;
    char buffer[2048];

    pArchivo = fopen("peliculas.html","w");
    bin = fopen("bin.dat","rb");

    if(pArchivo != NULL || bin != NULL)
    {
        while(!feof(bin))
        {
            cantidad = fread(buffer,1,sizeof(buffer),bin);
            fwrite(buffer,1,cantidad,pArchivo);
        }
        fclose(bin);

        fprintf(pArchivo,"<!DOCTYPE html>");
        fprintf(pArchivo,"<html>");
        while(pMovie[i].estado == ALTA)
        {
            fprintf(pArchivo,"<article class='col-md-4 article-intro'>");
            fprintf(pArchivo,"<a href='#'>");
            fprintf(pArchivo,"<img class='img-responsive img-rounded' src='%s'alt=''>",pMovie[i].linkDeImagen);
            fprintf(pArchivo,"</a><h3><a href='#'>%s</a></h3>",pMovie[i].titulo);
            fprintf(pArchivo,"<ul><li>Género:%s</li>",pMovie[i].genero);
            fprintf(pArchivo,"<li>Puntaje:%d</li>",pMovie[i].puntaje);
            fprintf(pArchivo,"<li>Duración:%f</li>/ul>",pMovie[i].duracion);
            fprintf(pArchivo,"<p>%s</p></article>",pMovie[i].descripcion);
            i++;
        }
        fprintf(pArchivo,"</html>");
        fclose(pArchivo);
        retorno = 1;
    }
    return retorno;
}

