// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, la Calzada sigue descendiendo para "
   "salvar el desnivel existente entre las llanuras de Anduar y las de "
   "Dendara, mientras el tunel sigue bajando, la luz disminuye.");
   add_exit("northeast"   ,REAL"real57.c","road");
   add_exit("southwest"   ,REAL"real55.c","road");
   set_light(45);
   crea_bichos();
}
