#include "/w/barthleby/path.h"

inherit MURALLAS_NOELLA"std_muralla.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^YELLOW%^Murallas de Noella%^RESET%^");
   long_desc_muralla();



add_exit("noreste", MURALLAS_NOELLA+"muralla36","road");
add_exit("sudoeste", MURALLAS_NOELLA+"muralla34","road");
add_exit("noroeste", CALLEJONES+"callejon_A4","road");
}

