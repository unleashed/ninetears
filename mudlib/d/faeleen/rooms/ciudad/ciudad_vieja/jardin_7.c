//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   jardin();    
   add_exit("oeste",CIUDAD"jardin_6.c","standard");   
   add_exit("este",CIUDAD"jardin_8.c","standard");   
}
