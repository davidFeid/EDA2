#include <stdio.h>
#include "enemigo.h"


void init_enemigo(Enemigo *enemigo,  char *nombre, int vida, int ataque, int defensa,Habilidad *habilidad){
    strcpy(enemigo->nombre, nombre);

    enemigo->habilidad=malloc(sizeof(Habilidad));
    strcpy(enemigo->habilidad->nombre, habilidad->nombre);
    strcpy(enemigo->habilidad->descripcion,habilidad->descripcion);
    enemigo->habilidad->modificadorAtaque=habilidad->modificadorAtaque;
    enemigo->habilidad->modificadorDefensa=habilidad->modificadorDefensa;
    enemigo->habilidad->modificadorHP=habilidad->modificadorHP;
    

    enemigo->vida = vida;
    enemigo->ataque = ataque;
    enemigo->defensa = defensa;
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
    if (enemigo!=NULL)
    {
    printf("                Nombre: %s\n", enemigo->nombre);
    printf("                Habilidad:\n");
    printHabilidad(enemigo->habilidad);
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

