// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, En el poblado de Eloras, a ambos "
   "lados de la calzada se elevan las viviendas de los habitantes de Eloras, "
   "sin gran lujo pero sin ser pobres,la Calzada al penetrar en las colinas "
   "empiezan a descender para llegar al nivel de las llanuras de Dendara.");
   add_exit("norte"   ,REAL"real52.c","road");
   add_exit("sur"     ,SENDA"p3.c","road");
   set_light(65);
   crea_bichos();
}
