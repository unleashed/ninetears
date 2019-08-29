//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   jardin();    
   add_exit("oeste",CIUDAD"jardin_18.c","standard");   
   add_exit("este",CIUDAD"jardin_16.c","standard");   
}
