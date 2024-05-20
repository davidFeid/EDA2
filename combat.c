#include "personaje.h"
#include "escena.h"
#include "enemigo.h"
#include "opcion.h"
#include "habilidad.h"
#include <time.h>
#include <stdlib.h>

typedef struct{

} Queue;

int PlayScene(Escena*escena,Personaje*personaje){
    Opcion* opcion_escogida = decision(escena);
    Queue*turns = randomTurns(3);

    while(turns->size > 0 && personaje->vida > 0){
        Enemigo* current_enemigo = (Enemigo*) dequeue(turns);
        if(combate(personaje,current_enemigo) == 0){
            printf("Has sido asesinado, tu batalla ha terminado");
            free(opcion_escogida);
            free(turns);
            return 0;   
        }
    }
    printf("Tu sed de sangre interior ha hecho ganar tu batalla");
    free(opcion_escogida);
    free(turns);
    return 1;
}

void mostrar_habilidades(Habilidad* habilidades) {
    printf("Habilidades disponibles:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i+1, habilidad[i].nombre);
    }
}

int seleccionar_habilidad() {
    int opcion;
    printf("Elige una habilidad: ");
    scanf("%d", &opcion);
    return opcion;
}

void usar_habilidad(Personaje* jugador, Enemigo* enemigo, Habilidad* habilidad) {
    if (strcmp(habilidad->nombre, "Ataque normal") == 0) {
        ataque_normal(jugador, enemigo);
    } else if (strcmp(habilidad->nombre, "Habilidad especial") == 0) {
        habilidad_especial(jugador, enemigo);
    }
}

void ataque_normal(Personaje* atacante, Enemigo* objetivo) {
    printf("¡El ataque normal golpea al enemigo!\n");
    objetivo->vida -= atacante->fuerza;
}

void habilidad_especial(Personaje* atacante, Enemigo* objetivo) {
    printf("¡El jugador utiliza su habilidad especial!\n");
    objetivo->vida -= atacante->fuerza * 2;
}

void playHumanTurn(Personaje* personaje, Enemigo* enemigo) {
    printf("Es tu turno. Elige una acción:\n");
    // poner lo que ataca
    mostrar_habilidades();
    seleccionar_habilidad();
    Habilidad habilidad_elegida = habilidad[i];
    usar_habilidad(personaje,enemigo,&habilidad_elegida);
    enemigo->vida -= personaje->fuerza;
}

void playMachineTurn(Personaje* personaje, Enemigo* enemigo) {
    printf("Es el turno del enemigo.\n");
    randomHabilidad();
    // poner los ataques del enemigo 
    personaje->vida -= enemigo->fuerza;
}

// falta la funcion de colas aleatorias

//Habilidadenemigo* randomHabilidad(Enemigo* enemigo) {
    Habilidadenemigo* habilidad = (Habilidad*) malloc(sizeof(Habilidad));
    srand(time(NULL));  
    int r = rand(habilidad);

    // Aquí podrías implementar la lógica para seleccionar una habilidad aleatoria del enemigo
    // Por ahora, simplemente devolvemos una habilidad nula
    return habilidad;
}

// falta la funcion de habilidades para el enemigo

int combate(Personaje*personaje, Enemgio*enemigo){
    int cont = 0;
    int N = 0;

    while (personaje->vida > 0 && enemigo->vida > 0){
        playHumanTurn(personaje,enemigo);
        if (enemigo->vida <= 0){
            printf("Has derrotado al enemigo");
            return 1;
        }
        playMachineTurn(personaje,enemigo);
        if(personaje->vida <= 0){
            printf("El enemigo te ha derrotado");
            return 0;
        }
    }
    return 1;
}

int main() {
    Escena escena;
    combate(personaje,enemigo);

    if (playScene(&escena, &personaje)) {
        printf("Has superado esta escena sin derramar sangre\n");
    } else {
        printf("No has podido completar la escena...\n");
    }

    return 0;
}