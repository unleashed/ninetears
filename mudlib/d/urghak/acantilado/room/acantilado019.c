#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("sur", ACANTILADO+"acantilado020.c", "path");
  add_exit("noreste", ACANTILADO+"acantilado018.c", "path");
}
