#include <stdio.h>
#include <stdlib.h>

void mostrarNombres(char mat [][20]);

int main()
{
    char nombres [5][20];

    for (int i=0;i<5;i++) {
    printf("ingrese nombre: ");
    fflush(stdin);
    gets(nombres[i]);
    }

    for (int i=0;i<5;i++) {
    printf("%s\n",nombres[i]);
    }

    return 0;
}
