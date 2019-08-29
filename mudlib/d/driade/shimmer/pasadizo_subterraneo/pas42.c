/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("blue");
   set_zone("pasadizo");
   set_light(10);
   set_short("%^BOLD%^BLACK%^Pasadizo Subterraneo%^RESET%^");
   set_long("%^BOLD%^BLACK%^Pasadizo Subterraneo%^RESET%^\n\n"
   "Estas en una especie de pasadizo subterraneo, a oscuras, apenas puedes ver mas alla "
   "de tus narices, es un lugar frio, humedo y tenebroso, al tocar las paredes notas como las "
   "raices de los arboles salen de la tierra como fuertes brazos, y puedes oir el lejano correteo "
   "de algun arrollo subterraneo.\n\n");

add_clone(NPCS+"varios_pasadizo_subterraneo.c",random(3));

add_exit("noroeste",SUBT+"pas41.c","standard");
add_exit("sudeste",SUBT+"pas43.c","standard");


}