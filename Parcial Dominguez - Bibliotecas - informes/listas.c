#include <stdio.h>
#include <stdlib.h>


#include "listas.h"
#include "autos.h"
#include "trabajos.h"

//LISTADOS


/** \brief Muestra contenido del vector
 *
 * \param marcas[] eMarca es el vector a mostrar
 * \param tMarca int, es el tamaño del vector
 *
 */
void listarMarcas (eMarca marcas[], int tMarca)
{
    printf("MARCAS DISPONIBLES\n\n");
    printf("ID\tMARCA\n");
    for (int i=0; i<tMarca; i++)
    {
        listarMarca(marcas[i]);
    }



}

/** \brief Muestra un elemento del vector
 *
 * \param marca eMarca, es el elemento a mostrar
 *
 */
void listarMarca (eMarca marca)
{

    printf("%d\t%s\n", marca.id, marca.descripcion);

}


/** \brief Muestra contenido del vector
 *
 * \param colores[] eColor es el vector a mostrar
 * \param tColor int, es el tamaño del vector
 *
 */
void listarColores (eColor colores[], int tColor)
{

    printf("COLORES DISPONIBLES\n\n");
    printf("ID\tCOLOR\n");
    for (int i=0; i<tColor; i++)
    {
        listarColor(colores[i]);
    }
}

/** \brief Muestra un elemento del vector
 *
 * \param color eColor, es el elemento a mostrar
 *
 */
void listarColor (eColor color)
{
    printf("%d\t%s\n", color.id, color.nombreColor);
}


/** \brief Muestra contenido del vector
 *
 * \param lavados[] eServicio es el vector a mostrar
 * \param tLavado int, es el tamaño del vector
 *
 */
 void listarServicios (eServicio lavados[], int tLavado)
{

    printf("SERVICIOS DISPONIBLES\n\n");
    printf("ID\tSERVICIO\tPRECIO\n");
    for (int i=0; i<tLavado; i++)
    {
        listarLavado(lavados[i]);
    }
}



/** \brief Muestra un elemento del vector
 *
 * \param lavado eServicio, es el elemento a mostrar
 *
 */

void listarLavado (eServicio lavado)
{
    printf("%d\t%10s\t%.2f\n",lavado.id, lavado.descripcion, lavado.precio);


}


/** \brief Muestra elementos del vector
 *
 * \param autos[] eAuto es el vector a mostrar
 * \param tAutos int tamaño del vector
 * \param marcas[] eMarca vector para asociar marca a idMarca
 * \param tMarca int tamaño del vector
 * \param [] eColor colores vector para asociar color a idColor
 * \param tColor int tamaño del vector
 *
 */
void listarAutos(eAuto autos[], int tAutos, eMarca marcas[], int tMarca, eColor colores [], int tColor)
{

    printf("ID\tPATENTE\t     MARCA\tCOLOR\tMODELO\n");
    for (int i=0; i<tAutos; i++)
    {
        if (autos[i].isEmpty == 0)
        {
            listarAuto(autos[i],marcas, tMarca, colores, tColor);
        }
    }

}


/** \brief muestra un elemento del vector
 *
 * \param aut eAuto es el elemento a mostrar
 * \param marcas[] eMarca, vector a recorrer para sacar descripcion y mostrarla
 * \param tMarca int, tamaño del vector
 * \param colores[] eColor vector a recorrer para saacar descripcion y mostrarla
 * \param tColot int, tamaño del vectr
 *
 */
void listarAuto (eAuto aut, eMarca marcas[], int tMarca, eColor colores[], int tColor )
{

    char descMarca[20];
    char desccColor[20];

    cargarDescMarca(aut.idMarca, marcas, tColor, descMarca);
    cargarDescColor(aut.idColor, colores, tColor, desccColor);

    printf("%d\t%s  %10s\t%s\t\%d\n",aut.id, aut.patente, descMarca, desccColor, aut.modelo);

}



/** \brief Muestra elementos del vector
 *
 * \param trabajos[] eTrabajo vector a mostrar
 * \param tTrabajo int tamaño del vector
 * \param lavados[] eServicio vector de donde se toma descripcion
 * \param tLavado int tamaño del vector
 *
 */
void listarTrabajos(eTrabajo trabajos[], int tTrabajo,  eServicio lavados[], int tLavado)
{

    printf("ID\tPATENTE\t  SERVICIO\tFECHA DE REALIZACION\n");
    for (int i=0; i<tTrabajo; i++)
    {
        if (trabajos[i].isEmpty == 0)
        {
            listarTrabajo(trabajos[i], lavados, tLavado);
        }
    }

}

/** \brief Muestra un elemento del vector
 *
 * \param trab eTrabajo, elemento a mostrar
 * \param lavados[] eServicio vector de donde se saca la descripcion para mostrar
 * \param tLavados tamaño del vector.
 *
 */
void listarTrabajo (eTrabajo trab, eServicio lavados[], int tLavados)
{

    char descServicio[20];

    cargarDescServicio(trab.idServicio, lavados, tLavados,descServicio);

    printf("%d\t%s  %10s\t%02d/%02d/%d\n",trab.id, trab.patente, descServicio, trab.fecha.dia, trab.fecha.mes, trab.fecha.anio);

}

