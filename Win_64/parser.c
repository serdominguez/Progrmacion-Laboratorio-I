#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int cant;
    Employee* auxiliar = employee_new();

    if (pFile == NULL || pArrayListEmployee == NULL)
    {

        return todoOk;
    }

    char buffer[4][128];

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3]);

    while(!feof(pFile))
    {


        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3]);

        if (cant == 4)
        {
            auxiliar = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

            if (auxiliar != NULL)
            {

                ll_add(pArrayListEmployee, auxiliar);

            }
        }

    }
    todoOk = 1;

    return todoOk;

}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
