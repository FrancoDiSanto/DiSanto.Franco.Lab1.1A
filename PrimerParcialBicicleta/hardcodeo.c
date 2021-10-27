#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "cliente.h"
#include "datawarehouse.h"
int hardcodearBicis(eBicicleta bikes[], int len , int cant, int* pId, int* pIdCliente)
{
    int cantidad=0;

    if(bikes != NULL && len > 0 && cant >=0 && cant <= len && pId != NULL)
    {
        for(int i =0; i < cant; i ++)
        {
            bikes[i].id = *pId;
            (*pId)++;

            strcpy(bikes[i].marca, marcasDW[i]);
            //strcpy(employees[i].lastName, apellidosDW[i]);
            bikes[i].idColor = idColoresDW[i];
            bikes[i].idTipo = idTipoDW[i];
            bikes[i].material = materialeDw[i];
            bikes[i].idCliente = idClientesDW[i];
            bikes[i].isEmpty = 0;
            //(*pIdCliente)++;
            cantidad++;


        }


    }


    return cantidad;
}

int hardcodearTrabajos(eTrabajo lista[],int tam, int cant, int* pIdTrabajo)
{
    int cantidadCargada=0;
    if(lista != NULL && tam > 0 && cant>=0 && cant <= tam && pIdTrabajo != NULL)
    {
        for(int i =0; i < cant ; i ++)
        {
            lista[i].id = *pIdTrabajo;
            (*pIdTrabajo)++;

            lista[i].idBicicleta = idBicisDW[i];

            lista[i].idServicio = idServiciosDW[i];

            lista[i].isEmpty=0;

            cantidadCargada++;
        }


    }



return cantidadCargada;


}

int hardcodearCliente(eCliente lista[], int tam, int cant , int* pIdCliente)
{   int cantidadCargada;
    if(lista != NULL && tam > 0 && cant <= tam && pIdCliente != NULL)
    {
        for(int i =0 ; i < cant ; i ++)
        {
            lista[i].id = *pIdCliente;
            (*pIdCliente)++;

            strcpy(lista[i].nombre, nombresDW[i]);
            lista[i].sexo = sexosDW[i];
            lista[i].isEmpty =0;

            cantidadCargada++;





        }



    }

    return cantidadCargada;
}
