#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sexos[5];
    int mujeres=0;
    int hombres=0;

    for (int i=0; i<5; i++)
    {
        printf("ingrese sexo f o m ");
        fflush(stdin);
        scanf("%c",&sexos[i]);

        while (sexos[i]!='f' && sexos[i]!='m')
        {
            printf("Error. ingrese sexo f o m ");
            fflush(stdin);
            scanf("%c",&sexos[i]);

        }
    }

    for (int i=0; i<5; i++)
    {
        if (sexos[i]=='f')
        {
            mujeres++;
        }
        else
        {
            hombres ++;
        }

    }

    printf("hay %d mujeres y %d hombres",mujeres,hombres);

    return 0;
}
