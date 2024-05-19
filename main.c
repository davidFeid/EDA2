#include "main.h"
void inicializar_habilidades(){
    Habilidad *ataquesusto=malloc(sizeof(Habilidad));
    init_habilidad(ataquesusto,"ataque susto","Los fantasmas desaparacen para asustarte y quitarte vida y puntos de defensa ",0,10,10);

    Habilidad *mordisco=malloc(sizeof(Habilidad));
    init_habilidad(mordisco,"mordisco","El cofre se abre y te muerde",0,0,15);

    Habilidad *lanzamientocuchillos=malloc(sizeof(Habilidad));
    init_habilidad(lanzamientocuchillos,"lanzamiento de cuchillos","El elfo subordinado saca un manojo de cuchillos y te los lanza,estos te inmobilizaran los braozos ",10,0,10);

    Habilidad *mazazo=malloc(sizeof(Habilidad));
    init_habilidad(mazazo,"mazazo","El elfo supremo saca una maza que tenia guardada en la cabeza y te golpea en la cabeza con ella ",0,0,25);

    Habilidad *ataqueacuatico=malloc(sizeof(Habilidad));
    init_habilidad(ataqueacuatico,"ataque aquatico","Las tortuguitas se sumergen bajo el agua y saltan a por ti las dos a la vez complicando tu defensa ",0,10,5);

    Habilidad *caparazoneterno=malloc(sizeof(Habilidad));
    init_habilidad(caparazoneterno,"caparazo eterno","El tortugon se esconde bajo el caparazon y rechaza parte de tus ataques ",15,0,0);

    Habilidad *llamaradas=malloc(sizeof(Habilidad));
    init_habilidad(llamaradas,"llamaradas","Los mini blazes te acrralan con llamaradas de fuego ",0,15,15);

    Habilidad *bloqueatomico=malloc(sizeof(Habilidad));
    init_habilidad(bloqueatomico,"bloque atomico","EL blaze te lanza un bloque atomico gigantesco que cuando te golpea explosiona y te inmobiliza ",25,25,25);

    Habilidad *habilidades[]={ataquesusto,mordisco,lanzamientocuchillos,mazazo,ataqueacuatico,caparazoneterno,llamaradas,bloqueatomico};
    inicializar_enemigos(habilidades);   

}
void inicializar_enemigos(Habilidad *habilidades[]){
    //Enemigo fantasma;
    Enemigo *fantasma1 = malloc(sizeof(Enemigo));
    init_enemigo(fantasma1, "Fantasma de soldado", 100, 50, 20,habilidades[0]);
    /* aplicar_habilidad(fantasma1,habilidades[0]); */

    Enemigo *fantasma2 = malloc(sizeof(Enemigo));
    init_enemigo(fantasma2, "Fantasma de soldado", 100, 50, 20,habilidades[0]);
    /* aplicar_habilidad(fantasma2,habilidades[0]); */
    //Enemigo cofretrampa;
    Enemigo *cofretrampa = malloc(sizeof(Enemigo));
    init_enemigo(cofretrampa, "Cofre Trampa", 225, 100, 200,habilidades[1]);
    /* aplicar_habilidad(cofretrampa,habilidades[0]); */


    Enemigo *subordinadoelfo = malloc(sizeof(Enemigo));
    init_enemigo(subordinadoelfo, "Subordinado elfo", 125, 120, 80,habilidades[2]); 
    

    //Enemigo jefoelfe;
    Enemigo *jefoelfe = malloc(sizeof(Enemigo));    
    init_enemigo(jefoelfe, "Elfo Jefe", 400, 150, 300,habilidades[3]);
    
   
    Enemigo *tortuguita1=malloc(sizeof(Enemigo));
    init_enemigo(tortuguita1, "Tortugas", 155, 210, 400,habilidades[4]);

    Enemigo *tortuguita2=malloc(sizeof(Enemigo));;
    init_enemigo(tortuguita2, "Tortugas", 155, 210, 400,habilidades[4]);

    //Enemigo tortuga;
    Enemigo *tortugon = malloc(sizeof(Enemigo));
    init_enemigo(tortugon, "Tortuga", 205, 110, 500,habilidades[5]);
    

    //Enemigo miniblaze;
    Enemigo *miniblaze = malloc(sizeof(Enemigo));
    init_enemigo(miniblaze, "Secuaz de Blaze", 350, 120, 300,habilidades[6]);
    

    //Enemigo blaze;
    Enemigo *blaze = malloc(sizeof(Enemigo));
    init_enemigo(blaze, "BLAZE", 1000, 400, 600,habilidades[7]);
    //
    //printf("holaa"); */
     Enemigo *enemigos[][2] = {{fantasma1,fantasma2},{cofretrampa},{subordinadoelfo,jefoelfe},{tortuguita1,tortuguita2},{tortugon},{miniblaze,blaze},{blaze}};
    
    inicializar_opcion(enemigos); 
}

