//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void init()
{
    ::init();
    add_action("col_me","collect");
}

int col_me(string str)
{
    object *stuff;
    int c;
    if(str == "moss")
    {
        stuff = all_inventory(this_player());
        for(c=0; c<sizeof(stuff);c++)
        {
            if((string)stuff[c]->query_name() == "moss")
            {
                write("You have collected some moss already!\n");
                return(1);
            }
            else
            {
                switch(random(5)+1)
                {
                case(1): clone_object(MISC + "blue_moss.c")->move(this_player());
                    break;
                case(2): clone_object(MISC + "red_moss.c")->move(this_player());
                    break;
                case(3): clone_object(MISC + "green_moss.c")->move(this_player());
                    break;
                case(4): clone_object(MISC + "yellow_moss.c")->move(this_player());
                    break;
                case(5): clone_object(MISC + "purple_moss.c")->move(this_player());
                    break;
                case(6): clone_object(MISC + "orange_moss.c")->move(this_player());
                    break;
                }
                write("You scrape a piece of moss from the wall.\n");
                return(1);
            }
        }
    }
    return(0);
}
object caverat;
void setup ()   { my_setup();
    set_short("Realm of the Dwarf:  Side Passage");
    set_zone("CAVE");
    set_light(40);
    set_long("\n   Realm of the Dwarf:  Side Passage\n\n"
      "     This side passage is very narrow, however you have "
      "plenty of room to stand upright.  The tunnel runs "
      "east and west here.  Going west would lead you to "
      "a large open area in the cave.  To the east you can "
      "just make out a bend in the tunnel.  There are low, "
      "muffled sounds coming from the east passage, but you "
      "are unable to make them out. "
      "\n\n");
    add_sound(({"sounds","muffled sounds"}),"The sounds are "
      "coming from the passage to the east.  You are barely "
      "able to make out the sounds of laughter and cheering.  "
      "\n\n");
    add_item(({"tunnel","walls","passage"}),"The tunnel walls "
      "are covered with some kind of beautiful, multi-colored "
      "moss.  "
      "\n\n");
    add_item(({"moss","mosses","multi-colored moss"}),"The moss "
      "here covers the walls with colors that fade from blue, "
      "purple, and green to yellow, orange, and red.  "
      "You might be able to collect a small amount of it "
      "without destroying the whole thing.  "
      "\n\n");
    add_exit("east",ROOM+"dwarf36","path");
    add_exit("west",ROOM+"dwarf34","path");
}
void dest_me()
{
    if(caverat)
        caverat->dest_me();
    ::dest_me();
}
