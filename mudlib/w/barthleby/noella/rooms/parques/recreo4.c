#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^GREEN%^Parque de recreo%^RESET%^");
   long_desc_recreo();




add_exit("oeste", PARQUES+"recreo1","road");
add_exit("sur", PARQUES+"recreo3","road");
   set_zone("recreo");

}


