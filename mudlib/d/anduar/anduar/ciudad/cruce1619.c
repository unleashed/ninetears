// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Oskuro%^RESET%^");
   set_long("Estas en lo que antiguamente era la calle este de Anduar, "
        "puedes ver muchas casas en casi todas las direcciones, hay "
        "hermosos arboles a ambos lados de las calles, puedes "
        "observar que las amplias calles estan muy cuidadas, y hay "
        "muchas casas en casi todas las direcciones. Hay un murmullo "
        "constante de la gente que pasea por las calles. Observas que "
        "casi todos sus habitantes son humanos, aunque se puede ver "
        "algun que otro enano o elfo, al oeste observas un gran templo, el "
        "templo de Gestur y al este las puertas de un gran banco.\n");
   add_exit("norte"   ,ANDUAR"ae1519.c","road");
   add_exit("sur"     ,ANDUAR"ae1719.c","road");
   add_exit("este"     ,ANDUAR"enbanco","road");
   add_exit("oeste", "/d/oficios/clerigos/gestur/rooms/entrada.c", "gate");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}
