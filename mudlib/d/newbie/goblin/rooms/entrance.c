// Goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
    set_zone("goblin_newbie");
    set_short("Realm of the Goblin:  Gloomy Cavern");
    set_long("\nRealm of the Goblin:  Gloomy Cavern\n\n"
      "     You stand in the middle of a large cavern.  There are several "
      "other Goblins of varying ages wandering around.  The soft moss under"
      " your feet makes you think of home.  There is a large statue here in"
      " the middle of the room, but you are unsure what for.  This is where"
      " all Goblin families leave their young children to learn the ways of"
      " Goblins.  To the south, you see a mighty gate blocking your way, "
      "but to the north, northwest, and east there are paths to the well-"
      "traveled caves.\n\n");
    add_property("no_undead",1);
    add_item(({"children", "goblins"}),
      "These are all young goblins that have come of age. About to "
      "begin lifes long adventure.\n");
    add_item(({"caves", "caverns"}),
      "They appear to be well traveled caves.\n");
    add_item(({"wall", "rock"}),
      "The walls here are dark and damp. They are covered "
      "with moss and fungus. Some places there are "
      "bodily wastes smeared up on the walls. The "
      "sight of it is disgusting.\n");
    add_item(({"statue"}),
      "This ten foot statue is of Chip-tooth the great. The mighty dwarf"
      " slayer. He is holding aloft the severed head of a dwarven warrior, there is a plaque on the base.\n");
    add_item(({"gate"}),
      " This enormus gate is made of metal, you can't see much at this distance other then it is large.\n");
    add_item(({"plaque"}),
     "Chip-tooth the Dwarf Slayer died while advancing to the rear "
     "in the Great Dwarf Mine Wars.  The plaque is a bit tarnished, "
     "perhaps you could rub it clean for other goblins that are not "
     "as wise as you can read it clearly.  "
     "\n\n");
    add_item(({"moss", "fungus"}), 
      "The moss and fungus probably grow here "
      "because the walls are so damp and wet.\n");

    set_short("entrance");
    set_light(45);
    // Items...

    add_exit("north", ROOM+"guildrm3.c","path");
    add_exit("south",ROOM+"ngob2.c","path");
    add_exit("northwest",ROOM+"ngob8.c","path");
    add_exit("east",ROOM+"ngob4.c","path");
    // Exits...

    add_clone(CHAR+"drole.c",1);
    add_clone(CHAR+"cave_rat.c",1);
    add_clone(CHAR+"goblin.c",1);
    //NPC'S

} /* setup() */

void init()
{
   ::init();
   add_action("rub_plaque","rub");
}
int rub_plaque(string str)
{
   if(str != "plaque")
   {
   return(0);
   }
   {
     write("As you rub the plaque you feel the blessings of Chip-tooth "
          "surge into your soul.\n");
     this_player()->adjust_hp(random(3)+1);
     return(1);
   }
}
