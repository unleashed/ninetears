#include "/w/barthleby/path.h"

inherit PRISION"std_prision.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella. Celda 2%^RESET%^");
   long_desc_bloque_A();



add_exit("norte", PRISION+"bloque_A","corridor");
set_zone("bloque");

}

