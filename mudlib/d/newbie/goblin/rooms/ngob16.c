// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

object *npc;
void setup() {
    // Descriptions...
    set_short("Realm of the Goblin:  River");
    set_light(20);
    set_zone("newbie_river");
    set_long("\nRealm of the Goblin:  River\n\n"
      "     You have waded into the river, which is very cold. "
      "The river is not very wide and it is only about 2 feet deep. "
      "The current is running west to east. To the south is a tunnel opening up "
      "to the river.\n\n");
    add_property("no_undead",1);
    add_item(({"wall", "rock"}),
      "The walls here are dark and damp. They are covered "
      "with moss and fungus.\n");
    add_item(({"moss", "fungus"}), 
      "The moss and fungus probably grow here "
      "because the walls are so damp and wet.\n");
    add_item("river","This river doesn't look to deep as far as you "
      "can tell, maybe about two feet deep. You see some blind fish swimming "
      "in it occassionally.\n");
    add_item(({"fish","blind fish"}),"These are your ordinary cave fish, "
      "they look quite tasty.\n");

    // Items....

    add_exit("west","/d/newbie/goblin/rooms/ngob17.c","path");
    add_exit("east","/d/newbie/goblin/rooms/ngob18.c","path");
    add_exit("south","/d/newbie/goblin/rooms/ngob15.c","path");
    // Exits....
    npc = allocate(3);
} /*setup() */

void reset()
{
    int i;
    for(i =0; i< sizeof(npc); i++)
    {
        if(!npc[i])
        {
            npc[i]=clone_object(CHAR+"frog.c");
            npc[i]->move(this_object());
        }
    }
}
void dest_me()
{
    int i;
    for(i=0; i< sizeof(npc); i++)
    {
        if(npc[i]) npc[i]->dest_me();
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
