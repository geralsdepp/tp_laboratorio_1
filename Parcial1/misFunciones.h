
typedef struct
{
    char nombre[20];
    int precio;
    int idProducto;
    int cantVendida;
    int stock;
    int estado;
}S_Producto;

typedef struct
{
    char nombre[20];
    char password[10];
    int idUsuario;
    int estado;
    S_Producto producto;
    int calificacion;
    int contProducto;
}S_Usuario;



int menuOpcion(void);
void alta_usuario(S_Usuario ficha[],int cant);
void baja_usuario(S_Usuario ficha[]);
void modificar_usuario(S_Usuario ficha[]);
void inicializarArray_usuario(S_Usuario ficha[],int cant);
int obtenerEspacioLibre_usuario(S_Usuario ficha[],int cant);
void listar_public_usuario(S_Usuario ficha[]);
void listar_usuario(S_Usuario ficha[]);

void publicar_producto(S_Producto prod[],S_Usuario ficha[],int cant);
void cancelar_publicacion(S_Producto prod[],S_Usuario ficha[]);
void modificar_publicacion(S_Producto prod[],S_Usuario ficha[]);
void comprar_producto(S_Producto prod[],S_Usuario ficha[]);
void inicializarArray_producto(S_Producto prod[],int cant);
int obtenerEspacioLibre_producto(S_Producto prod[],int cant);
void listar_public(S_Usuario ficha[]);


