// Aokromes Noviembre 1999

#include "../path.h"
inherit LABERINTO2+"cultivos";

void setup() {

   set_light(50);
   set_short("Cultivos de "PN);
   set_long("Estas en una senda entre los amplios cultivos del poblado de "
   +PN+" por todos lados se ven cultivos de la mas exotica procedencia, "
   "algunos tal vez no son ni si quiera del contienente, si no de las mas "
   "lejanas islas de ultramar.\n");
   crea_bichos();
add_exit("west",LABERINTO2+"senda_9.c","plain");
add_exit("southwest",LABERINTO2+"senda_16.c","plain");
}
