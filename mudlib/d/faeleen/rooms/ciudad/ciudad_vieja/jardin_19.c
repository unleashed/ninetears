//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   jardin();    
   day_clone(NPC+"ciudad.c",random(2));
   add_exit("oeste",CIUDAD"jardin_0.c","standard");   
   add_exit("este",CIUDAD"jardin_18.c","standard");   
}
