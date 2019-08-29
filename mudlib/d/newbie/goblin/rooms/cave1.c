// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
    // Descriptions...
    set_short("Realm of the Goblin:  Tunnels");
    set_light(20);
    set_zone("newbie_tunnels");
    set_long("\nRealm of the Goblin:  Tunnels\n\n"
      "     You stand outside of a really large gate. "
      "It is locked and no matter how much you pound on it, it "
      "will not open. The tunnel you stand in is bare and damp. "
      "It continues south to who knows where.\n\n");
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
    add_exit("south",ROOM+"cave2.c","path");
    modify_exit("south",({"function","pick_tribe"}));
    /* took npc out since tribe is found in modify_exit now, Tek 11-97
	add_clone("/d/mm/Cities/caldera/monster/tribe_giver.c",1);
    */

    // Exits....
} /*setup() */



int pick_tribe()
{
    if(this_player()->query_race() == "goblin")
    {
	if(!this_player()->query_race_group_ob())
	{
	    write("Determining what tribe you belong to.........."
	      "\n\n");


	    //This is the code to add clans to the player
	    switch(random(100) ) {
	    case 0..50:
		this_player()->set_race_group_ob("/std/race_groups/garona");
		write("Tribe Garona has you in their records.\n");
		write_file("/d/newbie/logs/GARONA",this_player()->query_cap_name()+" is a member Garona tribe, on "+ctime(time())+"\n");
		break;

	    case 51..99:
		this_player()->set_race_group_ob("/std/race_groups/chiptooth");
		write("Tribe Chiptooth has you in their records.\n");
		write_file("/d/newbie/logs/CHIPTOOTH",this_player()->query_cap_name()+
		  " is a member of Chiptooth tribe, on "+ctime(time())+"\n");
		break;
	    } //end code to add clans
	    write("Type race on to turn on your race channel.\n\n");

	    return(1);
	}
	write("You have a Tribe all ready, quit wasting my time.\n");
	return 1;
    } //end If("goblin")
    write("You are not a Goblin, don't waste my time.\n");
    return 1;
}
