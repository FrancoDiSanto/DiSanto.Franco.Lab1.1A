#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "trabajo.h"
#include "validaciones.h"
int initTrabajos(eTrabajo listt[], int tam)
{
    int todoOK=0;
    for(int i =0; i <tam ; i++)
    {
        listt[i].isEmpty=1;
        todoOK=1;
    }
    return todoOK;
}

int altaTrabajo(eBicicleta bikes[],int  tam,eColor colors[],int tamc ,eTipo types[] , int tamt,eTrabajo trabajos[], int tamtrab, eServicio services[], int tams, int* pNuevoTrabajo, eCliente clients[], int tamclient)
{
    int todoOK=0;
    int indice;
    eTrabajo nuevotrabajo;
    int idBici;
    int idServicio;
    if(bikes != NULL && colors != NULL && types != NULL && trabajos != NULL && tam > 0 && tamc >0 && tamt >0 && tamtrab >0 && pNuevoTrabajo != NULL)
    {
        printf("            ALTA TRABAJOS           \n");
        indice = buscarLibreTrabajo(trabajos, tamtrab);

        if (indice == -1)
        {
            printf("no hay lugar para mas trabajos ");
        }
        else
        {
            mostrarBicis(bikes,tam,colors,tamc,types,tamt, clients, tamclient);
            printf("ingrese id bici: ");
            scanf("%d", &idBici);
            while(!validarIDBici(idBici,bikes, tam))
            {
                printf("ingrese id bici valido: ");
                scanf("%d", &idBici);

            }
            nuevotrabajo.idBicicleta = idBici;


            mostrarServicios(services,tams);
            printf("ingrese id servicio: ");
            scanf("%d", &idServicio);
            while(!validarIDServicio(idServicio, services, tams))
            {
                printf("ingrese id servicio: ");
                scanf("%d", &idServicio);
            }
            nuevotrabajo.idServicio = idServicio;



            nuevotrabajo.id = *pNuevoTrabajo;
            (*pNuevoTrabajo)++;
            nuevotrabajo.isEmpty=0;



            trabajos[indice] = nuevotrabajo;

            todoOK=1;


        }




    }
return todoOK;
}



int buscarLibreTrabajo(eTrabajo lista[], int tam)
{
    int LLibre=-1;
    for(int i =0; i<tam; i++)
    {
        if(lista[i].isEmpty)
        {
            LLibre=i;
            break;
        }
    }
return LLibre;

}

void mostrarTrabajos(eTrabajo works[], int tamw, eServicio services[], int tams, eBicicleta bikes[], int tam)
{

    int flag=1;
    if(works != NULL && tamw >0 && services != NULL && tams> 0 && bikes != NULL && tam > 0)
    {
        printf("-------------Lista de trabajos-----------\n");
        printf(" id    idBici         tipo             Servicio      \n\n");
        for(int i =0; i< tamw ; i++)
        {
            if(!works[i].isEmpty)
            {
                mostrarTrabajo(works[i], services, tams, bikes, tam);
                flag =0;
            }

        }
    if(flag)
    {
        printf("\n");
        printf("\n");
        printf("--------No hay trabajos para mostar------ \n");
    }

    printf("\n");
    printf("\n");
    }

}



void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tams, eBicicleta bikes[], int tam)
{
    char marcaBici[20];
    char descServicio[20];
    if(cargarMarcaBici(unTrabajo.idBicicleta,bikes,tam,marcaBici) &&
       cargarDescripcionServicio(unTrabajo.idServicio,servicios, tams, descServicio ))
    {
        printf("%3d    %5d              %-12s           %-20s   \n", unTrabajo.id,
               unTrabajo.idBicicleta,
               marcaBici,
               descServicio
               );


    }



}
