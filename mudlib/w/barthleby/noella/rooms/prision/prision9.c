#include "/w/barthleby/path.h"

inherit PRISION"std_prision.c";


void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella%^RESET%^");
   long_desc_prision();




//add_clone(NPC+"guardia_gorband", 2);

add_exit("noreste", PRISION+"prision8","corridor");
add_exit("sudoeste", PRISION+"prision10","corridor");

}

