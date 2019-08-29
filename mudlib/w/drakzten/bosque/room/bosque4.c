inherit "/std/bosque.c";

void setup(){

set_short("%^GREEN%^Bosque Tralak%^BOLD%^%^BLACK%^ sector norte%^RESET%^");

set_long(query_short()+"\n Te encuentras por el sector norte de este infinito bosque, logras escuchar unos extranyos chillidos de animales, al mirar hacia el cielo los arboles te tapan haci que la luz es la justa y necesaria, puedes ver los distintos arboles de distintos tipos y formas.\n\n");

add_exit("noreste","/w/drakzten/bosque/room/bosque1","door");

add_exit("sur","/w/drakzten/bosque/room/bosque9","door");

add_exit("este","/w/drakzten/bosque/room/bosque2","door");

add_exit("oeste","/w/drakzten/bosque/room/bosque10","door");

add_exit("sudoeste","/w/drakzten/bosque/room/bosque11","door");
add_clone("/w/drakzten/bosque/npj/lobo",2);
add_clone("/w/drakzten/bosque/npj/aranya",2);

         
         }