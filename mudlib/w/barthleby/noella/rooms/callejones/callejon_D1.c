#include "/w/barthleby/path.h"

inherit CALLEJONES"std_callejon.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Callej�n oscuro%^RESET%^");
   long_desc_callejones();



add_exit("oeste", MURALLAS_NOELLA+"muralla26","road");
add_exit("norte", CALLEJONES+"callejon_D2","road");
add_exit("este", PRINCIPALES+"plaza_del_tapal","road");
}

