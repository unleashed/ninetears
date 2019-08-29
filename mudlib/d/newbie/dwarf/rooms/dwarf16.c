//  Dwarven Newbie Area:  Created By Mist   Fall 1994

#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Lake View");
set_light(80);
	set_long("\n   Realm of the Dwarf:  Lake View\n\n"
	 "     You are standing in an enormous pit on the shore "
		"of a beautiful lake.  The sandy shore extends north "
		"and seems to bend around the lake.  The shore also "
		"leads south to a rock wall with a cave at the top.  "
		"Coming out of the cave is a large and powerful "
		"waterfall.  The mist and the cool breeze coming "
		"from the waterfall send chills down your spine.  "
		"The northern end of the lake obviously has another "
		"cave under the water that serves as an outlet for "
		"the large amounts of water that is pumped in by "
		"waterfall.  It is causing a whirlpool that stretches "
		"out over a large portion of the lake.  The mist has  "
                "enshrouded most of the surrounding area, but in a "
"small indentation in the rock wall something catches your "
                "eye.  You can't make out much at this distance, perhaps "
                "a closer look is needed.  "
		"\n\n");

	add_item(({"lake","beautiful lake","water"}),"The lake "
		"extends all the way over to the western wall and "
		"reaches to the south where there is a large "
		"waterfall.  The lake is very beautiful and would "
		"be a perfect place for a swim, if it wasn't for the "
		"whirlpool that covers its northern end.  It might "
		"be best not to go in.  "
		"\n\n");
	add_item(({"fall","waterfall"}),"The waterfall drops from a "
		"cave in the southern wall, down onto the rocks below.  "
		"The sound is almost deafning here as the powerful "
		"falls beat loudly on the rocks.  "
		"\n\n");
	add_item(({"whirlpool"}),"The whirlpool covers most of the "
		"northern end of the lake.  It must be caused by a "
		"cave or tunnel at the bottom of the lake that serves "
		"as an outlet for the water in the lake.  "
		"\n\n");
	add_item(({"shore","beach","sandy shore","sand"}),"The sand "
		"here is clean and white.  The shore extends along the "
		"eastern shore to the north and south.  "
		"\n\n");
	add_item(({"wall","rock wall","cave"}),"The rock wall to the "
		"south has a cave that the waterfall is coming out of.  "
		"There is a pile of rocks that you might be able to "
		"climb up next to the waterfall.  You also notice a small "
             "indention, and there appears to be something "
                "wedged in there.  "
		"\n\n");
	add_item(({"pile","rocks"}),"This pile of rocks is right next "
		"to the waterfall.  It would be a dangerous climb, but "
		"you could probably make your way to the top.  "
		"\n\n");
add_item("indentation","This indentation in the rock wall "
                "has a small glowing crystal wedged in it.  "
                "The crystal appears to have magical properties.  "
                "This causes you to be wary of touching it "
                "even though it appears to be yours for the taking.  "
                "\n\n");


  add_clone(CHAR+"drole.c",1);
  add_clone(CHAR+"goblin.c",1);
add_exit("south",ROOM+"dwarf20","path");
add_exit("north",ROOM+"dwarf13","path");
add_exit("east",ROOM+"dwarf17","path");
}


void init()
{
   ::init();
   add_action("touch_crystal","touch");
}
int touch_crystal(string str)
{
   if(str != "crystal")
   {
   return(0);
   }
   {
     write("You reach out and touch the glowing crystal and feel a "
          "sudden surge of energy pass from it to you.  "
          "\n\n");
     this_player()->adjust_hp(random(2)+2);
     return(1);
   }
}
