// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, hacia el sur se ven las colinas de "
   "Ostigurth, mientras hacia el norte sigue hacia Dendara, hacia el sudoeste "
   "observas la altigua ruta dirigiendose hacia el este.\n");
    add_exit("noroeste", REAL2+"real_b_12","road");
   add_exit("sur",      REAL2+"real_b_10","road");
   add_exit("este",     CAMINO+"s88","plain");
   add_exit("sudoeste", CAMINO+"s90","plain");
   set_light(65);
   crea_bichos();
}
