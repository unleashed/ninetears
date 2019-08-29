#include "path.h"
inherit "/std/room";
void setup(){
    set_light(50);
set_short("Realm of the Lizard:  Underwater");
set_long("\nRealm of the Lizard:  Underwater\n\n"
	 "     You are at the edge of an ancient underwater civilization"
             " that has fell into great ruin.  The ruins are to the east. "
             " There are lots of fish swimming around through the ruins. "
             " To the west there is a large cliff.\n");
   add_item("cliff", "This is a steep enbankment to the west.  There"
            " is a lot of seaweed growing on this cliff.\n");
    add_item("ruins", "These are the last remains of a past civilization. "
             " They are mostly rubble now.\n");
    add_item("fish", "These multicolored fish have take over this place.\n");
    add_item("seaweed", "This seaweed seems to be sort of covering a hole"
             " of some sorts.\n");
    add_item("hole", "As you peer into the hole, you realize that"
             " is is actually a large tunnel!\n");
    add_exit("north", UWATER+"uw06", "path");
    add_exit("east", UWATER+"uw03.c", "path");
    add_exit("southeast", UWATER+"uw04", "path");
    add_exit("south", UWATER+"uw08", "path");
}
void init(){
    add_action("do_move", "move");
    add_action("do_enter", "enter");
  ::init();
}
int do_move(string str){
   if(str == "seaweed"){
       say(this_player()->query_cap_name()+" moves some seaweed and finds"
          " a secret tunnel.\n");
         write("You move some seaweed and find a hidden tunnel!\n");
      return 1;
      }
}
int do_enter(string str){
   if(str == "tunnel"){
      say(this_player()->query_cap_name()+" enters the tunnel in the"
             " cliff.\n");
      write("You enter the tunnel in the side of the cliff.\n");
      this_player()->move(UWATER+"uw10");
      this_player()->look_me();
       return 1;
       }
}
