#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras%^RESET%^");
   set_long("Por todos lados escuchas los sonidos de los diversos animales "
   "que pueblan el mismo, al este, separado de ti por un caudaloso rio, esta "
   "el %^BOLD%^%^YELLOW%^Desierto de la %^BOLD%^%^BLACK%^muerte%^RESET%^ "
   "mientras el camino se dirige al sur, paralelo al rio. Al oeste a poca distancia "
   "hay una roca de grandes dimensiones.\n");
   add_exit("noroeste", BOSQUEELORAS+"c6", "plain");
   add_exit("sur", BOSQUEELORAS+"c8", "plain");
   add_exit("oeste","/d/anduar/rutic/entrada.c","secret");
set_light(50);
}
