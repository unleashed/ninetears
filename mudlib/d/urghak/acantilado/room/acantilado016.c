#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("noroeste", ACANTILADO+"acantilado017.c", "path");
  add_exit("este", ACANTILADO+"acantilado015.c", "path");
  add_exit("sudeste", ACANTILADO+"acantilado014.c", "path");
}
