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
      "     This part of the river is getting smaller. The roof of "
      "the river tunnel is starting to become quite low, even for a goblin. "
      "You see some writing on the cavern wall. You can continue "
      "north or south.\n\n");
    add_property("no_undead",1);
    add_item(({"wall", "rock"}),
      "The walls here are dark and damp. They are covered "
      "with moss and fungus. You see some writing on on the wall also.\n")+
    add_item(({"moss", "fungus"}), 
      "The moss and fungus probably grow here "
      "because the walls are so damp and wet.\n");
    add_item("river","This river doesn't look to deep as far as you "
      "can tell, maybe about two feet deep. You see some blind fish swimming "
      "in it occassionally.\n");
    add_item(({"fish","blind fish"}),"These are your ordinary cave fish, "
      "they look quite tasty.\n");
    add_item(({"feet","foot"}),"Your feet are starting to turn purple.");
    add_item("writing","You see some writing, maybe you should read it.");

    // Items....
    add_exit("north", ROOM+"ngob41.c","path");
    add_exit("south", ROOM+"ngob38.c","path");
    // Exits....
    npc = allocate(2);
} /*setup() */

void reset()
{
    int i;
    for(i = 0; i < sizeof(npc); i++)
    {
        if(!npc[i])
        {
            npc[i]=clone_object("/d/newbie/goblin/npcs/quipper.c");
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
    add_action("read_writing","read");
    ::init();
}
int read_writing(string str) {
    if(str=="writing") {
        write("The writing says KEEP OUT go no further if you value "
          "your pitiful life.\n");
        tell_room(ENV(TP),CNAME + " seems disturbed as "+this_player()->query_possesive()+ " reads "
          "some writing on the wall.\n", (TP));
        return 1;
    }
}
