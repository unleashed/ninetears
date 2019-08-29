/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("blue");
   set_zone("pasadizo");
   set_light(10);
   set_short("%^BOLD%^BLACK%^Pasadizo Subterraneo%^RESET%^");
   set_long("%^BOLD%^BLACK%^Pasadizo Subterraneo%^RESET%^\n\n"
   "Estas en una especie de pasadizo subterraneo, sobre ti esta una de las salidas del tunel, "
   "por lo que algo de luz te rodea, pero al fondo no ves mas que oscuridad. Es un lugar frio, humedo y tenebroso, "
   "al tocar las paredes notas como las raices de los arboles salen de la tierra como fuertes brazos, "
   "y puedes oir el lejano correteo de algun arrollo subterraneo.\n\n");

add_clone(NPCS+"varios_pasadizo_subterraneo.c",random(3));

add_exit("norte",SUBT+"pas38.c","standard");
add_exit("arriba",ZHYRKHOM+"min104.c","standard");

}