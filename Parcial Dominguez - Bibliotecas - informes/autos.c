#include <stdio.h>
#include <stdlib.h>

#include "autos.h"
#include "valida.h"

//AUTOS

/** \brief Pone el flag isEmpty en true para todo el array
 *
 * \param autos es array de eAutos, es el vector a recorrer
 * \param tAutos es int, es el tamao del vector
 *
 */
void inicializaAutos (eAuto autos[], int tAutos)
{
    for (int i=0; i<tAutos; i++)
    {
        autos[i].isEmpty = 1;       //pone el flag isEmpty en true

    }

}

/** \brief Recorre array y devuelve primer indice libre (isEmpty == 1)
 *
 * \param autos es array de eAutos, es el vector a recorrer
 * \param tAutos es int, es el tamao del vector
 * \return indice int, devuelve numero de indice libre, o -1 si no encontro
 *
 */
int buscarIndiceLibre (eAuto autos[], int tAutos)
{
    int indice = -1;

    for (int i=0; i<tAutos; i++)
    {
        if (autos[i].isEmpty)
        {
            indice = i;
            break;
        }

    }

    return indice;
}


/** \brief Da de alta un eAuto
 *
 * \param autos es array de eAuto, es el vector donde se dara de alta un nuevo auto
 * \param tAutos es int, tamaño del vector a recorrer
 * \param id es int, es el numero de identificacion que se le asignara al nuevo auto
 * \param marcas es array de eMarca, se verica el vector a fin de poder seleccionar marca del auto nuevo
 * \param tMarcas es in, tamaño del vector a recorrer
 * \param colores es array de eColor, se verica el vector a fin de poder seleccionar color del auto nuevo
 * \param tColor es in, tamaño del vector a recorrer
 * \return int, 1 si pudo dar el alta, 0 si fallo.
 *
 */
