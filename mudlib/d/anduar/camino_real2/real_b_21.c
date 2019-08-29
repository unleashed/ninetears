// Aokromes, Septiembre de 1999
#include "../path.h"
inherit REAL+"afueras4.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la ciudad de Dendara, hacia el sur el camino se desvia al oeste "
   "para rodear un hermoso sauce lloron que sirve de refugio para muchas "
   "criaturas y al norte se desvia al este para unirse con la vieja ruta.\n");
   add_exit("norte",    REAL2+"real_b_22","road");
   add_exit("sudoeste", REAL2+"real_b_20","road");
   set_light(65);
   crea_bichos();
}