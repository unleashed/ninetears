/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("magenta");
   set_zone("caminosur");
   set_light(50);
   set_short("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "Estas en el camino que une el Harak-Din con la ciudad de Zhyrkh, es un camino amplio y "
   "peligroso ya que abundan seres de de razas malignas por esta zona. El camino transcurre "
   "sobre colinas y valles ya que te encuentras aun en una zona elevada cercana a las montanyas.\n\n");

add_clone(NPCS+"varios_camino_sur.c",random(2));

add_exit("arriba",HARAK+"lad102.c","standard");
add_exit("este",CAMSUR+"cam28.c","standard");

}