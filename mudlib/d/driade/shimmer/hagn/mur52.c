/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("red");
   set_light(50);
   set_short("Muralla Oeste del Reino de %^BOLD%^%^CYAN%^Hagn %^RESET%^");
   set_long("Muralla Oeste del Reino de %^BOLD%^%^CYAN%^Hagn %^RESET%^\n\nA tu lado se erige una inmensa muralla que recorre serpenteando la llanura hasta donde "
   "te alcanza la vista siempre al lado del camino en el que te encuentras. Al acercarte a la muralla "
   "puedes contemplar el material rocoso, negro y frio, si lo miras fijamente puedes observer tu propio "
   "reflejo deformado sobre la rugosa superficie, el mundo parece distinto al verse reflejado en tan hostil "
   "material, un mundo frio y asolado, quizas como el que se encuentra tras la propia muralla\n\n");

add_clone(NPCS+"varios_humanos.c",1);

add_exit("sur",HAGN+"mur53.c","standard");
add_exit("norte",HAGN+"mur51.c","standard");

}