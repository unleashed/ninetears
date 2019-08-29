// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Oskuro%^RESET%^");
   set_long("Estas en la ancestral ciudad de anduar a ambos lados de la "
   "calzada observas una zona residencial, en la parte delantera un cerezo "
   "decora el jardin, en el cual un aguila esta posado en una rama mientras "
   "es observado por un noble que pasea por el mismo entre claveles, a salvo "
   "gracias a una hilera de columnas que rodea la propiedad. Tambien observas "
   "la lujosa casa de algun usurero.");
   add_exit("norte"   ,ANDUAR"ae0919.c","road");
   add_exit("sur"     ,ANDUAR"ae1119.c","road");
   add_exit("dentro"  ,ANDUAR"encambio","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}
