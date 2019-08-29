//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_alf();
   add_clone(NPC+"ciudad_pobre.c",2); 
   add_exit("este",CIUDAD"barrio_alf_5.c","standard");
   add_exit("sur",CIUDAD"barrio_alf_10.c","standard");
   add_exit("sudoeste",CIUDAD"barrio_alf_9.c","standard");
}
