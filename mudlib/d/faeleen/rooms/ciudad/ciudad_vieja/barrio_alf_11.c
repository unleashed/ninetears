//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_alf();
   add_clone(NPC+"ciudad_pobre.c",1); 
   add_exit("noroeste",CIUDAD"barrio_alf_6.c","standard");
   add_exit("este",CIUDAD"barrio_alf_12.c","standard");
   add_exit("sur",CIUDAD"barrio_alf_16.c","standard");
}
