#include "path.h"
inherit CASTLE+"baseroom.c";
object *npc;

void setup() { my_setup();
set_short("Realm of the Orc:  Dungeon Cell");
set_light(40);
set_long("\n   Realm of the Orc:  Dungeon Cell.\n\n"
         "     This appears to be just a normal cell used to keep "
"prisoners of various races. It is cold and damp with no "
"distinguishing features of any kind. "
" Maybe its the lack of features that raises a brow to this room. "
"It almost appears that this cell has never been used! "
"\n\n");
add_item(("floor"),"\nLooking at the floor, you see nothing "
          "other small pebbles scattered around the room.");
add_item(("walls"),"The wall here are made of large stones stacked "
          "on top of one another, and connected together by a "
          "crude morter.");
add_item(("door"),"This is a very sturdy oak door.  It is about "
          "six inches thick, no one would have ever been able to "
          "escape throught it");
add_exit("north",DUNGEON +"dungeon06","door");
npc=allocate(2);
}



void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
   npc[i]=clone_object("/d/newbie/orc/monsters/cave_rat.c");
   npc[i]->move(this_object());
   }
}
}

void dest_me()
{
   int i;
   for(i = 0; i < sizeof(npc); i++)
   {
      if( npc[i] ) npc[i]->dest_me();
   }
   ::dest_me();
}

int do_search(string str)
{
if(str=="wall")
{
tell_object(this_player(),"\n"
"  You discover a lose stone and behind it you find an unusual "
"piece of metal. The metal seems attached and maybe part of some "
"kind of mechanism. Maybe if you knew how to operate it "
"something cool might happen....\n");
return 1;
}
  else
 tell_object(this_player(),"\n"
 " You search around but find nothing of interest.\n\n");
return 1;
}
void init()
{
::init();
add_action("do_search","search");
add_action("do_flip","flip");
}
int do_flip(string str)
{
if(str=="switch")
{
tell_object(this_player(),"\n"
" The floor beneath you disappears...........YOU FALL!!!!\n\n");
tell_room(this_object(),"\n"
" You hear the slam of metal doors.\n");
this_player()->move(DUNGEON + "dungeon1a");
this_player()->look_me();
return 1;
}
return 0;
}
