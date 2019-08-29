//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   moeste();
   add_exit("noreste",CIUDAD"moeste_0.c","standard");
   add_exit("sudoeste",CIUDAD"moeste_2.c","standard");
}