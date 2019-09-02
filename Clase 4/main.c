#include <stdio.h>
#include <stdlib.h>


int getIntRange(int,int);

int main()
{
    int valor;
    valor = getIntRange(-100,100);

    printf("\n\nel numero ingresado es %d\n", valor);

    return 0;
}

int getIntRange(int min, int max)
{

    int numero;
    printf("Ingrese numero entre %d y %d: ",min,max);
    scanf("%d",&numero);

    while(numero>max || numero<min)
    {
        printf("\nERROR. Ingrese numero entre %d y %d: ",min,max);
        scanf("%d",&numero);
    }
    return numero;


}
