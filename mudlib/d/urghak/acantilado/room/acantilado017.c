#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("oeste", ACANTILADO+"acantilado018.c", "path");
  add_exit("sudeste", ACANTILADO+"acantilado016.c", "path");
}
