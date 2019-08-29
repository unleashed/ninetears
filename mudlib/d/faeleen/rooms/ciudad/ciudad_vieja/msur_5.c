//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   msur();
   add_exit("sudoeste",CIUDAD"msur_4.c","standard");
   add_exit("este",CIUDAD"msur_6.c","standard");
   add_exit("abajo",CIUDAD"ext_sur_5.c","standard");
}