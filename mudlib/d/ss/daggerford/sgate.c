#include "path.h"
inherit CITYROOM;

#define NUM 1

object guard;

void setup()
{
	set_light(80);
	set_short("City Gates");
	set_long(
"You are at the southern gate of Daggerford.  You can go north from "+
"here into Daggerford, or out into the wilderness. Far to the east you notice "+
"some mountains. From somewhere south of here wafts the smell of a swamp.\n");

	add_exit("north", ROOM+"wall1", "road");
        add_exit("out","/d/ss/daggerford/outside/out3.c","gate");

	add_item("mountains",
		 "Although they are so far away, you can make out the white "+
		 "snowcaps on the tops of the highest peaks.\n");
	add_item("gate",
"This gate leads out of the city. In the far distance "+
"you can see some mountains.\n");

	add_item("swamp",
			"A dark swamp lies to the south, somewhere along the Sword Coast.\n");

	set_zone("city");

	set_monster(NUM, "city");
    modify_exit("out", ({"function", "GO_OUT"}));
   }
 
 
int GO_OUT()
   {object target;
    target=this_player();
    if((string)(target->query_name()) == "The militiaman")
      {tell_room(environment(target), "The militiaman stops pursuing his "+
          "prey.\n\n", ({target}));
       return 0;
      }
    return 1;
   }

void reset()
{
	::reset();
	if(!guard)
	{
		guard=clone_object(CHAR+"cityguard");
		guard->move(this_object());
	}
}
