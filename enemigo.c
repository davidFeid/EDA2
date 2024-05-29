#include <stdio.h>
#include "enemigo.h"

void init_enemigo(Enemigo *enemigo, char *nombre, int vida, int ataque, int defensa, Habilidad *habilidades[], int num_habilidades) {
    strcpy(enemigo->nombre, nombre);

    enemigo->vida = vida;
    enemigo->ataque = ataque;
    enemigo->defensa = defensa;

    enemigo->num_habilidades = num_habilidades;
    
    // Reservar memoria para el array de habilidades del enemigo
    enemigo->habilidades = malloc(num_habilidades * sizeof(Habilidad*)); 
    
    // Copiar cada habilidad al array de habilidades del enemigo
    for (int i = 0; i < num_habilidades; i++) {
        enemigo->habilidades[i] = malloc(sizeof(Habilidad));

        strcpy(enemigo->habilidades[i]->nombre, habilidades[i]->nombre);
        strcpy(enemigo->habilidades[i]->descripcion, habilidades[i]->descripcion);
        
        enemigo->habilidades[i]->modificadorAtaque = habilidades[i]->modificadorAtaque;
        enemigo->habilidades[i]->modificadorDefensa = habilidades[i]->modificadorDefensa;
        enemigo->habilidades[i]->modificadorHP = habilidades[i]->modificadorHP;
    }
}

// Función para imprimir la información de un enemigo
void print_enemigo(Enemigo *enemigo) {
    if (enemigo != NULL) {
        printf("                Nombre: %s\n", enemigo->nombre);
        printf("                Habilidades:\n");
        
        // Iterar sobre las habilidades del enemigo e imprimir cada una
        for (int i = 0; i < enemigo->num_habilidades; i++) {
            printf("                Habilidad %d:\n", i + 1);
            printHabilidad(enemigo->habilidades[i]);
        }

        printf("                Vida: %d\n", enemigo->vida);
        printf("                Ataque: %d\n", enemigo->ataque);
        printf("                Defensa: %d\n", enemigo->defensa);
    }
}

// Función para liberar la memoria asignada a un enemigo
void free_enemigo(Enemigo *enemigo) {
    if (enemigo != NULL) {
        free(enemigo); 
    }
}