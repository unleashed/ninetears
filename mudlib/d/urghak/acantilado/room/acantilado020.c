#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("norte", ACANTILADO+"acantilado019.c", "path");
  add_exit("sudoeste", ACANTILADO+"acantilado021.c", "path");
}
