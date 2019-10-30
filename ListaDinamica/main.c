#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    int id;
    char nombre[20];
    float sueldo;

} eEmpleado;

eEmpleado* newEmpleado();
eEmpleado* newEmpledaoParam (int id, char* nombre, float sueldo);
int setIdEmpleado(eEmpleado* e, int id);
int setSueldoEmpleado(eEmpleado* e, float sueldo);
int setNombreEmpleado(eEmpleado* e, char* nombre);
int getIdEmpleado(eEmpleado* e, int* id);
int getNombreEmpleado(eEmpleado* e, char* nombre);
int getSueldoEmpleado(eEmpleado* e, float* sueldo);
int mostrarEmpleados (eEmpleado** e, int tam);
int mostrarEmpleado (eEmpleado* e);
eEmpleado** agrandarLista(eEmpleado** vec, int tam);
int guardarEmpleadosBinario (eEmpleado** lista, int tam, char* path);


int main()
{
    int tam = 0;
    int tam2 = 0;
    int cant;
    eEmpleado* auxEmpleado = NULL;
    eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*));
    char buffer[3][30];


    if (lista == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    FILE* f = fopen("empleados.csv", "r") ;
    if (f == NULL)
    {
        exit(1);
    }

    fscanf(f, "%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1], buffer[2]);


    while (!feof(f))
    {
        cant = fscanf(f, "%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1], buffer[2]);
        if (cant == 3)
        {
            auxEmpleado = newEmpledaoParam(atoi(buffer[0]), buffer[1], atof(buffer[2]) );
            if (auxEmpleado != NULL)
            {

                *(lista + tam) = auxEmpleado;
                tam ++;

                if ((lista = agrandarLista(lista, tam + 1) ) != NULL)
                {
                    //  printf("t %d\n", tam);
                    //  mostrarEmpleado(*(lista+tam));
                    //printf("Empleado agregado a la lista\n");

                }
            }
        }

    }
    fclose(f);

    mostrarEmpleados(lista, tam);

    if (guardarEmpleadosBinario(lista, tam, "empleados.bin"))
    {

        printf("Empleados guardados con exito\n");
        system("pause");
    }
    else
    {
        printf("No se pudieron serializar los empleados\n");
        system("pause");

    }


    //------------------LEO DESDE BINARIO------------------------------

    eEmpleado** lista2 = (eEmpleado**) malloc(sizeof(eEmpleado*));

    if (lista2 == NULL)
    {
        printf("No se pudo asignar memoria\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    f = fopen("empleados.bin", "rb") ;
    if (f == NULL)
    {
        exit(1);
    }

    while (!feof(f))
    {

        auxEmpleado = newEmpleado();

        if (auxEmpleado != NULL)
        {
            cant = fread( auxEmpleado, sizeof(eEmpleado), 1, f);
            if (cant == 1)
            {

                *(lista2 + tam2) = auxEmpleado;
                tam2 ++;

                if ((lista2 = agrandarLista(lista2, tam2 + 1) ) == NULL)
                {
                    printf("No se pudo agrandar");


                }
            }

        }

    }

    printf("Empleados binarios\n");
    mostrarEmpleados(lista2, tam2);

    fclose(f);


    // --------------------CREAR UN ARCHIVO CSV------------------------

    if (guardarEmpleadosCSV(lista2, tam2, "LISTA.csv") ) {

        printf( "Se guardaron los empleados en csv\n");
    } else {
        printf("problema para guardar los empleados\n");
    }

    return 0;
}


eEmpleado* newEmpleado()
{

    eEmpleado* nuevo = (eEmpleado*) malloc(sizeof(eEmpleado));

    if (nuevo != NULL)
    {
        nuevo ->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->sueldo = 0;

    }

    return nuevo;

}


eEmpleado* newEmpledaoParam (int id, char* nombre, float sueldo)
{
    eEmpleado* nuevo = newEmpleado();
    if (nuevo != NULL)
    {
        if (setIdEmpleado(nuevo, id) &&
                setNombreEmpleado(nuevo, nombre) &&
                setSueldoEmpleado(nuevo, sueldo))
        {

            //  printf("Empleado creado correctamente\n");

        }
        else
        {
            nuevo = NULL;

        }

    }

    return nuevo;
}


int setIdEmpleado(eEmpleado* e, int id)
{
    int todoOk = 0;

    if (e != NULL && id >= 10000 && id <= 20000)
    {

        e->id = id;
        todoOk = 1;

    }

    return todoOk;
}


int setSueldoEmpleado(eEmpleado* e, float sueldo)
{
    int todoOk = 0;

    if (e != NULL && sueldo > 0)
    {

        e->sueldo = sueldo;
        todoOk = 1;

    }

    return todoOk;
}


int setNombreEmpleado(eEmpleado* e, char* nombre)
{
    int todoOk = 0;

    if (e != NULL && nombre != NULL && strlen(nombre)<19)
    {

        strcpy(e->nombre, nombre);
        todoOk = 1;

    }

    return todoOk;
}


int getIdEmpleado(eEmpleado* e, int* id)
{

    int todoOk = 0;

    if (e != NULL && id != NULL )
    {
        *id = e->id;
        todoOk = 1;
    }

    return todoOk;
}


int getSueldoEmpleado(eEmpleado* e, float* sueldo)
{

    int todoOk = 0;

    if (e != NULL && sueldo != NULL )
    {
        *sueldo = e->sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int getNombreEmpleado(eEmpleado* e, char* nombre)
{

    int todoOk = 0;

    if (e != NULL && nombre != NULL )
    {
        strcpy(nombre, e->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int mostrarEmpleado (eEmpleado* e)
{

    int todoOk = 0;

    if (e != NULL)
    {

        printf("%d  %s  %.2f\n",e->id, e->nombre, e->sueldo);
        todoOk = 1;
    }

    return todoOk;
}

int mostrarEmpleados (eEmpleado** e, int tam)
{

    int todoOk = 0;

    printf("ID     NOMBRE     SUELDO\n");

    if (e != NULL && tam > 0)
    {

        for (int i = 0; i<tam; i++)
        {
            mostrarEmpleado(*(e + i));

        }

    }

    return todoOk;
}


eEmpleado** agrandarLista(eEmpleado** vec, int tam)
{

    eEmpleado** aux = (eEmpleado**)  realloc(vec, sizeof(eEmpleado*) * tam);

    if (aux != NULL)
    {
        vec = aux;
    }

    return vec;

}


int guardarEmpleadosBinario (eEmpleado** lista, int tam, char* path)
{

    int todoOk = 0;
    int cant;
    FILE* f;

    if (lista != NULL && path != NULL && tam > 0)
    {

        f = fopen(path, "wb");
        if (f == NULL)
        {
            return todoOk;

        }
        for (int i=0; i<tam; i++)
        {
            cant = fwrite(*(lista+i), sizeof(eEmpleado), 1, f);
            if (cant<1)
            {
                return todoOk;
            }
        }

        fclose(f);
        todoOk = 1;

    }

    return todoOk;

}



int guardarEmpleadosCSV (eEmpleado** lista, int tam, char* path) {

    int todoOk =0;


    if (lista != NULL && path != NULL && tam>0) {

        FILE* f = fopen(path, "w");
        int cant;
        if (f == NULL)
        {
            return todoOk;

        }
        fprintf(f,"ID NOMBRE SUELDO\n");
        for (int i=0; i<tam; i++)
        {
            cant = fprintf(f, "%d,%s,%.2f\n",(*(lista+i))->id,(*(lista+i))->nombre,(*(lista+i))->sueldo);

            if (cant<1)
            {
                return todoOk;
            }
        }

        fclose(f);
        todoOk = 1;

    }


    return todoOk;
}
