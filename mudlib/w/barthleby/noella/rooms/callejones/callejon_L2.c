#include "/w/barthleby/path.h"

inherit CALLEJONES"std_callejon.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Callej�n oscuro%^RESET%^");
   long_desc_callejones();



add_exit("sudoeste", PARQUES+"suleithel2","road");
add_exit("norte", CALLEJONES+"callejon_L1","road");
add_exit("este", CALLEJONES+"callejon_L3","road");
}

