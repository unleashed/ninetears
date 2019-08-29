// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, por todos los laterales de la "
   "crecen plantas como queriendo recuperar este su antiguo hogar, pero los "
   "amplios sumideros impiden que llegen a la misma y que cualquier bicho "
   "salvaje ataque a algun viajero.\n");
   add_exit("noreste"   ,REAL+"real3.c","road");
   add_exit("oeste"     ,REAL+"real1.c","road");
   set_light(65);
   crea_bichos();
}