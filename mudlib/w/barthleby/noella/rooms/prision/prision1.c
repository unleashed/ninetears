#include "/w/barthleby/path.h"

inherit PRISION"std_prision.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella%^RESET%^");
   long_desc_prision();




//add_clone(NPC+"guardia_gorband", 3);

add_exit("norte", CAMINO_NORDESTE+"camino_nordeste2","road");
add_exit("noreste", PRISION+"prision2","corridor");
add_exit("sur", PRISION+"prision14","corridor");

}

