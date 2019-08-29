/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("cyan");
   set_zone("caminominas");
   set_light(50);
   set_short("%^BOLD%^YELLOW%^Camino a Minas Zhyrkhom%^RESET%^");
   set_long("%^BOLD%^YELLOW%^Camino a Minas Zhyrkhom%^RESET%^\n\n"
   "Estas en un camino estrecho y empinado que parte del camino sur a Zhyrkh, "
   "rodeando y subiendo por la ladera de una pequenya montanya cubierta de grutas, las minas "
   "de Zhyrkhom, el camino se dirige hacia hacia una pequenya meseta situada en la mitad de la "
   "montanya.\n\n");

add_clone(NPCS+"minero_mina_zhyrkhom.c",random(1));

add_exit("norte",ZHYRKHOM+"camino_minas3.c","standard");
add_exit("sudeste",ZHYRKHOM+"camino_minas1.c","standard");

}