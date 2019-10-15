#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "valida.h"
#include "autos.h"
#include "listas.h"

#define TMARCA 5
#define TCOLOR 5
#define TLAVADO 4
#define TAUTOS 20
#define TTRABAJO 20

int main()
{
    //harcodeo arrays
    eMarca marcas[TMARCA] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };

    eColor colores[TCOLOR] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };

    eServicio lavados[TLAVADO] =
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600},
    };
    //fin harcodeo



    eAuto autos[TAUTOS];
    inicializaAutos(autos, TAUTOS);

    eTrabajo trabajos[TTRABAJO];
    inicializaTrabajos(trabajos, TTRABAJO);


    int id = 1;
    int flag = 0;
    int idTrabajo = 1;

    id = id + hardcodearAutos(autos, TAUTOS, 15);  //harcodeo de autos para pruebas

    do
    {
        switch (menu())
        {
        case 1:
            system( "cls");
            if (altaAuto(autos, TAUTOS, id, marcas, TMARCA, colores, TCOLOR))
            {
                id ++;
            }
            break;
        case 2:
            printf("MENU 2");
            ModificarAuto(autos, TAUTOS, marcas, TMARCA, colores, TCOLOR);
            break;
        case 3:
            for (int i=0; i<TAUTOS; i++)
            {
                if (autos[i].isEmpty == 0)
                {
                    flag = 1;
                }

            }
            if (flag)
            {
                bajaAuto(autos, TAUTOS, marcas, TMARCA, colores, TCOLOR);
                flag = 0;
            }
            else
            {
                printf("\n");
                printf("No hay autos cargados\n");
                system("pause");
            }
            break;
        case 4:
            for (int i=0; i<TAUTOS; i++)
            {
                if (autos[i].isEmpty == 0)
                {
                    flag = 1;
                }

            }
            if (flag)
            {
                system("cls");
                ordenarAutos(autos, TAUTOS);
                listarAutos(autos, TAUTOS, marcas, TMARCA, colores, TCOLOR);
                system("pause");
                flag = 0;
            }
            else
            {
                printf("\n");
                printf("No hay autos cargados\n");
                system("pause");
            }

            break;
        case 5:
            system("cls");

            listarMarcas(marcas, TMARCA);
            system("pause");
            break;
        case 6:
            system("cls");

            listarColores(colores, TCOLOR);
            system("pause");
            break;
        case 7:
            system("cls");

            listarServicios(lavados,TLAVADO);
            system("pause");
            break;
        case 8:

            if (altaTrabajo(trabajos, TTRABAJO, autos, TAUTOS, idTrabajo, marcas, TMARCA, colores, TCOLOR, lavados, TLAVADO)) {
                idTrabajo ++;
            }
            break;
        case 9:
            for (int i=0; i<TTRABAJO; i++)
            {
                if (trabajos[i].isEmpty == 0)
                {
                    flag = 1;
                }

            }

            if (flag)
            {
            system("cls");

            listarTrabajos(trabajos, TTRABAJO,lavados, TLAVADO);
            system("pause");
            flag = 0;
            break; }
            else
            {
                printf("\n");
                printf("No hay trabajos cargados\n");
                system("pause");
            }

        }



    }
    while (1);



}


