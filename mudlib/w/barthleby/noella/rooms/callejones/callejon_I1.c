#include "/w/barthleby/path.h"

inherit CALLEJONES"std_callejon.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Callej�n oscuro%^RESET%^");
   long_desc_callejones();



add_exit("oeste", MURALLAS_NOELLA+"muralla21","road");
add_exit("este", CALLEJONES+"callejon_I2","road");
}

