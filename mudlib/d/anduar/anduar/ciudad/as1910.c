// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Dendara%^RESET%^");
   set_long("Estas en la ancestral ciudad de anduar a ambos lados de la "
   "calzada observas un grupo de casas echas de piedra en la parte delantera "
   "un roble decora el jardin, en el cual un cuervo esta posado en una rama "
   "mientras es observado por un elfo que pasea por el mismo entre azucenas, "
   "a salvo gracias aun foso que rodea la propiedad. Al norte puedes observar "
   "el gremio de los guerreros, y al sur una herreria");
   add_exit("oeste"   ,ANDUAR"as1909.c","road");
   add_exit("este"    ,ANDUAR"as1911.c","road");
   add_exit("norte", FIGHTERS+"entrada", "door");
   add_exit("sur", ANDUAR"herreria", "door");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}
