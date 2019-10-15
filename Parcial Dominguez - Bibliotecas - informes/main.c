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
#define TTRABAJO 50

//INFORMES
void informes (eAuto autos[], int tAutos, eMarca marcas[], int tMarcas, eColor colores[], int tColores, eServicio servicios[], int tServicios, eTrabajo trabajos[], int tTrabajos);

float gastoPromedioMarca (int idMarca, eAuto autos[], int tAutos, eMarca marcas[], int tMarca, eColor colores[], int tColores, eTrabajo trabajos[], int tTrabajos, eServicio servicios[], int tServicios);

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
        {20003, "Completo", 600}
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
    idTrabajo = hardcodearTrabajos(trabajos, TTRABAJO, 40); //harcodeo de trabajos para pruebas

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

            if (altaTrabajo(trabajos, TTRABAJO, autos, TAUTOS, idTrabajo, marcas, TMARCA, colores, TCOLOR, lavados, TLAVADO))
            {
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
                break;
            }
            else
            {
                printf("\n");
                printf("No hay trabajos cargados\n");
                system("pause");
            }
            break;
        case 10:
            for (int i=0; i<TTRABAJO; i++)
            {
                if (trabajos[i].isEmpty == 0)
                {
                    for (int j=0; j<TAUTOS; j++)
                    {
                        if (autos[j].isEmpty == 0)
                        {
                            flag = 1;
                        }

                    }
                }

            }

            if (flag)
            {
                system("cls");
                informes(autos, TAUTOS, marcas, TMARCA, colores, TCOLOR, lavados, TLAVADO, trabajos, TTRABAJO);


                system("pause");
                flag = 0;
                break;
            }
            else
            {
                printf("\n");
                printf("Aun no hay trabajos o autos cargados\n");
                system("pause");
            }


            break;


        }



    }
    while (1);



}

/** \brief Carga elemntos de prueba en un vector de eAutos
 *
 * \param vec[] eAuto vector en el q se cargaran los elementos
 * \param tam int tamaño del vector para verificar que no se sobrepase
 * \param cantidad int cantidad de elementos de prueba a cargar
 * \return int devuelve cantidad de elementos que pudo cargar
 *
 */
