// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Aqui la calzada se desvia "
   "bruscamente hacia el oeste para sortear un nuevo gran desnivel en el "
   "terrero que deja ver lo abajo que baja la gigantesca roca, tal vez "
   "intentaron desenterrarla entera pero no llegaron abajo y no taparon el "
   "pozo.");
   add_exit("oeste"   ,REAL"real19.c","road");
   add_exit("southeast"     ,REAL"real17.c","road");
   set_light(65);
   crea_bichos();
}