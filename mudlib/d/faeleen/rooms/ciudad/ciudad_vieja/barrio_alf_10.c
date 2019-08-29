//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_alf();
   add_exit("sudeste",CIUDAD"barrio_alf_15.c","standard");
   add_exit("norte",CIUDAD"barrio_alf_4.c","standard");
}
