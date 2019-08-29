// Xerxes '02

#include "../../path.h"

inherit "/std/outside";

void setup()
{
   set_short("Poblado de %^GREEN%^Urghak%^RESET%^");
   set_long("El poblado de Urghak fue levantado antanyo por los ancestros de los"
            "goblins, en la colina con el mismo nombre. Consiste en un monton de "
            "chozas y cabanyas, que se agrupan en distintos barrios gobernados por "
            "distintas tribus. En lo mas alto de la colina se alza la cabanya del "
            "cacique de la ciudad.\n");
   set_light(80);

   add_exit("norte", POBLADO + "poblado28.c", "path");
   add_exit("este", POBLADO + "poblado30.c", "path");
   add_exit("sudoeste", POBLADO + "poblado32.c", "path");
      
   set_zone("ciudad_urghak");
}