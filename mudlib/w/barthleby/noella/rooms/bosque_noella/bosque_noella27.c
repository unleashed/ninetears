#include "/w/barthleby/path.h"

inherit BOSQUE"std_bosque_noella.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^GREEN%^Camino en el bosque%^RESET%^");
   long_desc_bosque_noella();



add_exit("este", CAMINO_SUDESTE+"camino_sudeste10","road");
add_exit("sur", BOSQUE+"bosque_noella28","road");

}



