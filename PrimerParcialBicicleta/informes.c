#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "color.h"
#include "menu.h"
#include "servicio.h"
#include "tipo.h"
#include "trabajo.h"
float cargarPrecio(int id , eServicio lista[], int tam );
int buscarTrabajosBici(eBicicleta bicis[], int tamb, eColor colors[],int tamc, eServicio services[],int tams, eTipo tipos[], int tamtipos, eTrabajo trabajos[], int tamtrab,eCliente lista[], int tam);
int contadorColoryTipo(eBicicleta bicis[], int tam,int idColor, int idTipo);
void contadoraCarbAlum(eBicicleta bicis[], int tam, int* contA, int* contC );
void contadorColores(eBicicleta bicis[], int tam, int* cGris,int* cBlanco, int* cAzul,int* cNegro, int* cRojo);
float impoteServicios(eBicicleta bicis[], int tamb, eColor colors[],int tamc, eServicio services[],int tams, eTipo tipos[], int tamtipos, eTrabajo trabajos[], int tamtrab,eCliente lista[], int tam);
//void bicilcetasColor(eBicicleta bicis[], int tamb, eColor colors[],int tamc, eTipo tipos[], int tamtipos,eCliente lista[], int tam);
void informes(eBicicleta bicis[], int tamb, eColor colors[],int tamc, eServicio services[],int tams, eTipo tipos[], int tamtipos, eTrabajo trabajos[], int tamtrab,eCliente lista[], int tam)
{
    char salir = 'n';
    int contCarbono=0;
    int contAluminio=0;
    int idColoraBuscar;
    int idTipoABuscar;
    int cuantasHay;
    int contGris=0;
    int contBlanco=0;
    int contAzul=0;
    int contNegro=0;
    int contRojo=0;
    float aPagar=0;
    if(bicis != NULL && tamb > 0 && colors != NULL && tamc > 0 && services != NULL && tams>0 && tipos!= NULL && tamtipos>0 && trabajos!= NULL)
    {
        do{
                switch(menuInformes())
                {
                case 1:
                    bicilcetasColor(bicis,tamb,colors,tamc, tipos, tamtipos, lista,tam);
                    break;
                case 2:
                    bicilcetasTipo(bicis,tamb,colors,tamc, tipos, tamtipos, lista,tam);
                    break;
                case 3:
                    contadoraCarbAlum(bicis, tamb, &contAluminio , &contCarbono);
                    if(contCarbono > contAluminio)
                    {
                        printf("hay mas bicis de carbono %d", contCarbono);
                    }else if(contCarbono < contAluminio){
                        printf("hay mas bicis de aluminio %d", contAluminio);
                    }else{
                        printf("hay empate %d", contAluminio);
                    }
                    break;
                case 4:
                    ordenarBicisTipo(bicis, tamb);
                    mostrarBicis(bicis,tamb,colors,tamc,tipos,tamtipos,lista,tam);
                    break;
                case 5:
                    mostrarColores(colors, tamc);
                    printf("ingrese id color a buscar");
                    scanf("%d", &idColoraBuscar);

                    mostrarTipos(tipos, tamtipos);
                    printf("ingrese id tipo a buscar");
                    scanf("%d", &idTipoABuscar);

                    cuantasHay=contadorColoryTipo(bicis,tamb,idColoraBuscar,idTipoABuscar);
                    printf("de ese tipo y ese color hay %d bicis \n", cuantasHay);

                    break;
                case 6:
                    contadorColores(bicis, tamb, &contGris , &contBlanco , &contAzul, &contNegro, &contRojo);
                    if(contAzul > contBlanco && contAzul > contGris && contAzul > contNegro && contAzul > contRojo)
                    {
                        printf("El color mas elegido fue el azul %d bicis", contAzul);
                    }else if (contBlanco > contAzul && contBlanco > contGris && contBlanco > contNegro && contBlanco > contRojo ){
                        printf("El color mas elegido fue el blanco %d bicis", contBlanco);
                    }else if(contGris > contAzul && contGris > contBlanco && contGris > contNegro && contGris > contRojo ){
                        printf("El color mas elegido fue el gris %d bicis", contGris);
                    }else if(contNegro > contAzul && contNegro > contBlanco && contNegro > contGris && contNegro > contRojo ){
                        printf("El color mas elegido fue el negro %d bicis", contNegro);
                    }else{
                        printf("El color mas elegido fue el rojo %d bicis", contRojo);
                    }
                    break;
                case 7:
                    buscarTrabajosBici(bicis,tamb,colors,tamc,services,tams,tipos,tamtipos,trabajos,tamtrab,lista,tam);
                    break;
                case 8:
                    //aPagar = impoteServicios(bicis,tamb,colors,tamc,services,tams,tipos,tamtipos,trabajos,tamtrab,lista,tam);
                    //printf("la bici debe %f", aPagar);
                    break;
                case 9:
                    break;
                case 10:
                    break;
                case 11:
                    printf("Desea salir: ingrese s ");
                    fflush(stdin);
                    scanf("%c", &salir);
                    break;
                default:
                    printf("ingrese una opcion correcta\n");
                }
            system("pause");
        }while(salir != 's');


    }


}

void bicilcetasColor(eBicicleta bicis[], int tamb, eColor colors[],int tamc, eTipo tipos[], int tamtipos,eCliente lista[], int tam)
{
    int idColorAMostrar;
    if(bicis != NULL && tamb > 0 && colors != NULL && tipos != NULL && lista != NULL )
    {
        mostrarColores(colors, tamc);
        printf("ingrese el color que desea ver \n");
        scanf("%d", &idColorAMostrar);
        for(int i =0 ; i < tamb ; i ++)
        {
            if(bicis[i].idColor == idColorAMostrar)
            {

                mostrarBici(bicis[i], colors,tamc,tipos, tamtipos, lista, tam);
            }

        }



    }


}




