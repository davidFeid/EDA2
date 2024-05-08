#include "main.h"

void inicializar_enemigos(){
    Enemigo fantasma;
    init_enemigo(&fantasma, "Fantasma de soldado", 100, 50, 20);
   
    Enemigo cofretrampa;
    init_enemigo(&cofretrampa, "Cofre Trampa", 225, 100, 200);
    

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

void inicializar_decision(){
    Decision cementerio;
    init_decision(&cementerio,"Después de derrotar a todos los enemigos, te encuentras a la salida del cementerio. Estando todavía desconcertado, no te estás del todo situado en tu antigua vida, asi que no sabes que camino hay que tomar. Por donde deseas ir?", 3, "");
    print(&cementerio);

    Decision bosque;
    init_decision(&bosque, "Perdido dentro del bosque, te encuentras con unos carteles que te dan información sobre que ruta escoger. Una vez leídos, hacía donde decides partir?",3,"");
    print(&bosque);

    Decision lago;
    init_decision(&lago,"Contemplando de una vez el azul claro del agua del lago, observas al frente y ves que hay ciertos caminos que no están en muy buenas condiciones. Estando el camino partido en 3, hacia donde deseas partir para llegar al casitllo?",3,"");
    print(&lago);
}



void inicializar_opcion(){
    Opcion cementerio1;
    init_Opcion(&cementerio1,"Has decidido escoger el camino derecho","Este camino derecho te llevaba a la casa de tu viejo amigo RUFF, el cuál es herrero", , , "Llegas a la casa del viejo herrero y el viejo, no se puede creer que estés delante suya. Se piensa que todo es una mentira y está soñando despierto, pero nombras a “SIRA” y entonces sabe que eres real. Este decide ayudarte y acaba explicándote todo lo que ha sucedido en estos años. Recibes una katana, la cúal incrementará +20 el ataque y una armadura que te subirá en +10. Lo recoges todo y sigues adelante");
    
    Opcion cementerio2;
    init_Opcion(&cementerio2,"Has decidido escoger el camino izquierdo", "En el camino izquierdo contemplabas un cofre brillante que podria contener ciertos elementos curativos, de subida de defensa, mejora de ataques…", &cofretrampa, 1, "Llegas al cofre en medio del bosque y te encuentras en que es un cofre trampa, el cuál salta a atacarte” → Lo matas, saqueas el loot, el cual te dará 2 pociones de vida y 2 de escudo");
    
    Opcion cementerio3;
    init_Opcion(&cementerio3, "Has decidido ir por el camino central","Bien sabias que si decideias tirar recto por el camino central, llegarías al bosque más rápidamente escapando de todo posible enfrentamiento.", , ,"Asi que corres ràpidamente por el medio del camino, esquivando a todos los enemigos que vas observando. En tus pies encuentras 1 poción de vida y varios càdaveres de guerreros. Despúés de un tiempo, llegas al bosque");
    
    Opcion bosque1;
    init_Opcion(&bosque, "Decides seguir el cártel de la derecha", "Si ibas por la derecha, te encontrarás con una tienda en la cuál podrias comprar ciertos objetos antes de  llegar a tu próximo destino", , , "Acabas llegando a la tienda donde decides adquirir una poción de vida");

    Opcion bosque2;
    init_Opcion(&bosque, "Decides ir por el cártel izquierdo" ,"Este cártel te decia que llegarías al lago por el camino más rápido de todos escapando de todo enemigo y de todo posible lugar de looteo ", , , "Como el cártel te informaba, has llegado al lago escapando de toda pelea posible y sigues con los mismos objetos que al principio");

    Opcion bosque3;
    init_Opcion(&bosque, "Decies ir por el cártel central", "Este camino central te indicaba que pelearías contra el elfo supremo y sus secuaces, y tu, sin miedp, has decidido pelear", &subordinadoelfo &elfosupremo, 2 1 , "La pelea contra este jefe es tuya y con ello te has llevado su gran armadura, la qual te ha otorgado +20 de defensa");
    
    Opcion lago1;
    init_Opcion(&lago,"Pillas el camino derecho", " El camino de la derecha está más destrozado pero observas que al final del camino hay unas ruinas de un pequeño castillo destrozado en el cúal podrías encontrar ciertas mejoras para llegar al castillo final", , , "Has logrado llegar a las ruinas donde te has encontrado a la ESPADA SAGRADA, la cuál perteneció a grandes héroes històricos pasados. Esta te sumará +80 de ataque, asi que te equipas con ella y sigues hacia delante");

    Opcion lago2;
    init_Opcion(&lago,"Pillas el camino izquierdo", "El camino izquierdo aparenta vacio y sin enemigos espérandote, por lo que podrias coger ese camino para llegar más ràpido", &tortuga, 1 , "Una tortuga bandida te ha asaltado, logrando acabar con ella, has continuado tu viaje hasta el gran castillo");

    Opcion lago3;
    init_Opcion(&lago,"Pillas el camino central", "En el camino del medio se interpone un grupo de tortugas humanizadas, las cúales portan armas y tienen sed de robarte todo lo que tengas encima. Tu sin miedo, decides ir a por ellas", &tortuga, 2, "Logras acabar con las tortugas las cuáles te darán una poción de recuperación de vida y otra de maná" );
}

void inicializar_escenario(){
    Escena cementerio;
    init_escena(&cementerio, "Cementerio de KINGSLAND", "El aire que se puede respirar es tenebroso y todo lo que te rodea son tumbas de tus compañeros soldados caídos en batalla al largo de estos años. Puedes contemplar que todo está más deteriorado por culpa de las continúas guerras, cosa que está provocando que los territorios se vayan malgastando");

    Escena bosque;
    init_escena(&bosque, "El bosque maldito", "El bosque oscuro maldito de KINGSLAND, conocido por el hecho de que hay gente que ha logrado entrar pero no salir...El aire que se respira por esta zona es intenso y fuerte, los pulmones se te llenan de un oxigeno malvado y la gran cantidad de árboles provoca que no puedas contemplar nada de lo que haya dentro de este bosque", );

    Escena lago;
    init_escena(&lago, "Lago del sueño","Después de una larga aventura, llegas a contemplar al fin el gran azul reflejado en el agua del lago de KINGSLAND. El agua del lago puede tranqulizar a todo ser que la contemple gracias a su gran luz brillante, todo la tranqulidad parece estar reflejada en este lago, porque sus alrededores están todos destrozados." );

    Escena castillo;
    init_escena(&castillo, "El gran castillo de KINGSLAND","El final de tu largo recorrido prevalece en este territorio, el gran castillo. Nada más entrar, todos tus buenos antiguos recuerdos por las calles y rincones de este castillo llenan tu mente. Toda la felicidad que antes había en estas calles se ha arrebatado con el paso del tiempo y ahora simplemente hay alboroto y miedo.",  );

}
int main(){
    // Crear una instancia de la estructura Personaje
    Personaje miPersonaje;

    // Configurar el personaje
    init_personaje(&miPersonaje);

    // Mostrar los datos del personaje configurado
    print_personaje(&miPersonaje);

    inicializar_enemigos();
    inicializar_decision();
    inicializar_escenario();
    inicializar_opcion();
    return 0;
}