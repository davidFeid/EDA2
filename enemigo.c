#include <stdio.h>
#include "enemigo.h"


void init_enemigo(Enemigo *enemigo, char *nombre, int vida, int ataque, int defensa, Habilidad *habilidades[],int num_habilidades) {
    // Copiamos el nombre del enemigo
    strcpy(enemigo->nombre,nombre);
  // Asignamos la vida, ataque y defensa
    enemigo->vida = vida;
    enemigo->ataque = ataque;
    enemigo->defensa = defensa;
    // Asignamos el número de habilidades
    enemigo->num_habilidades=num_habilidades;
    // Reservamos memoria para el array de habilidades
    enemigo-> habilidades = malloc(num_habilidades * sizeof(Habilidad*)); 
    // Copiamos cada habilidad al array de habilidades del enemigo
    for (int i = 0; i < num_habilidades; i++) {
        enemigo->habilidades[i] = malloc(sizeof(Habilidad));
        strcpy(enemigo->habilidades[i]->nombre, habilidades[i]->nombre);
        strcpy(enemigo->habilidades[i]->descripcion, habilidades[i]->descripcion);
        enemigo->habilidades[i]->modificadorAtaque = habilidades[i]->modificadorAtaque;
        enemigo->habilidades[i]->modificadorDefensa = habilidades[i]->modificadorDefensa;
        enemigo->habilidades[i]->modificadorHP = habilidades[i]->modificadorHP;
    }
}


/* void aplicar_habilidad(Enemigo *enemigo, Habilidad *habilidad) {
    enemigo->habilidad=malloc(sizeof(Habilidad));
    strcpy(enemigo->habilidad->nombre, habilidad->nombre);
    strcpy(enemigo->habilidad->descripcion,habilidad->descripcion);
    enemigo->habilidad->modificadorAtaque=habilidad->modificadorAtaque;
    enemigo->habilidad->modificadorDefensa=habilidad->modificadorDefensa;
    enemigo->habilidad->modificadorHP=habilidad->modificadorHP;
    enemigo->ataque+=habilidad->modificadorAtaque;
    enemigo->defensa+=habilidad->modificadorDefensa;
    enemigo->vida+=habilidad->modificadorHP;

} */


void print_enemigo( Enemigo *enemigo) {
    if (enemigo != NULL) {
        printf("                Nombre: %s\n", enemigo->nombre);
        printf("                Habilidades:\n");
        for (int i = 0; i < enemigo->num_habilidades; i++) {
            printf("                Habilidad %d:\n", i + 1);
            printHabilidad(enemigo->habilidades[i]);
        }
        printf("                Vida: %d\n", enemigo->vida);
        printf("                Ataque: %d\n", enemigo->ataque);
        printf("                Defensa: %d\n", enemigo->defensa);
    }    
}


void free_enemigo(Enemigo *enemigo){
   if (enemigo!=NULL)
   {
     free(enemigo);   
    }
    
}

