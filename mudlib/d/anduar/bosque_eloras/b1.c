#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras%^RESET%^");
   set_long("Nada mas penetrar en este bosquecillo por todos lados escuchas "
   "los sonidos de los diversos animales que pueblan el mismo, en lo alto de "
   "las colinas observas una construccion de negra obsidiana que corona las "
   "mismas, se trata de La Torre Negra, una milenaria construccion que se "
   "dice fue levantada por Oskuro.\n");
   add_exit("oeste", BOSQUEELORAS+"b2", "plain");
  add_exit("sudoeste", BOSQUEELORAS+"a1", "plain");
   add_exit("sur", SENDA+"p4", "plain");
set_light(50);
add_clone("/d/anduar/npcs/bichos.c",3);
}
