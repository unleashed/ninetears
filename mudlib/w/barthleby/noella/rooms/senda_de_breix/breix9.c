#include "/w/barthleby/path.h"

inherit BREIX"std_senda_breix.c";


void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^ORANGE%^Senda de Breix%^RESET%^");
   long_desc_breix();



add_exit("noroeste",  BREIX+"breix10","road");
add_exit("sudeste",  LOUREN+"louren1","road");

}





