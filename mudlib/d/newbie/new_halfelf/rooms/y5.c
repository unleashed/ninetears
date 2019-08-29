#include "path.h"
inherit "/std/newbieguild";
void setup()
  {
add_property("no_undead",1); set_short("Realm of the Elf:  Guild Room");
set_light(90);
   
	set_short("the Adventurer's Guild");	

	set_long("Guild Room\n"
       "     This brightly lit room is covered with sketches of famous "
   "elven adventurers who have gotten their start here.\n"
   "Diagrams scrawled on the walls show vital points of various "
   "beasts and hints on how to get killing blows. All in all , it's a very "
   "busy looking place.\n"
   "A small sign almost disappears into the clutter on the walls.\n"
            "\n\n");
   
	add_item("sign","\nThe sign reads:\n"
       "+-----------------------------------------------------+\n"
       "|                                                     |\n"
       "|                Adventurer's Guild                   |\n"
       "|                                                     |\n"
       "|      'cost' To find the XP cost to advance.         |\n"
       "|      'advance' To advance your skills.              |\n"
       "|      'info' To get some information.                |\n"
       "|                                                     |\n"
       "|      You cannot advance above level 5 here.         |\n"
       "|                                                     |\n"
       "+-----------------------------------------------------+\n"
       "\n");
   	
	add_item(({"sketches","sketch"})," The sketches "
       "are very old.  You are unable to make them out. \n\n");
	
	add_item(({"diagrams","diagram"}),"The only one you can understand says "
	"\"If it'll kill you, it'll kill a Drow as well.\"\n");

	add_exit("north",ROOMS+"y3.c","door");
	add_exit("south",ROOMS+"y7.c","door");
	add_exit("west",ROOMS+"v5.c","door");
	add_exit("up",ROOMS+"H5.c","door");
  }