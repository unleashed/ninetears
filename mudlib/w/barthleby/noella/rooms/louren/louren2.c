#include "/w/barthleby/path.h"

inherit LOUREN"std_louren.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^GREEN%^Pueblo de L'Ouren%^RESET%^");
   long_desc_louren();



add_exit("oeste",  LOUREN+"louren1","road");
add_exit("norte",  LOUREN+"louren3","road");
}




