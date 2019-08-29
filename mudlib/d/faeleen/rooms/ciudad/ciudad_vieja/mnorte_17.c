//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   mnorte();
   add_exit("este",CIUDAD"mnorte_18.c","standard");
   add_exit("sudoeste",CIUDAD"moeste_0.c","standard");
}
