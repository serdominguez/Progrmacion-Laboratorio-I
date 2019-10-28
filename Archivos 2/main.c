#include <stdio.h>
#include <stdlib.h>


typedef struct
{

    int id;
    char nombre[20];
    float sueldo;

} eEmpleado;

int mostrarEmpleado (eEmpleado* e);


int main()
{
    int cant;
    eEmpleado unEmpleado = {1234, "Julia", 34500};

    mostrarEmpleado(&unEmpleado);

    /*
    FILE* f = fopen("data.bin", "wb");

    if (f == NULL) {
        exit(EXIT_FAILURE);
    }

    cant = fwrite(&unEmpleado, sizeof(eEmpleado), 1, f);

    if (cant<1) {
        printf("Problemas para guardar el archivo");
    } else {
        printf("Se guardo de manera exitosa");
    }

    fclose(f); */

    eEmpleado clonEmpleado;

    FILE* f = fopen("data.bin", "rb");

    if (f == NULL) {
        exit(EXIT_FAILURE);
    }

    cant = fread(&clonEmpleado, sizeof(eEmpleado), 1, f);

    if (cant == 1) {
        printf("Archivo leido correctamente\n");

    }else {
        printf("Problemas prar leer el archivo\n");

    }

    mostrarEmpleado(&clonEmpleado);

    return 0;
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
