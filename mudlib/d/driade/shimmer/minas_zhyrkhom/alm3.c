/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("red");
   set_zone("almacen");
   set_light(40);
   set_short("%^BOLD%^BLACK%^Almacen de la Mina%^RESET%^");
   set_long("%^BOLD%^BLACK%^Almacen de la Mina%^RESET%^\n\n"
   "Las estanterias del almacen se encuentran repletas de utensilios, ves a los mineros "
   "ajetreados ordenandolo todo y preparandose para un arduo dia de trabajo en la mina, "
   "estan tan ocupados que apenas notan tu presencia.\n\n");

add_clone(NPCS+"varios_almacen_mina_zhyrkhom.c",random(1));

add_exit("oeste",ZHYRKHOM+"alm2.c","standard");
add_exit("norte",ZHYRKHOM+"alm16.c","standard");
add_exit("este",ZHYRKHOM+"alm4.c","standard");


}