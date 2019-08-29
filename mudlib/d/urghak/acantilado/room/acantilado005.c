#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("arriba", ACANTILADO+"acantilado004.c", "path");
  add_exit("oeste", ACANTILADO+"acantilado006.c", "path");
}
