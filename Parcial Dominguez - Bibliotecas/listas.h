#include "trabajos.h"

#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED



#endif // LISTAS_H_INCLUDED

//LISTAS
void listarMarcas (eMarca marcas[], int tMarca);
void listarMarca (eMarca marca);
void listarColores (eColor colores[], int tColor);
void listarColor (eColor color);
void listarServicios (eServicio lavados[], int tLavado);
void listarLavado (eServicio lavado);
void listarAuto (eAuto aut, eMarca marcas[], int tMarca, eColor colores[], int tColor );
void listarAutos(eAuto autos[], int tAutos, eMarca marcas[], int tMarca, eColor colores [], int tColor);
void listarTrabajos(eTrabajo trabajos[], int tTrabajo, eServicio lavados[], int tLavado);
void listarTrabajo (eTrabajo trab, eServicio lavados[], int tLavados);
