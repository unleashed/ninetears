// Xerxes '02

#include "../../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^YELLOW%^Caseta de la Guardia%^RESET%^");
   set_long("Esta pequenya caseta, que se confunde facilmente con una letrina debido "
            "a la gran suciedad (cuya procedencia no deseas conocer) que la rodea, "
            "sirve de lugar de descanso a la Guardia Goblin que se encarga de la "
            "vigilancia del poblado.\n");
   set_light(80);

   add_exit("sur", POBLADO + "poblado5.c", "path");
      
   set_zone("ciudad_urghak");
}