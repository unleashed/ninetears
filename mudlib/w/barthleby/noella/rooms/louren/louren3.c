#include "/w/barthleby/path.h"

inherit LOUREN"std_louren.c";


void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^GREEN%^Pueblo de L'Ouren%^RESET%^");
   long_desc_louren();



add_exit("norte",  BREIX+"breix8","road");
add_exit("sur",  LOUREN+"louren2","road");
}




