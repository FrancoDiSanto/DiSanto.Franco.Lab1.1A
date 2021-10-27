#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "color.h"
void mostrarColor(eColor color)
{
    printf("%d      %s \n", color.id, color.descripcion);

}

void mostrarColores(eColor lista[], int tam)
{
    printf("-------------Lista de Colores------------\n");
    printf(" id        descripcion\n\n");
    for(int i =0; i< tam ; i++)
    {
        mostrarColor(lista[i]);

    }
}

int cargarDescripcionColor(int id, eColor colores[], int tam, char desc[]){
int todoOk=0;
for(int i =0; i < tam ;i++){
    if(colores[i].id == id){
        strcpy(desc, colores[i].descripcion);
        todoOk=1;
        break;
    }
}

return todoOk;
}
