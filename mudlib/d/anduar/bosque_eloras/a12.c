#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras%^RESET%^");
   set_long("Nada mas penetrar en este bosquecillo por todos lados escuchas "
   "los sonidos de los diversos animales que pueblan el mismo, al este, en "
   "los lindes del bosque observas el camino real, seguramente este sendero "
   "fue usado por los obreros del camino para acarrear materiales.\n");
   add_exit("noreste", BOSQUEELORAS+"a11", "plain");
  add_exit("noroeste", BOSQUEELORAS+"pl6", "plain");
  add_exit("sudoeste", BOSQUEELORAS+"pl7", "plain");
   add_exit("sur", BOSQUEELORAS+"a13", "plain");
set_light(50);
add_clone("/d/anduar/npcs/bichos.c",3);
}
