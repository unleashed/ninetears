#include "/w/barthleby/path.h"

inherit MURALLAS_NOELLA"std_muralla.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^YELLOW%^Murallas de Noella%^RESET%^");
   long_desc_muralla();



add_exit("noroeste", MURALLAS_NOELLA+"muralla2","road");
add_exit("sudeste", MURALLAS_NOELLA+"entra_muralla1","road");
add_exit("dentro", PRINCIPALES+"correos","road");
}
