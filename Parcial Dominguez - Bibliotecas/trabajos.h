#include "autos.h"

#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;


typedef struct
{
    int id; //comienza en 20000
    char descripcion [25];
    float precio;
} eServicio;

typedef struct
{
    int id;
    char patente[10];
    int idServicio;
    int isEmpty;
    eFecha fecha;

} eTrabajo;

#endif // TRABAJOS_H_INCLUDED

//TRABAJOS
void inicializaTrabajos (eTrabajo trabajos[], int tTrabajos);
int altaTrabajo (eTrabajo trabajos[], int tTrabajos, eAuto autos[], int tAutos, int id, eMarca marcas[], int tMarcas, eColor colores[], int tColor, eServicio lavados[], int tLavados);
int cargarDescServicio(int id, eServicio lavados[], int tLavado, char desc[]);

