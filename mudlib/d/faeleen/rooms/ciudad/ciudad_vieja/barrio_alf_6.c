//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_alf();
   add_clone(NPC+"ciudad_pobre.c",4); 
   add_exit("oeste",CIUDAD"barrio_alf_5.c","standard");
   add_exit("sudeste",CIUDAD"barrio_alf_11.c","standard");
}
