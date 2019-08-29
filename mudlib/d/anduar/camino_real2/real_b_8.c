// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, hacia el sur se ve un arbol y mas al "
   "sur las colinas de Ostigurth, hacia el norte sigue hacia Dendara, "
   "y en las cercanias del camino hay una inmensa charca.\n");
   add_exit("norte",   REAL2+"real_b_9","plain");
   add_exit("sudeste", REAL2+"real_b_7","road");
   set_light(65);
   crea_bichos();
   add_item("charca","es una charca con unas aguas muy cristalinas");
}
