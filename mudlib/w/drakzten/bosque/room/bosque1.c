inherit "/std/bosque.c";

void setup(){

set_short("%^GREEN%^Bosque Tralak%^BOLD%^%^BLACK%^ sector norte%^RESET%^");

set_long(query_short()+"\n Te encuentras por el sector norte de este infinito bosque, logras escuchar unos extranyos chillidos de animales, al mirar hacia el cielo los arboles te tapan haci que la luz es la justa y necesaria, puedes ver los distintos arboles de distintos tipos y formas.\n\n");

add_exit("norte","/w/drakzten/bosque/room/entrada_bosque","door");

add_exit("sur","/w/drakzten/bosque/room/bosque2","door");

add_exit("sudeste","/w/drakzten/bosque/room/bosque3","door");

add_exit("sudoeste","/w/drakzten/bosque/room/bosque4","door");

add_clone("/w/drakzten/bosque/npj/lobo",1);
         
         }