#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas al pie de las colinas de "+COLINAS+"."
   " La montanya no es excesivamente alta, pero su pendiente "
   "es bastante pronunciada. Al norte continua la senda y al horizonte "
   "se ve una gran fortaleza. Parece que este camino lleva hacia alli. "
   "Por lo que parece esta senda es de uso comun, ya que el terreno sobre "
   "el cual anda la gente esta totalmente falto de vegetacion.\n");
   add_exit("sudoeste", SENDA+"s60", "plain");
add_exit("norte"   ,REAL2"real_b_1.c","road");
   TRAMO3->comun(TO);
   TRAMO3->npcs(2, TO);
}
