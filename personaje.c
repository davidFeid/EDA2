#include <stdio.h>
#include "personaje.h"


void init_personaje(Personaje *personaje, Habilidad *habilidadesAtaque, int numHabilidadesAtaque, Habilidad *habilidadesDefensa, int numHabilidadesDefensa) {
    printf("¡Bienvenido! Vamos a configurar a tu personaje.\n");
    
    // Solicitar y almacenar el nombre del personaje
    printf("Ingresa el nombre de tu personaje: ");
    scanf("%s", personaje->nombre);

    // Solicitar y almacenar la dificultad
    int dificultad;
    printf("Selecciona la dificultad (1: Fácil, 2: Normal, 3: Difícil): ");
    scanf("%d", &dificultad);

    // Asignar valores predeterminados según la dificultad
    switch(dificultad) {
        case 1: // Fácil
            personaje->vida = 150;
            personaje->ataque = 40;
            personaje->defensa = 150;
            break;
        case 2: // Normal
            personaje->vida = 125;
            personaje->ataque = 30;
            personaje->defensa = 100;
            break;
        case 3: // Difícil
            personaje->vida = 100;
            personaje->ataque = 40;
            personaje->defensa = 50;
            break;
        default:
            fprintf(stderr, "Dificultad inválida. Por favor, reinicia el programa y selecciona una dificultad válida.\n");
            exit(EXIT_FAILURE);
    }

     // Mostrar habilidades de ataque disponibles y permitir la selección
    printf("Escoge dos de estas habilidades de ataque:\n");
    for (int i = 0; i < numHabilidadesAtaque; i++) {
        printf("%d. %s: %s\n", i + 1, habilidadesAtaque[i].nombre, habilidadesAtaque[i].descripcion);
    }

    int seleccionAtaque1, seleccionAtaque2;
    printf("Ingresa el número de tu primera habilidad de ataque: ");
    scanf("%d", &seleccionAtaque1);
    printf("Ingresa el número de tu segunda habilidad de ataque: ");
    scanf("%d", &seleccionAtaque2);

    // Validar las selecciones de ataque
    if (seleccionAtaque1 < 1 || seleccionAtaque1 > numHabilidadesAtaque || seleccionAtaque2 < 1 || seleccionAtaque2 > numHabilidadesAtaque || seleccionAtaque1 == seleccionAtaque2) {
        fprintf(stderr, "Selección inválida. Por favor, reinicia el programa y selecciona habilidades válidas.\n");
        exit(EXIT_FAILURE);
    }

    // Almacenar las habilidades de ataque seleccionadas en el personaje
    personaje->habilidadesAtaque[0] = &habilidadesAtaque[seleccionAtaque1 - 1];
    personaje->habilidadesAtaque[1] = &habilidadesAtaque[seleccionAtaque2 - 1];

    // Mostrar habilidades de defensa disponibles y permitir la selección
    printf("Escoge dos de estas habilidades de defensa:\n");
    for (int i = 0; i < numHabilidadesDefensa; i++) {
        printf("%d. %s: %s\n", i + 1, habilidadesDefensa[i].nombre, habilidadesDefensa[i].descripcion);
    }

    int seleccionDefensa1, seleccionDefensa2;
    printf("Ingresa el número de tu primera habilidad de defensa: ");
    scanf("%d", &seleccionDefensa1);
    printf("Ingresa el número de tu segunda habilidad de defensa: ");
    scanf("%d", &seleccionDefensa2);

    // Validar las selecciones de defensa
    if (seleccionDefensa1 < 1 || seleccionDefensa1 > numHabilidadesDefensa || seleccionDefensa2 < 1 || seleccionDefensa2 > numHabilidadesDefensa || seleccionDefensa1 == seleccionDefensa2) {
        fprintf(stderr, "Selección inválida. Por favor, reinicia el programa y selecciona habilidades válidas.\n");
        exit(EXIT_FAILURE);
    }

    // Almacenar las habilidades de defensa seleccionadas en el personaje
    personaje->habilidadesDefensa[0] = &habilidadesDefensa[seleccionDefensa1 - 1];
    personaje->habilidadesDefensa[1] = &habilidadesDefensa[seleccionDefensa2 - 1];

    personaje->usado_golpe_de_tiempo = 0;
}

void print_personaje(Personaje *personaje) {
    printf("\nNombre: %s\n", personaje->nombre);
    printf("Vida: %d\n", personaje->vida);
    printf("Ataque: %d\n", personaje->ataque);
    printf("Defensa: %d\n", personaje->defensa);
    printf("Habilidades de ataque:\n");
    for (int i = 0; i < 2; i++) {
        printHabilidad( personaje->habilidadesAtaque[i]);
    }
    printf("Habilidades de defensa:\n");
    for (int i = 0; i < 2; i++) {
        printHabilidad( personaje->habilidadesDefensa[i]);
    }
}

void free_personaje(Personaje *personaje){
    if (personaje!=NULL)
    {
        free(personaje);
    }
    
}