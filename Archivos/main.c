#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f = fopen("archivo.txt", "r");

    char mensaje[30] = "Esto es un mensaje";

    char cadena[30];

    char auxChar;

    if (f == NULL) {
        printf("No se pudo abrir el archivo");
        system("pause");
        exit(EXIT_FAILURE);
    }

    //fprintf(f, "Hola mundo");
    //fwrite(mensaje, sizeof(char), strlen(mensaje),f);

    //fscanf(f, "%s", cadena);
    /*
    while(!feof(f)) {
    fgets(cadena, 29, f);
    printf("%s", cadena);
    } */

    while(!feof(f)) {
    auxChar = fgetc(f);
    printf("%c", auxChar);
    fread(cadena, sizeof(char),29,f)
    }

    fclose(f);



    return 0;
}
