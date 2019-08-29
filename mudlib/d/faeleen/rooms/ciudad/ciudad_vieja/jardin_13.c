//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   jardin();    
   add_exit("norte",CIUDAD"jardin_14.c","standard");   
   add_exit("sur",CIUDAD"jardin_12.c","standard");   
}
