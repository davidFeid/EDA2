#include "main.h"
// Función para inicializar las habilidades del juego
void inicializar_habilidades(){
    // Código para crear e inicializar diferentes habilidades para cada tipo de enemigo

    // Fantasmas
    Habilidad *ataquesusto = malloc(sizeof(Habilidad));
    init_habilidad(ataquesusto, "ataque susto", "Los fantasmas desaparacen para asustarte y quitarte vida y puntos de defensa", 0, 10, 5);

    Habilidad *proteccioneterea = malloc(sizeof(Habilidad));
    init_habilidad(proteccioneterea, "protección etérea", "El fantasma se vuelve intangible, reduciendo el daño recibido", 15, 0, 0);

    // Cofre trampa
    Habilidad *mordisco = malloc(sizeof(Habilidad));
    init_habilidad(mordisco, "mordisco", "El cofre se abre y te muerde para romper tus protecciones", 0, 15, 0);

    Habilidad *defensadura = malloc(sizeof(Habilidad));
    init_habilidad(defensadura, "defensa dura", "El cofre se cierra herméticamente, aumentando su defensa", 20, 0, 0);

    // Elfo Subordinado
    Habilidad *lanzamientocuchillos = malloc(sizeof(Habilidad));
    init_habilidad(lanzamientocuchillos, "lanzamiento de cuchillos", "El elfo subordinado saca un manojo de cuchillos y te los lanza, estos te inmovilizan los brazos y te costara mas atacar", 15, 0, 5);

    Habilidad *esquivarapido = malloc(sizeof(Habilidad));
    init_habilidad(esquivarapido, "esquiva rápida", "El elfo subordinado esquiva rápidamente los ataques", 20, 0, 0);

    // Elfo Supremo
    Habilidad *mazazo = malloc(sizeof(Habilidad));
    init_habilidad(mazazo, "mazazo", "El elfo supremo saca una maza que tenía guardada en la cabeza y te golpea en la cabeza con ella", 0, 10, 20);

    Habilidad *armaduramagica = malloc(sizeof(Habilidad));
    init_habilidad(armaduramagica, "armadura mágica", "El elfo supremo invoca una armadura mágica que reduce el daño recibido", 15, 0, 0);

    // Tortuguita
    Habilidad *ataqueacuatico = malloc(sizeof(Habilidad));
    init_habilidad(ataqueacuatico, "ataque acuático", "Las tortuguitas se sumergen bajo el agua y saltan a por ti las dos a la vez complicando tu defensa", 0, 20, 0);

    Habilidad *caparazonreforzado = malloc(sizeof(Habilidad));
    init_habilidad(caparazonreforzado, "caparazón reforzado", "La tortuguita se esconde bajo su caparazón reforzado, aumentando su defensa", 10, 0, 0);

    // Tortugón
    Habilidad *golpepesado = malloc(sizeof(Habilidad));
    init_habilidad(golpepesado, "golpe pesado", "El tortugón lanza un golpe pesado con su caparazón", 0, 15, 10);

    Habilidad *caparazoneterno = malloc(sizeof(Habilidad));
    init_habilidad(caparazoneterno, "caparazón eterno", "El tortugón se esconde bajo el caparazón y rechaza parte de tus ataques", 15, 0, 0);

    // Mini Blaze
    Habilidad *llamaradas = malloc(sizeof(Habilidad));
    init_habilidad(llamaradas, "llamaradas", "Los mini blazes te acorralan con llamaradas de fuego", 0, 20, 10);

    Habilidad *escudoflamigero = malloc(sizeof(Habilidad));
    init_habilidad(escudoflamigero, "escudo flamígero", "El mini blaze crea un escudo de llamas que reduce el daño recibido", 15, 0, 0);

    // Blaze
    Habilidad *bloqueatomico = malloc(sizeof(Habilidad));
    init_habilidad(bloqueatomico, "bloque atómico", "El blaze te lanza un bloque atómico gigantesco que cuando te golpea explota ", 30, 0, 30);

    Habilidad *pareddefuego = malloc(sizeof(Habilidad));
    init_habilidad(pareddefuego, "pared de fuego", "El blaze invoca una pared de fuego que bloquea los ataques entrantes", 25, 0, 0);

    Habilidad *tormentadefuego = malloc(sizeof(Habilidad));
    init_habilidad(tormentadefuego, "tormenta de fuego", "El Blaze invoca una tormenta de fuego que causa daño a todos los enemigos cercanos", 20, 0, 15);

    Habilidad *escudoinfernal = malloc(sizeof(Habilidad));
    init_habilidad(escudoinfernal, "escudo infernal", "El Blaze crea una bola de fuego gigante y se mete en ella que reduce el daño recibido y quema a los atacantes", 30, 10, 0);

    Habilidad *habilidades[][4]={{ataquesusto,proteccioneterea},{mordisco,defensadura},{lanzamientocuchillos,esquivarapido},{mazazo,armaduramagica},{ataqueacuatico,caparazonreforzado},{golpepesado,caparazoneterno},{llamaradas,escudoflamigero},{bloqueatomico,pareddefuego,tormentadefuego,escudoinfernal}};
    inicializar_enemigos(habilidades);   

}

