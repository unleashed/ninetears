/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : Calle de la Biblioteca%^RESET%^");
   long_desc_callejon();

   add_clone(BRETHEM+"npcs/guardia",1);

add_exit("norte",      BRETHEM + "gen12.c","standard");
add_exit("sudeste",    BRETHEM + "mar11.c","standard");
add_exit("dentro",     BRETHEM + "biblioteca1.c","standard");


}
