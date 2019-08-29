/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("cyan");
   set_zone("caminominas");
   set_light(50);
   set_short("%^BOLD%^YELLOW%^Camino a Minas Zhyrkhom%^RESET%^");
   set_long("%^BOLD%^YELLOW%^Camino a Minas Zhyrkhom%^RESET%^\n\n"
   "Te encuentras en la ladera de la montanya, a medio camino de la entrada principal de las "
   "minas, desde aqui puedes ver como los mineros y los exclavos realizan su trabajo, picando las "
   "pocas piedras que quedan en el exterior de la montanya y transportando el mineral en carretillas.\n\n");

add_clone(NPCS+"minero_mina_zhyrkhom.c",random(1));

add_exit("oeste",ZHYRKHOM+"camino_minas7.c","standard");
add_exit("sudoeste",ZHYRKHOM+"camino_minas5.c","standard");

}