#include <stdio.h>
#include "personaje.h"

/* void init_prota(Personaje *personaje,  char *nombre, int vida, int ataque, int defensa,  char habilidades[4][50]) {
    strcpy(personaje->nombre, nombre);
    personaje->vida = vida;
    personaje->ataque = ataque;
    personaje->defensa = defensa;
    for (int i = 0; i < 4; i++) {
        strcpy(personaje->habilidades[i], habilidades[i]);
    }
} */
void init_personaje(Personaje *personaje) {
    printf("¡Bienvenido! Vamos a configurar a tu personaje.\n");
    
    // Solicitar y almacenar el nombre del personaje
    printf("Ingresa el nombre de tu personaje: ");
    scanf("%s", personaje->nombre);

    // Solicitar y almacenar los puntos de vida, ataque y defensa
    printf("Ingresa los puntos de vida de tu personaje: ");
    scanf("%d", &personaje->vida);

    printf("Ingresa los puntos de ataque de tu personaje: ");
    scanf("%d", &personaje->ataque);

    printf("Ingresa los puntos de defensa de tu personaje: ");
    scanf("%d", &personaje->defensa);
}

void print_personaje(Personaje *personaje) {
    printf("\nNombre: %s\n", personaje->nombre);
    printf("Vida: %d\n", personaje->vida);
    printf("Ataque: %d\n", personaje->ataque);
    printf("Defensa: %d\n", personaje->defensa);
    printf("Habilidades:\n");
    for (int i = 0; i < 4; i++) {
        printf("- %s\n", personaje->habilidades[i]);
    }
}

void free_personaje(Personaje *personaje){
    if (personaje!=NULL)
    {
        free(personaje);
    }
    
}