#include <stdio.h>
#include <stdlib.h>
#define TAM 100
#define TAMT 4
#define TAMS 4
#define TAMC 5
#define TAMTRAB 100

typedef struct{
int dia;
int mes;
int anio;
}eFecha;

typedef struct{
int id; // comienza en 5000
char descripcion[20];
}eTipo;

typedef struct{
int id; // comienza en 5000
char descripcion[20];
}eColor;

typedef struct{
int id;
char marca[20];
int idColor;
int idTipo;
char material;
int isEmpty;
}eBicicleta;

typedef struct{
int id; //comienza en 20000)
char descripcion[25]; // (máximo 25 caracteres)
float precio;

}eServicio;

typedef struct{
int id; // (autoincremental)
int idBicicleta; // (debe existir) Validar
int idServicio; // (debe existir) Validar
eFecha fecha; // ( Validar día, mes y año )
int isEmpty;
}eTrabajo;

/** \brief muestra un menu de opciones
 *
 * \return int devuelve la opcion elegida para entrar a ese case en main
 *
 */
int menu();
int submenu();
int initBicicletas(eBicicleta listt[], int tam);
int initTrabajos(eTrabajo listt[], int tam);
int buscarLibre(eBicicleta lista[],int tam);
void mostrarColor(eColor color);
void mostrarColores(eColor lista[], int tam);
void mostrarTipos(eTipo tips[], int tamt);
void mostrarTipo(eTipo tipo);
void mostrarServicios(eServicio lista[], int tams);
void mostrarServicio(eServicio servicio);
int cargarDescripcionColor(int id, eColor colores[], int tam, char desc[]);
int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[]);
int altaBici(eBicicleta bikes[] , int tam , eColor colors[] , int tamc , eTipo types[] , int tamt, int* pIdNuevaBici);
int modificarBicicleta(eBicicleta lista[], int tam, eColor colorss[], int tamc, eTipo tipos[], int tamt);
void mostrarBicis(eBicicleta lista[], int tam, eColor marcas[], int tamm, eTipo tipos[], int tamt);
void mostrarBici(eBicicleta unaBici,eColor colors[], int ttamc, eTipo ttipos[], int ttamt);
int bajaBicicleta(eBicicleta lista[], int tam, eColor colorss[], int tamc, eTipo tipos[], int tamt);
int validarIDBici(int id, eBicicleta lista[], int tam);
int validarIDServicio(int id, eServicio lista[], int tam);
int cargarMarcaBici(int id, eBicicleta lista[], int tam, char marca[]);
int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char desc[]);
void mostrarTrabajos(eTrabajo works[], int tamw, eServicio services[], int tams, eBicicleta bikes[], int tam);
void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tams, eBicicleta bikes[], int tam);



///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{

    eTipo tipos[TAMT]= { {1000, "Rutera"}, {1001, "Carrera"},{1002, "Mountain"},{1003, "BMX"}};

    eServicio servicios[TAMS]= { {20000, "Limpieza", 30}, {20001, "Parche", 400},{20002, "Centrado", 500},{20003, "Cadena", 450}};

    eColor colores[TAMC]={ {5000, "Gris"}, {5001, "Blanco"},{5002, "Azul"},{5003, "Negro"},{5004, "Rojo"}};

    eBicicleta bicis[TAM];
    int idBici = 100;
    initBicicletas(bicis,TAM);

    eTrabajo trabajos[TAMTRAB];
    int idTrabajo =1;
    initTrabajos(trabajos, TAMTRAB);

    char salir = 'n';

    do{
            switch(menu()){
            case 1:

                if(altaBici(bicis,TAM,colores,TAMC,tipos,TAMT,&idBici))
            {
                printf("1- Alta Bici Exitosa\n");

            }
            else
            {
                printf("1-Hubo un error,  Alta Bici fallida\n");

            }
                break;
            case 2:
                modificarBicicleta(bicis,TAM, colores, TAMC, tipos,TAMT);
                break;
            case 3:
                bajaBicicleta(bicis,TAM,colores,TAMC,tipos,TAMT);
                break;
            case 4:
                mostrarBicis(bicis, TAM, colores, TAMC, tipos, TAMT);
                break;
            case 5:
                mostrarTipos(tipos, TAMT);
                break;
            case 6:
                mostrarColores(colores, TAMC);
                break;
            case 7:
                mostrarServicios(servicios,TAMS);
                break;
            case 8:
                altaTrabajo(bicis,TAM,colores,TAMC,tipos,TAMT,trabajos,TAMTRAB,servicios,TAMS, &idTrabajo);
                break;
            case 9:
                mostrarTrabajos(trabajos,TAMTRAB,servicios,TAMS,bicis,TAM);
                break;

            case 10:
                break;



            }


    system("pause");
    }while(salir=='n');






    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu()
{
    int opcion;


    system("cls");
    printf("******menu de opciones********\n");
    printf("1- Alta Bicicleta\n");
    printf("2- Modificar Bicicleta\n");
    printf("3- Baja Bicicleta\n");
    printf("4- Listar Bicicleta\n");
    printf("5- Listar tipos\n\n");
    printf("6- Listar colores\n");
    printf("7- Listar servicios \n");
    printf("8- ALta trabajo \n");
    printf("9- Listar trabajo \n");

    printf("10- Salir \n");
    printf("ingrese su opcion : ");
    scanf("%d", &opcion );

    return opcion;
}


