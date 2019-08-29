//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   jardin();    
   add_exit("oeste",CIUDAD"jardin_17.c","standard");   
   add_exit("sur",CIUDAD"jardin_15.c","standard");   
}
