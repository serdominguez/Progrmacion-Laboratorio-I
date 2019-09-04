#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*  int numeros [10] = {1,2,3,4,5,6,7,8,9,10};

      printf("Los elementos del array son : ");

      for (int i=0; i<10; i++) {

          printf("%d ",numeros[i]);
      }
    */

    int numero[5]= {1,6,2,6,3};
    int maximo;
    int flag = 0;

    for (int i=0; i<5; i++)
    {

        if (numero[i]>maximo || flag == 0)
        {
            maximo=numero[i];
            flag = 1;

        }

    }

    printf("El indice donde se encontro el maximo fue :");

     for (int i=0; i<5; i++)
    {
        if (numero[i]==maximo) {

            printf("%d ", i);
        }

    }


    return 0;
}
