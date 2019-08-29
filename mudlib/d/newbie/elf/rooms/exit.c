#include "path.h"

inherit "/std/outside";

void setup() {
	add_property("no_undead",1); set_short("Realm of the Elf:  Path to the Outside Realms");
   set_long("\n   Realm of the Elf:  Path to the Outside Realms.\n\n"
            "     The dense forest of your youthful homeland spreads "
		"out behind you.  Ahead of you, to your north, lies a river "
		"with a rapid current.  On the other side of the river you can "
		"see a road with outside traffic.  For the first time "
		"in your life you catch glimpses of humans, dwarves "
		"and other non-elves.  You wonder if you are ready to "
		"leave your homeland.  You wonder if you can even if you are ready.  "
		"There is no bridge crossing this river and you "
		"don't dare brave the fierce current.  As you look "
		"around trying to figure out how elves leave the forest "
                "you notice a large tree growing on the river bank."
                "\n\n");

	add_item("tree","This huge tree dominates the river.  Some "
		"of its giant branches reach all the way across "
		"the river!  Perhaps you could treewalk across the river "
		"on these branches.\n");
	add_item("river","This river seperates the elven forest "
		"from the rest of the world.  Many an elf has drowned "
		"trying to swim in its raging current.\n");

	set_light(60);

	add_alias("leaves", "leaf");
	add_alias("trunks", "trunk");
	add_alias("trees", "tree");


	add_item("floor", "The forest floor is carpeted with a thick pad of "
			  "fallen leaves.  They are quite springy and make for "
			  "pleasant walking.\n");

	add_item("sky", "Vivid blue peeks between thick foliage, giving the "
			"forest floor a peaceful dappled quality.\n");

	add_item("leaf", "The green leaves spreading above you glimmer in the "
			 "filtered sunlight.\n");
	add_exit("west", ROOM+ "fo17", "plain");

set_zone("elves");
}

void init() {
	add_action("climb_tree","treewalk");
::init();
}


int climb_tree()
{
   if(this_player()->query_level() < 5)
   {
      write("You start to climb the tree, but you feel to inexperienced "
      "and your natural common sense drives you back. "
   "Maybe later, when you are a bit tougher, it's a rough world out there.\n");
      return 1;
   }
	if(this_player()->query_property("treewalking"))
	{
		write("You gracefully walk across the river perched on the"
			" thick tree branches.\n");
     this_player()->move(ROOM+"exit2.c");
		this_player()->look_me();
            return 1;
	}
	else
	{
	write("You have yet to master the elven art of treewalking.  "
		"You don't dare cross the river via this tree.\n");
         return 1;
	}
}
