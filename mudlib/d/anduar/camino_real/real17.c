// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, El camino sigue sorteando la "
   "gigantesca roca que parece ser de algun desconocido material, lastima que "
   "sea inrompible ya que seria una magnifica arma, o tambien una buena "
   "armadura pero restaria mucha movilidad");
   add_exit("noroeste"   ,REAL"real18.c","road");
   add_exit("southeast"     ,REAL"real16.c","road");
   set_light(65);
   crea_bichos();
}