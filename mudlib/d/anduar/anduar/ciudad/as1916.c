// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Dendara%^RESET%^");
   set_long("Estas en la ancestral ciudad de anduar a ambos lados de la "
   "calzada observas un grupo de casas echas de adobe en la parte delantera "
   "un pino decora el jardin, en el cual un aguila esta posado en una rama "
   "mientras es observado por un perro que pasea por el mismo entre violetas, "
   "a salvo gracias a una hilera de columnas que rodea la propiedad. Hueles "
   "a pan recien asado saliendo de un edificio de la calle.");
   add_exit("oeste"   ,ANDUAR"cruce1915.c","road");
   add_exit("este"    ,ANDUAR"as1917.c","road");
   add_exit("dentro"    ,ANDUAR"panaderia","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}
