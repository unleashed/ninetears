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

add_exit("este",       BRETHEM + "castros6.c","standard");
add_exit("sudoeste",   BRETHEM + "descub2.c","standard");



}