void bicilcetasTipo(eBicicleta bicis[], int tamb, eColor colors[],int tamc, eTipo tipos[], int tamtipos,eCliente lista[], int tam)
{
    int idTipoAMostrar;
    if(bicis != NULL && tamb > 0 && colors != NULL && tipos != NULL && lista != NULL )
    {
        mostrarTipos(tipos, tamtipos);
        printf("ingrese el tipo que desea ver \n");
        scanf("%d", &idTipoAMostrar);
        for(int i =0 ; i < tamb ; i ++)
        {
            if(bicis[i].idTipo == idTipoAMostrar)
            {

                mostrarBici(bicis[i], colors,tamc,tipos, tamtipos, lista, tam);
            }

        }



    }


}

void contadoraCarbAlum(eBicicleta bicis[], int tam, int* contA, int* contC )
{
    if(bicis != NULL && tam > 0 && contA != NULL && contC != NULL)
    {

        for(int i =0 ; i < tam ; i ++)
        {
            if( bicis[i].isEmpty == 0 )
            {
                if(bicis[i].material == 'c')
                {
                    (*contC)++;

                }else{
                    (*contA)++;
                }

            }

        }

    }


}




int ordenarBicisTipo(eBicicleta bikes[], int tam)
{
    int todoOk=0;
    eBicicleta aux;
    if(bikes != NULL && tam > 0 )
    {
        todoOk=1;
        for(int i =0 ; i < tam-1 ; i ++)
        {
            for(int j = i +1 ; j< tam ; j ++)

            {
                if(bikes[i].isEmpty == 0 && bikes[j].isEmpty ==0)
                {
                    if( bikes[i].idTipo > bikes[j].idTipo )
                    {
                        aux = bikes[i];
                        bikes[i] = bikes[j];
                        bikes[j] = aux;
                    }




                }
            }


        }




    }
   return todoOk;
}

int contadorColoryTipo(eBicicleta bicis[], int tam,int idColor, int idTipo)
{
    int contador=0;
    if(bicis != NULL && tam > 0 )
    {
        for(int i =0 ; i < tam ; i ++)
        {
            if(bicis[i].idColor == idColor && bicis[i].idTipo == idTipo)
            {
                contador++;

            }

        }


    }
    return contador;
}

void contadorColores(eBicicleta bicis[], int tam, int* cGris,int* cBlanco, int* cAzul,int* cNegro, int* cRojo)
{
    if(bicis != NULL && tam > 0)
    {
        for(int i =0 ; i < tam ; i ++)
        {
            if(bicis[i].isEmpty ==0 && bicis[i].idColor == 5000)
            {
                (*cGris)++;
            }else if(bicis[i].isEmpty ==0 && bicis[i].idColor == 5001){
                (*cBlanco)++;
            }else if(bicis[i].isEmpty ==0 && bicis[i].idColor == 5002){
                (*cAzul)++;
            }else if(bicis[i].isEmpty ==0 && bicis[i].idColor == 5003){
                (*cNegro)++;
            }else if(bicis[i].isEmpty ==0 && bicis[i].idColor == 5004){
                (*cRojo)++;
            }

        }
    }

}


int buscarTrabajosBici(eBicicleta bicis[], int tamb, eColor colors[],int tamc, eServicio services[],int tams, eTipo tipos[], int tamtipos, eTrabajo trabajos[], int tamtrab,eCliente lista[], int tam)
{
    int todoOk=0;
    int biciAbuscar;
    if(bicis != NULL && trabajos != NULL && services != NULL && tam > 0 )
    {
        todoOk =1;
        mostrarBicis(bicis,tamb,colors,tamc,tipos,tamtipos,lista,tam);
        printf("ingrese id de bici a buscar trabajos");
        scanf("%d", &biciAbuscar);

        for(int i =0 ; i < tamtrab ; i ++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idBicicleta == biciAbuscar)
            {

                mostrarTrabajo(trabajos[i],services,tams,bicis,tamb);
            }


        }

    }

    return todoOk;
}

/*float impoteServicios(eBicicleta bicis[], int tamb, eColor colors[],int tamc, eServicio services[],int tams, eTipo tipos[], int tamtipos, eTrabajo trabajos[], int tamtrab,eCliente lista[], int tam)
{
    int biciAbuscar;
    int idServicioaCargar;
    float retornoPrecio=0;

    if(bicis != NULL && trabajos != NULL && services != NULL && tam > 0 )
    {

        mostrarBicis(bicis,tamb,colors,tamc,tipos,tamtipos,lista,tam);
        printf("ingrese id de bici a buscar trabajos");
        scanf("%d", &biciAbuscar);

        for(int i =0 ; i < tamtrab ; i ++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idBicicleta == biciAbuscar)
            {
                idServicioaCargar = trabajos[i].idServicio;
                retornoPrecio = retornoPrecio + (cargarPrecio(idServicioaCargar,services,tams));

            }

        }


    return retornoPrecio;
}

float cargarPrecio(int id ,eServicio services[], int tam )
{
    float precio=0;
    if( lista != NULL && tam > 0 )
    {
        for(int i =0; i < tam ; i ++)
        {
            if(services[i].id == id )
            {

                precio = services[i].precio;
            }

        }

    }

    return precio;
}*/
