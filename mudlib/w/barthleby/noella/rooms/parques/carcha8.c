#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^GREEN%^Parques de Carchan�m%^RESET%^");
   long_desc_carchanim();



add_exit("oeste", PARQUES+"carcha7","road");
add_exit("norte", PARQUES+"carcha6","road");
add_exit("sur", PARQUES+"carcha10","road");

}
