#include <stdio.h>
#include "enemigo.h"


void init_enemigo(Enemigo *enemy,  char *nombre, int vida, int ataque, int defensa) {
    strcpy(enemy->nombre, nombre);
    enemigo->vida = vida;
    enemigo->ataque = ataque;
    enemigo->defensa = defensa;
}

void print_enemigo( Enemigo *enemy) {
    printf("Nombre: %s\n", enemigo->nombre);
    printf("Vida: %d\n", enemigo->vida);
    printf("Ataque: %d\n", enemigo->ataque);
    printf("Defensa: %d\n", enemigo->defensa);
}

void free_enemigo(Enemigo *enemy){
   if (enemy!=NULL)
   {
     free(enemy);   
    }
    
}