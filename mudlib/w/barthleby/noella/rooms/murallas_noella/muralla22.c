#include "/w/barthleby/path.h"

inherit MURALLAS_NOELLA"std_muralla.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^YELLOW%^Murallas de Noella%^RESET%^");
   long_desc_muralla();



add_exit("noroeste", MURALLAS_NOELLA+"muralla21","road");
add_exit("este", CALLEJONES+"callejon_D5","road");
add_exit("sudeste", CALLEJONES+"callejon_D4","road");
add_exit("sur", MURALLAS_NOELLA+"muralla23","road");
}

