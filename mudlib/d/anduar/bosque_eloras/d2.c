#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras: Calle del amanecer%^RESET%^");
   set_long("Estas en uno de los senderos que los habitantes de este bosque "
   "llaman calle del amanecer, por todos lados ves pequenyas construcciones "
   "que parecen ser el hogar de los pequenyos habitantes de este bosque, este "
   "sendero en concreto se dirige caoticamente de este a oeste.\n");
   add_exit("oeste", BOSQUEELORAS+"d3", "plain");
   add_exit("noreste", BOSQUEELORAS+"d1", "plain");
set_light(50);
add_clone("/d/anduar/npcs/halfling.c",random(3));
}
