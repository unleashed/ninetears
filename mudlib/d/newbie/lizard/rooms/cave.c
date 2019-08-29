// Made by Tek August 1995

#include "path.h";
inherit "/std/room";
object *npc;
void setup()
{
    // Descriptions...
    set_light(70);
    set_short("Realm of the Lizard:  Gloomy Cave");
    set_long("\nRealm of the Lizard:  Gloomy Cave\n\n"
      "     This cave is currently the liar of some creature, "
      "although it looks like it wasn't always. "
      "In the back of the cave there are some piles of junk and old "
      "furniture. There are bones scattered all over and vines and weeds, "
      "mingled amongst them.\n\n");

    add_property("no_undead",1);
    add_item("junk","This junk is really old, maybe a hundred years. "
      "You see a large chest of somesort buried amongst the "
      "furniture.\n\n");
    add_item("furniture","This stuff is so old it is unrecognizable. "
      "\n\n");
    add_item("bones","Most of these bones are from creatures you would "
      "normally find in the swamp, but some look like the bones "
      "of lizard-men.\n\n");
    add_item("chest","This is a really large iron bound chest. It "
      "looks like it has been here a hundred years. Maybe "
      "this is the treasure the smith went to look for.\n\n");
    add_item(({"vines", "weeds",}),"These vines and weeds look like they "
      "were brought in to the cave because they are not growing "
      "in anything they are just laying about.\n\n");
    // Items....
    add_exit("out",ROOM+"lizard09.c","path");

    // Exits....
    npc=allocate(1);
} /*setup() */

void init() {
    add_action("do_open","open");
    ::init();
}
int do_open(string str) {
    if(str=="chest") {
        if(this_player()->query_property("LIZARD_TREASURE"))
        {
            write("You open the chest but it seems to be empty.\n\n");
            return 1;
        }
        else
        {
            write("You have found some gold, a sparkling green "
              "chainmail, and a gemstone.\n\n"
              "You quickly grab up the coins, better get the chainmail and "
              "gemstone."
              "\n\n\n");
            new(MISC+"gem.c")->move(this_object());
            new(ARMOR+"chainmail2.c")->move(this_object());
            this_player()->adjust_money(50,"silver");
            this_player()->add_timed_property("LIZARD_TREASURE",1, 3600);
            return 1;
        }
    }
}

void reset()
{
    int i;
    for(i = 0; i < sizeof(npc); i++)
    {
        if(!npc[i])
        {
            npc[i]=clone_object("/d/newbie/lizard/npcs/bog_beast2.c");
            npc[i]->move(this_object());
        }
    }
}

void dest_me()
{
    int i;
    for(i = 0; i < sizeof(npc); i++)
    {
        if( npc[i] ) npc[i]->dest_me();
    }
    ::dest_me();
}

