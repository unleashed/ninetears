#include "/w/barthleby/path.h"

inherit BOSQUE"std_bosque_noella.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^GREEN%^Camino en el bosque%^RESET%^");
   long_desc_bosque_noella();



add_exit("noreste", BOSQUE+"bosque_noella25","road");
add_exit("sudoeste", CAMINO_SUDESTE+"camino_sudeste10","road");

}




