#include "path.h"
inherit "/std/outside";
inherit "/d/hoerk/belaern/s_jung/city/shops/restock.c";


void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Deep in the High Forest");
set_long("\n   Realm of the Elf:  Deep in the High Forest.\n\n"
         "     You are deep in the High Forest.  "
    "This looks like a very gloomy and unsecure part of the forest. "
	"There are a lot of large trees and bushes around here.  "
	"To the north you see a dark, forbidding forest.  Perhaps "
	"this is the evil that the treant warned you about.  You "
	"might want to wait till you are stronger and more experienced "
        "before you venture into the gloomy forest."
        "\n\n");

 add_item("tree","The trees are covering the sky above you.\n");
 add_item("bush","The bushes are covering the view in all directions.\n");
 add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
	"Everywhere you look, you see small animals moving.\n");

 add_exit("south", ROOM+"fo7", "road");
add_exit("north",GLOOM+"dfo1a","road");

  set_zone("forest"); 
add_clone(CHAR+"shirein",1);
}

