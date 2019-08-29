#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("este", ACANTILADO+"acantilado022.c", "path");
  add_exit("noroeste", ACANTILADO+"acantilado024.c", "path");
}