// Función para inicializar los enemigos del juego
void inicializar_enemigos(Habilidad *habilidades[][4]){
    // Código para crear e inicializar instancias de enemigos y asignar habilidades

    //Creación de enemigos escenario 1, con sus respectivas habilidades
    Enemigo *fantasma1 = malloc(sizeof(Enemigo));
    init_enemigo(fantasma1, "Fantasma de soldado", 100, 50, 20,habilidades[0],2);

    Enemigo *fantasma2 = malloc(sizeof(Enemigo));
    init_enemigo(fantasma2, "Fantasma de soldado", 100, 50, 20,habilidades[0],2);
    
    Enemigo *cofretrampa = malloc(sizeof(Enemigo));
    init_enemigo(cofretrampa, "Cofre Trampa", 225, 100, 200,habilidades[1],2);

    //Creación de enemigos escenario 2, con sus respectivas habilidades
    Enemigo *subordinadoelfo = malloc(sizeof(Enemigo));
    init_enemigo(subordinadoelfo, "Subordinado elfo", 125, 120, 80,habilidades[2],2); 
    
    Enemigo *jefoelfe = malloc(sizeof(Enemigo));    
    init_enemigo(jefoelfe, "Elfo Jefe", 400, 150, 300,habilidades[3],2);
     
    //Creación de enemigos escenario 3, con sus respectivas habilidades
    Enemigo *tortuguita1=malloc(sizeof(Enemigo));
    init_enemigo(tortuguita1, "Tortugas", 155, 210, 400,habilidades[4],2);

    Enemigo *tortuguita2=malloc(sizeof(Enemigo));;
    init_enemigo(tortuguita2, "Tortugas", 155, 210, 400,habilidades[4],2);

    Enemigo *tortugon = malloc(sizeof(Enemigo));
    init_enemigo(tortugon, "Tortuga", 205, 110, 500,habilidades[5],2);
    
    //Creación de enemigos escenario 4, con sus respectivas habilidades
    Enemigo *miniblaze = malloc(sizeof(Enemigo));
    init_enemigo(miniblaze, "Secuaz de Blaze", 350, 120, 300,habilidades[6],2);
    
    Enemigo *blaze = malloc(sizeof(Enemigo));
    init_enemigo(blaze, "BLAZE", 1000, 400, 600,habilidades[7],4);
    
    Enemigo *enemigos[][2] = {{fantasma1,fantasma2},{cofretrampa},{subordinadoelfo,jefoelfe},{tortuguita1,tortuguita2},{tortugon},{miniblaze,blaze},{blaze}};
    
    inicializar_opcion(enemigos); 
}

