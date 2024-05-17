#include "habilidad.h"

void init_habilidad(Habilidad *habilidad,
                    char *nombre,
                    char *descripcion,
                    int modificadorAtaque,
                    int modificadorDefensa,
                    int modificadorHP) {
    
    strcpy(habilidad->nombre, nombre);
    strcpy(habilidad->descripcion, descripcion);
    habilidad->modificadorAtaque = modificadorAtaque;
    habilidad->modificadorDefensa = modificadorDefensa;
    habilidad->modificadorHP = modificadorHP;
}

void printHabilidad(Habilidad *habilidad) {
    printf("            Nombre: %s\n", habilidad->nombre);
    printf("            Descripción: %s\n", habilidad->descripcion);
    printf("            Modificador de Ataque: %d\n", habilidad->modificadorAtaque);
    printf("            Modificador de Defensa: %d\n", habilidad->modificadorDefensa);
    printf("            Modificador de HP: %d\n", habilidad->modificadorHP);
}

void freeHabilidad(Habilidad *habilidad){
    if(habilidad != NULL) free(habilidad);
}

