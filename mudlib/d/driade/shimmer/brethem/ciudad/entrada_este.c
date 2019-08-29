/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("red");
   set_short("%^BOLD%^RED%^Puerta Este de %^YELLOW%^Brethem%^RESET%^");
   set_long("%^BOLD%^RED%^Puerta Este de Brethem%^RESET%^\n\n"
            "Estas en la entrada este de la ciudad de Brethem, un enorme arco en la roca de la muralla sirve de puerta"
            "de entrada a la ciudad, en la cima del arco, vigilando la entrada se eleva una gran gargola de piedra en "
            "postura amenazante.\n\n");

     

   add_exit("norte",        BRETHEM + "muralla.c","standard");
   add_exit("sur",          BRETHEM + "muralla.c","standard");
   add_exit("este",         BRETHEM + "nuse.c","standard");
   add_exit("oeste",        BRETHEM + "av_este19.c","standard");
   modify_exit("oeste",({"function","do_entrada"}));

   add_clone(BRETHEM + "npcs/guardia_entrada.c", 1);

}

int do_entrada()
{

   write("Pasas bajo el gran arco de la muralla hacia el interior de la ciudad.\n\n");

return 1;
}

