#include "path.h"
inherit CASTLE+"baseroom.c";
object *npc;
void setup () {
set_short("Realm of the Orc:  Skeletal Remains Room");
set_light(40);
set_long("\n   Realm of the Orc:  Skeletal Remains Room.\n\n"
         "     There are skeletons scattered everywhere around "
         "the room.  Other than this, there is nothing it the "
         "entire room.  Even the door to the south has been "
         "taken off the hinges.  It looks as if someone used "
         "this room to place the remains of the guards in one "
         "location."
         "\n\n");
add_item(({"skeleton","steletons"}),"\nThese are the decayed "
           "remains of the palace guards.  As far as you call "
           "tell there must be skeletons of a dozen guards, "
           "and every item of value has been removed.");
add_item(({"door"}),
           "   It is a large oak door which is resting "
          "against the door facing.  With the hurry that was "
          "taken to get out of here, someone knocked it off "
               "the hinges.");


 
add_exit("south",DUNGEON +"dungeon07","door");
npc=allocate(2);
}
void reset()
{
int i;
for(i=0;i<sizeof(npc); i ++)
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
for(i=0; i<sizeof(npc); i ++)
{
if(npc[i])npc[i]->dest_me();
}
::dest_me();
}
// sojourn
