// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, hacia el sur se ve un arbol y mas al "
   "sur las colinas de Ostigurth, hacia el noreste sigue hacia Dendara, "
   "mientras una rana croa en una charca cercana.\n");
   add_exit("noroeste", REAL2+"real_b_8","plain");
   add_exit("sur",     REAL2+"real_b_6","road");
   set_light(65);
   crea_bichos();
   add_item("rana","es una rana que no para de croar");
   add_item("charca","es una charca en la cual una rana no para de croar");
}
