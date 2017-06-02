#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    int id;
    char titulo[50];
    char genero[30];
    float duracion;
    char descripcion[500];
    int puntaje;
    char linkDeImagen[500];
    int estado;

}S_Movie;

/** \brief despliega un menu de opciones
 * \return retorna la opcion ingresada
 */
int menuOpcion(void);

/**
 *  \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  \param nombre el nombre para el archivo.
 */
int generarHTML(S_Movie* pMovie);

/** \brief inicializa array en 0
 * \param movie, puntero a la estructura s_movie
 * \return largo del array reservado, y si no -1 si no logra reservar e inicializarlo
 */
int inicializar(S_Movie* pMovie);
void hardcodear(S_Movie pMovie[],int array);
int generarArchivoBinario(S_Movie* pMovie);
/** \brief buscador de lugar libre en el array
 *
 * \param pMovie es el puntero a la estructura
 * \param array, es el largo del array disponible a ocupar
 * \return retorna el espacio libre
 *
 */

int buscarLugarLibre(S_Movie* pMovie, int array);
void crearArrayPelicula(S_Movie pMovie[]);
#endif // FUNCIONES_H_INCLUDED
