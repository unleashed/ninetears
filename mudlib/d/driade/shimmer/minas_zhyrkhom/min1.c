/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("yellow");
   set_zone("mina");
   set_light(30);
   set_short("%^BOLD%^BLACK%^Minas de %^BOLD%^YELLOW%^Zhyrkhom%^RESET%^");
   set_long("%^BOLD%^BLACK%^Minas de %^BOLD%^YELLOW%^Zhyrkhom%^RESET%^\n\n"
   "Esta es la entrada de las Minas de Zhyrkhom, estas en una habitacion amplia "
   "y bien iluminada, hay antorchas en la pared de toda la mina. Ante ti se abren "
   "una multitud de tuneles en todas direcciones, si uno se adentra mucho en la mina, "
   "es facil perderse en las tantas ramificaciones que tiene.\n\n");

add_clone(NPCS+"varios_mina_zhyrkhom.c",random(2));

add_exit("fuera",ZHYRKHOM+"camino_minas8.c","standard");
add_exit("oeste",ZHYRKHOM+"min59.c","standard");

}