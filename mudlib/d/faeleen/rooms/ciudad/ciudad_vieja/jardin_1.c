//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   jardin();
   day_clone(NPC+"artista.c",random(1)); 
   add_exit("norte",CIUDAD"jardin_0.c","standard");   
   add_exit("sur",CIUDAD"jardin_2.c","standard");   
}
