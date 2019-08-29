/*  Text alterations and replacement by Grimbrand 2-1-96                */

#include "path.h"
inherit "/std/underground";
int counter;

void setup() {
    add_property("no_undead",1); set_light(10);

    set_short("Realm of the Duergar:  Proving Grounds");

    set_long("\n   Realm of the Duergar:  Proving Grounds.\n\n"
      "     This area is is the same as the other rooms you have been "
      "in for the most part.  All of the walls have a fairly smooth "
      "finish except for the occasional marring where someone has "
      "tried to pick their way into another room.  The west wall looks "
      "as if it has been paid particular attention in that regard.  "
      "There are various irregularly sized and shaped rocks littering "
      "the floor.  It looks like someone started to work on those rocks "
      "and for some reason gave up and moved on.  Most of the moss "
      "seems to be intact except on the western wall, yet there still "
      "remains enough to provide adequate illumination.\n"
      "\n");

    add_item("rocks",
      "   Looking at the rocks you notice they are all rough and "
      "irregular in shape.  Thinking back to what Hewlen told you "
      "it might be best if you started picking the rocks if you "
      "have any hopes of progressing.\n\n");

    add_item("walls",
      "   As you look at the walls, you notice that in "
      "various places, it looks like someone has tried to chip "
      "away at the walls.  You wonder why they would bother "
      "picking in any direction.  It's not like they would dig "
      "into another room.\n");

    add_item("moss",
      "   As you look at the moss, you can see that it is "
      "growing directly upon the rock.  It gives off a blueish "
      "glow that helps to light the area up enough to where you "
      "can see fairly well.\n");


    add_exit("north",NEWBIE+"dlev1_02","path");
    add_exit("south",NEWBIE+"dlev1_04","path");
    add_exit("east",NEWBIE+"dlev1_01","path");
   add_exit("southwest",NEWBIE+"dlev1_06","door");
    add_clone(DNPC+"rat",2);
}

int swing(string str) {
    object *others;
    int c;
    if(str == "west") {
        if(counter < 5) {
            counter++;
            if(counter == 5) {
                write("As you hit the wall with you pick, the wall caves in "
                  "revealing a hidden chamber.\n");
                this_object () -> add_exit("west", NEWBIE+ "dlev1_05.c", "hole");
                write("A hidden room to the west has been revealed.\n");
                say(this_player()->query_cap_name()+" breaks the cave wall to "
                  "the west with his pick revealing a hiden room.\n");
                ::init();
                others = all_inventory(this_object());
                for(c=0;c<sizeof(others);c++)
                    if(living(others[c]))
                        others[c]->move(this_object());
                return 1;
            }
            else write("You swing your pick hitting the west wall.\n");
            return 1;
        }
    }
    else write("Pick where??");
    return 1;
}
