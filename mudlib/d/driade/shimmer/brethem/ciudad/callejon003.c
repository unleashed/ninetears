/* By Shimmer */

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : Callejon del Viento%^RESET%^");
   long_desc_callejon();  

   crea_npcs_callejon();

add_exit("oeste",    BRETHEM + "callejon002.c","standard");
add_exit("este",     BRETHEM + "plaza_eleisson4.c","standard");

}
