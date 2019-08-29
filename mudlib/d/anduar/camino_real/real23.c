// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Con el rio en las inmediaciones "
   "empiezas a oir el ruido de la corriente, arrastrando miles de litros de "
   "agua a una velocidad tal que cualquier embarcacion quedaria destrozada, "
   "mientras observas que el puente parece estar echo de la misma roca "
   "situada unos metros hacia el sur, pero la misma parece estar intacta, "
   "entonces de donde salio la roca del puente?");
   add_exit("norte"   ,REAL"real24.c","road");
   add_exit("sur"     ,REAL"real22.c","road");
   set_light(65);
   crea_bichos();
}