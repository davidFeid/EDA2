#include <stdio.h>
#include "personaje.h"

void init_prota(Protagonista *prota,  char *nombre, int vida, int ataque, int defensa,  char habilidades[4][50]) {
    strcpy(protagonista->nombre, nombre);
    protagonista->vida = vida;
    protagonista->ataque = ataque;
    protagonista->defensa = defensa;
    for (int i = 0; i < 4; i++) {
        strcpy(protagonista->habilidades[i], habilidades[i]);
    }
}

void print_prota(Protagonista *prota) {
    printf("Nombre: %s\n", protagonista->nombre);
    printf("Vida: %d\n", protagonista->vida);
    printf("Ataque: %d\n", protagonista->ataque);
    printf("Defensa: %d\n", protagonista->defensa);
    printf("Habilidades:\n");
    for (int i = 0; i < 4; i++) {
        printf("- %s\n", protagonista.habilidades[i]);
    }
}

void free_protagonista(Protagonista *prota){
    if (prota!=NULL)
    {
        free(prota);
    }
    
}