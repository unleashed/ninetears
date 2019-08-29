// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Paris%^RESET%^");
   set_long("Estas en la ancestral ciudad de anduar a ambos lados de la "
   "calzada observas un grupo de casas echas de piedra en la parte delantera "
   "un haya decora el jardin, en el cual un azor esta posado en una rama "
   "mientras es observado por un perro que pasea por el mismo entre "
   "pasionarias, a salvo gracias a una cerca de madera que rodea la "
   "propiedad. Un delicioso olor a comida caliente sale de un cercano portal");
   add_exit("norte"   ,ANDUAR"ao0907.c","road");
   add_exit("sur"     ,ANDUAR"ao1107.c","road");
   add_exit("dentro", ANDUAR"taberna");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}
