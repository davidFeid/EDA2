#include "main.h"

int main() {
    // Crear una instancia de la estructura Personaje
    Personaje miPersonaje;

    // Configurar el personaje
    init_personaje(&miPersonaje);

    // Mostrar los datos del personaje configurado
    print_personaje(&miPersonaje);

    return 0;
}