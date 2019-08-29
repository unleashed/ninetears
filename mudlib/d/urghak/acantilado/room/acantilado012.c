#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("noroeste", ACANTILADO+"acantilado013.c", "path");
  add_exit("sur", ACANTILADO+"acantilado011.c", "path");
}
