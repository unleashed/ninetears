/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : Callejon de union%^RESET%^");
   long_desc_callejon();

   crea_npcs_callejon();

add_exit("norte",      BRETHEM + "mied9.c","standard");
add_exit("sudoeste",   BRETHEM + "plaza_central2.c","standard");
add_exit("este",       BRETHEM + "mied8.c","standard");


}
