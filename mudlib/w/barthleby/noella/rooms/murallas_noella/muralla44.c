#include "/w/barthleby/path.h"

inherit MURALLAS_NOELLA"std_muralla.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^YELLOW%^Murallas de Noella%^RESET%^");
   long_desc_muralla();



add_exit("noreste", MURALLAS_NOELLA+"entra_muralla1","road");
add_exit("sudeste", MURALLAS_NOELLA+"ponte_en_construccion1","road");
add_exit("sudoeste", MURALLAS_NOELLA+"muralla43","road");
}

