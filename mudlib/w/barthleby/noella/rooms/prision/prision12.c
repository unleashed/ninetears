#include "/w/barthleby/path.h"

inherit PRISION"std_prision.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella. Acceso al bloque A%^RESET%^");
   long_desc_prision();




//add_clone(NPC+"guardia_gorband", 2);

add_exit("noroeste", PRISION+"bloque_A","corridor");
add_exit("noreste", PRISION+"prision11","corridor");
add_exit("sudoeste", PRISION+"prision13","corridor");

}

