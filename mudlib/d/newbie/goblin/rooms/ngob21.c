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
    set_long("\nRealm of the Goblins:  Gloomy Tunnels\n\n"
      "     The tunnel here is partially caved in and you are forced "
      "to crawl along the top of the rubble. You knees are being cut up "
      "really badly on the sharp stones. You see something sticking "
      "out of the rubble but you can't be sure what it is. "
      "To the north you see a wide cavern but it is to misty to "
      "tell much about it.\n\n");
    add_property("no_undead",1);
    add_item(({"wall", "rock"}),
      "The walls here are dark and damp. They are covered "
      "with moss and fungus. Some places there are "
      "bodily wastes smeared up on the walls. The "
      "sight of it is disgusting.\n");
    add_item(({"moss", "fungus"}), 
      "The moss and fungus probably grow here "
      "because the walls are so damp and wet.\n");
    add_item(({"ground","floor"}),"The ground is covered in rubble, with "
      "some really sharp stones in it.\n");
    add_item("dust","This dust has been here awhile.\n");
    add_item("rubble","This rubble has fallen from the roof of this "
      "tunnel. You are sure glad you were not here when it collapsed. "
      "You see a arm sticking out.\n");
    add_item("arm","This arm seems to be connected to a goblin. The arm "
      "appears to have been chewed on, probably by cave rats. Guess this "
      "fellow just couldn't run fast enough.\n");
    add_item("goblin","He's dead, quite dead.\n");
    add_item(({"north","cavern"}),"You can't see much through all the "
      "mist.\n");
    add_item("mist","It kinda looks like fog but but it is not. Must be "
      "a near some water of some kind.\n");

    // Items....

    add_exit("north", ROOM"ngob22.c","path");
    add_exit("south", ROOM "ngob20.c","path");
    // Exits....
    npc= allocate(3);
} /*setup() */

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

void reset()
{
    int i;
    for(i = 0; i < sizeof(npc); i++)
    {
        if(!npc[i])
        {
            npc[i]=clone_object("/d/newbie/goblin/npcs/cave_rat.c");
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

