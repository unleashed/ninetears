/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("blue");
   set_zone("pasadizo");
   set_light(10);
   set_short("%^BOLD%^BLACK%^Pasadizo Subterraneo%^RESET%^");
   set_long("%^BOLD%^BLACK%^Pasadizo Subterraneo%^RESET%^\n\n"
   "Estas en una especie de pasadizo subterraneo, casi a oscuras, puedes ver algo debido a "
   "unas extranyas rocas de las paredes que emiten una tenue y debil luz, suficiente para "
   "ver donde pisas y poco mas. Al fondo y detras tuya no hay mas que oscuridad.\n\n");

add_clone(NPCS+"varios_pasadizo_subterraneo.c",random(3));

add_exit("norte",SUBT+"pas43.c","standard");
add_exit("sudeste",SUBT+"pas45.c","standard");


}