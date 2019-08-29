// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, la Calzada llega a un cruce, en el "
   "cual, hacia el sur se diriges a las colinas de Ostigurth, hacia el "
   "suroeste se interna por un tunel que pasa por debajo de Ostigurth, y "
   "hacia el noreste se dirige hacia dendara. Ves unas rocas al este.\n");
   add_exit("sur", SENDA+"s61", "plain");
   add_exit("southwest", REAL+"real57", "plain");
 add_exit("noreste", REAL2+"real_b_2", "plain");
   set_light(65);
   crea_bichos();
   add_item(({"roca","rocas"}),"Unas pesadas rocas que ocultan una cueva.\n");
   add_item("cueva","Ves una cueva oculta a los ojos de la gente detras de "
   "unas rocas.\n");
            
   add_exit("cueva", "/d/anduar/anduar/quest/cueva.c","hidden");
}
