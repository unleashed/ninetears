// Aokromes Noviembre 1999

#include "../path.h"
inherit LABERINTO2+"cultivos";

void setup() {

   set_light(50);
   set_short("Cultivos de "PN);
   set_long("Estas en una senda entre los amplios cultivos del poblado de "
   +PN+" por todos lados se ven barbechos, se ve que no quieren agotar la "
   "tierra, si no que quieren que les dure muchos a�os, a diferencia de los "
   "cultivos de otros reinos.\n");
crea_bichos();
add_exit("west",LABERINTO2+"senda_31.c","plain");
add_exit("northeast",LABERINTO2+"senda_26.c","plain");
}
