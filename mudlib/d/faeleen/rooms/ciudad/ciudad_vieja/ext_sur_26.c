//Ciudad de Faeleen, Flangerant 2002

// inherit "/std/ciudad.c";
#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   exterior();
   add_exit("oeste",CIUDAD"ext_sur_25.c","standard");
   add_exit("noreste",CIUDAD"ext_sur_27.c","standard");
   add_exit("arriba",CIUDAD"msur_17.c","standard");
}