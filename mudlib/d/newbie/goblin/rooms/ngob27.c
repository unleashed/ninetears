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
      "     This tunnel leads to the west and northeast. "
      "The floor is covered in dust. "
      "You seem to smell stale ale or beer to the northeast. "
      "There are foot prints all over the place here on the floor, "
      "seems to have been alot of traffic here in the "
      "last few weeks.\n\n");
    add_property("no_undead",1);
    add_item(({"wall", "rock"}),
      "The walls here are dark and damp. They are covered "
      "with moss and fungus. Some places there are "
      "bodily wastes smeared up on the walls. The "
      "sight of it is disgusting.\n");
    add_item(({"moss", "fungus"}), 
      "The moss and fungus probably grow here "
      "because the walls are so damp and wet.\n");
    add_item(({"ground","floor"}),"The ground is covered in dust, with "
      "some foot prints occasionally being seen.\n");
    add_item("dust","This dust has been here awhile.\n");
    add_item(({"foot prints","footprints","prints"}),"You see some foot prints but "
      "they have been smeared in too much to tell where they go.\n");

    // Items....

    add_exit("northeast", ROOM"ngob47.c","path");
    add_exit("west", ROOM "ngob25.c","path");
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
            npc[i]=clone_object("/d/newbie/goblin/npcs/centi.c");
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
    add_action("smell_ale","smell");
    ::init();
}
int smell_ale(string str) {
    if(str=="ale") {
        write("You smell old ale from the northeast.\n");
        return 1;
    }
}
