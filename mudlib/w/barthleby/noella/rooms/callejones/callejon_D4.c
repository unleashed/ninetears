#include "/w/barthleby/path.h"

inherit CALLEJONES"std_callejon.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Callej�n oscuro%^RESET%^");
   long_desc_callejones();



add_exit("noroeste", MURALLAS_NOELLA+"muralla22","road");
add_exit("norte", CALLEJONES+"callejon_D5","road");
add_exit("sur", CALLEJONES+"callejon_D3","road");
}