int initBicicletas(eBicicleta listt[], int tam)
{
    int todoOK=0;
    for(int i =0; i <tam ; i++)
    {
        listt[i].isEmpty=1;
        todoOK=1;
    }
    return todoOK;
}


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



int altaBici(eBicicleta bikes[],int  tam, eColor colors[] ,int tamc ,eTipo types[] , int tamt, int* pIdNuevaBici)
{
    int todoOk=0;
    int i;
    eBicicleta nuevaBici;
    int idTipo;
    int idColor;

    system("cls");
    printf("Alta Bicicleta\n");
    printf("id  %d \n", *pIdNuevaBici);

    if(bikes != NULL && tam >0 && pIdNuevaBici != NULL)
    {
        i= buscarLibre(bikes, tam);
        printf("%d", i);
        if(i == -1)
        {
            printf("NO hay lugar en el sistema");
        }
        else
        {


            printf("ingrese marca: ");
            fflush(stdin);
            gets(nuevaBici.marca);

            mostrarColores(colors, tamc);
            printf("ingrese id Color: ");
            scanf("%d", &idColor);
            while(idColor < 5000 || idColor > 5004)
            {
                printf("Error, ingrese id Marca valido: ");
                scanf("%d", &idColor);
            }

            mostrarTipos(types, tamt );
            printf("ingrese ID tipo: ");
            fflush(stdin);
            scanf("%d", &idTipo);
            while(idTipo< 1000 || idTipo > 1003)
            {
                printf("Error ID tipo: ");
                fflush(stdin);
                scanf("%d", &idTipo);

            }

            printf("ingrese material (c O a): ");
            fflush(stdin);
            scanf("%c", &nuevaBici.material);
            while(nuevaBici.material != 'c' && nuevaBici.material != 'a')
            {
                printf("ingrese material (c O a): ");
                fflush(stdin);
                scanf("%c", &nuevaBici.material);
            }



            nuevaBici.idTipo = idTipo;
            nuevaBici.idColor = idColor;
            nuevaBici.id= *pIdNuevaBici;
            (*pIdNuevaBici)++;
            nuevaBici.isEmpty=0;

            bikes[i] = nuevaBici;
            todoOk=1;
        }


}
return todoOk;
}


int buscarLibre(eBicicleta lista[],int tam)
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


void mostrarBicis(eBicicleta lista[], int tam, eColor colors[], int tamc, eTipo tipos[], int tamt)
{
    int flag=1;
    printf("----------***  LISTA DE BICICLETAS  ***------------ \n");
    printf("id       marca        tipo         color           material (c -> carbono   a -> aluminio)\n");
    printf("-------------------------------------------------------------------------------------\n");
    for(int i =0; i<tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarBici(lista[i],colors , tamc, tipos, tamt);
            flag=0;
        }

    }

    if(flag)
    {
        printf("\n");
        printf("\n");
        printf("--------No hay notebooks para mostar------ \n");
    }

    printf("\n");
    printf("\n");

}




