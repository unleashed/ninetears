#include "/w/barthleby/path.h"

inherit CLOACAS"std_cloacas.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^%^BLACK%^Catacumbas de Noella%^RESET%^");
   long_desc_catacumbas();





//add_clone(NPC+"rata_gigante", 2);

add_exit("noreste", CLOACAS+"catacumbas2","corridor");
set_zone("catacumbas");

}


/*Falta la salida hacia la catedral que saldra haciendo o moviendo algo que tambien falta*/
