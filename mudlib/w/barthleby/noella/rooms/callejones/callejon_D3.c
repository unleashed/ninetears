#include "/w/barthleby/path.h"

inherit CALLEJONES"std_callejon.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Callej�n oscuro%^RESET%^");
   long_desc_callejones();



add_exit("norte", CALLEJONES+"callejon_D4","road");
add_exit("este", CALLE+"calle10","road");
add_exit("sur", CALLEJONES+"callejon_D2","road");
add_exit("dentro", PRINCIPALES+"orrosa.c","road");
}

