#include "/w/barthleby/path.h"

inherit CALLEJONES"std_callejon.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Callej�n oscuro%^RESET%^");
   long_desc_callejones();



add_exit("norte", MURALLAS_NOELLA+"muralla6","road");
add_exit("sur", CALLEJONES+"callejon_L2","road");
}

