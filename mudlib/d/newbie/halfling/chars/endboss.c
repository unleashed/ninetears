inherit "/obj/monster";
#include "path.h"

void setup()
{
set_name("rotting skeleton");
set_short("rotting skeleton");
add_alias("skeleton");
set_main_plural("skeletons");
add_plural("skeletons");
set_long("The remains of a fallen halfling that have arisen. This skeleton has been "
"cursed to walk these caves for an eternity. It's thirst is neverending, "
"it's thirst for blood. \n");

set_race("halfling");
set_gender(1);
set_level(12);
set_xp(700);
add_clone(MISC+"skelwhip.c",1);
add_clone(MISC+"staff.c",1);
init_equip();
 }
