//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("sudoeste",CIUDAD"ext_sur_4.c","standard");
   add_exit("este",CIUDAD"ext_sur_6.c","standard");
   add_exit("arriba",CIUDAD"msur_5.c","standard");
}