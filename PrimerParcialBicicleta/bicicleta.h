#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#include "cliente.h"
typedef struct{
int id;
char marca[20];
int idColor;
int idTipo;
int idCliente;
char material;
int isEmpty;
}eBicicleta;


#endif // BICICLETA_H_INCLUDED
/** \brief coloca el campo is empty en 0 de todas las posiciones
 *
 * \param listt[] eBicicleta  array de bicis de main
 * \param tam int tamanio del array de bicis
 * \return int retorna 1 si todo salio bien
 *
 */
int initBicicletas(eBicicleta listt[], int tam);
/** \brief recorre el array de bicics buscando un lugar para una nueva bicicleta, campo is empty en 0
 *
 * \param lista[] eBicicleta
 * \param tam int array de bicis de main
 * \return int retorna la posicion libre
 *
 */
int buscarLibre(eBicicleta lista[],int tam);
/** \brief permite agregar una bicicleta al array de bicis en un lugar vacio, campo is empty en 1 y lo coloca en 0
 *
 * \param bikes[] eBicicleta array de bicis
 * \param tam int tamanio del array de bicis
 * \param colors[] eColor array de colores disponibles
 * \param tamc int tamanio del array de colores
 * \param types[] eTipo tipos de bicis disponibles
 * \param tamt int tamanio del array de tipos
 * \param pIdNuevaBici int* puntero al id de la bicis en main, se asigna automaticamente y se autoincrementa
 * \return int retorna 1 si salio todo bien
 *
 */
int altaBici(eBicicleta bikes[] , int tam , eColor colors[] , int tamc , eTipo types[] , int tamt, int* pIdNuevaBici, eCliente clients[] , int tamclient, int* pIdCliente);
/** \brief muestra las bicicletas y permite elegir una para modificar dos campos de ellas
 *
 * \param lista[] eBicicleta array de bicis
 * \param tam int tamanio del array de bicis
 * \param colorss[] eColor array de colores disponibles
 * \param tamc int tamanio del array de colores
 * \param tipos[] eTipo tipos de bicis disponibles
 * \param tamt int tamanio del array de tipos
 * \return int retorna 1 si salio todo bien
 *
 */
int modificarBicicleta(eBicicleta lista[], int tam, eColor colorss[], int tamc, eTipo tipos[], int tamt, eCliente clients[], int tamclient);
/** \brief muestra en forma de lista la bicis dadas de alta, si no hay ninguna lo comenta
 *
 * \param lista[] eBicicleta array de bicis
 * \param tam int tamanio del array de bicis
 * \param marcas[] eColor array de colores
 * \param tamm int tamanio del arrat de colores
 * \param tipos[] eTipo array de tipos de bici
 * \param tamt int tamanio del array de los tyipos de bici
 * \return void no retorna nada porque solo muestra si hay
 *
 */
void mostrarBicis(eBicicleta lista[], int tam, eColor marcas[], int tamm, eTipo tipos[], int tamt, eCliente clients[], int tamclient);
/** \brief llamada dentro de mostrarBicis, recibe una posicion del array de bicis y muestra su contenido
 *
 * \param unaBici eBicicleta posicion i (a mostrar) del array de bicis
 * \param colors[] eColor lista de colores, va a acargar la descriocion del campo idColor de la bicicleta a mostrar
 * \param ttamc int tamanio del array de colores
 * \param ttipos[] eTipo lista de tipos, va a acargar la descriocion del campo idTipo de la bicicleta a mostrar
 * \param ttamt int tamanio del array de tipos
 * \return void no retorna nada porque muestra una posicion ya validada dentro de mostrar bicis
 *
 */
void mostrarBici(eBicicleta unaBici,eColor colors[], int ttamc, eTipo ttipos[], int ttamt, eCliente clients[], int tamclient);
/** \brief realizaa una baja logica de la bici seleccionada, coloca su campo isEmpty en 1, para cuando se busque un lugar libre, este aparezca
 *
 * \param lista[] eBicicleta array de bicicletas
 * \param tam int tamanio dle arrat de bicicletas
 * \param colorss[] eColor array de colores
 * \param tamc int tamanio del array de colors
 * \param tipos[] eTipo array de tipos
 * \param tamt int tamanio del arrya de tipos
 * \return int retorna 1 si salio todo bien
 *
 */
int bajaBicicleta(eBicicleta lista[], int tam, eColor colorss[], int tamc, eTipo tipos[], int tamt, eCliente clients[], int tamclient);

/** \brief recibe un id de una bici y carga por referencia su descripcion en la variable marca[]
 *
 * \param id int id de la bici a buscar para devolcer su marca
 * \param lista[] eBicicleta array de biciccletas
 * \param tam int tamanio del arrat de bicicletas
 * \param marca[] char variable donde se cargara la marca
 * \return int
 *
 */
int cargarMarcaBici(int id, eBicicleta lista[], int tam, char marca[]);




int ordenarBicis(eBicicleta bikes[], int tam);
