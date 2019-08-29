#include "path.h"
inherit HAVMAND+"beach.c";
object rodion;
void setup()
{

   set_light(LIGHT);
    set_long("\nIsla de Havmand : Playa\n\n"
    "   Esta la parte mas septentrional de la isla. La blanca arena se "
    "extiende hacia el sur, mientras al norte hay rocas. La pureza del "
    "mar azul resulta muy tentadora, pero la vision de unas aletas cortando "
    "el agua te hace deshechar de la idea de nadar."
    "\n\n");
    add_item("rocas","Cortantes rocas volcanicas, deberas tener cuidado "
    "si quieres explorar por alli.\n");
    add_item(({"aleta","aletas"}),"Oscuras aletas se desplazan en circulos "
    "a poca distancia de la orilla, solo se te ocurre que pertenecen a algun "
    "tipo de criatura marina, probablemente carnivora... Realmente no te "
    "apetece examinarla mas de cerca.\n");

   add_clone(CHARS+"rodion",1);
}
void init()
{
    add_exit("norte",HAVMAND+"r04.c","path");
    add_exit("sur",HAVMAND+"b02.c","path");
    add_exit("oeste",HAVMAND+"j17.c","path");

    ::init();
}
void reset()
{
   if(!rodion)
{
      rodion = clone_object(CHARS+"rodion");
   rodion->move(this_object());
   }
}
