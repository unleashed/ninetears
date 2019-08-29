#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras%^RESET%^");
   set_long("Por todos lados escuchas los sonidos de los diversos animales "
   "que pueblan el mismo, en lo alto de las colinas observas una construccion "
   "de negra obsidiana que corona las mismas, se trata de La Torre Negra, una "
   "milenaria construccion que se dice fue levantada por Oskuro, el camino "
   "se desvia hacia el noroeste.\n");
   add_exit("este", BOSQUEELORAS+"b8", "plain");
   add_exit("noroeste", BOSQUEELORAS+"b10", "plain");
   add_clone("/d/anduar/npcs/bichos.c",3);
set_light(50);
}
