#include "path.h"
inherit HERE+"bsand.c";
setup() {
   
   add_property("no_undead",1);
   set_short("%^BOLD%^RED%^Isle of Belaern : Blood Sands%^RESET%^");
   set_long("%^BOLD%^RED%^Isle of Belaern: Blood Sands%^RESET%^\n\n"
   "   You are standing at the base of a huge mountain of red rock. "
   "The sheer walls appear menacing, and unclimbable."
   "\n\n");
   add_exit("west", HERE+"bsand12.c", "path");
   add_exit("south", HERE+"bsand17.c", "path");
   add_clone(NPCS+"dghoul.c",1);
  add_item(({"sand","desert"}),
              "The sand here is of blood-red color, with tiny bits of "
              "what looks like red and black rock.\n");
   add_item(({"walls", "wall", "mountain"}),
              "Looking up the sheer face of the mountain, you see several "
              "indentations in the rock, and a small plant.\n");
   add_item(({"indentation","indentations"}),
   "All but one of the indentations looks of no interest "
            "to you. A circle indentation near the base of the mountain looks "
            "promising.\n");
   add_item("circle","Upon closer inspection, you realize that this is not a "
            "circle, but what appears to be the imprint of a hand.\n");
   add_item("hand","The outline looks like the imprint of a hand with a "
            "pair of lips imprinted inside of it.\n");
   add_item("lips","This pair of lips look like the lips of a lover begging "
            "for a smooch.\n");
  add_item("plant","This is a small, scraggly plant clinging to life on the "
           "rock.\n");

}
init() {
 ::init();
   add_action("kiss_lips","kiss");
  add_action("kiss_lips", "smooch");
  }
kiss_lips(string str) {
  if(!str) { return(0); }
if(str != "lips" && str != "lip") { return(0); }
   write("You gently touch your lips to the lips on the wall....and a door "
         "suddenly appears from the wall around the hand and swings open. You "
         "are thrown into the room, and the door shuts behind you.\n");
   say(this_player()->query_cap_name() +" kisses an indentation in the wall, and "
         "is pulled into an opening which appears, and suddenly closes.\n");
   write("\n");
   this_player()->move(HERE+"deadmans.c");
  this_player()->look_me();
   return 1;
}
