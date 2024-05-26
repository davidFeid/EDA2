#include "habilidad.h"

void init_habilidad(Habilidad *habilidad,
                    const char *nombre,
                    const char *descripcion,
                    int modificadorAtaque,
                    int modificadorDefensa,
                    int modificadorHP){
    // Asignar memoria para nombre y descripcion
    habilidad->nombre = malloc(strlen(nombre) + 1);  // +1 para el carácter nulo
    habilidad->descripcion = malloc(strlen(descripcion) + 1);  // +1 para el carácter nulo

    if (habilidad->nombre == NULL || habilidad->descripcion == NULL) {
        fprintf(stderr, "Error al asignar memoria para los nombres o descripciones\n");
        exit(1);
    }

    strcpy(habilidad->nombre, nombre);
    strcpy(habilidad->descripcion, descripcion);
    habilidad->modificadorAtaque = modificadorAtaque;
    habilidad->modificadorDefensa = modificadorDefensa;
    habilidad->modificadorHP = modificadorHP;
}

void printHabilidad(Habilidad *habilidad) {
    printf("                    Nombre: %s\n", habilidad->nombre);
    printf("                    Descripción: %s\n", habilidad->descripcion);
    printf("                    Modificador de Ataque: %d\n", habilidad->modificadorAtaque);
    printf("                    Modificador de Defensa: %d\n", habilidad->modificadorDefensa);
    printf("                    Modificador de HP: %d\n", habilidad->modificadorHP);
}

void freeHabilidad(Habilidad *habilidad){
    if(habilidad != NULL) free(habilidad);
}

