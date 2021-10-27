#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED
/** \brief recibe un id y recorre el array de bicicletas para saber si este existe
 *
 * \param id int id a buscar
 * \param lista[] eBicicleta array de bicicletas
 * \param tam int tamanio del array de bicicletas
 * \return int retorna 1 si este existe
 *
 */
int validarIDBici(int id, eBicicleta lista[], int tam);
/** \brief recibe un id y recorre el array de servicios para saber si este existe
 *
 * \param id int id del servicio a buscar
 * \param lista[] eServicio lista de servicios
 * \param tam int tamanio del array de servicios
 * \return int retorna 1 si este existe
 *
 */
int validarIDServicio(int id, eServicio lista[], int tam);
