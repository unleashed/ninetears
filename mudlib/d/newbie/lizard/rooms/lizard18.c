/* Added by Galvin 95-05-02 */
#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
    set_short("Realm of the Lizard:  Musty Swamp");
    set_light(60);
    set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
      "     You make your way through the mist and thick vegetation. Twisted "
      "trees almost completely surround this area and they seem to loom "
      "forbidding over you. The faint path takes a sharp turn here and "
      "the mist seems to clear up further north. Eerie sounds can "
      "occasionaly be heard but you can't locate the sources through "
      "the dense mist. \n\n");
    add_property("no_undead",1);
    add_item(({"tree","trees",}), "These gnarled trees are covered with the "
      "usual swampmoss that seems to grow everywhere and on everything. "
      "Creepy vines hang from the thick trees and seem to move slowly. "
      "\n\n");
    add_item(({"vine","vines",}), "The way they seem to move against you is "
      "creepy, very creepy. \n\n");
    add_item("mist", "The dense mist follows your every move, twisting every "
      "sound and shape. \n\n");
    add_item("path", "The path is hard to see on the soggy ground but it can "
      "still be followed. \n\n");
    add_item("vegetation", "The ground is soggy and covered with gnarled weeds. "
      "Creepy vines hang from the trees in multitude. \n\n");
    add_item("ground", "It's soggy and covered with gnarled weeds. \n\n");
    add_exit("north",SWAMP +"lizard14","room");
    add_exit("west",SWAMP +"lizard17","room");
    add_exit("southeast",ROOMS+"swamp01.c","path");
}
