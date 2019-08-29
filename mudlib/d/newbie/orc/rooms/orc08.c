#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Bedroom");
set_light(40);
set_long("\n   Realm of the Orc:  Bedroom.\n\n"
   "   The bedroom is a mess, the tattered remains of a four poster bed stand "
"against the far wall. "
   "The drapes around the bed are still there, which seems puzzling considering "
   "the level of destruction elsewhere. A trail in the dust on the floor "
   "leads from the door to the bed, where there stands a small chest."
   "\n");
   add_item(({"bed","drapes"}),"The drapes are somewhat tattier close up than they appeared "
   "to be from a distance, thats probably due to the chainmail lining the inside. "
   "The mattress of the bed has been cut to pieces, and any blankets are missing. "
   "Looks like someone was looking for loot fairly intensively. "
   "A glitter from the wall end of the bed may be something that was overlooked "
   "though.\n");
   add_item(({"trail","dust"}),"  The trail leads from the doorway "
       "to the bed.\n");
   add_item("chest","This small chest sits at the foot of the bed and "
        "appears to be unlocked.\n");

   add_item("wall","  The wall here is cleaner than the walls in the "
       "rest of the castle.  It would seem that the battle never got "
       "this far.\n");
   add_item(({"glitter"}),"The glittering item appears to be a gem, recessed into "
   "the wall somewhat. The only reason you can see it now is that some of the "
   "dried blood seems to have flaked off the wall. "
   "\n");
add_item("gem","If you had a dagger you could probably pry this out.\n");
   add_item(({"armour","weapons"}),"The armour still has an occupant, "
   "he's rather dead, and dried blood still trails down the wall by the head "
   "of the bed. It looks like some incredible force has driven him partway "
   "into the wall.");
   add_item(({"door","around"}),"Your first impressions seem to have been mistaken , "
   "it's just that there are few obvious signs of battle in this room. "
   "everything has a thin film of dust and soot, apart from a bloody area "
   "near the bed, and a clear track leading to the door. "
   "\n");
   add_item(({"gem"}),"The gem looks as though it'll take some effort to get out. ");
add_item("ceiling", "\n"
" Hmmm, it appears that the ceiling does some 'moving around'.\n");
   new("/baseobs/weapons/dagger")->move(this_object());
//add_exit("south",CASTLE +"orc14","door");
add_exit("west",CASTLE +"orc07","door");
}
void init()
{
   ::init();
   add_action("do_pry","pry");
   add_action("open_chest","open");
}
int open_chest(string str)
{
   if(str != "chest")
   {
   return(0);
   }
   else
   {
     write("You strugle to open the chest...\n"
          "You finally open the chest and are pleasantly surprised to "
          "find some Orc Wafers.  You hurriedly scarf them down "
          "and feel a little healthier.\n");
   this_player()->adjust_hp(random(3)+1);
     return(1);
   }
}
int do_pry(string str)
{
   object * olist;
   int i;
   if(str != "gem")
      {
         return 0;
      }
   else
   {
      olist = this_player()->query_weapons_wielded();
     for(i = 0; i < sizeof(olist); i++)
      {
         if((string)olist[i]->query_name() == "dagger")
         {
            tell_object(this_player(),"The wall spins and tosses you headfirst into another room.!");
tell_room(this_object(),"\n"
" You feel a sudden gust of air and turn only to find dust descending from the ceiling.\n");
            this_player()->move(CASTLE+"orc14");
            this_player()->look_me();
            return 1;
         }
      }
   }
   return 0;
}
