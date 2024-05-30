#include "movimiento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

// Afegeix un moviment nou a la pila
void push(Movimiento** cima, char* nombre) {
    Movimiento* nuevoMovimiento = (Movimiento*)malloc(sizeof(Movimiento));
    // Copiem el nom del moviment a l'estructura del nou moviment
    strcpy(nuevoMovimiento->nombre, nombre);
    // El nou moviment apunta a l'anterior cim de la pila
    nuevoMovimiento->siguiente = *cima;
    // Actualitzem el cim de la pila per ser el nou moviment
    *cima = nuevoMovimiento;
}

// Elimina el moviment del cim de la pila i retorna el seu nom
char* pop(Movimiento** cima) {
    if (*cima == NULL) return NULL; // Comprovem si la pila està buida
    Movimiento* temp = *cima;
    *cima = (*cima)->siguiente; // Actualitzem el cim de la pila
    char* nombre = temp->nombre;
    free(temp); // Alliberem la memòria del moviment eliminat
    return nombre;
}

// Obtén un moviment aleatori de la pila
char* obtener_movimiento_aleatorio(Movimiento* cima, int k) {
    int tamano = obtener_tamano_pila(cima);
    if (k >= tamano) return NULL; // Comprovem que k no sigui més gran que la mida de la pila
    Movimiento* temp = cima;
    // Iterem per trobar el k-è moviment des del cim
    for (int i = 0; i < tamano - k - 1; i++) {
        temp = temp->siguiente;
    }
    return temp->nombre; // Retornem el nom del moviment
}

// Calcula la mida de la pila
int obtener_tamano_pila(Movimiento* cima) {
    int tamano = 0;
    Movimiento* temp = cima;
    // Recorrem la pila comptant els elements
    while (temp != NULL) {
        tamano++;
        temp = temp->siguiente;
    }
    return tamano; // Retornem la mida de la pila
}

// Executa l'habilitat "Golpe de tiempo" que repeteix un moviment aleatori del historial
void golpe_de_tiempo(Movimiento* historial, Personaje* atacante, Enemigo* objetivo) {
    if (atacante->usado_golpe_de_tiempo) {
        printf("Ya has usado Golpe de Tiempo y no se puede usar nuevamente. Pierdes tu turno \n");
        return; // L'habilitat ja ha estat utilitzada
    }
    
    int tamano = obtener_tamano_pila(historial);
    if (tamano == 0) {
        printf("No hi ha moviments en l'historial.\n");
        return; // No hi ha moviments a repetir
    }
    
    int k = rand() % tamano; // Triem un moviment aleatori
    char* movimiento = obtener_movimiento_aleatorio(historial, k);
    if (movimiento == NULL) {
        printf("No s'ha pogut obtenir un moviment de l'historial.\n");
        return; // No hem pogut obtenir el moviment
    }

    // Anunciem el moviment seleccionat
    printf("El jugador utiliza Tiempo Mental y repite el movimiento '%s' potenciado x2!. No puedes usarlo nuevamente en la partida \n", movimiento);

    // Executem el moviment seleccionat amb el doble de potència
    if (strcmp(movimiento, "Ataque normal") == 0) {
        objetivo->vida -= 2 * atacante->ataque; // Aquí es doblarà el *2 de l'atac normal
        printf("Al enemigo le queda %d de vida\n", objetivo->vida);
    } else {
        for (int i = 0; i < 4; i++) {
            if (strcmp(movimiento, atacante->habilidadesAtaque[i]->nombre) == 0) {
                objetivo->vida -= 2 * atacante->habilidadesAtaque[i]->modificadorAtaque; // Aquí està en joc aquest *2 que doblarà el valor de l'habilitat
                printf("Al enemigo le queda %d de vida\n", objetivo->vida);
                break;
            }
        }
    }
    
    atacante->usado_golpe_de_tiempo = 1; // Marquem l'habilitat com a utilitzada

    // Eliminem el moviment de la pila
    Movimiento* temp = historial;
    Movimiento* anterior = NULL;
    for (int i = 0; i < tamano - k - 1; i++) {
        anterior = temp;
        temp = temp->siguiente;
    }
    if (anterior != NULL) {
        anterior->siguiente = temp->siguiente;
    } else {
        historial = temp->siguiente;
    }
    free(temp);
}
