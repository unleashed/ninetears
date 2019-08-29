#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "You stand on a ledge halfway down a large rocky pit. A damp looking "
    "cleft in the edge of the pit lies behind you. The air is filled with "
    "small flying insects and the sounds of water. A small waterfall seems "
    "to run down into the pit somewhere to your right, and sea water is "
    "surging around at the bottom of the pit. A tunnel seems to connect "
    "to the sea down there somewhere. Around the edge of the pit to your "
    "lower left, there seems to be another ledge. There is small tree growing "
    "out of the pit edge just above you. "
    "\n\n");
   set_night_long("\nIsle of Havmand: Jungle\n\n"
      "   Sounds of cascading water come to you out of the darkness, although "
      "you can't see much. Just above you, you can see the shadowy outline "
      "of what looks like a small tree, and below you to the left, a darker "
      "shadow hints at the possibility of another ledge. Getting to it could "
      "be a challenge though. "
      "\n\n");
    add_sound(({"waterfall","water"}),"The steady rattle of the waterfall is mixed with "
    "the lower pitched swooshing sounds from the surge pool below. "
    "\n");
   add_item("pit","A large hole in the ground, it has seawater swirling round "
      "in the bottom, and there is no way to get down that far anyway.\n\n");
    add_item("insects","Lots of gnats, and quite a few larger things, which "
    "seem eager to make closer aquaintance with your blood. \n");
    add_smell("water","You can smell sea water quite stongly.\n");
    add_item("waterfall","You can't actually see it, but you can hear "
    "it clearly enough.\n");
    add_item("tunnel","You can just see the upper lip of the tunnel mouth "
    "with water breaking into foam as it surges to and fro. \n");
    add_item("ledge","You grab onto the tree, and swing out a little.\n"
    "There seems to be something lying on the ledge to your left, but "
    "you'd need something to help you get back up, even if you didn't "
    "break your neck jumping down. "
    "\n");
    add_item("tree","A small scraggly, but particularly tough looking "
    "tree, it seems to have sent roots deep into the rock above you.\n");
add_item("cleft","This is a section of cliff which has been washed away, allowing "
"access to the sea.  Unfortunately, it is several hundred feet straight DOWN.  \n");
}
void init()
{
    add_exit("east",HAVMAND+"j36.c","path");
    add_action("do_rope","climb");
    ::init();
}

int do_rope(string str)
{
    object *olist;
    olist = find_match("vine",this_player());
    if(!sizeof(olist))
    {
        write("You can't do that, without a rope you'll be trapped "
        "forever in the pit.\n");
       say((string)this_player()->query_cap_name()+" looks at "
       "the ledge below speculatively for a few seconds, tenses, "
       "then chickens out.\n",this_player());
       return 1;
   }
   write("You swiftly tie one end of your vine to the tree above, wind "
   "the rest around your waist, tying the end off neatly, and with a wild "
   "yell swing down to the ledge below !\n");
   say("YEEEEEEEEEEE HAAAAAAAAAAAAAAAAA!\n");
   this_player()->move(HAVMAND+"pit.c");
   this_player()->look_me();
   return 1;
}




