#include "/w/barthleby/path.h"

inherit BREIX"std_senda_breix.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^ORANGE%^Senda de Breix%^RESET%^");
   long_desc_breix();



add_exit("noroeste",  COUTO+"couto22","road");
add_exit("este",  BREIX+"breix10","road");
add_exit("sur",  BREIX+"breix12","road");

}
