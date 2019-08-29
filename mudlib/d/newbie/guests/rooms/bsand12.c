#include "path.h"
inherit HERE+"bsand.c";
setup() {
   
   add_property("no_undead",1);
   set_short("%^BOLD%^RED%^Isle of Belaern : Blood Sands%^RESET%^");
set_long("%^BOLD%^RED%^\nIsle of Belaern: Blood Sands%^RESET%^.\n"
   "   Garish black streaks lightly dust the red dunes in this area. "
            "The dark color seems a terrible contrast to the red, almost "
            "as if one depicts life, and the other death. You see what "
         "looks like a large rock outcropping to the north."
         "\n\n");
   add_exit("east", HERE+"bsand13.c", "path");
   add_exit("west",HERE+"con02","path");
   add_exit("south", HERE+"bsand15.c", "path");
   add_exit("southeast",HERE+"bsand16.c","path");
  add_item(({"sand","desert"}),
              "The sand here is of blood-red color, with tiny bits of "
              "what looks like red and black rock.\n");
   add_item(({"rock","outcropping"}),
              "You can barely make out a large mountain of red rock in the "
              "distance.\n");


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