void mostrarBici(eBicicleta unaBici,eColor colors[], int ttamc, eTipo ttipos[], int ttamt)
{
    char descripcionTipo[20];
    char descripcionColor[20];
    char nombre[20];
    //cargarNombre(unaNoteookk.idCliente, clients, tamc, nombre);
    cargarDescripcionColor(unaBici.idColor, colors, ttamc, descripcionColor);
    cargarDescripcionTipo(unaBici.idTipo, ttipos, ttamt, descripcionTipo);
    printf("%d      %-10s     %-10s   %-10s     %c",
            unaBici.id , unaBici.marca , descripcionTipo,
            descripcionColor, unaBici.material);
    printf("\n");





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



int modificarBicicleta(eBicicleta lista[], int tam, eColor colorss[], int tamc, eTipo tipos[], int tamt)
{
    int todoOK=0;
    if(lista != NULL && tam > 0 && colorss != NULL && tamc > 0 && tipos != NULL && tamt > 0 )
    {
         int idAModificar;

         mostrarBicis(lista,tam,colorss,tamc,tipos,tamt);
         printf("ingrese el numero de id de la bici a modificar \n");
         scanf("%d", &idAModificar);


        for(int i =0; i<tam; i++)
        {


            if(lista[i].id == idAModificar)
            {
                int AM = i;
                char salir = 'n';
                    do{

                        switch(submenu())
                        {
                            case 1:
                                mostrarTipos(tipos, tamt);
                                printf("reingrese id tipo");
                                scanf("%d", &lista[AM].idTipo);
                                while(lista[AM].idTipo > 1003 || lista[AM].idTipo < 1000)
                                {
                                    printf("Tipo invalido reingrese id tipo");
                                    scanf("%d", &lista[AM].idTipo);

                                }
                            break;
                            case 2:
                                printf("ingrese material (c O a): ");
                                fflush(stdin);
                                scanf("%c", &lista[AM].material);
                                while(lista[AM].material != 'c' && lista[AM].material != 'a')
                                {
                                    printf("ingrese material (c O a): ");
                                    fflush(stdin);
                                    scanf("%c", &lista[AM].material);
                                }
                            break;
                            case 3:
                                printf("Desea salir/ dejar de modificar ingrese 's' de asi serlo : ");
                                fflush(stdin);
                                scanf("%c", &salir);
                            break;
                        }



                    }while(salir== 'n');
                todoOK =1;
            }

        }
    }

    return todoOK;
}

int submenu()
{
    int opcion;


    system("cls");
    printf("******menu de opciones********\n");
    printf("1- Modificar tipo\n");
    printf("2- Modificar material\n");

    printf("3- Salir \n");
    printf("ingrese su opcion : ");
    scanf("%d", &opcion );

    return opcion;



}



int bajaBicicleta(eBicicleta lista[], int tam, eColor colorss[], int tamc, eTipo tipos[], int tamt)
{
    int idABorrar;
    int todoOk=0;
    mostrarBicis(lista, tam, colorss, tamc, tipos, tamt);
    printf("ingrese el numero de id de la  notebook a eliminar \n");
    scanf("%d", &idABorrar);

    for(int i =0; i<tam; i++)
    {


        if(lista[i].id == idABorrar)
        {
            lista[i].isEmpty=1;
            todoOk=1;
            mostrarBici(lista[i],colorss, tamc, tipos, tamt);

        }

    }

    return todoOk;
}




int altaTrabajo(eBicicleta bikes[],int  tam,eColor colors[],int tamc ,eTipo types[] , int tamt,eTrabajo trabajos[], int tamtrab, eServicio services[], int tams, int* pNuevoTrabajo)
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
            mostrarBicis(bikes,tam,colors,tamc,types,tamt);
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

int validarIDBici(int id, eBicicleta lista[], int tam)
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
        printf("%3d    %5d              %-10s           %-20s   \n", unTrabajo.id,
               unTrabajo.idBicicleta,
               marcaBici,
               descServicio
               );


    }



}


int cargarMarcaBici(int id, eBicicleta lista[], int tam, char marca[])
{
    int todoOk=0;

    for(int i =0; i < tam ; i++)
    {
        if(lista[i].id == id)
        {
            strcpy(marca, lista[i].marca);
            todoOk=1;
            break;
        }
    }


    return todoOk;
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






