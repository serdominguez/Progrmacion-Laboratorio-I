#include <stdio.h>
#include <stdlib.h>
#include "valida.h"
#include "string.h"

#define TMARCAS 5
#define TCOLORES 5
#define TLAVADOS 4
#define TAUTOS 50

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcion[20] ;

} eMarca;

typedef struct
{
    int id;
    char nombreColor[20];

} eColor;

typedef struct
{
    int id;
    char patente[15];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

} eAuto;

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

} eServicio;

typedef struct
{
    int id;
    char patente[15];
    int idServicio;
    eFecha fecha;

} eTrabajo;



// menues
int menuPrincipal();

//AUTOS
void inicializaAutos(eAuto autos[], int tam);
int altaAuto(eAuto autos[], int tAuto, eMarca marcas[], int tMarcas, eColor colores[], int tColores, int idAuto);
int buscarLibre(eAuto vec[], int tam);
int buscarAuto(char patente, eAuto vec[], int tam);


//MOSTRAR

void listarMarcas (eMarca marcas[], int tam);
void listarMarca(eMarca marcas, int tam);
void listarColor(eColor colores, int tam);
void listarColores (eColor colores[], int tam);
void listarServicio(eServicio servicios, int tam);
void listarServicios (eServicio servicios[], int tam);



int main()
{
    eMarca marcas[TMARCAS] =
    {
        {1000, "Renault" },
        {1001, "Fiat" },
        {1002, "Ford" },
        {1003, "Chevrolet" },
        {1003, "Peugeot" }
    };



    eColor colores[TCOLORES] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };

    eServicio lavados[TLAVADOS] =
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600}
    };

    eAuto autos[TAUTOS];
    inicializaAutos(autos, TAUTOS);


    char salir = 'n';
    int flag = 0;
    int IdAuto = 0;


    do
    {

        switch (menuPrincipal())
        {
        case 1:
            printf("menu 1");
            if (altaAuto(autos, TAUTOS, marcas, TMARCAS, colores, TCOLORES, IdAuto))
            {
                IdAuto ++;
            };
            system("pause");
            break;
        case 2:
            printf("menu 2");
            break;
        case 3:

         printf("menu 3");

            break;
        case 4:
            printf("listar autos");
            for (int i=0; i<TAUTOS; i++) {
                if (autos[i].isEmpty == 0) {
                    flag = 1;
                    break;
                    }
            }
            if (flag == 1) {
            listarAutos(autos, TAUTOS, marcas, TMARCAS, colores, TCOLORES);
            system("pause");
            } else {
            printf("No hay autos para mostrar");
            system("pause");

            }
            break;
        case 5:
            listarMarcas(marcas,TMARCAS);
            system("Pause");
            break;
        case 6:
            listarColores(colores,TCOLORES);
            system("Pause");
            break;
        case 7:
            listarServicios(lavados,TLAVADOS);
            system("Pause");
            break;
        case 8:
            printf("menu 8");
            break;
        case 9:
            printf("menu 9");
            break;
        case 0:
            salir = validaChar2("Confirme salida (S/N): ", "ERROR, debe ingresar S o N ", 's', 'n');

        }

    }
    while (salir != 's');


    return 0;
}


/** \brief Mustra menu de opciones
 *
 * \return char opcion elegida por el usuario
 *
 */
