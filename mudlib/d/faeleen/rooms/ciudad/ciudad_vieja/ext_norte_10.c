//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("este",CIUDAD"ext_norte_9.c","standard");
   add_exit("oeste",CIUDAD"ext_norte_11.c","standard");
}