#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^GREEN%^Parques de Carchaním%^RESET%^");
   long_desc_carchanim();



//add_clone(NPC+"crea_ciudadanos", 2);

add_exit("norte", PARQUES+"carcha7","road");
add_exit("este", PARQUES+"carcha10","road");
add_exit("sudeste", CALLEJONES+"callejon_J5","road");

}
