#include "/w/barthleby/path.h"

inherit CAMINO_NORTE"std_caminoN.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Camino Norte%^RESET%^");
   long_desc_cn();






add_exit("norte", CAMINO_NORTE+"camino_norte2","road");
add_exit("sur", MURALLAS_NOELLA+"entra_muralla2","road");
}



