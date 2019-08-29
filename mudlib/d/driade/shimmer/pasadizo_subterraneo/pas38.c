/* By Shimmer */

#include "../path.h"

inherit "/std/underground";

void setup() {

   set_exit_color("blue");
   set_zone("pasadizo");
   set_light(10);
   set_short("%^BOLD%^BLACK%^Pasadizo Subterraneo%^RESET%^");
   set_long("%^BOLD%^BLACK%^Pasadizo Subterraneo%^RESET%^\n\n"
   "Estas en una especie de pasadizo subterraneo, aun puedes ver un poco dado que estas cerca de "
   "una de las salidas, pero al fondo no ves mas que oscuridad. Es un lugar frio, humedo y tenebroso, "
   "al tocar las paredes notas como las raices de los arboles salen de la tierra como fuertes brazos, "
   "y puedes oir el lejano correteo de algun arrollo subterraneo.\n\n");

add_clone(NPCS+"varios_pasadizo_subterraneo.c",random(3));

add_exit("norte",SUBT+"pas37.c","standard");
add_exit("sur",SUBT+"pas39.c","standard");

}