// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Aqui observas unas rocas que marcan "
   "el principio del poblado de Eloras, cualquier persona que pase de las "
   "mismas y rompa la ley sera juzgado segun las leyes del poblado.");
   add_exit("noreste"   ,REAL"real45.c","road");
   add_exit("sur"     ,REAL"real43.c","road");
   set_light(65);
   crea_bichos();
}