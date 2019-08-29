//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   jardin();
   day_clone(NPC+"ciudad.c",random(1)); 
   add_exit("norte",CIUDAD"jardin_1.c","standard");   
   add_exit("sur",CIUDAD"jardin_3.c","standard");   
}
