# include "path.h"
inherit "/std/room";
void setup()
{
    add_property("no_undead",1);
    set_short("Isle of Havmand: Hovel.");
    set_light(60);
   set_long("\nIsle of Havmand : Hovel\n\n"
    "This miserable little hovel is nestled against the castle wall like all "
    "the others in this village. It looks as if it has been unused for a long "
    "time. There is a little table with a couple of chairs along one wall, "
    "and a long bench along another wall. Anything else that was here seems to "
    "have been removed at some time. "
    "\n\n");
    add_item("table","A dust covered little table, one of its legs looks to be "
    "broken.\n");
    add_item(({"chair","chairs"}),"Two wooden chairs, they are covered in dust "
    "and are in need of some repair as their backs have been broken.\n");
    add_item("bench","A long wooden bench is built along one wall. It looks as "
    "if it was designed to be slept on, although there are no blankets or "
    "mattress.\n");
   add_item("leg","The table only has three legs, the fourth is not "
      "here.  Odd, the table manages to stand upright with just three "
      "legs although it doesn't look too sturdy.\n");

    add_exit("east",HAVMAND+"t05.c","path");
}
