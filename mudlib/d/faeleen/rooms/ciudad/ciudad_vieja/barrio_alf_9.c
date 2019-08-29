//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_alf();
   add_exit("norte",CIUDAD"barrio_alf_3.c","standard");
   add_exit("noreste",CIUDAD"barrio_alf_4.c","standard");
   add_exit("sur",CIUDAD"barrio_alf_14.c","standard");
}
