#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "tipo.h"
void mostrarTipos(eTipo tips[], int tamt)
{
printf("-------------Lista de Tipos------------\n");
    printf(" id        descripcion\n\n");
    for(int i =0; i< tamt ; i++)
    {
        mostrarTipo(tips[i]);

    }

}

void mostrarTipo(eTipo tipo)
{

printf("%d      %s \n", tipo.id, tipo.descripcion);

}

int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[]){
int todoOk=0;
for(int i =0; i < tam ;i++){
    if(tipos[i].id == id){
        strcpy(desc, tipos[i].descripcion);
        todoOk=1;
        break;

    }
}

return todoOk;
}

