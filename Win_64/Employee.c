#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new() {

    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));

    if (newEmployee != NULL) {

        newEmployee->id = 0;
        strcpy(newEmployee->nombre," ");
        newEmployee->sueldo = 0;
        newEmployee->horasTrabajadas = 0;

    }

    return newEmployee;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr) {

    Employee* nuevo = employee_new();

    if (nuevo != NULL) {

        employee_setId(nuevo, atoi(idStr));
        employee_setNombre(nuevo, nombreStr);
        employee_setHorasTrabajadas(nuevo, atoi(horasTrabajadasStr));
        employee_setSueldo(nuevo, atoi(sueldoStr));

    }

    return nuevo;
}


int employee_setId(Employee* this,int id) {

    int todoOk = 0;

    if (this != NULL) {

        this->id = id;
        todoOk = 1;

    }

    return todoOk;

}

int employee_setNombre(Employee* this,char* nombre) {

    int todoOk = 0;

    if (this != NULL) {

        strcpy(this->nombre, nombre);
        todoOk = 1;

    }

    return todoOk;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas) {

    int todoOk = 0;

    if (this != NULL) {

        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;

    }

    return todoOk;



}

int employee_setSueldo(Employee* this,int sueldo) {

    int todoOk = 0;

    if (this != NULL) {

        this->sueldo = sueldo;
        todoOk = 1;

    }

    return todoOk;


}

int employee_getId(Employee* this,int* id) {

    int todoOk = 0;

    if (this != NULL && id !=NULL) {

        *id = this->id;
        todoOk = 1;


    }

    return todoOk;

}

int employee_getSueldo(Employee* this,int* sueldo) {

    int todoOk = 0;

    if (this != NULL && sueldo !=NULL) {

        *sueldo = this->sueldo;
        todoOk = 1;


    }

    return todoOk;

}

int employee_getHorasTrabajadas(Employee* this,int* horas) {

    int todoOk = 0;

    if (this != NULL && horas !=NULL) {

        *horas = this->horasTrabajadas;
        todoOk = 1;


    }

    return todoOk;

}

int employee_getNombre(Employee* this,char* nombre) {

    int todoOk = 0;

    if (this != NULL && nombre !=NULL) {

        strcpy(nombre,this->nombre );
        todoOk = 1;


    }

    return todoOk;

}

