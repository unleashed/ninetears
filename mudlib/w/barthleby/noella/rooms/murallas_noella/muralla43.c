#include "/w/barthleby/path.h"

inherit MURALLAS_NOELLA"std_muralla.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^YELLOW%^Murallas de Noella%^RESET%^");
   long_desc_muralla();



add_exit("noreste", MURALLAS_NOELLA+"muralla44","road");
add_exit("sudeste", MURALLAS_NOELLA+"muralla42","road");
add_exit("sudoeste", CALLE+"calle18","road");
add_exit("dentro", PRINCIPALES+"floristeria_noella","road");
}

