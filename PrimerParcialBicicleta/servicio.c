#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "servicio.h"
void mostrarServicios(eServicio lista[], int tams)
{
    printf("-------------Lista de Servicios------------\n");
    printf(" id        descripcion         precio\n\n");
    for(int i =0; i< tams ; i++)
    {
        mostrarServicio(lista[i]);

    }


}

void mostrarServicio(eServicio servicio)
{
    printf("%d      %s        %-5.2f \n", servicio.id, servicio.descripcion, servicio.precio);

}

int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char desc[])
{
    int todoOk=0;

    for(int i =0; i < tam ;i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(desc, servicios[i].descripcion);
            todoOk=1;
            break;
        }
    }


return todoOk;
}
