#include "/w/barthleby/path.h"

inherit PRISION"std_prision.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella. Celda 3%^RESET%^");
   long_desc_bloque_A();



add_exit("oeste", PRISION+"bloque_A","corridor");
set_zone("bloque");

}

