#include "../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^GREEN%^Bosque de Eloras: Calle corta%^RESET%^");
   set_long("Estas en uno de los senderos que los habitantes de este bosque "
   "llaman calle de la corta, por todos lados ves pequenyas construcciones "
   "que parecen ser el hogar de los pequenyos habitantes de este bosque, este "
   "sendero en concreto se dirige directamente de sudoeste a noreste.\n");
   add_exit("noreste", BOSQUEELORAS+"i2", "plain");
   add_exit("sudoeste", BOSQUEELORAS+"c10", "plain");
set_light(50);
add_clone("/d/anduar/npcs/halfling.c",random(3));
}
