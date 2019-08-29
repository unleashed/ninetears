#include "path.h"
inherit CASTLE+"baseroom.c";
void setup() { my_setup();
set_short("Realm of the Orc:  Temple");
set_light(40);
set_long("\n   Realm of the Orc:  Temple.\n\n"
         "     The room has a foul smell about it and is layered with "
         "filth.  "
"Unusual carvings adorn the walls and a huge mural decorates the ceiling. "
"In the center of the room sits a large stone table. The table looks kind of "
"important. Next to the table lays a large metal plate. It might be "
"a drain of some kind.\n\n");
add_smell(({"foul smell","bad smell","smell","odor"}),
"\n\n"
" It smells of dung!! very strong!!\n\n");
add_item(({"table","stone table"}),
"\n\n"
"  The table has no etchings or decorations of any kind."
" On the surface of the table are many deep scars. "
"A strange light illuminates the room, it seems "
"to originate from the table.\n\n");
add_item(({"filth","dung","shit","crap","floor"}),
"\n\n"
"  Some beasty has a huge social problem. You seriously "
"doubt that it has many friends.");
add_item("light", "\n\n"
" The light seems to originate from the stone table.\n");
add_item(({"plate","drain","metal plate"}),
"\n\n"
" It looks very heavy, but you think you can move it with "
"a little strength. You need to put your back into it.\n\n");
add_clone(CHAR+"demon.c",1);
add_exit("north",DUNGEON +"dungeon3a","door");
}


void init()
{
::init();
add_action("do_move","move");
}
int do_move(string str)
{
if(str=="plate")
{
tell_object(this_player(),"\n"
  "You strain your muscles but you finally move the plate over.\n\n"
   "As you move the plate out of the way, you slip and fall in.\n\n"
  "You land in some kind of drain, and you roll and slide very far.\n\n"
   "Eventually you come to a stop and see a opening and you climb "
    "through.\n\n You get up and shake the dirt and water off.\n\n\n"
   "Actually you think that was kinda fun, maybe you should do it again."
    "\n\n\n");
  say(this_player()->query_cap_name()+" moves the metal plate and "
 "slips and falls through the hole screaming.\n\n");
this_player()->move(TOWN + "town06");
this_player()->look_me();
return 1;
}
return 0;
}
