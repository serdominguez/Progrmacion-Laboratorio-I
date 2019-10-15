#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eMarca;

typedef struct
{
    int id;
    char nombreColor[20];

} eColor;

typedef struct
{
    int id;
    char patente[10];
    int idMarca;
    int idColor;
    int modelo; //año de fabricacion
    int isEmpty;

} eAuto;

#endif // AUTOS_H_INCLUDED


//autos
void inicializaAutos (eAuto autos[], int tAutos);
int altaAuto (eAuto autos[], int tAutos, int id, eMarca marcas[], int tMarcas, eColor colores[], int tColor );
int cargarDescMarca(int id, eMarca marcas[], int tMarca, char desc[]);
int cargarDescColor(int id, eColor colores[], int tColor, char desc[]);
int hardcodearAutos( eAuto vec[], int tam, int cantidad);
int ModificarAuto(eAuto vec[], int tam, eMarca marcas[], int tMarca, eColor colores[], int tColor);
void ordenarAutos(eAuto vec[], int tam);
int bajaAuto(eAuto vec[], int tam, eMarca marcas[], int tMarca, eColor colores[], int tColor);
int buscarAuto(char patente[], eAuto vec[], int tam);
void ordenarAutosId(eAuto vec[], int tam);
int menu();