// Función para inicializar las opciones para cada escenario del juego
void inicializar_opcion(Enemigo *enemigos[][2]){
    // Código para crear e inicializar opciones para cada escenario y asignar enemigos
    
    
    //Opciones escenario 1, con los enemigos correspondientes en cada opción
    Opcion *opcion1_1=malloc(sizeof(Opcion));  
    init_opcion(opcion1_1, "Izquierda", "Te encuentras con dos fantasmas que tienes que vencer", enemigos[0], 2, "Has derrotado a los fantasmas y continuas tu camino.");

    Opcion *opcion1_2=malloc(sizeof(Opcion));  
    init_opcion(opcion1_2, "Medio", "El cofre que habia era trampa y tienes que vencerlo", enemigos[1], 1, "Has derrotado al cofre trampa y continuas tu camino");

    Opcion *opcion1_3=malloc(sizeof(Opcion)); 
    init_opcion(opcion1_3,"Derecha","Llegas a la puerta sin nigún enemigo de por medio",NULL,0,"Saltas la puerta y continuas tu camino");

    //Opciones escenario 2, con los enemigos correspondientes en cada opción
    Opcion *opcion2_1=malloc(sizeof(Opcion));  
    init_opcion(opcion2_1,"Izquierda","Has tenido suerte y no te pierdes en el laberinto, tampoco te encuentras a ningun enemigo ",NULL,0,"Consigues salir del bosque tenebroso sin pelear con nadie");

    Opcion *opcion2_2=malloc(sizeof(Opcion));  
    init_opcion(opcion2_2, "Medio", "Pasas por varios ostaculos y en medio de uno de ellos te ecuentros a un elfo subordinado y su jefe, te enfrentas a ellos", enemigos[2], 2, "Has derrotado a los elfos y consigues salir del bosque tenebroso.");

    Opcion *opcion2_3=malloc(sizeof(Opcion));  
    init_opcion(opcion2_2,"Derecha","Las voces continuan intentando apodersarse de ti, pero no te encuentras a ningun enemigo",NULL,0,"Consigues salir del bosque tenebroso sin pelear con nadie");
    
    //Opciones escenario 3, con los enemigos correspondientes en cada opción
    Opcion *opcion3_1=malloc(sizeof(Opcion));  
    init_opcion(opcion3_1, "Izquierda", "Andaras con cuidado de no caer al agua pero no te encontraras a ningun enemigo en medio", NULL, 0, "Cruzas el lago sin tener que pelear contra ningún enemigo y el hombre que habias visto de lejos era tan solo un espantapajaros.");

    Opcion *opcion3_2=malloc(sizeof(Opcion));  
    init_opcion(opcion3_2, "Medio", "Por este camino tendras que vecer a a las dos tortuguitas armadas que intentaran que no llegues al castillo", enemigos[3], 2, "Después de vencer a las dos torutguitas, acabas de cruzar el lago ");

    Opcion *opcion3_3=malloc(sizeof(Opcion)); 
    init_opcion(opcion3_3,"Derecha","A pesar de que has escogido el camino rápido vas a tener que perder tiempo luchando contra el tortugon ",enemigos[4],1,"Después de vencer al tortugon, acabas de cruzar el lago");
    
    //Opciones escenario 4, con los enemigos correspondientes en cada opción
    Opcion *opcion4_1=malloc(sizeof(Opcion));  
    init_opcion(opcion4_1, "Ventana", "Rompes la ventana y entras al castillo pero te toca a enfrentarte a al BLAZE y a los mini blazes", enemigos[5], 2, "Has derrotado al boss final y recuperas a la princesa.");

    Opcion *opcion4_2=malloc(sizeof(Opcion)); 
    init_opcion(opcion4_2, "Puerta", "Consigues forzar la puerta  entrar al castillo y librarte de los mini blazes, pero ahora te toca enfrentarte al BLAZE", enemigos[6], 1, "Has derrotado al boss final y recuperas a la princesa.");

    Opcion *opcion4_3=malloc(sizeof(Opcion)); 
    init_opcion(opcion4_3, "Sotano", "Entrando por el sotano te libras de entrentarte contra los mini blazes, pero aún te queda el BLAZE", enemigos[6], 1, "Has derrotado al boss final y recuperas a la princesa.");
    
    
    Opcion *opciones[][3] = {{opcion1_1,opcion1_2,opcion1_3},{opcion2_1,opcion2_2,opcion2_3},{opcion3_1,opcion3_2,opcion3_3},{opcion4_1,opcion4_2,opcion4_3}};
    inicializar_decision(opciones); 
}

// Función para inicializar las decisiones para cada escenario del juego
void inicializar_decision(Opcion *opciones[][3]){
    // Código para crear e inicializar decisiones para cada escenario y asignar opciones


    //La decisión ha tomar en el escenario 1, co sus opciones correspondientes
    Decision *decision1=malloc(sizeof(Decision));
    init_decision(decision1, "¿Por que puerta quieres salir del cementerio?", opciones[0], 3);
    
    //La decisión ha tomar en el escenario 2, co sus opciones correspondientes
    Decision *decision2=malloc(sizeof(Decision));
    init_decision(decision2, "Así que, por donde deseas ir?", opciones[1], 3);
    
    //La decisión ha tomar en el escenario 3, co sus opciones correspondientes
    Decision *decision3=malloc(sizeof(Decision));
    init_decision(decision3, "¿Qué camino vas a coger?", opciones[2], 3);
    
    //La decisión ha tomar en el escenario 4, co sus opciones correspondientes
    Decision *decision4=malloc(sizeof(Decision));
    init_decision(decision4,"Por donde quieres entrar?", opciones[3], 2);
    
    Decision *decisiones[] = {decision1,decision2,decision3,decision4};
    
    inicializar_escenario(decisiones);
}

