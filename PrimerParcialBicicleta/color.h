#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
typedef struct{
int id; // comienza en 5000
char descripcion[20];
}eColor;


#endif // COLOR_H_INCLUDED
/** \brief recibe una posicion del array de coilores y lo muestra
 *
 * \param color eColor posicion del array de colores
 * \return void no retorna nada
 *
 */
void mostrarColor(eColor color);
/** \brief recorre el array de colores y por cada posicion llama a mostrarColor y muestra todas las posiciones del array
 *
 * \param lista[] eColor array de colores
 * \param tam int tamanio del array de colores
 * \return void no retorna nada
 *
 */
void mostrarColores(eColor lista[], int tam);
/** \brief recibe un id de un color, recore el array revisando los campos id, cuando encuentra coincidencia carga el campo descripcion en la variable descripcion
 *
 * \param id int id del color a busca
 * \param colores[] eColor array de colores
 * \param tam int tamanio del array de colores
 * \param desc[] char variable para cargar lña descripcion del color a buscar
 * \return int retrorna 1 si salio todo bien
 *
 */
int cargarDescripcionColor(int id, eColor colores[], int tam, char desc[]);
