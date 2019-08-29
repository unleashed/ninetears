inherit "/d/anduar/bosque_negro/pl";
#include "../path.h"

void setup()
{
   set_short("%^BOLD%^Bosque Negro%^RESET%^");
   set_long("Estas en algun lugar en medio del bosque negro, mires por donde "
   "mires no ves mas que un inmenso mar de arboles, gigantescos colosos que "
   "apenas puedes ver la luz del sol, lo cual te hace imposible el orientarte "
   "dentro del mismo.\n");
   add_exit("oeste",    BOSQUENEGRO+"p1", "plain");
   add_exit("norte",    BOSQUENEGRO+"p4", "plain");
   add_exit("noroeste", BOSQUENEGRO+"p3", "plain");
   set_light(20);
   add_clone("/d/anduar/npcs/halfling.c",random(6));
}
