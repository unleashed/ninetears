#include "/w/barthleby/path.h"

inherit CALLEJONES"std_callejon.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Callej�n oscuro%^RESET%^");
   long_desc_callejones();



add_exit("sur", CALLEJONES+"callejon_J2","road");
add_exit("sudoeste", MURALLAS_NOELLA+"muralla19","road");
}

