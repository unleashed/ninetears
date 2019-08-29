#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras: Calle de la aurora%^RESET%^");
   set_long("Estas en uno de los senderos que los habitantes de este bosque "
   "llaman calle de la aurora, por todos lados ves pequenyas construcciones "
   "que parecen ser el hogar de los pequenyos habitantes de este bosque, este "
   "sendero en concreto se dirige caoticamente de noroeste a sudeste.\n");
   add_exit("oeste", BOSQUEELORAS+"g5", "plain");
   add_exit("este", BOSQUEELORAS+"g7", "plain");
set_light(50);
add_clone("/d/anduar/npcs/halfling.c",random(3));
}
