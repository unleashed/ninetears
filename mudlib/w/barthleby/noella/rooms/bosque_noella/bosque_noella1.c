#include "/w/barthleby/path.h"

inherit BOSQUE"std_bosque_noella.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^GREEN%^Camino en el bosque%^RESET%^");
   long_desc_bosque_noella();



add_exit("oeste", CAMINO_NORTE+"camino_norte6","road");
add_exit("este", BOSQUE+"bosque_noella2","road");

}
