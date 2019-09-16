#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 5
#define COLUMNAS 20
#define TAM 5

void mostrarAlumnos( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20]);
void mostrarAlumno(int leg, int age, char sexo, int nota1, int nota2, float promedio, char mat[]);
void ordenarArrayLeg(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20]);
void ordenarArrayAge(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20]);
void ordenarArraySex(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20]);
void ordenarArrayN1(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20]);
void ordenarArrayN2(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20]);
void ordenarArrayProm(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20]);
void ordenarArrayNom(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20]);
void ordenarAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20]);


int main()
{
    int legajos[TAM] = {932,123, 567, 379, 101};
    int edades[TAM] =  {21, 23, 20, 21, 30};
    char sexos[TAM] = {'m', 'm', 'f', 'f', 'm'};
    int notasp1[TAM] = {2, 4, 7, 8, 5};
    int notasp2[TAM] = {4, 10, 9, 4, 2};
    float promedios[TAM] = { 3, 7, 8, 6, 3.5};
    char nombres[FILAS][COLUMNAS] =
    {
        "Juan",
        "Manuel",
        "Alicia",
        "Sofia",
        "Claudio"
    };
    //char auxCad[100];
    int opcion;

    /* for(int i = 0; i < TAM; i++){

         printf("Ingrese legajo: ");
         scanf("%d", &legajos[i]);

         printf("Ingrese un nombre: ");
         fflush(stdin);
         gets(auxCad);

        while(strlen(auxCad) >19){
            printf("Nombre demasiado largo. Maximo 19 caracteres\nReingrese nombre: ");
            fflush(stdin);
            gets(auxCad);
        }
        strcpy(nombres[i], auxCad);

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
    mostrarAlumnos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM, nombres);
    printf("\n\n");

    printf("Opciones de ordeamiento:\n1-Legajo\n2-edad\n3-sexo\n4-nota primer parcial\n5-nota segundo parcial\n6-promedios\n7-nombres\n8-ordenamiento por sexo y legajo\n\n");
    printf("Elija opcion: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        ordenarArrayLeg(legajos, edades, sexos, notasp1, notasp2, promedios, TAM, nombres);
        break;
    case 2:
        ordenarArrayAge(legajos, edades, sexos, notasp1, notasp2, promedios, TAM, nombres);
        break;
    case 3:
        ordenarArraySex(legajos, edades, sexos, notasp1, notasp2, promedios, TAM, nombres);
        break;
    case 4:
        ordenarArrayN1(legajos, edades, sexos, notasp1, notasp2, promedios, TAM, nombres);
        break;
    case 5:
        ordenarArrayN2(legajos, edades, sexos, notasp1, notasp2, promedios, TAM, nombres);
    case 6:
        ordenarArrayProm(legajos, edades, sexos, notasp1, notasp2, promedios, TAM, nombres);
        break;
    case 7:
        ordenarArrayNom(legajos, edades, sexos, notasp1, notasp2, promedios, TAM, nombres);
        break;
    case 8:
        ordenarAlumnosSexLeg(legajos, edades, sexos, notasp1, notasp2, promedios, TAM, nombres);
        break;
//    case default:
        //      printf("NO ELIGIO OPCION VALIDA");

    }



    system("cls");
    printf("Eligio opcion %d\n\n",opcion);
    mostrarAlumnos(legajos, edades, sexos, notasp1, notasp2, promedios, TAM,nombres);

    return 0;
}

void mostrarAlumnos( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20])
{

    printf("Legajo\tEdad\tSexo\tNota1\tNota2\tPromedio\tNombre\n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarAlumno( leg[i], age[i], sex[i], n1[i], n2[i], prom[i], mat[i]);
    }
    printf("\n\n");
}



void mostrarAlumno(int leg, int age, char sexo, int nota1, int nota2, float promedio, char mat[])
{

    printf("%d\t%d\t%c\t%2d\t%2d\t%.2f\t\t%s\n", leg, age, sexo, nota1, nota2, promedio, mat);

}

void ordenarArrayLeg(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20])
{

    int auxInt;
    char auxChar;
    float auxFloat;
    char aux[20];

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (leg[i]>leg[j])
            {

                auxInt=leg[j];
                leg[j]=leg[i];
                leg[i]=auxInt;

                auxInt=age[j];
                age[j]=age[i];
                age[i]=auxInt;

                auxChar=sex[j];
                sex[j]=sex[i];
                sex[i]=auxChar;

                auxInt=n1[j];
                n1[j]=n1[i];
                n1[i]=auxInt;

                auxInt=n2[j];
                n2[j]=n2[i];
                n2[i]=auxInt;

                auxFloat=prom[j];
                prom[j]=prom[i];
                prom[i]=auxFloat;

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);
            }
        }
    }
}

void ordenarArrayAge(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20])
{

    int auxInt;
    char auxChar;
    float auxFloat;
    char aux[20];

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (age[i]>age[j])
            {

                auxInt=leg[j];
                leg[j]=leg[i];
                leg[i]=auxInt;

                auxInt=age[j];
                age[j]=age[i];
                age[i]=auxInt;

                auxChar=sex[j];
                sex[j]=sex[i];
                sex[i]=auxChar;

                auxInt=n1[j];
                n1[j]=n1[i];
                n1[i]=auxInt;

                auxInt=n2[j];
                n2[j]=n2[i];
                n2[i]=auxInt;

                auxFloat=prom[j];
                prom[j]=prom[i];
                prom[i]=auxFloat;

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);
            }
        }
    }
}

void ordenarArraySex(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20])
{

    int auxInt;
    char auxChar;
    float auxFloat;
    char aux[20];

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (sex[i]>sex[j])
            {

                auxInt=leg[j];
                leg[j]=leg[i];
                leg[i]=auxInt;

                auxInt=age[j];
                age[j]=age[i];
                age[i]=auxInt;

                auxChar=sex[j];
                sex[j]=sex[i];
                sex[i]=auxChar;

                auxInt=n1[j];
                n1[j]=n1[i];
                n1[i]=auxInt;

                auxInt=n2[j];
                n2[j]=n2[i];
                n2[i]=auxInt;

                auxFloat=prom[j];
                prom[j]=prom[i];
                prom[i]=auxFloat;

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);
            }
        }
    }
}

void ordenarArrayN1(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20])
{

    int auxInt;
    char auxChar;
    float auxFloat;
    char aux[20];

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (n1[i]>n1[j])
            {

                auxInt=leg[j];
                leg[j]=leg[i];
                leg[i]=auxInt;

                auxInt=age[j];
                age[j]=age[i];
                age[i]=auxInt;

                auxChar=sex[j];
                sex[j]=sex[i];
                sex[i]=auxChar;

                auxInt=n1[j];
                n1[j]=n1[i];
                n1[i]=auxInt;

                auxInt=n2[j];
                n2[j]=n2[i];
                n2[i]=auxInt;

                auxFloat=prom[j];
                prom[j]=prom[i];
                prom[i]=auxFloat;

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);
            }
        }
    }
}

void ordenarArrayN2(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20])
{

    int auxInt;
    char auxChar;
    float auxFloat;
    char aux[20];

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (n2[i]>n2[j])
            {

                auxInt=leg[j];
                leg[j]=leg[i];
                leg[i]=auxInt;

                auxInt=age[j];
                age[j]=age[i];
                age[i]=auxInt;

                auxChar=sex[j];
                sex[j]=sex[i];
                sex[i]=auxChar;

                auxInt=n1[j];
                n1[j]=n1[i];
                n1[i]=auxInt;

                auxInt=n2[j];
                n2[j]=n2[i];
                n2[i]=auxInt;

                auxFloat=prom[j];
                prom[j]=prom[i];
                prom[i]=auxFloat;

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);
            }
        }
    }
}

void ordenarArrayProm(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20])
{

    int auxInt;
    char auxChar;
    float auxFloat;
    char aux[20];

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (prom[i]>prom[j])
            {

                auxInt=leg[j];
                leg[j]=leg[i];
                leg[i]=auxInt;

                auxInt=age[j];
                age[j]=age[i];
                age[i]=auxInt;

                auxChar=sex[j];
                sex[j]=sex[i];
                sex[i]=auxChar;

                auxInt=n1[j];
                n1[j]=n1[i];
                n1[i]=auxInt;

                auxInt=n2[j];
                n2[j]=n2[i];
                n2[i]=auxInt;

                auxFloat=prom[j];
                prom[j]=prom[i];
                prom[i]=auxFloat;

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);
            }
        }
    }
}

void ordenarArrayNom(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20])
{

    int auxInt;
    char auxChar;
    float auxFloat;
    char aux[20];

    for (int i=0; i<tam-1; i++)
    {
        for (int j=i+1; j<tam; j++)
        {
            if (strcmp(mat[i], mat[j]) > 0)
            {

                auxInt=leg[j];
                leg[j]=leg[i];
                leg[i]=auxInt;

                auxInt=age[j];
                age[j]=age[i];
                age[i]=auxInt;

                auxChar=sex[j];
                sex[j]=sex[i];
                sex[i]=auxChar;

                auxInt=n1[j];
                n1[j]=n1[i];
                n1[i]=auxInt;

                auxInt=n2[j];
                n2[j]=n2[i];
                n2[i]=auxInt;

                auxFloat=prom[j];
                prom[j]=prom[i];
                prom[i]=auxFloat;

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);
            }
        }
    }
}


void ordenarAlumnosSexLeg( int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam, char mat[][20])
{

    int auxInt;
    float auxFloat;
    char auxChar;
    char aux[20];
    int swap = 0;

    for(int i=0; i < tam-1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {

            if( sex[i] > sex[j])
            {
                swap = 1;
            }
            else if( sex[i] == sex[j] && leg[i] > leg[j])
            {

                swap = 1;
            }

            if( swap )  //verifica si swap es igual a 1 (es true)
            {

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = age[i];
                age[i] = age[j];
                age[j] = auxInt;

                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                auxInt = n1[i];
                n1[i] = n1[j];
                n1[j] = auxInt;

                auxInt = n2[i];
                n2[i] = n2[j];
                n2[j] = auxInt;

                auxFloat = prom[i];
                prom[i] = prom[j];
                prom[j] = auxFloat;

                strcpy(aux, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], aux);
            }

            swap = 0;
        }
    }
}
