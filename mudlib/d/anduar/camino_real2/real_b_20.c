// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, estas a la sombra de un gigantesco sauce "
   "lloron, su sombra es de agradecer para muchas criaturas ya que el largo "
"trayecto de Anduar a Dendara es casi en su totalidad bajo un sol abrasador "
   ".\n");
   add_exit("noreste",   REAL2+"real_b_21","road");
   add_exit("sudeste",   REAL2+"real_b_19","road");
   set_light(45);
   add_item("sauce","Es un inmenso sauce lloron que da una agradable sombra");
   crea_bichos();
}