//  Dwarven Newbie Area ---- Created by Mist ---- Fall 1994
#include "path.h"
inherit "/std/outside";
object rope;

void setup() {
    add_property("no_undead",1);
    set_light(80);
    set_short("Realm of the Dwarf:  Outside Ledge");
    set_long("\n   Realm of the Dwarf:  Outside Edge\n\n"
      "     As you step out of the cave and onto the ledge, "
      "you are overwhelmed by the incredible view that "
      "unfolds before you.  This ledge is sticking out from "
      "the side of a mountain that reaches up, almost to the "
      "clouds.  From this view you can see a city below, "
      "with more cities off in the distance to the north and "
      "east.  To the west you can see an ocean that is dotted "
      "with small islands and ships that must run between "
      "them.  The steep incline of this mountain makes it "
      "look like a very dangerous climb down to the bottom.  "
      "There are some rocks with strange scratches on them "
      "next to the cave."  
      "\n\n");
    set_night_long("As you step to the ledge, you are taken by the "
      "serene view of the city lights below.  You can see "
      "lights off in the distance to the north and east.  "
      "Considering the view, you must be near the top of a "
      "high mountain.  "
      "There are some rocks here with unusual markings "
      "on them.  "
      "\n\n");
    add_item(({"city","cities"}),"The cities seem to be busy.  "
      "As populated as this area is, the cities are probably "
      "busy day and night."
      "\n\n");
    add_item(({"ocean","islands"}),"The ocean is vast and you can "
      "see that is is dotted with islands and ships running "
      "to them.  "
      "\n\n");
    add_item(({"mountain"}),"You are on a ledge near the top of "
      "the mountain.  Looking down you can see an incredible "
      "view of the realms.  Upward, you can see nothing but "
      "the clouds and sky.  "
      "\n\n");
    add_item(({"sky","clouds"}),"The clouds in the sky are just "
      "overhead.  You can almost touch them.  "
      "\n\n");
    add_item(({"rocks","scratches","markings"}),"The scratches "
      "on these rocks look like they have been made by a rope "
      "that someone must have tied here to climb up or "
      "down the mountain.  "
      "\n\n");
    add_exit("in",ROOM+"dwarf02","path");
}
void init()
{
    add_action("tie_me","tie");
    ::init();
}
int tie_me(string str)
{
    if(str == "rope to rocks")
    {
        object *stuff;
        int c;
        stuff = all_inventory(this_player());
        for(c=0; c<sizeof(stuff);c++)
        {
            if((string)stuff[c]->query_name() == "coil of rope")
            {
                // Taniwha 1995, quick hack to get it to work

                if(this_player()->query_level() > 4)
                    //i/f(this_player()->query_properties("skill_rope_knots"))
                {
                    write("You tie an excellent triple-hitch knot.  This "
                      "secures the rope to the rock.\n");
                    stuff[c]->dest_me();
                    clone_object(MISC + "rope2.c")->move(this_object());
                    return(1);
                }
                else
                {
                    write("You don't have the skills needed to tie a "
                      "knot that could support your weight.\n");
                    return(1);
                }

            }
            else
            {
                write("You do need a rope to do that.\n");
                return(1);
            }
        }
    }
}
