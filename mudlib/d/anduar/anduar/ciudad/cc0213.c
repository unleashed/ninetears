// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Calle de Osucaru%^RESET%^");
   set_long("Estas en la calle principal de Anduar, puedes ver muchas "
        "casas en casi todas las direcciones. Hay un murmullo "
        "constante de la gente que pasea por las calles. Observas que "
        "casi todos sus habitantes son humanos, aunque se puede ver "
        "algun que otro enano o elfo.\n");
   add_exit("norte"   ,ANDUAR"puerta0113.c","road");
   add_exit("sur"     ,ANDUAR"cc0313.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
add_clone("/d/anduar/npcs/espia.c",1);
}
void dest_me()
{
return 0;
}
