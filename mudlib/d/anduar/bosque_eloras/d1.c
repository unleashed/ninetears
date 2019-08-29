#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras: Calle del amanecer%^RESET%^");
   set_long("Estas en uno de los senderos que los habitantes de este bosque "
   "llaman calle del amanecer, por todos lados ves pequenyas construcciones "
   "que parecen ser el hogar de los pequenyos habitantes de este bosque, este "
   "sendero en concreto se dirige caoticamente de este a oeste.\n");
   add_exit("sudoeste", BOSQUEELORAS+"d2", "plain");
   add_exit("este", BOSQUEELORAS+"a3", "plain");
add_clone("/d/anduar/npcs/halfling.c",random(3));
set_light(50);
}
