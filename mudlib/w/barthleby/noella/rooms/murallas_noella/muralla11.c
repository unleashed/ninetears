#include "/w/barthleby/path.h"

inherit MURALLAS_NOELLA"std_muralla.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^YELLOW%^Murallas de Noella%^RESET%^");
   long_desc_muralla();



add_exit("oeste", MURALLAS_NOELLA+"muralla12","road");
add_exit("este", MURALLAS_NOELLA+"muralla10","road");
add_exit("sudoeste", PRINCIPALES+"circo","road");
}

