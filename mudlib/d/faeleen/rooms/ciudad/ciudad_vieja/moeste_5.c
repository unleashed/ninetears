//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   moeste();
   add_exit("norte",CIUDAD"moeste_4.c","standard");
   add_exit("sur",CIUDAD"moeste_6.c","standard");
}