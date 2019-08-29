/* Added by Galvin 95-05-06 */
#include "path.h"
inherit ROOM+"baseroom";

void setup() {
    set_short("Realm of the Lizard:  Musty Swamp");
    set_light(60);
    set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
      "     Here the faint path turns slightly, allowing you to safely cross a"
      " treacherous quicksand area. A few gnarled trees can be seen as "
      "looming shadows in the dense mist. The soggy ground is covered with"
      " weeds, roots and shrubs, which probably only exist to hinder your "
      "passage. Eerie sounds echo in the distance and the smell of "
      "stagnant swampwater comes from the east, where you notice a big "
      "pond through the mist. The pond isn't reachable from this location "
      "but you're not sure if you would like to come near that murky water"
      " anyway. \n\n");
    add_property("no_undead",1);
    add_item("trees", "The trees are clad in swampmoss and twisted vines. The "
      "branches look like they try to reach out for you and you can't help"
      " but take an involuntary step backwards. \n\n");
    add_item("vines", "Twisted vines hang from the trees in great numbers. \n\n");
    add_item("shrubs", "These shrubs are covered with nasty thorns and seem to "
      "grow everywhere. You notice an opening behind the shrubs.\n\n");
    add_item("opening","You can't see much about this opening, maybe "
      "if you moved the shrubs you could tell more.\n\n");
    add_item(({"pond", "water",}), "There's a huge amount of murky water in these"
      " parts and the smell could kill unprepared adventurers. All the "
      "water seem to originate from the pond to the east. \n\n");
    add_item("weed", "The weed seem to grow everywhere and on everything. \n\n");
    add_item("roots", "Long gnarled roots that entangle your feet whenever they "
      "get the chance. \n\n");
    add_item("mist", "The mist continues to plague your sight and hearing. It "
      "doesn't look like it's going to clear up. \n\n");
    add_item("ground", "It's an unfriendly place to stand and walk on. \n\n");
    add_item("path", "The path turns slightly to pass a quicksand. It can still "
      "be followed in the dark. \n\n");
    add_item("quicksand", "The quicksand covers a small area here, waiting for "
      "careless creatures to take an eternal bath. \n\n");
    add_clone("/d/newbie/lizard/npcs/bog_beast.c",1);
    add_exit("northeast",SWAMP +"lizard05","room");
    add_exit("south",SWAMP +"lizard11","room");
}

void init() {
    add_action("do_move","move");
    ::init();
}
int do_move(string str) {
    if (!str)
    {
        write("\nThere are numerous things to move here.\n");
        return 1;
    }
    else
    {
        if(str == "shrubs" || str == "shrub")
        {
            write("\nYou move the shrubs and stumble into a cave of somesort.\n\n");
            say(this_player()->query_cap_name()+" moves some shrubs and dissappears. "
              "\n\n");
            this_player()->move(ROOM+ "cave.c");
            write("You enter a cave.\n");
            say(this_player()->query_cap_name()+" stumbles in from outside. "
              "\n\n");
            this_player()->look_me();
        }
        else
            write("Try as you might you just can't seem to move that.\n");
        return 1;
    }
}



