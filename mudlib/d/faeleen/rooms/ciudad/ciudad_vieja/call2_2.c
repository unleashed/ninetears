//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   pobre();
   add_exit("noroeste",CIUDAD"call2_0.c","standard");
   add_exit("noreste",CIUDAD"call2_1.c","standard");
   add_exit("este",CIUDAD"call2_3.c","standard");
   add_exit("sudoeste",CIUDAD"call2_4.c","standard");      
}