// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";
object *npc;

void setup() {
    // Descriptions...
    set_short("Realm of the Goblin:  Underground Lake");
    set_light(20);
    set_zone("newbie_river");
    set_long("\nRealm of the Goblin:  Underground Lake\n\n"
      "     Upon entering this lake you notice that it is unusally quiet. "
      "The current has slowed even more, but you notice that it "
      "flows out the west cavern. You see some debris floating on the "
      "surface of the water. There are passages going to the north, northeast, "
      "west, southwest, and a cavern that leaves the water to the southeast.\n\n");
    add_property("no_undead",1);
    add_item(({"wall", "rock"}),
      "The walls here are dark and damp. They are covered "
      "with moss and fungus.\n");
    add_item(({"moss", "fungus"}), 
      "The moss and fungus probably grow here "
      "because the walls are so damp and wet.\n");
    add_item(({"fish","blind fish"}),"These are your ordinary cave fish, "
      "they look quite tasty.\n");

    add_item("debris","This is pieces of paper, wood, and sewage. It must "
      "have become stuck here because of the current slowing down.\n");
    add_item("paper","Most of this paper is just garbage but you notice "
      "one piece with some writing on it.\n");
    add_item("wood","Looks like pieces of support beams used in mining.");
    add_item("sewage","This looks really sickening, it kinda reminds "
      "you of home.\n");
    // Items....

    add_exit("west", ROOM+"ngob29.c","path");
    add_exit("southwest", ROOM+"ngob48.c","path");
    add_exit("north", ROOM+"ngob38.c","path");
    add_exit("southeast", ROOM+"ngob36.c","path");
    add_exit("northeast", ROOM+"ngob39.c","path");

    npc = allocate(1);
    // Exits....
} /*setup() */

void init() {
    add_action("read_paper","read");
    ::init();
}
int read_paper(string str) {
    if(str=="paper") {
        write("All this hard work at coding this area has been done by "
          "Allonon and Tek.\n");
        tell_room(ENV(TP),CNAME + " reads a piece of "
          "paper. "+ this_player()->query_gender() +" seems really impressed.\n", (TP));
        return 1;
    }
}
/*setup() */



void reset()
{
    int i;
    for(i = 0; i < sizeof(npc); i++)
    {
        if(!npc[i])
        {
            npc[i]=clone_object("/d/newbie/goblin/npcs/eel.c");
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

