#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("este", ACANTILADO+"acantilado005.c", "path");
  add_exit("oeste", ACANTILADO+"acantilado007.c", "path");
}
