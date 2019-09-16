#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int dia;
    int mes;
    int anio;

} eFechaIngreso;

typedef struct {
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFechaIngreso ingreso;

} eAlumno;

int main()
{
    eAlumno alumno1;

    eAlumno alumno2 = {521,"Diego",22,'m',8,6,7,{2,8,2015}};

/*
    printf("ingrese nombre: ");
    gets(alumno1.nombre);

    printf("ingrese legajo: ");
    scanf("%d",&alumno1.legajo);

    printf("ingrese edad: ");
    scanf("%d",&alumno1.edad);

    printf("ingrese sexo: ");
    fflush(stdin);
    scanf("%c",&alumno1.sexo);

    printf("ingrese nota primer parcial: ");
    scanf("%d",&alumno1.nota1);

    printf("ingrese nota segundo parcial: ");
    scanf("%d",&alumno1.nota2);

    alumno1.promedio = (float)(alumno1.nota1+alumno1.nota2)/2;

    printf("Ingrese dia de ingreso: ");
    scanf("%d",&alumno1.ingreso.dia);

    printf("Ingrese mes de ingreso: ");
    scanf("%d",&alumno1.ingreso.mes);

    printf("Ingrese anio de ingreso: ");
    scanf("%d",&alumno1.ingreso.anio);
    */

    printf("Nombre: %s\nLegajo: %d\nEdad: %d\nSexo: %c\nNota 1: %02d\nNota 2: %02d\nPromedio: %.2f\nFecha de ingreso %02d/%02d/%d\n",
            alumno2.nombre,
            alumno2.legajo,
            alumno2.edad,
            alumno2.sexo,
            alumno2.nota1,
            alumno2.nota2,
            alumno2.promedio,
            alumno2.ingreso.dia,
            alumno2.ingreso.mes,
            alumno2.ingreso.anio);


    return 0;
}
