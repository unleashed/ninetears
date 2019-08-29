//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_alf();
   add_clone(NPC+"ciudad_pobre.c",5); 
   add_exit("norte",CIUDAD"barrio_alf_9.c","standard");
   add_exit("pafuera","CIUDAD+/","standard");
}
