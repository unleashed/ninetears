// Aokromes Noviembre 1999

inherit "/d/anduar/laberinto2/cultivos.c";
#include "../path.h"

void setup() {

   set_light(50);
   set_short("Cultivos de "+PN);
   set_long("Estas en una senda entre los amplios cultivos del poblado de "
   +PN+" por todos lados se ven cultivos de la mas exotica procedencia, "
   "algunos tal vez no son ni si quiera del contienente, si no de las mas "
   "lejanas islas de ultramar.\n");
   crea_bichos();
add_exit("noroeste","/d/anduar/senda/rooms/s41","plain");
   add_exit("southwest",LABERINTO2+"senda_3.c","plain");
}
