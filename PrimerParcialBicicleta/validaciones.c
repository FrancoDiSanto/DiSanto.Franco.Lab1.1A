#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "bicicleta.h"
#include "servicio.h"
int validarIDBici(int id, eBicicleta lista[], int tam)
{
  int valido=0;


if (lista != NULL && tam > 0 )
{
    for(int i=0; i<tam; i++)
    {
        if(lista[i].id== id && lista[i].isEmpty ==0 )
        {
            valido=1;
            break;
        }
    }
}
return valido;

}


int validarIDServicio(int id, eServicio lista[], int tam)
{
    int valido=0;


if (lista != NULL && tam > 0 )
{
    for(int i=0; i<tam; i++)
    {
        if(lista[i].id== id)
        {
            valido=1;
            break;
        }
    }


}
return valido;
}