// Función para inicializar los escenarios del juego
void inicializar_escenario(Decision *decisiones[]){
    // Código para crear e inicializar instancias de escenarios y asignar decisiones
    
    Escenario *escenario1=malloc(sizeof(Escenario));
    init_escenario(escenario1, "Escenario 1", 
    "Tu misión ha empezado, acabas de aparecer en medio del cementerio de KINGSLAND, la ciudad que salvaste, y desconcertado, te encuentras con la gran maga SCARLET, la hermana menor de la princesa. Esta estaba rezando en tu tumba y se ha quedado anonadada de que tú estés delante suya. El gran héroe, después de tantos años, ha revivido. Llorando desconsoladamente, te pide ayuda para salvar a su hermana. Para ello, Scarlet te ha devuelto todos los ataques especiales que tenías en el pasado.\n\n"
    "Ahora tienes que emprender esta aventura y salvar a la princesa. Para salir del cementerio tienes tres puertas diferentes:\n"
    "La de la izquierda está abierta y pasas por un camino lleno de rosas totalmente iluminado.\n"
    "Por la del medio, que también está abierta, contemplas un cofre brillante que podría contener ciertos elementos curativos, de subida de defensa, mejora de ataques…\n"
    "Por último, por la de la derecha te encontrarás una puerta cerrada que deberás saltar y tendrás que pasar por un camino totalmente oscuro.",
    decisiones[0]);

    Escenario *escenario2=malloc(sizeof(Escenario));
    init_escenario(escenario2, "Escenario 2", 
    "Acabas de adentrarte al fin en la zona boscosa de KINGSLAND y no puedes observar nada de lo que hay más allá de los árboles. La luz dentro del bosque es oscura y el aire que se puede respirar contiene temor. Dentro de este se pueden escuchar llantos, gritos de desesperación y de dolor que provocan una mala experiencia para todo ser que entre en él. Hace unos años todo esto no era así, la gente iba dentro del bosque a buscar recursos y toda persona que lo visitaba tenía ganas de volver. Ahora mismo, no se siente ni una señal de vida, todo está destrozado y las voces de las almas de toda persona fallecida aquí dentro te están comiendo la cabeza.\n\n"
    "Sigues caminando, peleando contra toda voz maldita que se intenta apoderar de ti, y poco a poco ves cómo los árboles están aumentando su tamaño considerablemente. Te das cuenta de que no sabes muy bien dónde estás localizado, ya que todo el bosque es muy repetitivo y parecido, pero en medio de la nada, te encuentras unos carteles que te indican lo siguiente:\n\n"
    "Si sigues hacia adelante llegarás al lago sin perderte y sin escuchar voces, pero tendrás que superar obstáculos naturales.\n"
    "Si sigues hacia la izquierda, irás por el camino más rápido hacia el lago, pero es probable que te pierdas y acabes en un laberinto.\n"
    "Si sigues hacia la derecha, continuarás escuchando las voces tenebrosas pero acabarás en el lago igualmente.",
    decisiones[1]);

    Escenario *escenario3=malloc(sizeof(Escenario));
    init_escenario(escenario3, "Escenario 3", 
    "Parece que has llegado a un lugar mas calmado, empiezas a escuchar el sonido del agua fluir por el gran lago de KINGSLAND. Este lago rodea toda la capital, donde en ella se encuentra el gran castillo de la princesa. La paz que transmite el agua al fluir por todos los terrenos de KINGSLAND te hace volver a tu cordura normal, olvidándote de toda maldad que se haya sometido dentro de tu cabeza. Puedes observar que alrededor del lago todo está destrozado por las constantes batallas que se han provocado a lo largo de estos años, así que sigues caminando para llegar al borde del lago.\n\n"
    "Una vez llegas al inicio del gran lago, contemplas que tu camino se divide en tres debido a que el camino principal está bloqueado por cadáveres acumulados. Te tocará desviarte por otro lado. Ves que por el camino del medio se interpone un grupo de tortugas humanizadas, las cuales portan armas y tienen sed de robarte todo lo que tengas encima. Por otra parte, el camino izquierdo está  destrozado pero observamos que al final del camino hay un hombre que podría informarte de algo . El camino de la derecha aparenta vacío y sin enemigos esperándote, por lo que podrías coger ese camino para llegar más rápido.",
    decisiones[2]);

    Escenario *escenario4=malloc(sizeof(Escenario));
    init_escenario(escenario4, "Escenario 4", 
    "Has logrado por fin llegar a la capital de KINGSLAND, donde todo está lleno de llamas y sangre. Esto es obra del malvado BLAZE, el cual, con sus llamas, ha ido acabando con toda vida humana que se haya puesto en medio de su camino. Observas a la gente intentando huir, llorando por todo lo que está perdiendo en su vida. La mezcla del fuego y sangre está provocando que todo se pinte de rojo. Los gritos de sufrimiento que hay por las calles de tu villa están encendiendo tu fuego interior. Arrebatado por la furia y la venganza, empiezas a correr sin mirar atrás hasta la puerta donde vivías feliz al lado de tu princesa, donde, una vez estás allí… observas al gran BLAZE, sentado en la gran silla del reino, el cual tiene a la princesa atada dentro de la celda. Esta, aunque tenga los ojos vendados, ha podido notar tu presencia y ha empezado a llorar de felicidad, sin creerse que su estimado haya vuelto del otro mundo para salvarla. El gran BLAZE ha bloqueado la entrada con una gran llamarada.\n\n"
    "Pra entrar al castillo tienes las siguientes posibilidades:\n"
    "En la izquierda encuentras una ventana en mal estado, la cual podrías romper para poder entrar en el salón del castillo.\n"
    "Por el medio entraras por la gran puerta del castillo, donde tendrás que conseguir forzarla para poder pasar por ella.\n"
    "En la derecha encuentras el sótano, el cual te suena que tiene una vía directa hacia donde se encuentran la princesa y BLAZE.",
    decisiones[3]);

    simular_decision(escenario1);
}

