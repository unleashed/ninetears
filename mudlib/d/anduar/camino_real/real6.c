// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, al llegar a este lugar la brecha "
   "parece haber obligado al constructor a seguir hacia el noreste para "
   "llegar al fin de la misma, por suerte parece ser que no esta lejos.\n");
   add_exit("noreste"   ,REAL+"real7.c","road");
   add_exit("southwest"  ,REAL+"real5.c","road");
   set_light(65);
   crea_bichos();
}