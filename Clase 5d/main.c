#include <stdio.h>
#include <stdlib.h>

void mostrarVectorInt(int[], int );
void mostrarVectorChar(char[], int );
void mostrarVectorFloat(float[], int);

int main()
{
    int numeros [] = {23,21,43,54,58,51,66,88,32,95};
    char x[] = {'a','e','i','o','u'};
    float reales[] = {23.5, 56.34, 55.1, 89.7, 90.9};

    mostrarVectorInt(numeros,10);
    printf("\n");
    mostrarVectorChar(x,5);
    printf("\n");
    mostrarVectorFloat(reales,5);

    return 0;
}


void mostrarVectorInt(int vector[], int tam)
{
    for (int i=0; i<tam; i++)
    {
        printf("%d ",vector[i]);
    }
}


void mostrarVectorChar(char vector[], int tam ) {

    for (int i=0; i<tam; i++)
    {
        printf("%c ",vector[i]);
    }
}

void mostrarVectorFloat(float vector[], int tam ) {

    for (int i=0; i<tam; i++)
    {
        printf("%.2f ",vector[i]);
    }
}
