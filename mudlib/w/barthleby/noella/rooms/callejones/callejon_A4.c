#include "/w/barthleby/path.h"

inherit CALLEJONES"std_callejon.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Callej�n oscuro%^RESET%^");
   long_desc_callejones();



add_exit("noroeste", CALLEJONES+"callejon_C4","road");
add_exit("noreste", CALLEJONES+"callejon_A5","road");
add_exit("sudeste", MURALLAS_NOELLA+"muralla35","road");
add_exit("sudoeste", CALLEJONES+"callejon_A3","road");
}

