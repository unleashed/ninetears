#include "path.h"
inherit "/std/room";

void setup() {
    set_light(50);
    set_short("City of Dendall:  Farm");
   add_property("no_undead",1);
    set_long("\nCity of Dendall:  Farm\n\n"
      "    Stepping through the deepest, darkest shadows of Dendall, "
      "you come to the southern edge of the farm.  The ground is littered "
      "with broken or cast off farming tools.   Scanning north, you see "
      "the crops of the Duergar, animated in a nightmarish dance by the "
      "ever present wind of malevolence that sweeps through all areas "
      "governed by Grimbrand.\n\n");
    add_item("bags", "There are several bags that seem to be full with something"
      ".  At first you thought it was some kind of seed, but as you take "
      "a closer look, you can see that it is actually full of little "
      "mushrooms.\n");
    add_item("tools", "You see a hoe, a few shovels, and a rake leaning up "
      "against the cave wall.\n");
    add_item("hoe", "It appears to be just a normal hoe with a "
      "steel head on it.\n");
    add_item("shovel", "It appears to be just a normal shovel with a "
      " steel head on it.\n");
    add_item("rake", "It appears to be just a normal rake with individually "
      "crafted steel fingers.\n");
    add_item("fields", "Well ordered fields sweep out to the east, growing "
      "the many crops that sustain the Duergar population.\n");
    add_item("crop", "Shadow figures, caught up in a bizarre ritual of "
      "growth, the crops grown in the underdark are steeped in the "
      "same evil that permeates through everything here.\n");
    add_item("shadow", "The personal servants of Grimbrand, the shadows you "
      "see here hover ominously, menacingly, over all that you "
      "survey.\n");
    add_item("ground", "The ground is a mixture of dirt and rock.  Scattered "
      "about, you see various farming tools.\n");
    add_feel("wind", "An eerie breeze rushes through these caverns, bringing "
      "with it the malevolence and anger of the God of Death, "
      "Grimbrand.\n");

    add_clone(NPCS+"dfarmer.c", 1);	 
    add_exit("east", HERE+"den04", "road");
    add_exit("north",HERE+"den07","road");
    add_exit("south", HERE+"den01", "road");
    set_zone("farm");
}
