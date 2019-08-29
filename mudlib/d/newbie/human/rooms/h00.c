#include "path.h"
inherit "/std/outside";
int found;
object vine;
void setup()
{
    add_property("no_undead",1);
    set_light(LIGHT);
    set_short("Isle of Havmand : Hilltop");
    set_long("\nIsle of Havmand : Hilltop\n\n"
      "   This is the top of the hill and above the treeline at last. You look down "
      "onto the canopy of trees from the jungle you have just climbed through. "
      "The ground here is very rocky and dry, but a few trees still manage to "
      "flourish. "
      "\n\n");
    set_night_long("\nIsle of Havmand: Hilltop.\n"
      "   Everything seems very dark and the few shapes you can make "
      "out are full of mystery. Far out on the horizon you see an intermittent "
      "flashing light, and closer in the dark shapes of trees loom at you in the "
      "gloom. "
      "\n\n");
    add_item("canopy","You can look down on the tops of the jungle trees below "
      "you. They seem even thicker from here than when you were walking through "
      "them.\n");
    add_item(({"tree","trees"}),"The trees of the jungle are below you. The few "
      "trees here are healthy looking, and have vines growing on them. \n");
    add_item("vines","Strong rope like vines hang from the trees. "
      "They could be useful, if you can find something to chop them with.\n");
    add_item(({"light","flashing","flashing light"}),"You can see a light flashing "
      "on and off steadily in the far distance. You assume it is a warning "
      "device of some sort, probably a lighthouse.\n");

    add_exit("southeast",HAVMAND+"j29.c","path");
}

void init()
{
    add_action("do_cut","cut");
    add_action("do_cut","slice");
    add_action("do_cut","chop");
    ::init();
}
int do_cut(string str)
{
    if (!str)
    {
	write("Cut what?");
	return 1;
    }
    if(str == "vine")
    {
	object *ob;
	ob = find_match("hatchet",TP);
if(sizeof(ob) <1)
	{
write("You don't have anything that could cut through that.  \n");
return 0;
}
else
{
	    vine = new(OBJ+"vine.c");
	    vine->move(this_object());
write("With a swift swing, you cleave the vine in two.  It falls from the tree and "
"crumples upon the ground.  \n");
	    return 1;
	}
    }
    else
    {
	write("Cut what?\n");
    }
}
