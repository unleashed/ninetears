/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("red");
   set_zone("almacen");
   set_light(40);
   set_short("%^BOLD%^BLACK%^Almacen de la Mina%^RESET%^");
   set_long("%^BOLD%^BLACK%^Almacen de la Mina%^RESET%^\n\n"
   "Esta es la entrada de las Minas de Zhyrkhom, estas en una habitacion amplia "
   "y bien iluminada, hay antorchas en la pared de toda la mina. Ante ti se abren "
   "una multitud de tuneles en todas direcciones, si uno se adentra mucho en la mina, "
   "es facil perderse en las tantas ramificaciones que tiene.\n\n");

add_clone(NPCS+"varios_almacen_mina_zhyrkhom.c",random(2));

add_exit("fuera",ZHYRKHOM+"min59.c","standard");
add_exit("norte",ZHYRKHOM+"alm18.c","standard");
add_exit("este",ZHYRKHOM+"alm2.c","standard");


}