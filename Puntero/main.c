#include <stdio.h>
#include <stdlib.h>

void changeX(int*);

int main()
{
    int x;

    changeX(&x);

    printf("%d",x);

    return 0;
}


void changeX(int* puntero)
{

    int num;

    printf ("ingrese numero: ");
    scanf("%d", &num);
    *puntero = num;
}
