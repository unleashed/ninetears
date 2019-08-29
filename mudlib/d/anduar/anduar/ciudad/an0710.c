// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Takome%^RESET%^");
   set_long("Estas en la ancestral ciudad de anduar a ambos lados de la "
   "calzada observas unas viviendas de disenyo estranbotico en la parte "
   "delantera un haya decora el jardin, en el cual un gorrion esta posado "
   "en una rama mientras es observado por un senyor calvo que pasea por el "
   "mismo entre ortensias, a salvo gracias a una verja con figuras en "
   "columnas que rodea la propiedad. Tambien observas como multiples hadas "
   "salen y entran a un curioso edificio.");
   add_exit("oeste"   ,ANDUAR"an0709.c","road");
   add_exit("este"    ,ANDUAR"cruce0711.c","road");
   add_exit("dentro", ANDUAR+"correos", "door");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}
