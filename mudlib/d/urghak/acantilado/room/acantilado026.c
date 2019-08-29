#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("noreste", ACANTILADO+"acantilado025.c", "path");
  add_exit("sudoeste", ACANTILADO+"acantilado027.c", "path");
}
