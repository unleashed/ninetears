#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^GREEN%^Parque de recreo%^RESET%^");
   long_desc_recreo();




add_exit("oeste", PARQUES+"recreo2","road");
add_exit("norte", PARQUES+"recreo4","road");
add_exit("sur", PARQUES+"suleithel2","road");
   set_zone("recreo");

}


