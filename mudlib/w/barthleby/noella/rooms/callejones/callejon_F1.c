#include "/w/barthleby/path.h"

inherit CALLEJONES"std_callejon.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Callej�n oscuro%^RESET%^");
   long_desc_callejones();



add_exit("noreste", CALLEJONES+"callejon_F2","road");
add_exit("este", CALLEJONES+"callejon_E","road");
add_exit("sudoeste", CALLE+"calle11","road");
}