int menuPrincipal()
{
    int opcion;
    do
    {
        system("cls");
        printf("------------------------------------------------------------\n");
        printf("-------MENUE DE OPCIONES -----------------------------------\n");
        printf("------------------------------------------------------------\n");
        printf("1. Alta auto\n");
        printf("2. Modificar auto\n");
        printf("3. Baja auto\n");
        printf("4. Listar auto\n");
        printf("5. Listar marcas\n");
        printf("6. Listar colores\n");
        printf("7. Listar servicios\n");
        printf("8. Alta trabajo\n");
        printf("9. Listar trabajos\n");
        printf("0. salir\n");
        printf("Elija opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    while (opcion > 9);

    return opcion;
}

//AUTOS

void inicializaAutos(eAuto autos[], int tam)
{

    for (int i=0; i<tam; i++)
    {
        autos[i].isEmpty = 1;
    }

}

int buscarLibre(eAuto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int altaAuto(eAuto autos[], int tAuto, eMarca marcas[], int tMarcas, eColor colores[], int tColores, int idAuto)
{
    int todoOk = 0;
    eFecha fecha;
    eAuto temporal;
    int okValida = 0;


    system("cls");

    printf("*****Alta AUTO*****\n\n");

    int indice = buscarLibre(autos, tAuto);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        //pido patente
        validaString("Ingrese patente: ", "Error, la patente debe tener 6 digitos maximo.\nIngrese patente:", 6, temporal.patente);

        //pido marca
        while (okValida == 0 )
        {
            listarMarcas(marcas, tMarcas);
            validaInt("Seleccione marca por ID: ", "ERROR, el ID debe ser numerico.\nSeleccione marca por ID: ",0, &temporal.idMarca);
            for (int i=0; i<tMarcas; i++)
            {
                if (temporal.idMarca == marcas[i].id)
                {
                    okValida = 1;
                }
            }

            if (okValida == 0)
            {
                printf("\n ID ERRONEO\n");
            }
        }

        //pido color
        okValida = 0;
        while (okValida == 0 )
        {
            listarColores(colores, tColores);
            validaInt("Seleccione color por ID: ", "ERROR, el ID debe ser numerico.\nSeleccione color por ID: ",0, &temporal.idColor);

            for (int i=0; i<tColores; i++)
            {
                if (temporal.idColor == colores[i].id)
                {
                    okValida = 1;
                }
            }

            if (okValida == 0)
            {
                printf("\n ID ERRONEO\n");
            }
        }
        //pido modelo
        printf("Ingrese modelo: ");
        scanf("%d",&temporal.modelo);

        temporal.isEmpty == 0;
        temporal.id = idAuto;


        todoOk = 1;

        autos[indice] = temporal;

        printf("Alta exitosa!!\n\n");

    }

    return todoOk;
}



//LISTADOS

/** \brief Muestra marcas
 *
 * \param marcas es vectore de emarcas
 * \param tam es int, tamaño del vector a recorre
 *
 */
void listarMarcas (eMarca marcas[], int tam)
{


    printf("\nID\tMARCA\n");
    for (int i=0; i<tam; i++)
    {
        listarMarca(marcas[i],tam);


    }


}

/** \brief Muestra una marca
 *
 * \param marcas es vectore de emarcas
 * \param tam es int, tamaño del vector a recorre
 *
 */
void listarMarca(eMarca marcas, int tam)
{

    printf("%d\t%s\n", marcas.id, marcas.descripcion);
}


/** \brief Muestra colores
 *
 * \param colores es vectore de emarcas
 * \param tam es int, tamaño del vector a recorre
 *
 */
void listarColores (eColor colores[], int tam)
{


    printf("\nID\tCOLOR\n");
    for (int i=0; i<tam; i++)
    {
        listarColor(colores[i],tam);

    }


}

/** \brief Muestra un color
 *
 * \param colores es vectore de emarcas
 * \param tam es int, tamaño del vector a recorre
 *
 */
void listarColor(eColor colores, int tam)
{

    printf("%d\t%s\n", colores.id, colores.nombreColor);
}


/** \brief Muestra servicios
 *
 * \param colores es vectore de emarcas
 * \param tam es int, tamaño del vector a recorre
 *
 */
void listarServicios (eServicio servicios[], int tam)
{


    printf("\nID\tSERVICIO\tPRECIO\n");
    for (int i=0; i<tam; i++)
    {
        listarServicio(servicios[i],tam);

    }


}

/** \brief Muestra un servicio
 *
 * \param colores es vectore de emarcas
 * \param tam es int, tamaño del vector a recorre
 *
 */
void listarServicio(eServicio servicios, int tam)
{

    printf("%d\t%10s\t%.2F\n", servicios.id, servicios.descripcion, servicios.precio);
}


void listarAutos (eAuto autos[], int tam, eMarca marcas[], int tMarca, eColor colores[], int tColores)
{


    printf("\nID\tPATENTE\tMARCA\tCOLOR\tMODELO\n");
    for (int i=0; i<tam; i++)
    {
        listarAuto(autos[i],tam);

    }


}

/** \brief Muestra un color
 *
 * \param colores es vectore de emarcas
 * \param tam es int, tamaño del vector a recorre
 *
 */
void listarAuto(eAuto autos, int tam, eMarca marcas[], int tMarca, eColor colores[], int tColores)
{
    char marca[20];

    for (int i=0; i<tMarca; i++)
    {
        if (strcmp(autos.idMarca,marcas[i].id)==0)
        {
            strcpy(marca,marcas[i].id);
            break;

        }
    }

    char color[10];

    for (int i=0; i<tColores; i++)
    {
        if (strcmp(autos.idColor,colores[i].id)==0)
        {
            strcpy(color,colores[i].id);
            break;

        }
    }

    //printf("\nID\tPATENTE\tMARCA\tCOLOR\tMODELO\n");
    printf("%d\t%s\t%s\t%s\t%d\n", autos.id, autos.patente, marca, color, autos.modelo);
}





int buscarAuto(char patente, eAuto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( strcmp(vec[i].patente,patente) == 0 && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



