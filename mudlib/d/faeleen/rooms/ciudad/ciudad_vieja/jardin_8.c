//Ciudad de Faeleen, Flangerant 2002

#include "../../path.h"
inherit CIUDAD+"ciudad.c";

void setup()
{
   jardin();    
   day_clone(NPC+"artista.c",random(1));
   add_exit("oeste",CIUDAD"jardin_7.c","standard");   
   add_exit("este",CIUDAD"jardin_9.c","standard");   
}
