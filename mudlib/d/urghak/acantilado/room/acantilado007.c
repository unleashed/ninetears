#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("sudoeste", ACANTILADO+"acantilado008.c", "path");
  add_exit("este", ACANTILADO+"acantilado006.c", "path");
}
