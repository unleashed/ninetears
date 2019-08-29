inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1);
set_short("Realm of the Gnome:  Macedonian Tunnels");
set_zone("TUNNEL");
set_light(40);
set_long("\n\nRealm of the Gnome:  Macedonian Tunnels\n\n"
	 "     You have now entered the section of the Macedonian Tunnels used "
       "only by gnomes.  As you look around you see many stalagtites and "
       "stalagmites protruding from the floor and the ceiling.  There is "
       "an underground stream running smoothly along the center of the"
       " passageway, and there seems to be some odd plant life growing next to "
       "it.  There appears to be some sort of drawings on the walls, and "
       "some other various objects that appear to have been abandoned here."
     " To the west you can see Macedonia, and the tunnel continues to the east,"
     " and the southeast."
       "\n\n");
add_smell("air","The air smells rather damp and musty, and you can tell that"
     " you have entered an underground tunnel.\n\n");

add_item(({"stalagmites","stalagmite","floor"}),"As you look around you see that some of"
     " the stalagmites jutting up from the floor actually join together with"
     " the stalagtites from the ceiling.\n\n");
add_item(({"stalagtites","stalagtite","ceiling"}),"As you look up at the ceiling, you notice many"
    " stalagtites jutting down at you from the roof of the tunnel.  While you watch"
    ", you see a drop of water fall from one and hit you on the forehead.\n\n");
add_feel("air","The air feels kinda damp and chilly.\n\n");
add_item("stream","The stream seems to be shallow but you arent sure.  It is "
     "very clear and its surface is almost mirror-like.\n\n");
add_item("drawings","These appear to be ancient drawings, but upon further"
      " inspection you see that they are actually complex designs for some"
     " invention.\n\n");
add_item(({"walls","wall"}),"The walls of the tunnel are very slick due to the water "
     "that trickles down them and into the stream.\n\n");
add_item("objects","As you take a closer look at these odd objects, you notice"
      " that they are actually half finished inventions that have been"
     " abandoned by their makers.\n\n");
add_item(({"plants","plant-life","plant"}),"These are very odd plants.  They seem almost colorless "
     "because they are growing with an absence of light, and yet they have"
     " the most unusual bloom.\n\n");
add_item(({"bloom","flower","petals"}),"The petals of the bloom are almost translucent, and yet"
     " they appear so soft that you could touch them.  The bloom itself seems"
     " to have taken after a type of wild lilly.\n\n");
add_feel("bloom","As you gently rub one of the petals, you enjoy its velvety"
      " texture.");
add_exit("west",GNOME +"gnome15","path");
add_exit("east",UNDER +"under02","path");
add_exit("southeast",UNDER +"under03","path");
add_clone(CHAR +"bat.c", 1);
}
