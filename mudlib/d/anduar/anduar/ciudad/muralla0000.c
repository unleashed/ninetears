// Aokromes
#include "../path.h"
inherit ANDUAR+"afueras.c";

void init()
{
        ::init();
        add_action("do_east","entrar");
}

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Muralla%^RESET%^");
   long_desc();
   add_exit("este"    ,ANDUAR"muralla0001.c","road");
   add_exit("sur"     ,ANDUAR"muralla0100.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}
int do_east() 
{ 
    if(TP->query_group_name() == "Crebain") 
    { 
 
        write("Entras en el Clan Crebain.\n");
        TP->move("/d/clanes/crebain/rooms/main");
        TP->look_me();
        return 1; 
     }
     write("Melon");
     return 0;
} 
