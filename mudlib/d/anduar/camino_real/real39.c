// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Desde aqui observas como el rio "
   "Urzabalgai desvia su ruta para dirigirse de norte a sur, cambiando "
   "totalmente su rumbo anterior.");
   add_exit("norte"   ,REAL"real40.c","road");
   add_exit("sur"     ,REAL"real38.c","road");
   set_light(65);
   crea_bichos();
}