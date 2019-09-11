#include <stdio.h>
#include <stdlib.h>
#include <strings.h>    //biblioteca de funciones de string

int main()
{
    char nombre[10];
    char auxCad[100];
//  int cant;

    char n1[10] = "juana";
    char n2[10] = "JUAN";
    int x;
    int y;

    x = strcmp(n1,n2);  //compara dos canedas, da -1 si a>b 0 si a=b 1 si a<b

    y = stricmp(n1,n2); //compara dos canedas, da -1 si a>b 0 si a=b 1 si a<b (NO ES CASE SENSITIVE)

    strcat(n1,n2); //concatena sobre el primer string, el segundo

    strupr(n1); //Convierte en mayuscula toda la cadena
    strlwr(n1); //convierte en minuscula toda la cadena

    printf("%d\n",x);

    printf("Ingrese nombre: ");
    gets(auxCad);

    while (strlen(auxCad)>9)    //strlen -> verifica cantidad de caracteres de un string
    {
        printf("Error, nombre muy largo. Reingrese: ");
        gets(auxCad); //asigna string ingresado a variable

    }

    strcpy(nombre, auxCad);  //strcpy copia sobre el primer string ingresado el segundo
    //strncpy recibe dos cadenas y un nomero, copia tantos caracteres de la cadena 2 sobre la 1 como se indica en el numero

    printf("%s\n",nombre);


    return 0;
}


//
