#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 10

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int isEmpty;
} eAlumno;

void mostrarAlumno(eAlumno x);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno alumnos[],int tam);
int buscarLibre (eAlumno alumons[], int tam);
int buscarAlumno (int legajo, eAlumno alumnos[], int tam);
int altaAlumno (eAlumno alumnos[], int tam);
int altaAlumnoAuto (eAlumno alumnos[], int tam, int legajo);
int bajaAlumno(eAlumno alumno[], int tam);
int modificarAlumno (eAlumno alumno[], int tam);
eAlumno newAlumno (int leg, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha);
int harcodearAlumnos(eAlumno alumnos[], int tam, int cantidad);
int menu();



int main()
{
    eAlumno lista[TAM];
    char salir = 'n';

    int legajo = 20000;
    //int altaOK;


    inicializarAlumnos(lista,TAM);

    legajo = legajo + harcodearAlumnos(lista,TAM,10);


    do
    {

        switch (menu())
        {

        case 1:
            //printf("alta alumno\n");
            //altaAlumno(lista,TAM);
            if (altaAlumnoAuto(lista,TAM,legajo))
            {
                legajo++;
            }
            break;
        case 2:
            //printf("baja alumno\n");
            bajaAlumno(lista,TAM);
            break;
        case 3:
            //printf("modificar alumno\n");
            modificarAlumno(lista,TAM);
            break;
        case 4:
            //printf("listar alumno\n");
            mostrarAlumnos(lista,TAM);
            break;
        case 5:
            printf("Ordenar alumnos\n");
            ordenarAlumnos(lista,TAM);
            break;
        case 6:
            printf("informes\n");
        case 7:
            printf("confirma salida?\n");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("opcion invalida\n");
        }
        system("pause");

    }
    while (salir == 'n');


    return 0;
}




void mostrarAlumno(eAlumno x)
{
    printf("%d\t%s\t%d\t%c\t%d\t%d\t%.2f\t\t%02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    int flag = 0;

    system("cls");
    printf("LISTADO DE ALUMNOS\n\n");

    printf("Legajo\tNombre\tEdad\tSexo\tNota1\tNota2\tPromedio\tFIngreso\n");
    for(int i=0; i < tam; i++)
    {
        if (vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i]);
            flag = 1;
        }

    }

    if (flag == 0)
    {
        system("cls");
        printf("NO hay alumnos para mostar");

    }

    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam)
{

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].promedio > vec[j].promedio && vec[i].isEmpty == 0)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
    printf("\n alumnos ordenados por promedio\n");
}

int menu()
{
    int opcion;

    system("cls");
    printf("Menu de opciones\n\n");
    printf("1- Alta alumno\n");
    printf("2- Baja alumno\n");
    printf("3- Modificar alumno\n");
    printf("4- Listar alumnos\n");
    printf("5- Ordenar alumnos\n");
    printf("6- Informes\n");
    printf("7- Salir\n\n");
    printf("Ingrese opcion; ");
    scanf("%d",&opcion);

    return opcion;

}

void inicializarAlumnos(eAlumno alumnos[],int tam)
{

    for (int i=0; i<tam; i++)
    {
        alumnos[i].isEmpty=1;
    }

}