// Función para simular la elección de una opción dentro de un escenario
void simular_decision(Escenario *escenario) {
        // Código para simular la elección de una opción dentro de un escenario y mostrar la narrativa antes y después de la elección

        int opcion_idx;

        // Mostrar el escenario 
        print_escenario(escenario);

        // Simular elección de opción
        printf("%s\n",escenario->decision->texto_pregunta);
        printf("Elige (1-Izquierda, 2-Medio, 3-Derecha) [1-%d]: ", escenario->decision->num_opciones);
        scanf("%d", &opcion_idx);

        if (opcion_idx <= 0 || opcion_idx > escenario->decision->num_opciones) {
            printf("Opción no válida.\n");
            return;
        }

        Opcion *opcion = escenario->decision->opciones[opcion_idx-1];
        print_opcion(opcion);

        // Aplicar efectos de la opción
        if (opcion->num_enemigos > 0) {
            
        } 
        else {
            
        }

        printf("Narración después: %s\n", opcion->narracion_despues);
        
}

int main() {
    //Narración del inicio del juego
    printf("Hace unos años atrás, se vivió una gran guerra en los terrenos de \"KINGSLAND\" la cual puso en peligro a la princesa \"SIRA\", mejor conocida actualmente como la \"gran princesa\". El terror de los elfos, animales paranormales y personas no humanas, abundaba en las calles y casas de nuestra \"KINGSLAND\", hasta que un día, apareció un gran héroe. Este, cargando una gran espada y controlando los diferentes elementos de la naturaleza, fue capaz de salvar el reino y así ser proclamado como el \"gran guerrero\". La princesa, al contemplar a este gran guerrero, se enamoró perdidamente de él y juntos decidieron formar una familia dentro de \"KINGSLAND\", pero no todo será tan bonito como parece…\n\n");

    printf("Algunos meses después, el gran héroe enfermó misteriosamente y falleció, dejando así un gran vacío de poder dentro de \"KINGSLAND\", la cual actualmente ha recibido un gran ataque por parte de \"BLAZE\", el dios del fuego, quien ha raptado a la princesa y matado al rey. Este malvado es conocido ya por estas tierras, por un ataque fallido en unos años pasados, en el cual fue derrotado por el gran héroe. Al parecer, mostró una faceta falsa sobre él, presentándose como un malvado de muy poco nivel con el objetivo de envenenar a nuestro héroe. Esto, lo logró.\n\n");

    printf("De repente, el gran héroe contempla una luz desde el subsuelo, en su tumba. La voz del rey fallecido, padre de su princesa, empieza a retumbar por dentro de su cuerpo, pidiéndole que salve a la princesa de las manos de \"BLAZE\". Empieza a escuchar los gritos y sentimientos de SIRA y poco a poco va recuperando su ser. Con toda la sed de venganza, su tumba empieza a desmoronarse y de las tierras, vuelve a la vida el gran héroe revivido.\n\n");
    
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
    //print_personaje(&miPersonaje);
    printf("----------------------------------------------------\n");
    printf("\nEscenario:\n");
    inicializar_habilidades();
    return 0;

}

