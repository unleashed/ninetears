// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, hacia el sur se ven las colinas de "
   "Ostigurth, hacia el noreste sigue hacia Dendara, en los margenes de la "
   "calzada se puede ver un sumidero, el cual esta destinado a que la misma "
   "no se embarre.\n");
   add_exit("norte",    REAL2+"real_b_6","plain");
   add_exit("sudoeste", REAL2+"real_b_4","road");
   set_light(65);
   crea_bichos();
}
