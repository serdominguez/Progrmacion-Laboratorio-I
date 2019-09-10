#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarAlumnos( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void mostrarAlumno(int leg, int age, char sexo, int nota1, int nota2, float promedio);
void ordenarArrayLeg(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarArrayAge(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarArraySex(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarArrayN1(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarArrayN1(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void ordenarArrayProm(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);

int main()
{
    int legajos[TAM] = {932 ,123, 567, 379, 101};
    int edades[TAM] =  {21, 23, 20, 21, 30};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm'};
    int notasp1[TAM] = {2, 4, 7, 8, 5};
    int notasp2[TAM] = {4, 10, 9, 4, 2};
    float promedios[TAM] = { 3, 7, 8, 6, 3.5};
    int opcion;

   /* for(int i = 0; i < TAM; i++){

        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);

        printf("Ingrese edad: ");
        scanf("%d", &edades[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese Nota Primer Parcial: ");
        scanf("%d", &notasp1[i]);

        printf("Ingrese Nota Segundo Parcial: ");
        scanf("%d", &notasp2[i]);

        promedios[i] = (float) (notasp1[i] + notasp2[i]) / 2;
    }*/


    system("cls");
    mostrarAlumnos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
    printf("\n\n");

    printf("Opciones de ordeamiento:\n1-Legajo\n2-edad\n3-sexo\n4-nota primer parcial\n5-nota segundo parcial\n6-promedios\n\n");
    printf("Elija opcion: ");
    scanf("%d",&opcion);

    switch(opcion) {
    case 1:
        ordenarArrayLeg(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
        break;
    case 2:
        ordenarArrayAge(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
        break;
    case 3:
        ordenarArraySex(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
        break;
    case 4:
        ordenarArrayN1(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
        break;
    case 5:
        ordenarArrayN2(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
    case 6:
        ordenarArrayProm(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);
        break;
//    case default:
  //      printf("NO ELIGIO OPCION VALIDA");

    }



    system("cls");
    printf("Eligio opcion %d\n\n",opcion);
    mostrarAlumnos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM);

    return 0;
}

void mostrarAlumnos( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam){

    printf(" Legajo  Edad  Sexo  Nota1  Nota2  Promedio\n\n");
    for(int i=0; i < tam; i++){
      mostrarAlumno( leg[i], age[i], sex[i], n1[i], n2[i], prom[i]);
    }
    printf("\n\n");
}



void mostrarAlumno(int leg, int age, char sexo, int nota1, int nota2, float promedio){

    printf("   %d     %d    %c     %d    %d     %.2f\n", leg, age, sexo, nota1, nota2, promedio);

}

void ordenarArrayLeg(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam) {

    int auxLeg;
    int auxAge;
    char auxSex;
    int auxN1;
    int auxN2;
    float auxProm;

    for (int i=0;i<tam-1;i++) {
        for (int j=i+1;j<tam;j++) {
            if (leg[i]>leg[j]) {

                auxLeg=leg[j];
                leg[j]=leg[i];
                leg[i]=auxLeg;

                auxAge=age[j];
                age[j]=age[i];
                age[i]=auxAge;

                auxSex=sex[j];
                sex[j]=sex[i];
                sex[i]=auxSex;

                auxN1=n1[j];
                n1[j]=n1[i];
                n1[i]=auxN1;

                auxN2=n2[j];
                n2[j]=n2[i];
                n2[i]=auxN2;

                auxProm=prom[j];
                prom[j]=prom[i];
                prom[i]=auxProm;
            }
        }
    }
}

void ordenarArrayAge(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam) {

    int auxLeg;
    int auxAge;
    char auxSex;
    int auxN1;
    int auxN2;
    float auxProm;

    for (int i=0;i<tam-1;i++) {
        for (int j=i+1;j<tam;j++) {
            if (age[i]>age[j]) {

                auxLeg=leg[j];
                leg[j]=leg[i];
                leg[i]=auxLeg;

                auxAge=age[j];
                age[j]=age[i];
                age[i]=auxAge;

                auxSex=sex[j];
                sex[j]=sex[i];
                sex[i]=auxSex;

                auxN1=n1[j];
                n1[j]=n1[i];
                n1[i]=auxN1;

                auxN2=n2[j];
                n2[j]=n2[i];
                n2[i]=auxN2;

                auxProm=prom[j];
                prom[j]=prom[i];
                prom[i]=auxProm;
            }
        }
    }
}

void ordenarArraySex(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam) {

    int auxLeg;
    int auxAge;
    char auxSex;
    int auxN1;
    int auxN2;
    float auxProm;

    for (int i=0;i<tam-1;i++) {
        for (int j=i+1;j<tam;j++) {
            if (sex[i]>sex[j]) {

                auxLeg=leg[j];
                leg[j]=leg[i];
                leg[i]=auxLeg;

                auxAge=age[j];
                age[j]=age[i];
                age[i]=auxAge;

                auxSex=sex[j];
                sex[j]=sex[i];
                sex[i]=auxSex;

                auxN1=n1[j];
                n1[j]=n1[i];
                n1[i]=auxN1;

                auxN2=n2[j];
                n2[j]=n2[i];
                n2[i]=auxN2;

                auxProm=prom[j];
                prom[j]=prom[i];
                prom[i]=auxProm;
            }
        }
    }
}

void ordenarArrayN1(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam) {

    int auxLeg;
    int auxAge;
    char auxSex;
    int auxN1;
    int auxN2;
    float auxProm;

    for (int i=0;i<tam-1;i++) {
        for (int j=i+1;j<tam;j++) {
            if (n1[i]>n1[j]) {

                auxLeg=leg[j];
                leg[j]=leg[i];
                leg[i]=auxLeg;

                auxAge=age[j];
                age[j]=age[i];
                age[i]=auxAge;

                auxSex=sex[j];
                sex[j]=sex[i];
                sex[i]=auxSex;

                auxN1=n1[j];
                n1[j]=n1[i];
                n1[i]=auxN1;

                auxN2=n2[j];
                n2[j]=n2[i];
                n2[i]=auxN2;

                auxProm=prom[j];
                prom[j]=prom[i];
                prom[i]=auxProm;
            }
        }
    }
}

void ordenarArrayN2(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam) {

    int auxLeg;
    int auxAge;
    char auxSex;
    int auxN1;
    int auxN2;
    float auxProm;

    for (int i=0;i<tam-1;i++) {
        for (int j=i+1;j<tam;j++) {
            if (n2[i]>n2[j]) {

                auxLeg=leg[j];
                leg[j]=leg[i];
                leg[i]=auxLeg;

                auxAge=age[j];
                age[j]=age[i];
                age[i]=auxAge;

                auxSex=sex[j];
                sex[j]=sex[i];
                sex[i]=auxSex;

                auxN1=n1[j];
                n1[j]=n1[i];
                n1[i]=auxN1;

                auxN2=n2[j];
                n2[j]=n2[i];
                n2[i]=auxN2;

                auxProm=prom[j];
                prom[j]=prom[i];
                prom[i]=auxProm;
            }
        }
    }
}

void ordenarArrayProm(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam) {

    int auxLeg;
    int auxAge;
    char auxSex;
    int auxN1;
    int auxN2;
    float auxProm;

    for (int i=0;i<tam-1;i++) {
        for (int j=i+1;j<tam;j++) {
            if (prom[i]>prom[j]) {

                auxLeg=leg[j];
                leg[j]=leg[i];
                leg[i]=auxLeg;

                auxAge=age[j];
                age[j]=age[i];
                age[i]=auxAge;

                auxSex=sex[j];
                sex[j]=sex[i];
                sex[i]=auxSex;

                auxN1=n1[j];
                n1[j]=n1[i];
                n1[i]=auxN1;

                auxN2=n2[j];
                n2[j]=n2[i];
                n2[i]=auxN2;

                auxProm=prom[j];
                prom[j]=prom[i];
                prom[i]=auxProm;
            }
        }
    }
}
