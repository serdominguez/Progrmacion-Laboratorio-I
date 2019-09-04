#include <stdio.h>
#include <stdlib.h>

int buscarNumer(int num, int vec[], int tam);

int main()
{
    int numeros[] = {2,4,3,8,6,5,9,1,8,23};
    int esta;

    esta = buscarNumer(4,numeros,10);

    if (esta == 1)
    {
        printf("Esta\n");
    }
    else
    {

        printf("No esta");
    }

    return 0;
}

int buscarNumer(int num, int vec[], int tam)
{


    for (int i=0; i<tam; i++)
    {

        if (vec[i]==num)
        {
            return 1;
            break;
        }

    }

}

