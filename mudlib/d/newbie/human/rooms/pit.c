#include "path.h"
inherit "/std/outside";
int found;
object chain;
object sword;
void setup()
{
    add_property("no_undead",1);
    set_light(LIGHT);
    set_short("Isle of Havmand: Ledge. ");
    set_long("\nIsle of Havmand : Ledge\n\n"
    "   You are standing on a narrow ledge halfway down a deep pit. Below you "
    "sea water surges to and fro in a most alarming manner. If you slip and "
    "fall from here you will certainly die. Above you to your right is the "
    "ledge you have just swung down from. You are very pleased to see that "
    "your vine is still firmly attached because there is no other way out "
    "from here.\n"
    "Lying on the ledge is the skeletal remains of an adventurer who wasn't "
    "so lucky. Most of his equipment seems to have disappeared as well. "
    "\n\n");
    set_night_long("\nIsle of Havmand : Ledge\n\n"
    "   It is difficult to see anything because it is so dark. You can just "
    "make out what looks like a skeleton of sorts lying on this ledge. "
    "\n\n");
    add_sound("water","You can hear the sea pounding back and forth against "
    "rock walls.\n");
    add_smell("water","You can smell sea water quite strongly.\n");
    add_item(({"water","sea water"}),"Foaming waves pound against the rock "
    "walls at the bottom of this pit, sending up clouds of spray which don't "
    "quite reach to the ledge. \n");
    add_item("ledge","Above you to the right is the ledge you came from. "
    "From here it looks a lot smaller than when you were standing on it. \n");
    add_item("vine","This is the vine you used to swing down on. One end is "
    "attached to your waist and the other is still tied to a tree above. "
    "This is lucky because you wont be able to get out of here without it. \n");
    add_item("tree","The small scraggly but well-rooted tree you tied the "
    "end of your vine to. \n");
    add_item("skeleton","White, sun-bleached bones are about all that is left "
    "of some poor adventurer who got stuck here. \n");

}
void init()
{
    add_exit("vine",HAVMAND+"j37.c","path");
    add_action("do_search","search");
    ::init();
}
void reset()
{
    found = 0;
}
void dest_me()
{
    ::dest_me();
}
int do_search(string str)
{
    if(! found)
    {
        write("You search the skeleton and find a rusty chainmail and a bastard "
        "sword. They could both use a good clean, but since it's the best gear "
        "you are likely to find here, you sit down and start work on sharpening and "
        "polishing.\n");

        say(this_player()->query_cap_name()+" searches the skeleton.\n",this_player());

        found = 1;

      chain = new(ARMOUR+"chainmail");
        chain->set_short("Rusty chainmail");
        chain->set_long("This chainmail has a thin coating of rust and it's "
        "going to be uncomfortable to wear for a while. But time, use and a "
        "wipe with an oily cloth now and then should clean it up.\n");
        chain->move(this_object());

      sword = new(WEAPON+"bastard_sword");
        sword->set_short("Rusty Bastard sword");
        sword->set_long("A large heavy sword, you may have trouble swinging it "
        "but it isn't going to stop swinging in a hurry. It looks in pretty "
        "good shape even though it has a patina of rust. A little time "
        "and tender loving care should restore it nicely.\n");
        sword->move(this_object());
    }
    else
    {
        write("You search around but don't find anything.\n");
    }
        return 1;
}

