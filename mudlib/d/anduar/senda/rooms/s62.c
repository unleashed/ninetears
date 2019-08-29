#include "../../path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en una senda en las llanuras de "+LLANURAS+"."
   " Al norte la senda sigue y al horizonte "
   "se ve una gran fortaleza. Parece que este camino lleva hacia alli. Al "
   "sur cerca de aqui estan las colinas de "+COLINAS+"."
   "Por lo que parece esta senda es de uso comun, ya que el terreno sobre "
   "el cual anda la gente esta totalmente falto de vegetacion. Ves unas "
   "rocas al este.\n");
   add_exit("sur", SENDA+"s61", "plain");
   add_exit("southwest", REAL+"real57", "plain");
   add_exit("noreste", SENDA+"s63", "plain");
   TRAMO3->comun(TO);
   TRAMO3->npcs(2, TO);
   
   add_item(({"roca","rocas"}),"Unas pesadas rocas que ocultan una cueva.\n");
   add_item("cueva","Ves una cueva oculta a los ojos de la gente detras de "
   "unas rocas.\n");
            
   add_exit("cueva", "/d/anduar/anduar/quest/cueva.c","hidden");
   
}
