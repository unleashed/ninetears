#include "../path.h"
inherit ANDUAR+"roadroom.c";

void setup()
{
   base_desc();
   add_exit("southwest",ANDUAR+"c2","road");
   add_exit("north",ANDUAR+"c4","road");
   crea_bichos();
}

void dest_me()
{
   ::dest_me();
   destruye_bichos();
}
