#include "/w/barthleby/path.h"

inherit PRISION"std_prision.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Gorband Ab-Trabasir, prisi�n de Noella%^RESET%^");
   long_desc_prision();




//add_clone(NPC+"guardia_gorband", 4);

add_exit("noreste", PRISION+"prision9","corridor");
add_exit("sudoeste", PRISION+"prision11","corridor");

}

/*aqui va el armario donde se guarda el equipo de cada preso que solo podra coger cada preso o ser 
devuelto*/
