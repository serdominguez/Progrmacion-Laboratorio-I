#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "valida.h"
#include "trabajos.h"
#include "autos.h"
#include "listas.h"



//TRABAJOS

/** \brief recorre el vector y pone isEmpty en true en todas las pocisiones
 *
 * \param trabajos es vector de eTrabajos
 * \param tTrabajos es int, tamaño del vector de eTrabajo a recorrer-
 *
 */
void inicializaTrabajos (eTrabajo trabajos[], int tTrabajos)
{
    for (int i=0; i<tTrabajos; i++)
    {
        trabajos[i].isEmpty = 1;       //pone el flag isEmpty en true

    }

}

/** \brief Recorre vector y devuelve el primer indice con isEmpty en true
 *
 * \param trabajos es vector de eTRabajos
 * \param tTrabajo es int, tamaño del vector de eTrabajo a recorrer-
 * \return int indice libre encontrado, o -1 si no hay indice libre
 *
 */
int buscarIndiceLibreTrabajo (eTrabajo trabajos[], int tTrabajo)
{
    int indice = -1;

    for (int i=0; i<tTrabajo; i++)
    {
        if (trabajos[i].isEmpty)
        {
            indice = i;
            break;
        }

    }

    return indice;
}

/** \brief
 *
 * \param trabajos es vector de eTrabajo
 * \param tTrabajos es int, tamaño del vector trabajos a recorrer
 * \param autos es vector de eAutos
 * \param tAutos es int, tamaño del vector autos a recorrer
 * \param int id, numero incremental para identificar trabajos cargados
 * \param marcas es vector de eMarca.
 * \param tMarca es int, tamaño del vector de marcas a recorrer
 * \param colores es vector de eColor
 * \param tColor es int, tamaño del vector de colores a recorrer
 * \param lavados es vector de eServicio
 * \param tLavados es int, tamaño del vector de lavados
 * \return int, devuelve 1 si pudo cargar el trabajo, 0 si no.
 *
 */
int altaTrabajo (eTrabajo trabajos[], int tTrabajos, eAuto autos[], int tAutos, int id, eMarca marcas[], int tMarcas, eColor colores[], int tColor, eServicio lavados[], int tLavados)
{

    int todoOk = 0;
    int indiceTrabajo;
    int indice;
    int valido = 0;
    char patente[10];
    eTrabajo temporal;

    indiceTrabajo = buscarIndiceLibreTrabajo(trabajos, tTrabajos);

    system("cls");
    printf("ALTA DE TRABAJO\n\n");
    if (indiceTrabajo == -1)
    {
        printf( "SISTEMA LLENO\n");
        system("pause");
    }
    else
    {
        temporal.id = id; //CARGA ID

        //ELIGE AUTO
        ordenarAutosId(autos, tAutos);
        listarAutos(autos, tAutos, marcas, tMarcas, colores, tColor);

        printf("Ingrese patente: ");
        scanf("%s", patente);


        indice = buscarAuto(patente, autos, tAutos);

        if( indice == -1)
        {
            printf("No existe esa patente\n\n");
            system("pause");

        }
        else
        {
            //CARGA PATENTE
            strcpy(temporal.patente, autos[indice].patente);


            //CARGA SERVICIO
            listarServicios(lavados, tLavados);

            do
            {
                printf("\n");
                validaInt("Seleccione Servicio por ID: ", "ID ERRONEO\nSeleccione Servicio por ID: ",0, &temporal.idServicio);
                for (int i=0; i<tLavados; i++)
                {

                    if (temporal.idServicio == lavados[i].id)
                    {
                        valido = 1;
                    }
                }

                if (valido == 0)
                {

                    printf("NO SE INGRESO ID VALIDO\n");

                }
            }
            while (valido == 0);
            valido = 0;

            //CARGA FECHA
            printf("Ingrese fecha del trabajo (DD/MM/AAAA): ");
            fflush(stdin);
            scanf("%d/%d/%d", &temporal.fecha.dia, &temporal.fecha.mes, &temporal.fecha.anio);

            while (!validaFecha(temporal.fecha.dia, temporal.fecha.mes))
            {
                printf("Fecha invalida\nIngrese fecha del trabajo (DD/MM/AAAA): ");
                fflush(stdin);
                scanf("%d/%d/%d", &temporal.fecha.dia, &temporal.fecha.mes, &temporal.fecha.anio);


            }
            //CARGA DATOS AUTOMATICOS
            temporal.id = id;
            todoOk = 1;
        }

        if (todoOk) {
            trabajos[indiceTrabajo] = temporal;
        }

    }
    return todoOk;
}


/** \brief Carga la descripcion de un eServicio en string fuera de la funcion
 *
 * \param id int es el el id del servicio
 * \param lavados[] eServicio vector de servicios
 * \param tLavado int tamaño del vector
 * \param desc[] char bariable donde se cargara la descripcion
 * \return int devuele 1 si lo pudo cargar, 0 si no
 *
 */
int cargarDescServicio(int id, eServicio lavados[], int tLavado, char desc[])
{
    int todoOk = 0;

    for(int i=0; i < tLavado; i++)
    {
        if( id == lavados[i].id)
        {
            strcpy(desc, lavados[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
