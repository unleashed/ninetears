#include "path.h"

inherit "/std/outside";

void setup() {
	add_property("no_undead",1); set_short("Realm of the Elf:  Path to the Outside Realms");
   set_long("\n   Realm of the Elf:  Path to the Outside Realms.\n\n"
            "     After crossing the river you are now on a small "
            "path.  It leads north "
        "to another path. The river to the south is "
       "uncrossable from here. The forest looms all around you. "
       "The only way to go is north.\n\n"
       "Good luck in your adventures."
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
      add_exit("north","/d/ss/wilderness/path2.c","path");
   modify_exit("north", ({"function","go_north"}) );

}

   int go_north()
    {
  object me;
int lv;
int xp;


me = this_player();
lv = (int)me->query_level();
xp = (int)me->query_xp();
if(lv == 5&&xp > 30000) {
this_player()->adjust_xp(-xp+1000, this_player());
 write_file("/d/mm/logs/ELF_EXP_LOG",this_player()->query_cap_name()+" had "
 +xp+" in exp.\n");
return 1;
}
return 1;
}
