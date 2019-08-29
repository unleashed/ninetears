//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_alf();
   add_clone(NPC+"ciudad_pobre.c",1); 
   add_exit("norte",CIUDAD"barrio_alf_1.c","standard");
   add_exit("sur",CIUDAD"barrio_alf_9.c","standard");
   add_exit("sudoeste",CIUDAD"barrio_alf_8.c","standard");
}