int hardcodearTrabajos(eTrabajo vec[], int tam, int cantidad)
{
    int cont = 0;

    /*
        int id;
    char patente[10];
    int idServicio;
    int isEmpty;
    eFecha fecha;
    */

    eTrabajo suplentes[]=
    {
        { 1, "bcd222", 20000, 0, {01,02,2018}},
        { 2, "aaa112", 20002, 0, {30,12,2018}},
        { 3, "aaa121", 20003, 0, {30,12,2018}},
        { 4, "bcd222", 20002, 0, {31,12,2018}},
        { 5, "bbb232", 20003, 0, {31,12,2018}},
        { 6, "bbb322", 20001, 0, {31,12,2018}},
        { 7, "ccc123", 20002, 0, {01,01,2019}},
        { 8, "ccc234", 20003, 0, {01,01,2019}},
        { 9, "ccc345", 20002, 0, {01,01,2019}},
        { 10, "ddd999", 20001, 0, {01,02,2019}},
        { 11, "bcd222", 20000, 0, {01,02,2019}},
        { 12, "des789", 20001, 0, {02,02,2019}},
        { 13, "adf223", 20003, 0, {02,02,2019}},
        { 14, "ber954", 20002, 0, {29,12,2018}},
        { 15, "ccc101", 20000, 0, {29,12,2018}},
        { 16, "aaa111", 20001, 0, {28,12,2018}},
        { 17, "aaa112", 20003, 0, {28,12,2018}},
        { 18, "aaa121", 20002, 0, {28,12,2018}},
        { 19, "bcd222", 20000, 0, {29,12,2018}},
        { 20, "bbb232", 20003, 0, {30,12,2018}},
        { 21, "bbb322", 20002, 0, {31,12,2018}},
        { 22, "ccc123", 20003, 0, {02,01,2019}},
        { 23, "ccc234", 20000, 0, {03,01,2019}},
        { 24, "ccc345", 20003, 0, {03,01,2019}},
        { 25, "ddd999", 20002, 0, {02,02,2019}},
        { 26, "ddd888", 20001, 0, {01,02,2019}},
        { 27, "des789", 20002, 0, {03,02,2019}},
        { 28, "adf223", 20002, 0, {03,02,2019}},
        { 29, "ber954", 20003, 0, {01,01,2018}},
        { 30, "ccc101", 20001, 0, {01,02,2018}},
        { 31, "aaa111", 20003, 0, {27,12,2018}},
        { 32, "aaa112", 20001, 0, {27,12,2018}},
        { 33, "aaa121", 20000, 0, {27,12,2018}},
        { 34, "bcd222", 20002, 0, {27,12,2018}},
        { 35, "bbb232", 20002, 0, {03,01,2019}},
        { 36, "bbb322", 20000, 0, {03,01,2019}},
        { 37, "bcd222", 20000, 0, {03,02,2019}},
        { 38, "ccc234", 20002, 0, {03,01,2019}},
        { 39, "ccc345", 20001, 0, {02,01,2019}},
        { 40, "ddd999", 20000, 0, {03,02,2019}},
        { 41, "ddd888", 20003, 0, {03,02,2019}},
        { 42, "des789", 20002, 0, {03,02,2019}},
        { 43, "adf223", 20002, 0, {02,02,2019}},
        { 44, "ber954", 20001, 0, {29,12,2018}},
        { 45, "ccc101", 20003, 0, {29,12,2018}}
    };

    if( cantidad <= 45 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}





void informes (eAuto autos[], int tAutos, eMarca marcas[], int tMarcas, eColor colores[],
               int tColores, eServicio servicios[], int tServicios, eTrabajo trabajos[], int tTrabajos)
{
    float promedio;
    char marc[10];

    switch (menuInformes())
    {
    case 1:
        printf("1. Cantidad de peugeot que se lavaron en fecbrero: ");
        printf("%d\n", cantMarcatLavadoMes(02, 1004, autos, tAutos, trabajos, tTrabajos, servicios, tServicios));
        break;
    case 2:
        printf("2. Que autos gastaron mas de $400\n");
        mostrarAutosGastoMayorA(1800, autos, tAutos, marcas, tMarcas, colores, tColores, trabajos, tTrabajos,
                                servicios, tServicios);
        break;
    case 3:
        fechaMasLavados(trabajos, tTrabajos);
        break;
    case 4:
        informarColorServicio(5003, 20001,autos, tAutos, marcas, tMarcas, colores, tColores, trabajos, tTrabajos,
                              servicios, tServicios);
        break;
    case 5:
        promedio = gastoPromedioMarca(1001, autos, tAutos, marcas, tMarcas, colores, tColores, trabajos, tTrabajos,
                                      servicios, tServicios);
        cargarDescMarca(1001, marcas, tMarcas, marc);
        printf("El gasto promedio de la marca %s es: %.2f\n", marc, promedio);
        break;

    }



}

int menuInformes ()
{

    int opcion;

    do
    {
        system("cls");
        printf("------------------------------------------------------------\n");
        printf("-------MENU INFORMES----------------------------------------\n");
        printf("------------------------------------------------------------\n");
        printf("1. Cantidad de peugeot que se lavaron en febrero\n");
        printf("2. Que autos gastaron mas de $400\n");
        printf("3. Que fecha se lavaron mas autos\n");
        printf("4. listar autos rojos pulidos\n");
        printf("5. Gasto promedio de Fiat\n");
        printf("Elija opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    while (opcion > 10);

    return opcion;



}

int cantMarcatLavadoMes (int mes, int idMarca,  eAuto autos[], int tAutos, eTrabajo trabajos[], int tTrabajos, eServicio servicios[], int tServicios)
{
    int cantidad = 0;

    for (int i=0; i<tTrabajos; i++)
    {
        if (trabajos[i].fecha.mes == mes && trabajos[i].idServicio == 20000)
        {
            for (int j=0; j<tAutos; j++)
            {
                if (strcmp(trabajos[i].patente,autos[j].patente)==0 && autos[j].idMarca == idMarca)
                {
                    cantidad ++;
                }
            }
        }
    }

    return cantidad;
}

void mostrarAutosGastoMayorA (int gasto, eAuto autos[], int tAutos, eMarca marcas[], int tMarca, eColor colores[],
                              int tColores, eTrabajo trabajos[], int tTrabajos, eServicio servicios[], int tServicios)
{
    int acumula = 0;

    for (int i=0; i<tAutos; i++)
    {
        for (int j=0; j<tTrabajos; j++)
        {
            if ( (autos[i].isEmpty == 0 && trabajos[j].isEmpty == 0) && strcmp(autos[i].patente,trabajos[j].patente)==0)
            {
                for (int k=0; k<tServicios; k++ )
                {
                    if (trabajos[j].idServicio == servicios[k].id)
                    {
                        acumula = acumula + servicios[k].precio;
                    }
                }
            }
        }
        if (acumula > gasto)
        {
            printf("Gasto: %d\n", acumula);
            listarAuto(autos[i], marcas, TMARCA, colores, tColores);

            acumula = 0;
        }
    }

}

int fechaMasLavados (eTrabajo trabajos[], int tTrabajos)
{

    int contador = 0;
    int maximo = 0;
    int flag = 0;


    for (int i=0; i<tTrabajos-1; i++)
    {
        for (int j=i+1; j<tTrabajos; j++)
        {
            if (trabajos[i].fecha.dia == trabajos[j].fecha.dia && trabajos[i].fecha.mes == trabajos[j].fecha.mes && trabajos[i].fecha.anio == trabajos[j].fecha.anio)
            {
                contador ++;
            }


        }
        if (flag == 0 || contador>maximo)
        {
            maximo = contador;
            contador = 0;
            flag = 1;

        }
    }

    printf("\nEl maximo de lavados en un dia fue %d\n", maximo);

    printf("Registrado en la/s siguiente/s fecha/s: \n");
    contador = 0;
    for (int i=0; i<tTrabajos-1; i++)
    {
        for (int j=i+1; j<tTrabajos; j++)
        {
            if (trabajos[i].fecha.dia == trabajos[j].fecha.dia && trabajos[i].fecha.mes == trabajos[j].fecha.mes && trabajos[i].fecha.anio == trabajos[j].fecha.anio)
            {

                contador ++;
            }


        }

        if (contador == maximo)
        {

            printf("%d/%d/%d\n",trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
            contador = 0;


        }
    }

}

void informarColorServicio (int idColor, int idServicio, eAuto autos[], int tAutos, eMarca marcas[], int tMarca, eColor colores[], int tColores, eTrabajo trabajos[], int tTrabajos, eServicio servicios[], int tServicios)
{

    printf("se encontraron los siguientes autos: \n");
    for (int i=0; i<tAutos; i++)
    {
        if (autos[i].idColor == idColor && autos[i].isEmpty == 0)
        {

            for (int j=0; j<tTrabajos; j++)
            {
                if (strcmp(autos[i].patente,trabajos[j].patente) == 0 && trabajos[j].idServicio == idServicio && trabajos[j].isEmpty == 0)
                {

                    listarAuto(autos[i], marcas, tMarca, colores, tColores);

                }

            }
        }

    }


}

float gastoPromedioMarca (int idMarca, eAuto autos[], int tAutos, eMarca marcas[], int tMarca, eColor colores[], int tColores, eTrabajo trabajos[], int tTrabajos, eServicio servicios[], int tServicios)
{

    float promedio;
    float gasto = 0;
    int contador =0;

    for (int i=0; i<tAutos; i++)
    {
        if (autos[i].isEmpty ==0 && autos[i].idMarca == idMarca)
        {
            for (int j=0; j<tTrabajos; j++)
            {
                if (trabajos[j].isEmpty == 0 && strcmpi(autos[i].patente, trabajos[j].patente) == 0)
                {
                    for (int k=0; k<tServicios; k++)
                    {
                        if (trabajos[j].idServicio == servicios[k].id)
                        {
                            contador ++;
                            printf("patente %s, gasto %f\n",autos[i].patente, servicios[k].precio);
                            gasto = gasto + servicios[k].precio;

                        }
                    }

                }
            }

        }
    }

    promedio = gasto/contador;


    return promedio;
}


