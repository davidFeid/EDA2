#include <stdio.h>

typedef struct{
    char nombre[] ;
    int vida;
    int ataque;
    int defensa;
    char habilidades[];
}Protagonista;

typedef struct escena1
{
    Fantasma *vida;
    
};


typedef struct{
    int vida;
    int ataque;
    int defensa;
}Fantasma;

typedef struct{
    int option;
    Fantasma *enemigo;
    Protagonista *prota;
}Cementerio;