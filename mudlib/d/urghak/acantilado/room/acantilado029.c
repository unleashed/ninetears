#include "../path.h"

inherit "/d/urghak/acantilado/room/acantilado_main.c";

void setup()
{
  do_desc(1,1);
  add_exit("sudoeste", ACANTILADO+"acantilado028.c", "path");
  add_exit("abajo", ACANTILADO+"acantilado100.c", "path");
}
