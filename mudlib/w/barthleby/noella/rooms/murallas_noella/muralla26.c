#include "/w/barthleby/path.h"

inherit MURALLAS_NOELLA"std_muralla.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^YELLOW%^Murallas de Noella%^RESET%^");
   long_desc_muralla();



add_exit("norte", MURALLAS_NOELLA+"muralla25","road");
add_exit("sur", MURALLAS_NOELLA+"muralla27","road");
add_exit("este", CALLEJONES+"callejon_D1","road");
}