void inicializar_opcion(Enemigo *enemigos[][2]){
    //print_enemigo(enemigos[0][1]);
    
    Opcion *opcion1_1=malloc(sizeof(Opcion));  
    init_opcion(opcion1_1, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[0], 2, "Has derrotado al enemigo.");

    Opcion *opcion1_2=malloc(sizeof(Opcion));  
    init_opcion(opcion1_2, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[1], 1, "Has derrotado al enemigo.");

    Opcion *opcion1_3=malloc(sizeof(Opcion)); 
    init_opcion(opcion1_3,"Luchar","No te has encontrado con ningún enemigo",NULL,0,"Consigues llegar al bosque sin pelear con nadie");

    Opcion *opcion2_1=malloc(sizeof(Opcion));  
    init_opcion(opcion2_1, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[2], 2, "Has derrotado al enemigo.");

    Opcion *opcion2_2=malloc(sizeof(Opcion));  
    init_opcion(opcion2_2,"Luchar","No te has encontrado con ningún enemigo",NULL,0,"Consigues llegar al lago sin pelear con nadie");

    Opcion *opcion2_3=malloc(sizeof(Opcion));  
    init_opcion(opcion2_2,"Luchar","No te has encontrado con ningún enemigo",NULL,0,"Consigues llegar al lago sin pelear con nadie");

    Opcion *opcion3_1=malloc(sizeof(Opcion));  
    init_opcion(opcion3_1, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[3], 2, "Has derrotado al enemigo.");
    
    Opcion *opcion3_2=malloc(sizeof(Opcion));  
    init_opcion(opcion3_2, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[4], 1, "Has derrotado al enemigo.");

    Opcion *opcion3_3=malloc(sizeof(Opcion)); 
    init_opcion(opcion3_3,"Luchar","No te has encontrado con ningún enemigo",NULL,0,"Consigues llegar al lago sin pelear con nadie");

    Opcion *opcion4_1=malloc(sizeof(Opcion));  
    init_opcion(opcion4_1, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[5], 2, "Has derrotado al boss final.");

    Opcion *opcion4_2=malloc(sizeof(Opcion)); 
    init_opcion(opcion4_2, "Luchar", "Te encuentras con un enemigo poderoso:", enemigos[6], 1, "Has derrotado al boss final.");
    
    //print_opcion(&opcion1_1);
    Opcion *opciones[][3] = {{opcion1_1,opcion1_2,opcion1_3},{opcion2_1,opcion2_2,opcion2_3},{opcion3_1,opcion3_2,opcion3_3},{opcion4_1,opcion4_2}};
    inicializar_decision(opciones);
    
}



void inicializar_decision(Opcion *opciones[][3]){
    Decision *decision1=malloc(sizeof(Decision));
    init_decision(decision1, "¿Qué quieres hacer?", opciones[0], 3);

    Decision *decision2=malloc(sizeof(Decision));
    init_decision(decision2, "Así que, por donde deseas ir?", opciones[1], 3);

    Decision *decision3=malloc(sizeof(Decision));
    init_decision(decision3, "¿Cuál camino vas a coger?", opciones[2], 3);

    Decision *decision4=malloc(sizeof(Decision));
    init_decision(decision4,"Qué camino deseas tomar?", opciones[3], 2);
    
    Decision *decisiones[] = {decision1,decision2,decision3,decision4};
    
    //printf("----------------------------------------------------\n");
    //printf("\n Decisioneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeees:\n \n");
    //print_decision(&decision1);
    //print_decision(&decision1);
    inicializar_escenario(decisiones);
}

