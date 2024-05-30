#include <stdio.h>
#include "grafo.h"

void imprimir_opciones(Grafo *grafo, Escenario *escenarios[]) {
    printf("Opciones disponibles:\n");
    for (int i = 0; i < MAX_NODOS; i++) {
        if (grafo->grafo[grafo->nodo_actual][i] == 1 && grafo->historial[i] != 1) {
            printf("%d: Ir al Escenario %s\n", i + 1, escenarios[i]->nombre);
        }
    }
    printf("0: Ver historial\n");
}

void mover(Grafo *grafo, int opcion) {
    if (opcion == 0) {
        printf("Saliendo del mapa.\n");
        return;
    }
    if (opcion < 0 || opcion > MAX_NODOS || grafo->grafo[grafo->nodo_actual][opcion - 1] != 1) {
        printf("Opción no válida. Inténtalo de nuevo.\n");
        return;
    }
    grafo->nodo_actual = opcion - 1;
    grafo->historial[grafo->nodo_actual] = 1;
    printf("Te has movido al nodo %d.\n", grafo->nodo_actual + 1);
}

void mostrar_historial(Grafo *grafo, Escenario *escenarios[]) {
    printf("Historial de Escenario visitados:\n");
    for (int i = 0; i < MAX_NODOS; i++) {
        if (grafo->historial[i] == 1) {
            printf("%s ", escenarios[i]->nombre);
        }
    }
    printf("\n");
}

void init_grafo(Grafo *grafo) {
    // Inicializa la matriz de adyacencia con valores predeterminados
    int grafo_inicial[MAX_NODOS][MAX_NODOS] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}
    };
    // Copia los valores del grafo inicial al grafo pasado como argumento
    for (int i = 0; i < MAX_NODOS; i++) {
        for (int j = 0; j < MAX_NODOS; j++) {
            grafo->grafo[i][j] = grafo_inicial[i][j];
        }
    }
    // Inicializa el historial de nodos visitados
    for (int i = 0; i < MAX_NODOS; i++) {
        grafo->historial[i] = 0;
    }
    grafo->nodo_actual = 0; // Establece el nodo actual como el primero
    grafo->historial[0] = 1; // Marca el primer nodo como visitado
}
