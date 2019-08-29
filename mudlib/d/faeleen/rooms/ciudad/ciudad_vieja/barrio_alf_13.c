//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_alf();
   add_exit("norte",CIUDAD"barrio_alf_8.c","standard");
   add_exit("pafuera","CIUDAD+/","standard");
}
