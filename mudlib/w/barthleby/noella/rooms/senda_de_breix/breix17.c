#include "/w/barthleby/path.h"

inherit BREIX"std_senda_breix.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^ORANGE%^Senda de Breix%^RESET%^");
   long_desc_breix();



add_exit("norte",  BREIX+"breix16","road");
add_exit("sur",  CAMINO_SUDESTE+"camino_sudeste8","road");

}
