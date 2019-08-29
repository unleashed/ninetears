
#include "path.h"
inherit "/std/room";
int found;
object cask;
void setup()
{
    add_property("no_undead",1);
    set_short("Isle of Havmand: Tavern Cellar.");
    set_light(40);
   set_long("\nIsle of Havmand : Tavern Cellar\n\n"
    "You are in the gloomy little cellar below the tavern. There are a lot of "
    "old bottles in racks along one wall, and several small casks piled high "
    "along another wall. Cobwebs are draped over everything, and dust covers "
    "all the available surfaces. A narrow staircase leads up to the tavern bar. "
    "\n\n");
    add_item("bottles","Old bottles filled with unidentifiable liquids, you "
    "decide not to investigate too closely.\n");
    add_item("casks","Small wooden casks used for storage. Some of them are "
    "full of what smells like pickled fish, but several are empty.\n");
    add_item("cobwebs","Spiders have been very busy down here, and cobwebs are "
    "artistically draped over everything.\n");
    add_item("dust","Dust covers everything.\n");
    add_feel("dust","The dust feels gritty and leaves black marks on your fingers.\n");
    add_smell("fish","Really obnoxious, it smells like old socks.\n");
    add_item(({"stairs","staircase"}),"A small, narrow, wooden staircase, it leads "
    "up to the main bar of the tavern.\n");
add_item("racks","These serve to hold the wine casks in place, off the ground.  \n");
add_item(({"wall","walls"}),"There is nothing special about these plain cement walls.  \n");


}
void init()
{
    add_exit("up",HAVMAND+"v01.c","path");
    add_action("do_take","get");
    add_action("do_take","take");
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
int do_take(string str)
{
    if(!found)
    {
        write("You find a couple small casks in the cellar.\n");
        say(this_player()->query_cap_name()+" finds something in the cellar.\n",this_player());
        found = 1;

        cask = new(OBJ+"cask.c");
        cask->move(this_player());
        cask = new(OBJ+"cask.c");
        cask->move(this_player());

    }
    else
    {
      if(lower_case(str) == "cask")
      {
        write("It seems that someone has beaten you to all the empty casks.\n"
        "Never mind with a bar upstairs there are bound to be some sometime.\n");
      return 1;
      }
    }
    return 0;
}





