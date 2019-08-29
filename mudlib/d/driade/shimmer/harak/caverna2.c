/* By Shimmer */

#include "../path.h"

inherit "/std/underground";


void setup() {

   set_exit_color("blue");
   set_zone("caverna");
   set_light(40);
   set_short("%^BOLD%^RED%^Caverna del %^BOLD%^%^BLACK%^Harak-Din%^RESET%^");
   set_long("%^BOLD%^RED%^Caverna del %^BOLD%^%^BLACK%^Harak-Din%^RESET%^\n\n");



add_exit("oeste",    HARAK+"caverna1.c","standard");
add_exit("noreste",  HARAK+"caverna3.c","standard");

}