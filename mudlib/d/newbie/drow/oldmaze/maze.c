inherit "/std/room";
#include "path.h"

void setup() 
  {
  set_short("The Great Maze");
  set_light(15); add_item("piller","The pillar appears to be made out of the same grey stone as the walls, and doesn't appear to be of any importance.\n");
set_long("You are in the great maze.  It is here that you shall learn your "
	 "skills to survive in the underdark.  All who are under the level "
	 "of 5 are welcome here to challenge their fate, to see it they have "
	 "what it takes to become true Drow!\n");
  add_smell("room", "It smells old.\n");
  add_taste("air", "The air tastes Musty and old.");

  add_exit("east", MAZE+"maze01.c", "door");
  add_exit("west", "/d/bf/banefall/city/bazaar3", "door");
   modify_exit("west",({"function","mywest"}));

add_property("no_undead",1);   }  /* setup */

int mywest()
{
object me;
int lv;
int xp;


me = this_player();
lv = (int)me->query_level();
xp = (int)me->query_xp();
if(lv < 5 ) {
   notify_fail("Cyrcia demands that you be her spectre of "
    "death for the captives in this prison till you have gained more "
     "experience.\n\n");
   return 0;
}
if(lv == 5&&xp > 30000) {
    write("Cyrcia laughs at your pitiful attempt to leave her "
       "maze with the experience of multiple captive slaughters.  This experience was meant to train you not "
     "for you to abuse.  You get no free ride here.\n\n");
   this_player()->adjust_xp(-xp+1000, this_player());
write_file("/d/bf/banefall/log/NEWBIES",this_player()->query_cap_name()+" had too much xp.\n");
return 1;
}
return 1;
}
