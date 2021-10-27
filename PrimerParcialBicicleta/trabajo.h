#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "servicio.h"
#include "bicicleta.h"
typedef struct{
int id; // (autoincremental)
int idBicicleta; // (debe existir) Validar
int idServicio; // (debe existir) Validar
//eFecha fecha; // ( Validar día, mes y año )
int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED
/** \brief recorre el array de trabajos colocando su campo is emprty en 1, indicando que esta vacio
 *
 * \param listt[] eTrabajo array de trabajos
 * \param tam int tamanio del array de trabajos
 * \return int retorna 1 si salio todo bien
 *
 */
int initTrabajos(eTrabajo listt[], int tam);
/** \brief recorre el arrray buscvando el primer campo isEmpty en 1 para guardar su posicion
 *
 * \param lista[] eTrabajo lista de trabajos
 * \param tam int tamanio de la lista de trabajos
 * \return int retorna la posicion libre
 *
 */
int buscarLibreTrabajo(eTrabajo lista[], int tam);
/** \brief vincula las estructuras bicicletas con las servicio generando una estructura trabajo
 *
 * \param bikes[] eBicicleta array de bicicletas
 * \param tam int tamanio del array de bicis
 * \param colors[] eColor array de colores
 * \param tamc int tamanio del array de colore
 * \param types[] eTipo array de tipos
 * \param tamt int tamanioi de l array de tipos
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamtrab int tamaniio del array de trabajaops
 * \param services[] eServicio array de servicios
 * \param tams int tamnioi del array de servicios
 * \param pNuevoTrabajo int* puntero al id de trabajo, se asigna automaticamente y es auto incremental
 * \return int retorna 1 si salio todo bien
 *
 */
int altaTrabajo(eBicicleta bikes[],int  tam,eColor colors[],int tamc ,eTipo types[] , int tamt,eTrabajo trabajos[], int tamtrab, eServicio services[], int tams, int* pNuevoTrabajo, eCliente clients[], int tamclient);
/** \brief recorre el array de trabajos llamando en cada posicion a la funcion mostrar trabajo (si hay un trabajo existente = campo isempty en 0)
 *
 * \param works[] eTrabajo array de trabajos
 * \param tamw int tamanio del array de trabajos
 * \param services[] eServicio array de servicios
 * \param tams int tamanio del array de servicios
 * \param bikes[] eBicicleta array de bicicletas
 * \param tam int tamaniio del array de bicicletas
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo works[], int tamw, eServicio services[], int tams, eBicicleta bikes[], int tam);
/** \brief recibe una posicion del array de trabajos de tipo trabajo y lo muestra
 *
 * \param unTrabajo eTrabajo posicion i del array de trabajos de tipo eTrabajo
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaniioo del array de servicios
 * \param bikes[] eBicicleta arrayu de bicicletas
 * \param tam int tamanio del array de bicilcetas
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tams, eBicicleta bikes[], int tam);
