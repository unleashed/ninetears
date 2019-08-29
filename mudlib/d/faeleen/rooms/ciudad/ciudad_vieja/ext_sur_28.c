//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("sudoeste",CIUDAD"ext_sur_27.c","standard");
   add_exit("noreste",CIUDAD"ext_este_0.c","standard");
}