// Aokromes Noviembre 1999

#include "../path.h"
inherit LABERINTO2+"cultivos";

void setup() {

   set_light(50);
   set_short("Cultivos de "PN);
   set_long("Estas en una senda entre los amplios cultivos del poblado de "
   +PN+" por todos lados se ven gente recolectando los cultivos para "
   "llevarlos a la ciudad, tal vez tengan tiempo para acabar antes de que "
   "anochezca.\n");
   add_item("gente","personas de todas las edades que van de un lugar a otro "
   "recolectando el contenido de los cultivos.");
crea_bichos();
add_exit("northwest",LABERINTO2+"senda_94.c","plain");
add_exit("sudoeste","/d/anduar/senda/rooms/s25","plain");
// add_exit("sudoeste","/d/anduar/poblado/g0109","plain");
}
