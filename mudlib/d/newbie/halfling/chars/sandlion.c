inherit "/obj/monster";
#include "path.h"

void setup()
{
set_name("sandlion");
set_short("sandlion");
add_alias("sandlion");
set_main_plural("sandlions");
add_plural("sandlions");
set_long("This is the ferocious Sandlion.  It feeds on whatever is unlucky enough to "
"get trapped in its layer.  In this case, maybe you.  It has 8 legs, huge fangs, and "
"large, black eyes.  In one of its legs, you can see a glowing, blue gemstone.\n");

set_race("spider");
set_gender(1);
set_level(15);
set_xp(700);
set_str(14);
set_dex(13);
set_guild("fighter");
add_clone(MISC+"jewel.c",1);
 }
