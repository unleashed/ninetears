#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras%^RESET%^");
   set_long("Nada mas penetrar en este bosquecillo por todos lados escuchas "
   "los sonidos de los diversos animales que pueblan el mismo, al este, en "
   "los lindes del bosque observas el camino real, seguramente este sendero "
   "fue usado por los obreros del camino para acarrear materiales.\n");
   add_exit("este", BOSQUEELORAS+"a9", "plain");
  add_exit("noroeste", BOSQUEELORAS+"e1", "plain");
   add_exit("sudoeste", BOSQUEELORAS+"a11", "plain");
set_light(50);
add_clone("/d/anduar/npcs/bichos.c",3);
}
