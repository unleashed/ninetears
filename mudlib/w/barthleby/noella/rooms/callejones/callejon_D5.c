#include "/w/barthleby/path.h"

inherit CALLEJONES"std_callejon.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Callej�n oscuro%^RESET%^");
   long_desc_callejones();



add_exit("oeste", MURALLAS_NOELLA+"muralla22","road");
add_exit("este", CALLEJONES+"callejon_H","road");
add_exit("sur", CALLEJONES+"callejon_D4","road");
}

