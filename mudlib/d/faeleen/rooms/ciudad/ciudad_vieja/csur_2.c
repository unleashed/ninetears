//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   csur();
   add_exit("norte",CIUDAD"csur_1.c","standard");
   add_exit("sur",CIUDAD"ext_sur_15.c","standard");
}