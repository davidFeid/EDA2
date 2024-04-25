#include "habilidad.h"

void init_habilidad(Habilidad *habilidad,
                    char *nombre,
                    char *descripcion,
                    bool esTemporal,
                    int duracion,
                    int modificadorAtaque,
                    int modificadorDefensa,
                    int modificadorHP) {
    strcpy(habilidad->nombre, nombre);
    strcpy(habilidad->descripcion, descripcion);
    habilidad->esTemporal = esTemporal;
    habilidad->duracion = duracion;
    habilidad->modificadorAtaque = modificadorAtaque;
    habilidad->modificadorDefensa = modificadorDefensa;
    habilidad->modificadorHP = modificadorHP;
}

void printHabilidad(Habilidad *habilidad) {
    printf("Nombre: %s\n", habilidad->nombre);
    printf("Descripción: %s\n", habilidad->descripcion);
    printf("Tipo: %s\n", habilidad->esTemporal ? "Modificador Temporal" : "Ataque Directo");
    printf("Duración: %d\n", habilidad->duracion);
    printf("Modificador de Ataque: %d\n", habilidad->modificadorAtaque);
    printf("Modificador de Defensa: %d\n", habilidad->modificadorDefensa);
    printf("Modificador de HP: %d\n", habilidad->modificadorHP);
}

void freeHabilidad(Habilidad *habilidad){
    // @brief Frees the game_state memory if it is not NULL
    // @Returns: nothing
    if(habilidad != NULL) free(habilidad);
}