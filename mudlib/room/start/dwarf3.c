#include "path.h"
inherit "/std/room";

void setup()
{
        set_short("Dwarfen Storeroom.");

        set_long("This is a long disused storeroom with various bit of "
                "equipment etc scattered arround. Among the debris you "
                "notice a small sack which is bulging. There are various "
                "metal items but even you have trouble seeing what is actually under "
                "all the dust. You hear the currying off feet...damned  "
                "those rats.\n");
                                                       
        add_property("no_undead",1); set_light(80); 

        add_item("Sack", "This is a small but strong sack.\n");

        add_item("Metal", "This is generally rusted but you can make out a "
                "Small axe. The rest of the items are too hidden.\n");

        add_item("Debris", "This is dirty and smelly, p'haps leave it alone?.\n");

        add_item("Rats", "These are dark furred creatures.\n");

        add_alias("sack", "Sack");
        add_alias("metal", "Metal");
        add_alias("rat", "Rats");
        add_alias("rats", "Rats");
        add_alias("debris", "Debris");


        add_exit("west", PATH+"dwarf.c", "door");
}
