//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("oeste",CIUDAD"ext_sur_24.c","standard");
   add_exit("este",CIUDAD"ext_sur_26.c","standard");
}