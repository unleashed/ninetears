#include "../path.h"
inherit ANDUAR+"roadroom.c";

void setup()
{
   base_desc();
   add_exit("north",ANDUAR+"puerta2613","road");
   add_exit("south",ANDUAR+"c3","road");
   crea_bichos();
}

void dest_me()
{
   ::dest_me();
   destruye_bichos();
}
