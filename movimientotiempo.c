#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

#define MAX_MOVIMIENTOS 100

// Definición de la estructura para una pila de movimientos
typedef struct {
    Habilidad movimientos[MAX_MOVIMIENTOS];
    int top;
} PilaMovimientos;

// Función para inicializar la pila de movimientos
void inicializar_pila(PilaMovimientos *pila) {
    pila->top = -1;
}

// Función para agregar un movimiento a la pila
void push(PilaMovimientos *pila, Habilidad movimiento) {
    if (pila->top < MAX_MOVIMIENTOS - 1) {
        pila->top++;
        pila->movimientos[pila->top] = movimiento;
    } else {
        printf("La pila está llena. No se puede agregar más movimientos.\n");
    }
}
// Función para obtener el k-ésimo movimiento desde el último
Habilidad obtener_k_esimo_desde_el_final(PilaMovimientos *pila, int k) {
    if (k <= 0 || k > pila->top + 1) {
        printf("No hay suficientes movimientos en el historial.\n");
        exit(1);
    }
    return pila->movimientos[pila->top - k + 1];
}

// Función para ejecutar un movimiento potenciado
void ejecutar_movimiento_potenciado(Habilidad *movimiento) {
    printf("Ejecutando movimiento potenciado: %s (Potencia: %d)\n", movimiento->nombre, movimiento->modificadorAtaque);
}

// Función para el movimiento "Golpe de Tiempo"
void golpe_de_tiempo(PilaMovimientos *pila, int k) {
    Habilidad movimiento_a_ejecutar;
    movimiento_a_ejecutar = obtener_k_esimo_desde_el_final(pila, k);
    movimiento_a_ejecutar->modificadorAtaque *= 2;
    ejecutar_movimiento_potenciado(&movimiento_a_ejecutar);
}

int main() {
    PilaMovimientos historial_movimientos;
    inicializar_pila(&historial_movimientos);

    // Agregar movimientos de ejemplo al historial
    Habilidad movimiento1 = {"Golpe Fuerte", 10};
    Habilidad movimiento2 = {"Ataque Rápido", 5};
    Habilidad movimiento3 = {"Explosión de Fuego", 8};
    Habilidad movimiento4 = {"Rayo", 12};
    push(&historial_movimientos, movimiento1);
    push(&historial_movimientos, movimiento2);
    push(&historial_movimientos, movimiento3);
    push(&historial_movimientos, movimiento4);

    // Llamar al movimiento "Golpe de Tiempo" con k=2
    golpe_de_tiempo(&historial_movimientos, 2);

    return 0;
}
