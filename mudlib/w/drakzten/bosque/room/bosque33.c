inherit "/std/bosque.c";

void setup(){

set_short("%^GREEN%^Bosque Tralak%^BOLD%^%^BLACK%^ sector oeste%^RESET%^");

set_long(query_short()+"\n Te encuentras por el sector oeste de este infinito bosque, logras escuchar unos extranyos chillidos de animales, al mirar hacia el cielo los arboles te tapan haci que la luz es la justa y necesaria, puedes ver los distintos arboles de distintos tipos y formas.\n\n");

add_exit("este","/w/drakzten/bosque/room/bosque43","door");

add_exit("noroeste","/w/drakzten/bosque/room/bosque32","door");

add_clone("/w/drakzten/bosque/npj/lobo",4);
add_clone("/w/drakzten/bosque/npj/aranya",2);
add_clone("/w/drakzten/bosque/npj/buho",2);
         
         }