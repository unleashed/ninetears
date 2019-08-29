/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {
   set_zone("harak");
   set_exit_color("cyan");
   set_light(50);
   set_short("Camino hacia %^BOLD%^%^BLACK%^Harak-Din%^RESET%^");
   set_long("Camino hacia %^BOLD%^%^BLACK%^Harak-Din%^RESET%^\n\n"
   "Estas en el camino de Harak-Din, la gran montanya nevada que puedes ver al sur, "
   "al oeste el camino discurre atraves de una arboleda, y denuevo hacia el sur el "
   "camino comienza a hacerse cada vez mas empinado y tortuoso, y puedes ver pequenyos "
   "animales correteando de aqui para alla por todos lados.\n\n");

add_clone(NPCS+"varios_camino_harak.c",1);

add_exit("noreste",CAMHAGN+"cam17.c","standard");
add_exit("sur",CAMHAGN+"cam19.c","standard");
add_exit("oeste",BOSQUEHARAK+"camino1.c","standard");

}