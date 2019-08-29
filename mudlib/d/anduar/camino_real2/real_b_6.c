// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras3.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, hacia el sur se ven las colinas de "
   "Ostigurth, hacia el norte sigue hacia Dendara, en un lateral un arbol "
   "da sombra al viajero.\n");
   add_exit("norte", REAL2+"real_b_7","plain");
   add_exit("sur",   REAL2+"real_b_5","road");
   set_light(65);
   crea_bichos();
   add_item("arbol","es un sauce lloron, verdaderamente se tiene que dormir "
   "bien debajo");
}
