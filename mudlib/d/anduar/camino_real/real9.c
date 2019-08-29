// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, la carretera por fin parece enfilar "
   "hacia el norte, tras haber esquivado la grieta y vuelve a tener unos "
   "grandes sumideros para evacuar el agua.");
   add_exit("norte"   ,REAL"real10.c","road");
   add_exit("southwest"     ,REAL"real8.c","road");
add_exit("arriba",REAL"torre1.c","door");
   set_light(65);
   crea_bichos();
}
