//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   jardin();    
   add_exit("norte",CIUDAD"jardin_5.c","standard");   
   add_exit("este",CIUDAD"jardin_7.c","standard");
   add_exit("sur",CIUDAD"csur_0.c","standard");
   add_exit("oeste",CIUDAD"call_lib_4.c","standard");   
}
