#include "/w/barthleby/path.h"

inherit PRISION"std_prision.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella. Celda 8%^RESET%^");
   long_desc_bloque_B();



add_exit("sudoeste", PRISION+"bloque_B","corridor");
set_zone("bloque");

}

