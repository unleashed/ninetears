#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras%^RESET%^");
   set_long("Por todos lados escuchas los sonidos de los diversos animales "
   "que pueblan el mismo, al este, separado de ti por un caudaloso rio, esta "
   "el %^BOLD%^%^YELLOW%^Desierto de la %^BOLD%^%^BLACK%^muerte%^RESET%^ "
   "mientras el camino se dirige al sur, paralelo al rio.\n");
   add_exit("oeste", BOSQUEELORAS+"c22", "plain");
   add_exit("este", BOSQUEELORAS+"c24", "plain");
set_light(50);
}
