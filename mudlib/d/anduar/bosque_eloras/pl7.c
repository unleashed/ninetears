#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras: Plaza bonita%^RESET%^");
   set_long("Estas en uno de los senderos que los habitantes de este bosque "
   "llaman plaza bonita, por todos lados ves pequenyas construcciones "
   "que parecen ser el hogar de los pequenyos habitantes de este bosque, por "
   "todos lados observas halflins correteando por hay.\n");
  add_exit("oeste", BOSQUEELORAS+"pl8", "plain");
   add_exit("noreste", BOSQUEELORAS+"a12", "plain");
set_light(50);
add_clone("/d/anduar/npcs/halfling.c",random(6));
}
