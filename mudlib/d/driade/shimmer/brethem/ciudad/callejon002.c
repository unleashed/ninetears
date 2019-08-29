/* By Shimmer */

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : Callejon del Viento%^RESET%^");
   long_desc_callejon();  

   crea_npcs_callejon();

add_exit("norte",       BRETHEM + "callejon001.c","standard");
add_exit("noroeste",    BRETHEM + "gen19.c","standard");
add_exit("este",        BRETHEM + "callejon003.c","standard");


}
