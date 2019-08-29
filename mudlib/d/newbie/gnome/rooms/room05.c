inherit "/std/room";
#include "path.h"
void setup()
{
    set_short("Macedonia:  Tunnels");
    set_light(40);
    set_long("Macedonia:  Tunnels\n\n"
      "     This appears to be the end of the tunnel.  The light"
      " is much brighter here than in the rest of these tunnels. "
      " To your south stands a large gate.  You don't know where"
      " this gate leads, but being the adventurer you are, you"
      " feel an incredibly strong urge to find out where is goes"
      " to."
      "\n\n");
    add_exit("north", VALLEY +"room04","path");
   add_exit("gate","/d/sf/areas/roads/of_road/crossroads","gate");
   add_clone(NPC+"king.c",1);
}
void init()
{
    ::init();
    add_action("go_gate","gate");
    add_action("go_north","n*orth");
}
int go_gate(string str)
{
    if(this_player()->query_property("GNOME_NEWBIE"))
    {
	write("\nAldinanachru tells you: Thanks again for finding the "
	  "Greystone.\n\nAldinanachru thanks you.\n\n");
      this_player()->move("/d/sf/areas/roads/of_road/crossroads");
	this_player()->look_me();
	return 1;
    }
    else
    {
	write("\nAldinanachru says: I can't let you leave until I find "
	  "my Greystone.\n\n");
	return 1;
    }
}
int go_north(string str)
{
    if(this_player()->query_property("GNOME_NEWBIE"))
    {
	write("\nAldinanachru says: You can't return to Macedonia."
	  "\n\nAldinanachru says: People must think I found the "
	  "Greystone.\n\n");
	return 1;
    }
    else
    {
	write("\nAldinanachru says: If you find the Greystone of "
	  "Roerx, please bring it to me.\n\n");
	this_player()->move(VALLEY +"room04");
	this_player()->look_me();
	return 1;
    }
}