void inicializar_escenario(Decision *decisiones[]){
    // Crear el escenario
    
    Escenario *escenario1=malloc(sizeof(Escenario));
    init_escenario(escenario1, "Escenario 1", "Acabas de aparecer en medio del cementerio de KINGSLAND, la ciudad que salvaste en el pasado, y desconcertado, no acabas de reconocer todo el terreno que te rodea. El aire es crudo y puedes sentir un aire de temor y oscuridad por las tierras que antes te pertenecian. Ante la sensación de inseguridad, ràpidamente, coges la espada que esta clavada en tu tumba, col·locada por “alguien” quien parece que pensaba que algun dia volverias al mundo real. Observas que se te acercan unos fantasmas de no muy buena espina, asi que podrías tomar diferentes caminos para salir de aquí. Recuerdas que si cogias el camino derecho, llegabas hacia la casa del viejo herrero, llamado “RUFF”, con el cuál tenias una buena amistad. Este podria ayudarte a resolver tus dudas y él porque has vuelto al mundo real. Por otra parte, en el camino izquierdo contemplas un cofre brillante que podria contener ciertos elementos curativos, de subida de defensa, mejora de ataques…Estos 2 caminos nombrados tienen una alta probabilidad de encontrarse con enemigos, en cambio, si decides tirar recto por el camino central, llegarías al bosque más rápidamente escapando de todo posible enfrentamiento", &decisiones[0], 1);

    Escenario *escenario2=malloc(sizeof(Escenario));
    init_escenario(escenario2, "Escenario 2", "Despúes de una larga caminata, llegas por fin al bosque oscuro de KINGSLAND. El bosque está tan arboleado que es imposible ver lo que hay detrás de cada árbol, todo parece un sitio sin salida. En la entrada de este, te encuentras unos carteles que te indican 3 caminos por los cúales poder avanzar. Solo oyes gritos de desesperación, espadas chocándose y el sondio del viento zarandeando las hojas que componen el gran bosque. El cartel del medio te dice que si sigues hacia adelante te encontrarás con el elfo supremo, el cuál te puede hacer conseguir una gran recompensa si es derrotado. El cartel de la izquierda, te dice que puedes coger este camino el cuál es el más rápido para llegar al lago, escapando de todo enemigo posible. Por la otra banda, el cartel derecho te informa de que una tienda te encontrarás en el caso de que este camino cojas, pudiendo lootear asi antes de pasar a la siguiente zona", &decisiones[1], 1);

    Escenario *escenario3=malloc(sizeof(Escenario));
    init_escenario(escenario3,"Escenario 3", "Ya superado el bosque, te encuentras con el gran sonido pacífico del lago. Toda maldad que hayas podido encontrar en las zonas anteriores se desvanece ante el gran paisaje que el lago magistral te hace contemplar. Los caminos están todos destrozados y ves a lo lejos diferentes tipos de animales marítimos humanizados, así como grandes tortugas. Estas, se encuentran en el camino del medio, específicamente 2, esperándote a que pases por ahí para intentar quitarte todo lo que tienes. Por la izquierda contemplas aparantemente un camino vacío y sin enemigos, aunque parece que ciertas batallas han sucedido alli hace poco. El camino derecho está en sus últimas condiciones, el peor de todos, pero al final de este puedes contemplar un pequeño castillo abandonado en el cuál podrias coger ciertas cosas antes de partir",&decisiones[2],1);

    Escenario *escenario4=malloc(sizeof(Escenario));
    init_escenario(escenario4, "Escenario 4", "Acabas de llegar al castillo de KINGSLAND, donde todo está destrozado y solo se oyen gritos de sufrimiento por las calles de tu villa. Arrebatado por la furia y la venganza, tu rabia empieza a incrementar exageradamente, y con ella, tus ganas de asesinar. Empiezas a correr acabando con la vida de todo malvado que se cruce en tu camino, en un visto y visto, has asesinado aproximadamente a más de 100 subordinados. Logras llegar, empapado de sangre de los enemigos, a la puerta del gran castillo, la cuál está bloqueda. En tu camino de la izquierda observas que llegarías dentro del castillo superando antes 2 grandes subordinados de BLAZE. Por la derecha, superarías ciertos obstàculos sin pelearte para llegar al centro dell castillo. Ambos, te van a llevar al final de tu aventura, donde la princesa SIRA se encuentra emprisionada", &decisiones[3], 1);


    // Imprimir el escenario
    //printf("85555\n");
    print_escenario(escenario1);
}

int main() {
    // Crear una instancia de la estructura Personaje
    Habilidad habilidadesAtaque[4];
    init_habilidad(&habilidadesAtaque[0], "Golpe Fuerte", "Un golpe poderoso que aumenta el ataque.", 10, 0, 0);
    init_habilidad(&habilidadesAtaque[1], "Ataque Rápido", "Un ataque rápido que golpea primero.", 5, 0, 0);
    init_habilidad(&habilidadesAtaque[2], "Explosión de Fuego", "Una explosión que inflige daño a múltiples enemigos.", 8, 0, 0);
    init_habilidad(&habilidadesAtaque[3], "Rayo", "Un rayo que atraviesa la defensa enemiga.", 12, 0, 0);

    Habilidad habilidadesDefensa[4];
    init_habilidad(&habilidadesDefensa[0], "Defensa de Hierro", "Una defensa impenetrable que aumenta la defensa.", 0, 10, 0);
    init_habilidad(&habilidadesDefensa[1], "Escudo Mágico", "Un escudo que reduce el daño recibido.", 0, 8, 0);
    init_habilidad(&habilidadesDefensa[2], "Curación Rápida", "Recupera puntos de vida rápidamente.", 0, 0, 10);
    init_habilidad(&habilidadesDefensa[3], "Resistencia", "Aumenta la resistencia a los ataques enemigos.", 0, 7, 5);

    Personaje miPersonaje;
    init_personaje(&miPersonaje, habilidadesAtaque, 4, habilidadesDefensa, 4);  

    // Mostrar los datos del personaje configurado
    printf("\nPensonaje: \n");
    print_personaje(&miPersonaje);
    printf("----------------------------------------------------\n");
    printf("\nEscenario:\n");
    inicializar_habilidades();
    return 0;
}

