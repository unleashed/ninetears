#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("este", ACANTILADO+"acantilado024.c", "path");
  add_exit("sudoeste", ACANTILADO+"acantilado026.c", "path");
}
