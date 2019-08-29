#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("sudeste", ACANTILADO+"acantilado012.c", "path");
  add_exit("oeste", ACANTILADO+"acantilado014.c", "path");
  add_exit("noroeste", ACANTILADO+"acantilado015.c", "path");
}
