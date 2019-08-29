// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Takome%^RESET%^");
   set_long("Estas en la ancestral ciudad de anduar a ambos lados de la "
   "calzada observas una casa de madera en la parte delantera un alcornoque "
   "decora el jardin, en el cual un loro esta posado en una rama mientras es "
   "observado por un individuo encapuchado que pasea por el mismo entre "
   "rosales, a salvo gracias a un hermoso seto que rodea la propiedad. "
   "Tambien observas un pequenyo templo a algun dios olvidado que parece "
   "dedicarse a sanar a la gente");
   add_exit("oeste"   ,ANDUAR"an0715.c","road");
   add_exit("este"    ,ANDUAR"cruce0717.c","road");
   add_exit("dentro", ANDUAR+"resucitar","corridor");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}
