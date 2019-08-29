#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("este", ACANTILADO+"acantilado009.c", "path");
  add_exit("noroeste", ACANTILADO+"acantilado011.c", "path");
}