int buscarLibre (eAlumno alumnos[], int tam)
{

    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if (alumnos[i].isEmpty == 1)  //se puede sacar el igual, porque "==1" es true
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int buscarAlumno (int legajo, eAlumno alumnos[], int tam)
{

    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if (alumnos[i].isEmpty == 0 && alumnos[i].legajo==legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int altaAlumno (eAlumno alumnos[], int tam)
{

    int todoOK = 0;
    int indice;
    int esta;
    int legajo;
    int edad;
    int n1;
    int n2;
    char sexo;
    char nombre[20];
//   float promedio;
    eFecha fecha;
//    eAlumno nuevoAlumno;

    system("cls");
    printf("ALTA ALUMNO\n\n");

    indice = buscarLibre(alumnos, tam);

    if (indice == -1)
    {
        printf("SISTEMA COMPLETO, No se puede agregar mas alumnos\n");
        system("pause");
    }
    else
    {

        printf("Ingrese legajo: ");
        scanf("%d",&legajo);

        esta = buscarAlumno(legajo, alumnos, tam);

        if (esta != -1)
        {
            printf("Legajo ya registrado\n");
            mostrarAlumno(alumnos[esta]);
            system("pause");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);

            printf("Ingrese edad:");
            scanf("%d", &edad);

            printf("Ingrese sexo:");
            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese nota parcial 1:");
            scanf("%d", &n1);

            printf("Ingrese nota parcial 2:");
            scanf("%d", &n2);

            //promedio = (float) (nota1 + nota2) / 2;   calculado dentro de la funcion

            printf("Ingrese fecha ingreso: dd/mm/aaaa ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            //FALTA VALIDAR LOS DATOS

            //SE CARGAN UNA VEZ VALIDADOS
            alumnos[indice] = newAlumno(legajo,nombre,sexo,edad,n1,n2,fecha);
            todoOK = 1;
        }

    }
    return todoOK;

}


eAlumno newAlumno (int leg, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha)
{

    eAlumno nuevoAlumno;

    nuevoAlumno.legajo = leg;
    strcpy(nuevoAlumno.nombre,nombre);
    nuevoAlumno.edad = edad;
    nuevoAlumno.sexo = sexo;
    nuevoAlumno.nota1 = n1;
    nuevoAlumno.nota2 = n2;
    nuevoAlumno.promedio = (float)(n1 + n2) /2;
    nuevoAlumno.fechaIngreso = fecha;
    nuevoAlumno.isEmpty = 0;

    return nuevoAlumno;


}


int bajaAlumno(eAlumno alumno[], int tam)
{

    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;

    system("cls");
    printf("BAJA ALUMNO\n\n");


    printf("ingrese legajo: ");
    scanf("%d",&legajo);

    indice = buscarAlumno(legajo,alumno,tam);

    if (indice == -1)
    {

        printf("No existe alumno en ese legajo");
        system("pause");

    }
    else
    {
        mostrarAlumno(alumno[indice]);
        printf("confirma baja? ");
        fflush(stdin);
        confirma = getche();

        if (confirma == 's')
        {
            alumno[indice].isEmpty=1;
            printf("\nSe ha eliminado el alumno\n");
            todoOk = 1;

        }
        else
        {
            printf("\nBaja cancelada\n");
        }
        system("pause");

    }

    return todoOk;
}


int modificarAlumno (eAlumno alumno[], int tam)
{


    int todoOk = 0;
    int indice;
    int legajo;
    int opcion;
    int nota;
    // char confirma;

    system("cls");
    printf("MODIFICACION ALUMNO\n\n");


    printf("ingrese legajo: ");
    scanf("%d",&legajo);

    indice = buscarAlumno(legajo,alumno,tam);

    if (indice == -1)
    {

        printf("No existe alumno en ese legajo");
        system("pause");

    }
    else
    {
        mostrarAlumno(alumno[indice]);
        printf("Que nota desea modificar? ");
        scanf("%d",&opcion);

        switch (opcion )
        {
        case 1:
            printf("ingrese nueva nota del primer parcial: ");
            scanf("%d",&nota);
            alumno[indice].nota1 = nota;
            alumno[indice].promedio = (float)(alumno[indice].nota1+alumno[indice].nota2)/2;
            printf("\n");
            mostrarAlumno(alumno[indice]);
            break;
        case 2:
            printf("ingrese nueva nota del segundo parcial: ");
            scanf("%d",&nota);
            alumno[indice].nota1 = nota;
            alumno[indice].promedio = (float)(alumno[indice].nota1+alumno[indice].nota2)/2;
            printf("\n");
            mostrarAlumno(alumno[indice]);
        default:
            printf("\nDATO INVALIDO");

        }

    }

    return todoOk;

}


int altaAlumnoAuto (eAlumno alumnos[], int tam, int legajo)
{


    int todoOK = 0;
    int indice;
    //int esta;
    int edad;
    int n1;
    int n2;
    char sexo;
    char nombre[20];
//   float promedio;
    eFecha fecha;
//    eAlumno nuevoAlumno;

    system("cls");
    printf("ALTA ALUMNO\n\n");

    indice = buscarLibre(alumnos, tam);

    if (indice == -1)
    {
        printf("SISTEMA COMPLETO, No se puede agregar mas alumnos\n");
        system("pause");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese edad:");
        scanf("%d", &edad);

        printf("Ingrese sexo:");
        fflush(stdin);
        scanf("%c", &sexo);

        printf("Ingrese nota parcial 1:");
        scanf("%d", &n1);

        printf("Ingrese nota parcial 2:");
        scanf("%d", &n2);

        //promedio = (float) (nota1 + nota2) / 2;   calculado dentro de la funcion

        printf("Ingrese fecha ingreso: dd/mm/aaaa ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        //FALTA VALIDAR LOS DATOS

        //SE CARGAN UNA VEZ VALIDADOS
        alumnos[indice] = newAlumno(legajo,nombre,sexo,edad,n1,n2,fecha);
        todoOK = 1;
    }


    return todoOK;



}



int harcodearAlumnos(eAlumno alumnos[], int tam, int cantidad)
{

    int cont = 0;

    eAlumno listaAuxiliar[] =
    {
        {20000,"juan",      21,'m',2,10,6,      {12,5,2017}, 0},
        {20001,"Ana",       20,'f',10,10,10,    {22,4,2016}, 0},
        {20002,"Alicia",    25,'f',2,8,5,       {01,3,2015}, 0},
        {20003,"Miguel",    27,'m',4,10,7,      {11,2,2015}, 0},
        {20004,"Gaston",    23,'m',2,4,3,       {16,1,2014}, 0},
        {20005,"Amalia",    31,'f',8,10,9,      {29,11,2018}, 0},
        {20006,"Sofia",     32,'f',2,6,4,       {05,12,2019}, 0},
        {20007,"Diego",     28,'m',9,1,5,       {06,9,2013}, 0},
        {20008,"German",    40,'m',2,7,4.5,     {11,8,2010}, 0},
        {20009,"Clara",     19,'f',2,2,2,       {22,8,2010}, 0}

    };


    if(cantidad <= TAM && cantidad < 11)
    {
        for (int i=0; i<cantidad; i++)
        {
            alumnos[i] = listaAuxiliar[i];
            cont ++;
        }

    }


    return cont;
}
