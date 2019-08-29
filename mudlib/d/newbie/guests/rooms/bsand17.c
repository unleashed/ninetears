#include "path.h"
inherit HERE+"bsand.c";
setup() {
   
   add_property("no_undead",1);
   set_short("%^BOLD%^RED%^Isle of Belaern : Blood Sands%^RESET%^");
   set_long("%^BOLD%^RED%^Isle of Belaern: Blood Sands%^RESET%^\n\n"
   "   You stand in an area of hard flat sand, there is no horizon here, only "
   "and indistinct heat haze in all directions. The sun beats down "
   "disorientating you, and the wind whips across the sands erasing "
   "any footprints. You can hear what seem to be voices...... whispering. "
   "All in all this is a depressing place to stand. "
   "\n\n");
   add_exit("east",HERE+"con03","path");
 add_exit("west", HERE+"bsand16.c", "path");
   add_exit("north", HERE+"bsand14.c", "path");
  add_item(({"sand","desert"}),
              "   The sand here is of blood-red color, with tiny bits of "
              "what looks like red and black rock.\n");
   add_sound(({"voices","whispering"}),
"The voices whisper, 'Lay down, die, give up, "
"you struggle and for what?'"
   "\n\n");

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
