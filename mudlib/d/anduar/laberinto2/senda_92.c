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
add_exit("north",LABERINTO2+"senda_84.c","plain");
add_exit("east",LABERINTO2+"senda_93.c","plain");
add_exit("southwest",LABERINTO2+"senda_94.c","plain");
}
