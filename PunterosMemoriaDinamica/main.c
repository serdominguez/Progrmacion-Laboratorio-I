#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* numeros[5];

    *numeros = (int) malloc(sizeof(int)*5);

    if (numeros == NULL) {
        exit(EXIT_FAILURE);

    }
    for (int i=0; i<5; i++) {

    printf("Ingrese numero: ");
    scanf("%d", (numeros+i));

    }
    printf("\n");

    for (int i=0; i<5; i++) {

    printf("%d ", *(numeros+i));

    }


    return 0;
}
