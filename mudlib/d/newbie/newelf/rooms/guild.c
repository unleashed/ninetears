#include "path.h"
inherit "/std/newbieguild";

void setup()
{
    set_light(LIGHT);
    set_short("Galastriia :  Newbie Guild");
    set_long("\nGalastriia :  Newbie Guild\n\n"
      "     Contrary to most beginer's guilds, this one, set deep in an ancient stump "
      "is decorated with many pieces of furniture, tables, and even a tapestry.  As you stand "
      "looking about the guild, you also notice a sign above the door which reads:  "
      "\n\n"
      "     Type \"info\" to learn about this Guild.     "
      "\n\n");
    add_sign("     Type \"info\" to learn about this Guild.     \n");
    add_exit("northeast",ROOMS+"aaroc_center.c","door");
}
void init()
{
    ::init();
    add_action("do_info","info");
}

int do_info(string str)
{
    if(str || str == "") return (0);
    write(
      "Welcome to your guild!  Here, you can advance for free once you "
      "obtain the required experience at each level up to level five.  "
      "Once reaching level five, you can no longer advance here and "
      "will have to find another place in the realms to join.  To see"
      " how many experience points you are lacking to advance, "
      "type \"cost\".  \n"
      "\nAdvancing to your first level requires no experience points.  "
      "All you have to do is type \"advance\" and you will be level "
      "one.  You should consider using the \"rearrange\" command "
      "before doing so however.  When you advance, your stat rolls are "
      "based on your current stats.  So, if your stats reflect the "
      "high strength and dexterity of fighters, you will get fighter "
      "rolls.  Likewise, if you resemble a wizard, you will get a "
      "different set rolls.  Note however, there is no long term "
      "advantage to your stats gained here, after time, they will "
      "approach the average for your final guild which you are required "
      "to find to advance past level five.  "
      "\n\n");

    return 1;
}
