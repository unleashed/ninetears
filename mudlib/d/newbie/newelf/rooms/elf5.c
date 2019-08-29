#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      "The forest here is totally silent, making your noisy footsteps "
      "echo repeatedly between the trees. Total silence is not something "
      "one would expect in the middle of the forest. You wonder why the "
      "animals all seem to keep away from this area."
      "\n\n");

    add_clone(CHAR+"sprite.c",1);
    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southeast",ROOMS+"elf2.c","path");
    add_exit("north",ROOMS+"hp1.c","hidden");
    modify_exit("north",({"function","go_north"}));
}
int go_north()
{
    if(this_player()->query_level()<3)
    {
	notify_fail("You dont see an exit to your north.");
	return 0;
    }
    tell_object(this_player(), "You grin as you now notice a small opening in the brush to the north.\n");
    return 1;
}

