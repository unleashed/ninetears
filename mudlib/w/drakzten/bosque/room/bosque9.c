inherit "/std/bosque.c";

void setup(){

set_short("%^GREEN%^Bosque Tralak%^BOLD%^%^BLACK%^ sector norte%^RESET%^");

set_long(query_short()+"\n Te encuentras por el sector norte de este infinito bosque, logras escuchar unos extranyos chillidos de animales, al mirar hacia el cielo los arboles te tapan haci que la luz es la justa y necesaria, puedes ver los distintos arboles de distintos tipos y formas.\n\n");

add_exit("norte","/w/drakzten/bosque/room/bosque4","door");

add_exit("este","/w/drakzten/bosque/room/bosque5","door");

add_exit("sudoeste","/w/drakzten/bosque/room/bosque22","door");

add_exit("oeste","/w/drakzten/bosque/room/bosque11","door");

add_clone("/w/drakzten/bosque/npj/lobo",1);
add_clone("/w/drakzten/bosque/npj/aranya",3);

         
         }