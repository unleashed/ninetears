#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras: Calle corta%^RESET%^");
   set_long("Estas en uno de los senderos que los habitantes de este bosque "
   "llaman calle de la corta, por todos lados ves pequenyas construcciones "
   "que parecen ser el hogar de los pequenyos habitantes de este bosque, este "
   "sendero en concreto se dirige directamente de sudoeste a noreste.\n");
  add_exit("noreste", BOSQUEELORAS+"pl1", "plain");
   add_exit("noroeste", BOSQUEELORAS+"c10", "plain");
   add_exit("sudeste", BOSQUEELORAS+"c11", "plain");
//  add_exit("oeste", DESIERTO+"r1", "plain"); futura salida al desierto
set_light(50);
add_clone("/d/anduar/npcs/halfling.c",random(3));
}
