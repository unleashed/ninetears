// Sinister '99.

#include "../../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Torre Negra. Nivel 4.%^RESET%^");
   set_long("Una gigantesca estanteria se eleva hasta el altisimo techo, "
   "inmensos volumenes de magia de una edad incalculable, rodeados de runas de "
   "un poder sin igual, tan fuertes que serian capaces de matar a un dragon. "
   "En la parte superior del techo varias esferas giran sin parar, iluminando "
   "todas y cada unas de las estanterias. \n");
   add_exit("norte",TN4"tn_d_17","road");
   add_exit("este",TN4"tn_d_35","road");
   add_exit("sur",TN4"tn_d_19","road");
         
}
