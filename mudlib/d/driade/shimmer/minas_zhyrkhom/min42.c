/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("yellow");
   set_zone("mina");
   set_light(30);
   set_short("%^BOLD%^BLACK%^Minas de %^BOLD%^YELLOW%^Zhyrkhom%^RESET%^");
   set_long("%^BOLD%^BLACK%^Minas de %^BOLD%^YELLOW%^Zhyrkhom%^RESET%^\n\n"
   "Estas en uno de los tuneles de las Minas de Zhyrkhom, un lugar humedo y frio bajo "
   "tierra, el tunel es estrecho y numerosas vigas soportan el peso del techo, los mineros"
   "no paran de extraer minerales y transportarlo en las carretillas.\n\n");

add_clone(NPCS+"varios_mina_zhyrkhom.c",random(2));
add_clone(NPCS+"minero_mina_zhyrkhom.c",random(2));

add_exit("oeste",ZHYRKHOM+"min99.c","standard");
add_exit("sur",ZHYRKHOM+"min43.c","standard");
add_exit("noreste",ZHYRKHOM+"min41.c","standard");

}