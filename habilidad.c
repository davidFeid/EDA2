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
    if(habilidad != NULL) free(habilidad);
}

void aplicar_habilidad(Enemigo *enemigo, Habilidad *habilidad) {
    if (enemigo != NULL && habilidad != NULL) {
        enemigo->ataque += habilidad->modificadorAtaque;
        enemigo->defensa += habilidad->modificadorDefensa;
        enemigo->vida += habilidad->modificadorHP;
        
        // Si es un modificador temporal, podríamos necesitar lógica adicional para revertir los cambios después de un tiempo
    }
}