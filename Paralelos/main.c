#include <stdio.h>
#include <stdlib.h>

#define TAM 3

void mostarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);

int main()
{
    int legajos[TAM];
    int edades[TAM];
    char sexos[TAM];
    int notasP1[TAM];
    int notasP2[TAM];
    float promedios[TAM];

    for (int i=0;i<TAM; i++) {

        printf("ingrese legajo: ");
        scanf("%d", &legajos[i]);

        printf("ingrese Edad: ");
        scanf("%d", &edades[i]);

        printf("ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("ingrese nota primer parcial: ");
        scanf("%d", &notasP1[i]);

        printf("ingrese nota segundo parcial: ");
        scanf("%d", &notasP2[i]);

        promedios[i] = (float) (notasP1[i]+notasP2[i])/2 ;
    }

    mostarAlumnos(legajos,edades,sexos,notasP1,notasP2,promedios,TAM);

    return 0;
}


void mostarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam) {

    printf("Legajo   Edad   sexo   Nota1   Nota2   Promedio\n\n");
    for (int i=0;i<tam;i++) {
        printf("%d    %d   %c   %d   %d   %.2f\n",leg[i],age[i],sex[i],n1[i],n2[i],prom[i]);

    }
    printf("\n");



}
