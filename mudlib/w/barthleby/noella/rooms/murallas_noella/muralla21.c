#include "/w/barthleby/path.h"

inherit MURALLAS_NOELLA"std_muralla.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^YELLOW%^Murallas de Noella%^RESET%^");
   long_desc_muralla();



add_exit("noroeste", MURALLAS_NOELLA+"muralla20","road");
add_exit("este", CALLEJONES+"callejon_I1","road");
add_exit("sudeste", MURALLAS_NOELLA+"muralla22","road");
}
