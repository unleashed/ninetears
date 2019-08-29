inherit "/std/bosque.c";

void setup(){

set_short("Entrada al %^GREEN%^Bosque Tralak%^RESET%^");

set_long(query_short()+"\n Te encuentras en la entrada del gran bosque de tralak el cual guarda muchos secretos y misterios e incluso peligros %^BOLD%^%^RED%^mortales%^RESET%^, al mirar dentro del bosque no alcanzar a divisar nada solo arboles tras arboles de distintos tipos y formas. Al lado del signo puedes ver una persona que cuenta algunos de los secretos del bosque.\n\n");

add_exit("norte","/w/drakzten/bosque/camino","door");

add_exit("sur","/w/drakzten/bosque/room/bosque1","door");

add_clone("/w/drakzten/bosque/npj/willy_cuidador",1);

add_sign("Un signo clavado en un arbol.\n",
          "\tPara los %^BOLD%^%^BLACK%^Viajeros y %^GREEN%^Aventureros%^RESET%^:\n"
          "\tExtremo %^RED%^Cuidado %^RESET%^al entrar al bosque\n"
          "\tya que puee tener peligros %^BOLD%^%^RED%^MORTALES%^RESET%^ si uno no esta atento\n"
          "\tescucha a Willy si quieres saber algo mas de este maravilloso bosque.\n\n");
          
         }