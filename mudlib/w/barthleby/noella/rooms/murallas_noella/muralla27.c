#include "/w/barthleby/path.h"

inherit MURALLAS_NOELLA"std_muralla.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^YELLOW%^Murallas de Noella%^RESET%^");
   long_desc_muralla();



add_exit("norte", MURALLAS_NOELLA+"muralla26","road");
add_exit("sur", MURALLAS_NOELLA+"muralla28","road");
}

