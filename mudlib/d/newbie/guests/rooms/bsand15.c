#include "path.h"
inherit HERE+"bsand.c";
setup() {
   
   set_short("%^BOLD%^RED%^Isle of Belaern : Blood Sands%^RESET%^");
   set_long("%^BOLD%^RED%^Isle of Belaern: Blood Sands%^RESET%^"
   "   The seas of crimson sand seem to crash against the dark "       
              "mountain of rock to the north. The black obsidian-like "
              "walls impart in you a sense of penetrating remorse, "   
              "and awesome dread. The wind wails a piercing howl as it "   
             "blows through the jagged outcropping, almost as in pain in "
         "this tortured land."
         "\n\n");
   add_exit("east",HERE+"bsand16.c","path");
   add_exit("north",HERE+"bsand12.c","path");
   add_exit("south",HERE+"con04","path");
   add_property("no_undead",1);
  add_item(({"sand","desert"}),
              "The sand here is of blood-red color, with tiny bits of "
              "what looks like red and black rock.\n");
   add_item(({"mountain","outcropping","wall","walls","rock"}),
                "The smooth surface of the mountain seems to hold no "       
              "entrances, and nothing of interest. ");


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
   add_clone(NPCS+"dwight.c",1);
}
