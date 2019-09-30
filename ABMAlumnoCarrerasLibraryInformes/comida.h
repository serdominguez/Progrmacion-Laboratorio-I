#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct
{
    int id;
    char desc[20];
    float precio;
} eComida;


#endif // COMIDA_H_INCLUDED

//comidas
void mostrarComidas(eComida comidas[], int tam);
void mostrarComida(eComida comida);
int cargarDescComida(int id, eComida comidas[], int tam, char desc[]);
