// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

object *npc;
void setup() {
    // Descriptions...
    set_short("Realm of the Goblin:  Gloomy Tunnels");
    set_light(20);
    set_zone("newbie_tunnels");
    set_long("\nRealm of the Goblin:  Gloomy Tunnels\n\n"
      "     This is a dead end, the tunnel stops here, but the "
      "north wall looks like someone was starting to continue the tunnel "
      "in that direction. Other than that there isn't anything else "
      "of interest here.\n\n");
    add_property("no_undead",1);
    add_item(({"wall", "rock"}),
      "The walls here are dark and damp. They are covered "
      "with moss and fungus. Some places there are "
      "bodily wastes smeared up on the walls. The "
      "sight of it is disgusting.\n");
    add_item(({"moss", "fungus"}), 
      "The moss and fungus probably grow here "
      "because the walls are so damp and wet.\n");
    add_item("north wall","This wall has a section in it where "
      "the rock has been dug out. It appears to have been the start "
      "of a tunnel extension, but the work must have been abandoned.\n");

    // Items....

    add_exit("south", ROOM "ngob25.c","path");
    // Exits....
    npc = allocate(1);
} /*setup() */


void reset()
{
    int i;
    for(i = 0; i < sizeof(npc); i++)
    {
        if(!npc[i])
        {
            npc[i]=clone_object("/d/newbie/goblin/npcs/hobgoblin.c");
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

void init() {
    add_action("listen_water","listen");
    ::init();
}
int listen_water(string str) {
    if(str=="water") {
        write("You hear the sound of water running, it "
          "sounds quite relaxing.\n");
        tell_room(ENV(TP),CNAME + " seems to relax listening to the sounds "
          "of the water.\n", (TP));
        return 1;
    }
}
