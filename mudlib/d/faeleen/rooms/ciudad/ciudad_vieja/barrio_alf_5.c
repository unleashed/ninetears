//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   barrio_alf();
   add_exit("oeste",CIUDAD"barrio_alf_4.c","standard");
   add_exit("norte",CIUDAD"barrio_alf_2.c","standard");
   add_exit("este",CIUDAD"barrio_alf_6.c","standard");
}
