//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   jardin();
   day_clone(NPC+"artista.c",random(3)); 
   add_exit("norte",CIUDAD"jardin_4.c","standard");   
   add_exit("sur",CIUDAD"jardin_6.c","standard");   
}
