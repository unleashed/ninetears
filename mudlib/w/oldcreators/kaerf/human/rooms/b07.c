#include "path.h"
inherit HAVMAND+"beach.c";

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsla de Havmand : Playa\n\n"
    "Estas en una playa muy pequenya, la arena es blanca y finisima, "
    "parece un sitio muy tranquilo. Ves jungla al este y al sur, mientras "
    "la playa continua al oeste. Suaves olas lamen la orilla con blanca espuma. "
    " Los restos de una fogata en la arena indican, sin duda, que alguien "
    "ha pasado un tiempo aqui."
    "\n\n");
    add_item("fuego","Rocas ennegrecidas hacen un circulo donde hay cenizas, "
    "restos del fuego usado para cocinar o calentarse alguien.\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"b06.c","path");
    add_exit("sur",HAVMAND+"j03.c","path");

    ::init();
}
