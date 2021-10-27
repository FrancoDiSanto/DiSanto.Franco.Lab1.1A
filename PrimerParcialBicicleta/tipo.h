#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
typedef struct{
int id; // comienza en 5000
char descripcion[20];
}eTipo;


#endif // TIPO_H_INCLUDED
/** \brief recorre el array de tipos llamando en cada posicion a la funcion mostrar tipo
 *
 * \param tips[] eTipo array de tipos
 * \param tamt int tamanio del array de tipòs
 * \return void
 *
 */
void mostrarTipos(eTipo tips[], int tamt);
/** \brief recibe una posicion del array eTipo y lo muestra
 *
 * \param tipo eTipo posicion i del array eTipos
 * \return void
 *
 */
void mostrarTipo(eTipo tipo);
/** \brief recibe un id y busca coincidencias en el array, carga la descripcion de la coincidencia en la variable desc
 *
 * \param id int id a buscar
 * \param tipos[] eTipo array de tipos
 * \param tam int tamanio del array de tipos
 * \param desc[] char variable donde se carga la descripcion
 * \return int retona 1 si todo salio bien
 *
 */
int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[]);
