#include "/w/barthleby/path.h"

inherit CAMINO_SUDESTE"std_caminoSE.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLUE%^Camino Sudeste%^RESET%^");
   long_desc_cse();





add_exit("noroeste", CAMINO_SUDESTE+"camino_sudeste7","road");
add_exit("norte", BREIX+"breix17","road");
add_exit("sudeste", CAMINO_SUDESTE+"camino_sudeste9","road");
}



