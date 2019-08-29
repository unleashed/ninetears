/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("magenta");
   set_zone("caminosur");
   set_light(50);
   set_short("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "En camino gira a la derecha en el valle y se pierde en lo alto de una nueva colina, estas en "
   "un pequenyo valle lleno de arboles y por el que discurre un pequenyo riachuelo cargado de agua "
   "clara y fresca.\n\n");

add_clone(NPCS+"varios_camino_sur.c",random(2));

add_exit("sudoeste",CAMSUR+"cam34.c","standard");
add_exit("este",CAMSUR+"cam36.c","standard");

}