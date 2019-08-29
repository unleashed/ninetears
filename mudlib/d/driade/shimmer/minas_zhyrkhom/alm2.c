/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("red");
   set_zone("almacen");
   set_light(40);
   set_short("%^BOLD%^BLACK%^Almacen de la Mina%^RESET%^");
   set_long("%^BOLD%^BLACK%^Almacen de la Mina%^RESET%^\n\n"
   "El almacen de la mina es un lugar bastante iluminado, puedes ver trastos por todos "
   "lados, picos, palas, carretillas y demas utiles de los mineros, aqui se guarda todo "
   "cuanto se utiliza en la mina.\n\n");

add_clone(NPCS+"varios_almacen_mina_zhyrkhom.c",random(1));

add_exit("oeste",ZHYRKHOM+"alm1.c","standard");
add_exit("norte",ZHYRKHOM+"alm17.c","standard");
add_exit("este",ZHYRKHOM+"alm3.c","standard");


}