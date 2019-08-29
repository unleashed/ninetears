//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_alf();
   add_clone(NPC+"ciudad_pobre.c",2); 
   add_exit("oeste",CIUDAD"barrio_alf_0.c","standard");
   add_exit("sur",CIUDAD"barrio_alf_3.c","standard");
}
