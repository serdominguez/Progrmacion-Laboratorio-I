#include <stdio.h>
#include <stdlib.h>

#define TAM 5


void mostrarVectorInt(int[], int );

void ordenarVectorInt (int[], int, int);

int main()
{

    int vec[TAM] = {7,5,8,1,3};

    //int criterio = 1;


    printf("Vector desordenado ");
    mostrarVectorInt(vec, TAM);

    ordenarVectorInt(vec, TAM, 1);

    printf("Vector ordenado ");
    mostrarVectorInt(vec,TAM);



    return 0;
}


void mostrarVectorInt(int vector[], int tam)
{
    for (int i=0; i<tam; i++)
    {
        printf("%d ",vector[i]);
    }
}


void ordenarVectorInt (int vec[], int tam, int crit)
{
    int aux;
    for (int i=0; i<tam-1; i++)
    {

        for (int j=i+1; j<tam; j++)
        {
            if (crit==1)
            {
                if (vec[j]>vec[i])
                {

                    aux = vec[j];
                    vec [j] = vec[i];
                    vec [i] = aux;

                }


            }
            if (crit==0)
            {
                if (vec[j]<vec[i])
                {

                    aux = vec[j];
                    vec [j] = vec[i];
                    vec [i] = aux;

                }
            }
        }

    }
}


