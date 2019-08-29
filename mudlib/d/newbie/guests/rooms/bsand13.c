#include "path.h"
inherit HERE+"bsand.c";
setup() {
   
   add_property("no_undead",1);
   set_short("%^BOLD%^RED%^Isle of Belaern : Blood Sands%^RESET%^");
   set_long("%^BOLD%^RED%^Isle of Belaern: Blood Sands%^RESET%^\n\n"
   "   The red dunes slowly decrease in height as you near the large "
            "mountain of rock to the north. It seems as though the sizable "
         "outcropping has simply sprung out of the very desert."
         "\n\n");
   add_exit("west", HERE+"bsand14.c", "path");
   add_exit("east", HERE+"bsand12.c", "path");
  add_item(({"sand","desert"}),
              "The sand here is of blood-red color, with tiny bits of "
              "what looks like red and black rock.\n");


   set_night_long("%^BOLD%^RED%^Isle of Belaern: Blood Sands%^RESET%^\n\n"
   "   You can't see much at all, the sand is colorless now in the dark apart "
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
