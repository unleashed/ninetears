#include "path.h"
inherit "/std/newbieguild";

void setup()
  {
   set_light(LIGHT);
  set_short("Isle of Havmand: Guildroom");
   set_long("\nIsle of Havmand : Guildroom\n\n"
   "   This is a small room with little in the way of furniture or "
   "anything else that could get in the way of your training.  "
   "If you are new, a sign above the door you passed through reads:  "
   "\n\n"
   "   Type \"info\" to learn about our Guildroom.   "
   "\n\n");
      add_exit("east",HAVMAND+"t06.c","door");
   add_sign("   Type \"info\" to learn about our Guildroom.   \n");
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

   return(1);
}
