#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "valida.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu ();
void listarEmpleados (LinkedList* lista);
void listarEmpleado (LinkedList* lista, int index);
int altaEmpleado (LinkedList* lista);
int bajaEmpleado (LinkedList* lista);
int modificaEmpleado (LinkedList* lista);
int verificaId (LinkedList* lista, int id);
int switchModificaEmpleado (LinkedList* lista, int index);
int menuModificaEmpleado();
int modificaId(LinkedList* lista,int  index);
int modificaHoras(LinkedList* lista,int  index);
int modificaNombre(LinkedList* lista,int  index);
int modificaSueldo(LinkedList* lista,int  index);
int ordenaPorId(void* id1, void* id2);
int ordenaPorSueldo (void* e1, void* e2);
int ordenaPorHoras (void* e1, void* e2);
int ordenaPorNombre (void* e1, void* e2);

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flagCarga=0;



    do
    {
        option = menu();
        switch(option)
        {
        case 1:
            if (!flagCarga)
            {
                if (controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("Archivo cargado con exito\n");
                    flagCarga = 1;
                }
                else
                {
                    printf("NO SE PUDO CARGAR EL ARCHIVO\n");
                }

            }
            else
            {
                printf("El archivo de datos ya fue cargado\n");

            }
            system("pause");
            break;

        case 2:
            // controller_loadFromBinary("data.csv",listaEmpleados);
            break;

        case 3:
            if (flagCarga)
            {
                altaEmpleado(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 4:
            if (flagCarga)
            {
                modificaEmpleado(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 5:
            if (flagCarga)
            {
                bajaEmpleado(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 6:
            if (flagCarga)
            {
                ll_sort(listaEmpleados, ordenaPorId, 1);
                listarEmpleados(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;


        case 7:
            if (flagCarga)
            {
                switchOrdenaEmpleado(listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;

        case 8:
            if (flagCarga)
            {
                controller_saveAsText("nuevo.csv", listaEmpleados);
            }
            else
            {
                printf("Aun no se cargo el archivo de datos (opcion 1)\n");
            }
            system("pause");
            break;
        }
    }
    while(option != 10);
    return 0;
}


int menu ()
{

    int opcion;

    system("cls");
    printf("--------------------------------------\n");
    printf("---TRABAJO PRACTICO NRO 3-------------\n");
    printf("--------------------------------------\n");
    printf("--------------------------------------\n");
    printf("-Sergio Dominguez---------------------\n");
    printf("--------------------------------------\n");
    printf("MENU DE OPCIONES:\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");

    validaInt("Elija opcion: ", "DATO INVALIDO.\nElija opcion: ", 0, &opcion);

    return opcion;
}


int altaEmpleado (LinkedList* lista)
{
    int todoOk =0;
    int id;

    Employee* temporal = (Employee*) employee_new();

    system("cls");
    printf("***** ALTA EMPLEADO *****\n");



    validaInt("Ingrese ID: ", "ERROR, EL ID DEBE SER NUMERICO\nIngrese ID: ",0 , &id);

    if (verificaId(lista, id))
    {

        temporal->id = id;

        //printf("Ingrese nombre: ");
        //fflush(stdin);
        //gets(temporal->nombre);
        validaString("Ingrese nombre: ", "ERROR, el nombre no acepta numeros ni puede superar los 128 caracteres\nIngrese nombre: ", 128, temporal->nombre);
        poneMayuscula(temporal->nombre);

       // printf("ingrese horas trabajadas: ");
       // scanf("%d",&temporal->horasTrabajadas);
        validaInt("Ingrese horas trabajadas: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nIngrese horas trabajadas: ",0, &temporal->horasTrabajadas);


      //  printf("ingrese sueldo: ");
       // scanf("%d",&temporal->sueldo);
        validaInt("ingrese sueldo: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\ningrese sueldo: ",0, &temporal->sueldo);

        if (ll_add(lista, temporal))
        {
            todoOk = 1;
        }

    }
    else
    {
        printf("ID DUPLICADA\n");

    }



    return todoOk;
}

void listarEmpleados (LinkedList* lista)
{



    printf("  ID        NOMBRE  HORAS TRABAJADAS  SUELDO\n");

    for (int i=0; i<ll_len(lista); i++)
    {

        listarEmpleado(lista, i);


    }

}

void listarEmpleado (LinkedList* lista, int index)
{

    Employee* temporal = (Employee*) employee_new();

    temporal = ll_get(lista, index);
    printf("%4d  %12s  %8d          %d \n", temporal->id, temporal->nombre, temporal->horasTrabajadas, temporal->sueldo);

}

int bajaEmpleado (LinkedList* lista)
{
    int todoOk = 0;
    int id;
    int index;
    int flag = 0;
    char respuesta;
    Employee* temporal = (Employee*) employee_new();

    if (lista != NULL)
    {
        system("cls");
        printf("**** BAJA DE EMPLEADO ****\n");

        do
        {
          //  printf("seleccion Id para dar de baja o ingrese 0 para ver lista completa: ");
          //  scanf("%d", &id );
            validaInt("Seleccione Id para dar de baja o ingrese 0 para ver lista completa: ",
                      "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nSeleccione Id para dar de baja o ingrese 0 para ver lista completa: ", 0, &id );

            if (id == 0)
            {
                listarEmpleados(lista);
            }
            else
            {
                for (int i=0; i<ll_len(lista); i++)
                {
                    temporal = ll_get(lista, i);
                    if (temporal->id == id)
                    {
                        index = i;
                        flag = 1;
                    }

                    if (flag)
                    {
                        system("cls");
                        printf("Se va a dar de baja a: \n");
                        printf("  ID        NOMBRE  HORAS TRABAJADAS  SUELDO\n");
                        listarEmpleado(lista, index);
                        printf("\n\nEs correcto (s/n)? ");
                        fflush(stdin);
                        respuesta = getchar();
                        respuesta = tolower(respuesta);

                        if (respuesta == 's' && ll_remove(lista, index)==0)
                        {
                            printf("BAJA EXITOSA\n");
                            todoOk = 1;
                        }
                        else if (respuesta != 's')
                        {
                            printf("Baja cancelada\n");
                        }
                        else
                        {
                            printf("error realizando la baja\n");
                        }

                        break;
                    }

                }

            }


        }
        while (flag == 0);

    }

    return todoOk;

}


int modificaEmpleado (LinkedList* lista)
{
    int todoOk = 0;
    int id;
    int index;
    int flag = 0;
    char respuesta;
    Employee* temporal = (Employee*) employee_new();

    if (lista != NULL && temporal !=NULL)
    {
        system("cls");
        printf("**** MODIFICACION DE EMPLEADO ****\n");

        do
        {
          //  printf("seleccione Id para modificar o ingrese 0 para ver lista completa: ");
          //  scanf("%d", &id );
            validaInt("Seleccione Id para dar de baja o ingrese 0 para ver lista completa: ",
                      "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nSeleccione Id para dar de baja o ingrese 0 para ver lista completa: ", 0, &id );

            if (id == 0)
            {
                listarEmpleados(lista);
            }
            else
            {
                for (int i=0; i<ll_len(lista); i++)
                {
                    temporal = ll_get(lista, i);
                    if (temporal->id == id)
                    {
                        index = i;
                        flag = 1;
                        break;
                    }

                }
                if (flag)
                {
                    system("cls");
                    printf("Se va a modificar a: \n");
                    printf("  ID        NOMBRE  HORAS TRABAJADAS  SUELDO\n");
                    listarEmpleado(lista, index);
                    printf("\n\nEs correcto (s/n)? ");
                    fflush(stdin);
                    respuesta = getchar();
                    respuesta = tolower(respuesta);

                    if (respuesta == 's')
                    {
                        if (switchModificaEmpleado(lista, index))
                        {
                            todoOk = 1;
                        }
                    }
                    else if (respuesta != 's')
                    {
                        printf("Modificacion cancelada\n");
                    }

                    break;
                }
                else
                {

                    printf("El ID no corresponde a ningun empleado activo \n");
                    break;

                }

            }


        }
        while (flag == 0);

    }

    return todoOk;

}

int switchModificaEmpleado (LinkedList* lista, int index)
{

    int opcion;


    do
    {
        opcion = menuModificaEmpleado();
        switch(opcion)
        {
        case 1:
            modificaId(lista, index);
            system("pause");
            break;

        case 2:
            modificaNombre(lista, index);
            system("pause");
            break;

        case 3:
            modificaHoras(lista, index);
            system("pause");
            break;

        case 4:
            modificaSueldo(lista, index);
            system("pause");
            break;
        }
    }
    while(opcion != 5);

    return opcion;
}

int menuModificaEmpleado()
{

    int opcion;

    system("cls");
    printf("**** MODIFICACION DE EMPLEADO ****\n\n");
    printf("1. Modificar ID.\n");
    printf("2. Modificar Nombre.\n");
    printf("3. Modificar Horas trabajadas.\n");
    printf("4. Modificar Sueldo.\n");
    printf("5. Salir\n");
   // printf("Elija ocion: ");
   // fflush(stdin);
   // scanf("%d", &opcion);
    validaInt("Elija opcion: ", "DATO INVALIDO.\nElija opcion: ", 0, &opcion);


    return opcion;
}

int modificaId(LinkedList* lista,int  index)
{

    int todoOk = 0;
    int id;


    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {
       // printf("Ingrese nuevo ID: ");
       // scanf("%d",&id);
        validaInt("Ingrese nuevo ID: ", "ERROR, EL ID DEBE SER NUMERICO\nIngrese nuevo ID: ",0 , &id);


        if (verificaId(lista, id))
        {

            printf("Se modifico el ID %d por %d\n", temporal->id, id);
            temporal->id = id;
            todoOk = 1;

        }
        else
        {

            printf("ID DUPLICADA\n");

        }

    }
    else
    {

        printf("No se pudo modificar el ID");

    }


    return todoOk;
}

int verificaId (LinkedList* lista, int id)
{

    int todoOk = 1;

    Employee* temporal = (Employee*) employee_new();

    if (temporal != NULL)
    {

        for (int i=0; i<ll_len(lista); i++)
        {
            temporal = ll_get(lista, i);

            if (temporal->id == id)
            {
                todoOk = 0;
                break;
            }

        }

    }

    return todoOk;
}


int modificaNombre(LinkedList* lista,int  index)
{

    int todoOk = 0;
    char nombre[128];

    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {
      //  printf("Ingrese nuevo nombre: ");
      //  fflush(stdin);
      //  gets(nombre);

        validaString("Ingrese nuevo nombre: ", "ERROR, el nombre no acepta numeros ni puede superar los 128 caracteres\nIngrese nuevo nombre: ", 128, nombre);

        poneMayuscula(nombre);

        printf("Se modifico el nombre %s por %s\n", temporal->nombre, nombre);
        strcpy(temporal->nombre, nombre);
        todoOk = 1;

    }
    else
    {

        printf("No se pudo modificar el nombre");

    }


    return todoOk;
}

int modificaHoras(LinkedList* lista,int  index)
{

    int todoOk = 0;
    int horas;

    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {
       // printf("Ingrese nueva cantidad de horas trabajdas: ");
       // scanf("%d", &horas);

        validaInt("Ingrese nueva cantidad de horas trabajdas: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nIngrese nueva cantidad de horas trabajdas: ",
                  0, &temporal->horasTrabajadas);

        printf("Se modificaron las %d horas trabajadas por %d\n", temporal->horasTrabajadas, horas);
        temporal->horasTrabajadas = horas;
        todoOk = 1;

    }
    else
    {

        printf("No se pudo modificar las horas trabajadas");

    }


    return todoOk;
}

int modificaSueldo(LinkedList* lista,int  index)
{

    int todoOk = 0;
    int sueldo;

    Employee* temporal = (Employee*) employee_new();
    temporal = ll_get(lista, index);

    if (temporal != NULL)
    {
     //   printf("Ingrese nuevo sueldo: ");
    //    scanf("%d", &sueldo);
        validaInt("Ingrese nuevo sueldo: ", "ERROR, DEBE INGRESAR UN NUMERO POSITIVO\nIngrese nuevo sueldo: ",0, &temporal->sueldo);

        printf("Se modifico el sueldo %d por %d\n", temporal->sueldo, sueldo);
        temporal->sueldo = sueldo;
        todoOk = 1;

    }
    else
    {

        printf("No se pudo modificar el sueldo");

    }


    return todoOk;
}




int switchOrdenaEmpleado (LinkedList* lista)
{

    int opcion;
    int criterio = -1;


    do
    {
        opcion = menuOrdenaEmpleado();
        if (opcion < 5)
        {
            while (criterio != 0 || criterio !=1) {
            //printf("Seleccione 1 para orden ascendente, 0 para orden descendente: ");
            //scanf("%d", &criterio);
            validaInt("Seleccione 1 para orden ascendente, 0 para orden descendente: ",
                      "ERROR, debe ingresar 1 o 0\nSeleccione 1 para orden ascendente, 0 para orden descendente: ",0 , &criterio);
            }
        }

        switch(opcion)
        {
        case 1:
            ll_sort(lista, ordenaPorId, criterio);
            listarEmpleados(lista);
            system("pause");
            break;

        case 2:
            ll_sort(lista, ordenaPorNombre, criterio);
            listarEmpleados(lista);
            system("pause");
            break;

        case 3:
            //horas
            ll_sort(lista, ordenaPorHoras, criterio);
            listarEmpleados(lista);
            system("pause");
            break;

        case 4:
            //sueldo
            ll_sort(lista, ordenaPorSueldo,criterio);
            listarEmpleados(lista);
            system("pause");
            break;
        }
    }
    while(opcion != 5);

    return opcion;
}

int menuOrdenaEmpleado()
{

    int opcion;

    system("cls");
    printf("**** ORDEN DE EMPLEADO ****\n\n");
    printf("1. Ordenar por ID.\n");
    printf("2. Ordenar por Nombre.\n");
    printf("3. Ordenar por Horas trabajadas.\n");
    printf("4. Ordenar por Sueldo.\n");
    printf("5. Salir\n");
  //  printf("Elija ocion: ");
  //  fflush(stdin);
  //  scanf("%d", &opcion);
    validaInt("Elija opcion: ", "DATO INVALIDO.\nElija opcion: ", 0, &opcion);


    return opcion;
}

int ordenaPorId (void* e1, void* e2)
{

    int respuesta;
    int id1;
    int id2;

    employee_getId(e1, &id1);
    employee_getId(e2, &id2);


    if (id1 > id2)
    {

        respuesta = 1;

    }
    else if (id1 < id2)
    {

        respuesta = -1;

    }
    else
    {
        respuesta = 0;
    }

    return respuesta;
}

int ordenaPorSueldo (void* e1, void* e2)
{
    int respuesta;
    int sueldo1;
    int sueldo2;

    employee_getSueldo(e1, &sueldo1);
    employee_getSueldo(e2, &sueldo2);

    if (sueldo1 > sueldo2)
    {

        respuesta = 1;

    }
    else if (sueldo1 < sueldo2)
    {

        respuesta = -1;
    }
    else
    {
        respuesta =0;
    }

    return respuesta;
}

int ordenaPorHoras (void* e1, void* e2)
{
    int respuesta;
    int horas1;
    int horas2;

    employee_getHorasTrabajadas(e1,&horas1);
    employee_getHorasTrabajadas(e2,&horas2);

    if (horas1 > horas2)
    {

        respuesta = 1;

    }
    else if (horas1 < horas2)
    {

        respuesta = -1;
    }
    else
    {
        respuesta =0;
    }

    return respuesta;
}

int ordenaPorNombre (void* e1, void* e2)
{

    int respuesta;
    char nombre1[128];
    char nombre2[128];

    employee_getNombre(e1, nombre1);
    employee_getNombre(e2, nombre2);


    if (strcmp(nombre1, nombre2) > 0)
    {

        respuesta = 1;

    }
    else if (strcmp(nombre1, nombre2) < 0)
    {

        respuesta = -1;

    }
    else
    {

        respuesta =0;
    }

    return respuesta;
}