int altaAuto (eAuto autos[], int tAutos, int id, eMarca marcas[], int tMarcas, eColor colores[], int tColor )
{

    int todoOk = 0;
    int indice;
    int valido = 0;
    char confirma;
    eAuto temporal;

    indice = buscarIndiceLibre(autos, tAutos);

    system("cls");
    printf("ALTA DE AUTO\n\n");
    if (indice == -1)
    {
        printf( "SISTEMA LLENO\n");
        system("pause");
    }
    else
    {
        temporal.id = id; //CARGA ID

        //CARGA PATENTE
        validaString("Ingrese Patente: ", "ERROR, maximo 7 digitos\nIngrese Patente: ", 7, temporal.patente);

        //CARGA MARCA
        listarMarcas(marcas, tMarcas);
        do
        {
            printf("\n");
            validaInt("Seleccione marca por ID: ", "ID ERRONEO\nSeleccione marca por ID: ",0, &temporal.idMarca );
            for (int i=0; i<tMarcas; i++)
            {

                if (temporal.idMarca == marcas[i].id)
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

        //CARGA COLOR
        listarColores(colores, tColor);
        do
        {
            printf("\n");
            validaInt("Seleccione color por ID: ", "NO SE INGRESO ID VALIDO\nSeleccione color por ID: ",0, &temporal.idColor );
            for (int i=0; i<tColor; i++)
            {

                if (temporal.idColor == colores[i].id)
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

        //CARGA MODELO
        validaInt("Ingrese modelo: ", "DATO INVALIDO. Debe ser un numero positico\nIngrese modelo: ", 0, &temporal.modelo);

        printf("\nSe cargo el siguiente auto: \n");

        printf("ID\tPATENTE\t\tMARCA\tCOLOR\tMODELO\n");
        listarAuto(temporal, marcas, tMarcas, colores, tColor);

        printf("\n");
        confirma = validaChar2("Es correcto (s/n)? ", "ERROR. Debe ingresar s o n\nEs correcto (s/n)? ", 's', 'n');

        if (confirma == 's')
        {
            printf("CARGADO CORRECTAMENTE\n");
            temporal.id = id;
            temporal.isEmpty = 0;
            autos[indice] = temporal;

            todoOk = 1;
        }
        else
        {
            printf("Se cancelo la carga");
            system("pause");
        }

    }

    return todoOk;

}



/** \brief busca ID en vector de marcas y lo carga en un string dado
 *
 * \param id int id marca a buscar en el vector
 * \param marcas[] eMarca es el vector a recorrer
 * \param tMarca int tamaño del vector
 * \param desc[] char string que se cargara con el paramtro descripcion de la estructura eMarca
 * \return int devuelve 1 si lo pudo cargar, 0 si fallo.
 *
 */
int cargarDescMarca(int id, eMarca marcas[], int tMarca, char desc[])

{
    int todoOk = 0;

    for(int i=0; i < tMarca; i++)
    {
        if( id == marcas[i].id)
        {
            strcpy(desc, marcas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

/** \brief busca ID en vector de colores y lo carga en un string dado
 *
 * \param id int id color a buscar en el vecto
 * \param colores[] eColor  es el vector a recorrer
 * \param tColor int tamaño del vector
 * \param desc[] char tring que se cargara con el paramtro descripcion de la estructura eColor
 * \return int devuelve 1 si lo pudo cargar, 0 si fallo.
 *
 */
int cargarDescColor(int id, eColor colores[], int tColor, char desc[])

{
    int todoOk = 0;

    for(int i=0; i < tColor; i++)
    {
        if( id == colores[i].id)
        {
            strcpy(desc, colores[i].nombreColor);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}



/** \brief recorre vector de eAuto buscando una patente
 *
 * \param patente[] char, patente a buscar en el vector
 * \param vec[] eAuto, vector a recorrer
 * \param tam int, tamaño del vector
 * \return int, devuleve indice donde esta la patente buscada, 0 si no la encontro.
 *
 */
int buscarAuto(char patente[], eAuto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( (strcmp(patente,vec[i].patente)) == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Pone en 1 el flag isEmpty en un elemento elegido
 *
 * \param vec[] eAuto vector a recorrer
 * \param tam int tamaño del vector
 * \param marcas[] eMarca vector a recorrer para mostrar la marca
 * \param tMarca int tamaño del vector
 * \param colores[] eColor vector a recorre para mostar el color
 * \param tColor int tamaño del vectr
 * \return int devuelve 1 si la baja fue exitosa, 0 si no se realizo
 *
 */
int bajaAuto(eAuto vec[], int tam, eMarca marcas[], int tMarca, eColor colores[], int tColor)
{
    int todoOk = 0;
    char patente[10];
    int indice;
    char confirma;
    system("cls");
    printf("Baja Auto\n\n");
    listarAutos(vec, tam, marcas, tMarca, colores, tColor);

    printf("Ingrese patente: ");
    scanf("%s", patente);

    indice = buscarAuto(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe un auto con esa patente\n\n");
        system("pause");

    }
    else
    {


        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}

/** \brief Carga elemntos de prueba en un vector de eAutos
 *
 * \param vec[] eAuto vector en el q se cargaran los elementos
 * \param tam int tamaño del vector para verificar que no se sobrepase
 * \param cantidad int cantidad de elementos de prueba a cargar
 * \return int devuelve cantidad de elementos que pudo cargar
 *
 */
int hardcodearAutos(eAuto vec[], int tam, int cantidad)
{
    int cont = 0;

    eAuto suplentes[]=
    {
        { 1, "aaa111", 1000, 5000, 2010, 0},
        { 2, "aaa112", 1002, 5004, 2011, 0},
        { 3, "aaa121", 1003, 5005, 2012, 0},
        { 4, "bcd222", 1004, 5004, 2014, 0},
        { 5, "bbb232", 1005, 5002, 2014, 0},
        { 6, "bbb322", 1001, 5003, 2019, 0},
        { 7, "ccc123", 1005, 5000, 2009, 0},
        { 8, "ccc234", 1003, 5003, 2007, 0},
        { 9, "ccc345", 1002, 5003, 2011, 0},
        { 10, "ddd999", 1001, 5000, 2010, 0},
        { 11, "ddd888", 1000, 5002, 2005, 0},
        { 12, "des789", 1004, 5003, 2006, 0},
        { 13, "adf223", 1004, 5002, 2008, 0},
        { 14, "ber954", 1002, 5004, 2008, 0},
        { 15, "ccc101", 1000, 5005, 2010, 0}
    };

    if( cantidad <= 15 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

/** \brief Pide una patente y permite modificar color o modelo
 *
 * \param vec[] eAuto vector donde esta el elemento a modificar
 * \param tam int tamaño del vecrtor a recorrer
 * \param marcas[] eMarca vector de marcas para listar
 * \param tMarca int tamaño del vector a recorrer
 * \param colores[] eColor vector de colores para listar
 * \param tColor int tamaño del vector
 * \return int devuelve 1 si se realizo modificacion, 0 si no
 *
 */
int ModificarAuto(eAuto vec[], int tam, eMarca marcas[], int tMarca, eColor colores[], int tColor)
{

    int todoOk = 0;
    char patente[10];
    int indice;
    int valido = 0;
    eAuto temporal;


    system("cls");
    printf("Modificar Auto\n\n");

    listarAutos(vec, tam, marcas, tMarca, colores, tColor);

    printf("Ingrese patente: ");
    scanf("%s", patente);
    int opcion;

    indice = buscarAuto(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe esa patente\n\n");
        system("pause");

    }
    else
    {
        system("cls");
        printf("Modificar Auto\n\n");
        printf("Se va a modificar el auto: \n");
        printf("ID\tPATENTE\t     MARCA\tCOLOR\tMODELO\n");
        listarAuto(vec[indice], marcas, tMarca, colores, tColor);
        printf("\n");
        printf("1- Modificar Color\n");
        printf("2- Modificar Modelo\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            //CARGA COLOR
            listarColores(colores, tColor);
            do
            {
                printf("\n");
                validaInt("Seleccione color por ID: ", "NO SE INGRESO ID VALIDO\nSeleccione color por ID: ",0, &temporal.idColor );
                for (int i=0; i<tColor; i++)
                {

                    if (temporal.idColor == colores[i].id)
                    {
                        vec[indice].idColor = temporal.idColor;
                        valido = 1;
                    }
                }

                if (valido == 0)
                {

                    printf("NO SE INGRESO ID VALIDO\n");

                }


            }
            while (valido == 0);
            todoOk = 1;

            break;

        case 2:
            validaInt("Ingrese modelo: ", "DATO INVALIDO. Debe ser un numero positico\nIngrese modelo: ", 0, &vec[indice].modelo);
            todoOk = 1;

            break;
        case 3:

            printf("Se ha cancelado la mofdificacion ");
            break;

        }
    }
    return todoOk;
}


/** \brief ordena vector por marca y patente
 *
 * \param vec[] eAuto vector a ordenar
 * \param tam int tamaño del vector a ordenar
 *
 */
void ordenarAutos(eAuto vec[], int tam)
{
    eAuto auxAuto;
    int swap = 0;

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (vec[i].idMarca > vec[j].idMarca && vec[i].isEmpty==0 && vec[j].isEmpty==0)
            {
                swap = 1;


            }
            else if (vec[i].idMarca == vec[j].idMarca)
            {

                if (strcmp(vec[i].patente,vec[j].patente)>0)
                {
                    swap = 1;
                }
            }

            if (swap)
            {
                auxAuto = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAuto;
                swap = 0;
            }


        }
    }


}

/** \brief ordena vector por ID
 *
 * \param vec[] eAuto vector a ordenar
 * \param tam int tamaño del vector
 *
 */
void ordenarAutosId(eAuto vec[], int tam)
{
    eAuto auxAuto;

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (vec[i].id > vec[j].id)
            {
                auxAuto = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAuto;
            }
        }


    }
}

/** \brief muestra menu de opciones
 *
 * \return int, devuelve nmero de opcion seleccionada
 *
 */
int menu()
{
    int opcion;

    do
    {
        system("cls");
        printf("------------------------------------------------------------\n");
        printf("-------MENU PRINCIPAL-------------------------------------\n");
        printf("------------------------------------------------------------\n");
        printf("1. Alta Auto\n");
        printf("2. Modificar auto\n");
        printf("3. Baja auto\n");
        printf("4. Listar Autos\n");
        printf("5. Listar Marcas\n");
        printf("6. Listar colores\n");
        printf("7. Listar servicios\n");
        printf("8. Alta trabajo\n");
        printf("9. Listar trabajos\n");
        printf("10. Informes\n");
        printf("Elija opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    while (opcion > 11);

    return opcion;
}
