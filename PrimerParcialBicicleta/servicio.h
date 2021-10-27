#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
typedef struct{
int id; //comienza en 20000)
char descripcion[25]; // (máximo 25 caracteres)
float precio;

}eServicio;


#endif // SERVICIO_H_INCLUDED
/** \brief recorre el array de servicios llamando en cada posicion a mostrarServicio y muestra todos los servicios
 *
 * \param lista[] eServicio array de servicios
 * \param tams int tamanio del array de servicios
 * \return void
 *
 */
void mostrarServicios(eServicio lista[], int tams);
/** \brief recibe una posicion del array de servicios y lo muestras
 *
 * \param servicio eServicio posicion del array de servicios a mostrar
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);
/** \brief recibe un id de un servicio, recorre el array buscando conincidencia de id, y cuando la encuentra carga la descripcion en la variable descripcion
 *
 * \param id int id a busca r
 * \param servicios[] eServicio array de servicios
 * \param tam int tamanio del array de servicios
 * \param desc[] char variable donde se cargara la deacripcion del id encontrado
 * \return int retorna 1 si todo salio bien
 *
 */
int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char desc[]);
