#include <stdio.h>
#include "enemigo.h"


void init_enemigo(Enemigo *enemigo,  char *nombre, int vida, int ataque, int defensa) {
    strcpy(enemigo->nombre, nombre);
    enemigo->vida = vida;
    enemigo->ataque = ataque;
    enemigo->defensa = defensa;
}

void print_enemigo( Enemigo *enemigo) {
    printf("Nombre: %s\n", enemigo->nombre);
    printf("Vida: %d\n", enemigo->vida);
    printf("Ataque: %d\n", enemigo->ataque);
    printf("Defensa: %d\n", enemigo->defensa);
}

void free_enemigo(Enemigo *enemigo){
   if (enemigo!=NULL)
   {
     free(enemigo);   
    }
    
}