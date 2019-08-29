/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {
   set_zome("caminohagn");
   set_exit_color("white");
   set_light(50);
   set_short("Camino hacia %^BOLD%^%^CYAN%^Hagn%^RESET%^");
   set_long("Camino hacia %^BOLD%^%^CYAN%^Hagn%^RESET%^ : Cerca de la Muralla.\n\n"
   "El tortuoso camino por el que transitas esta lleno de restos de armas destrozadas y "
   "armaduras oxidadas por le paso del tiempo, ante ti la gran muralla se va haciendo "
   "cada vez mas grande e imponente, el olor comienza a ser insoportable, calandote en lo "
   "mas hondo de tu cuerpo como si estubiese intentando avisarte de los peligros que te "
   "esperan mas alla de sus muros.\n\n");

add_clone(NPCS+"varios_humanos.c",3);

add_exit("norte",CAMHAGN+"cam7.c","standard");
add_exit("sur",CAMHAGN+"cam9.c","standard");

}