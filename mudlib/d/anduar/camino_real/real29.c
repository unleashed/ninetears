// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Tras salir del asombro observas el "
   "puente de 15 metros de anchura y 30 de longitud, muy a lo lejos al oeste "
   "observas como el cauce del rio Urzabalgai, se desvia hacia el lejano "
   "norte, mientras que hacia el este, el rio se desvia para entrar en los "
   "desfiladeros del bosque de Orgoth, antes de llegar al pantano de Zulk.");
   add_exit("noroeste"   ,REAL"real30.c","road");
   add_exit("sur"     ,REAL"real28.c","road");
   set_light(65);
   crea_bichos();
}
