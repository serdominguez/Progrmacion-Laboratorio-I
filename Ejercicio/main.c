#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#define LAR 20

int main()
{
    char nombre[LAR];
    char apellido[LAR];
    char aux[LAR*5];
    char nombreCompleto[(2*LAR)-1+2];
    int i=0;


    printf("ingrese nombre: "); //pido nombre
    gets(aux);
    while (strlen(aux)>LAR-1)  //valido largo
    {
        printf("NOMBRE MUY LARGO.\ningrese nombre: ");
        gets(aux);

    }
    strcpy(nombre,aux); //cargo nombre validado

    printf("Ingrese apellido: ");
    gets(aux);
    while (strlen(aux)>LAR-1)
    {
        printf("APELLIDO MUY LARGO.\ningrese apellido: ");
        gets(aux);

    }

    strcpy(apellido,aux);

    /*
    //convierto string a minuscula
    strlwr(nombre);
    strlwr(apellido);

    //convierto primer caracter a mayuscula
    nombre[0]=toupper(nombre[0]);
    apellido[0]=toupper(apellido[0]);

    */

    strcpy(nombreCompleto,apellido);
    strcat(nombreCompleto,", ");
    strcat(nombreCompleto,nombre);

    //convierto primer caracter a mayuscula
    nombreCompleto[0]=toupper(nombreCompleto[0]);

    //imprimo resultado

        while (nombreCompleto[i] != '\0')
    {
        if (nombreCompleto[i] == ' ')
        {
            nombreCompleto[i+1] = toupper((nombreCompleto[i+1]));
        }
        i++;
    }

    printf("\n%s",nombreCompleto);




    return 0;
}
