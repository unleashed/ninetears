#include "path.h"
inherit HERE+"bsand.c";
setup() {
   
   add_property("no_undead",1);
   set_long("%^BOLD%^RED%^Isle of Belaern: Blood Sands%^RESET%^\n\n"
   "   The sand here appears to have been tossed around as though "
   "something or somethings were fighting here. Whatever it was has left "
   "black slime trails through the sand. "
   "\n\n");

add_item(({"slime","black slime"}),
   "\nThe slime looks disgusting, and appears to be composed of clotted blood "
   "bone chips and well.... slime. "
   "\n");
   set_short("%^BOLD%^RED%^Isle of Belaern : Blood Sands%^RESET%^");
 add_exit("northwest", HERE+"bsand12.c", "path");
   add_exit("east",HERE+"bsand17.c", "path");
   add_exit("west", HERE+"bsand15.c", "path");
  add_item(({"sand","desert"}),
              "The sand here is of blood-red color, with tiny bits of "
              "what looks like red and black rock.\n");

   set_night_long("%^BOLD%^RED%^Isle of Belaern: Blood Sands%^RESET%^\n\n"
   "You can't see much at all, the sand is colorless now in the dark apart "
   "from a phosporescent green glow from something in the sand. The glow "
   "gets redder as the dunes recede into the distance. Never enough to "
   "illuminate the light is possibly worse than no light at all as "
   "it distorts perspective and makes everwhere the same. Distant thunder "
   "rumbles continually like the snoring of a giant, and as lightning "
   "strikes the nearby dunes, the whole area brightens, then dims again. "
   "\n\n");
add_sound(({"thunder"}),"\nThe thunder grumbles continually here, the sound, "
   "and all the near misses prevent you from resting. "
   "\n");

}
