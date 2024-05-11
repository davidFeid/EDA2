#include "main.h"

void inicializar_enemigos(){
    Enemigo fantasma;
    init_enemigo(&fantasma, "Fantasma de soldado", 100, 50, 20);
   
    Enemigo cofretrampa;
    init_enemigo(&cofretrampa, "Cofre Trampa", 225, 100, 200);

    Enemigo enemigos_opcion1[] = {fantasma,cofretrampa};
    inicializar_opcion(enemigos_opcion1);

    Enemigo subordinadoelfo;
    init_enemigo(&subordinadoelfo, "Subordinado elfo", 125, 120, 80);
    

    Enemigo jefoelfe;
    init_enemigo(&jefoelfe, "Elfo Jefe", 400, 150, 300);
    

    Enemigo tortuga;
    init_enemigo(&tortuga, "Tortuga", 205, 110, 500);
    

    Enemigo miniblaze;
    init_enemigo(&miniblaze, "Secuaz de Blaze", 350, 120, 300);
    

    Enemigo blaze;
    init_enemigo(&blaze, "BLAZE", 1000, 400, 600);
}

void inicializar_opcion(Enemigo *enemigos){
    Opcion opcion1; 
    init_opcion(&opcion1, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos, 2, "Has derrotado al enemigo.");

    Opcion opciones_decision1[] = {opcion1};
    inicializar_decision(opciones_decision1);
}

void inicializar_decision(Opcion *opciones){
    Decision decision1;
    init_decision(&decision1, "¿Qué quieres hacer?", opciones, 1);
    
    Decision decisiones[] = {decision1};
    inicializar_escenario(decisiones);
}

void inicializar_escenario(Decision *decisiones){
    // Crear el escenario
    Escenario escenario;
    init_escenario(&escenario, "Escenario 1", "Descripción del escenario 1", decisiones, 1);

    // Imprimir el escenario
    printf("----------------------------------------------------\n");
    print_escenario(&escenario);
}

int main() {
    // Crear una instancia de la estructura Personaje
    Personaje miPersonaje;

    // Configurar el personaje
    init_personaje(&miPersonaje);

    // Mostrar los datos del personaje configurado
    printf("\nPensonaje: \n");
    print_personaje(&miPersonaje);
    printf("----------------------------------------------------\n");
    printf("\nEnemigos:\n \n");
    inicializar_enemigos();
    return 0;
}

