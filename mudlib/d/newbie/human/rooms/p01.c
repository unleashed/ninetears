#include "path.h"
inherit HAVMAND+"pirate.c";
object captain;
void setup()
{
    
   set_light(LIGHT);
    set_short("Isle of Havmand: Pirate Camp.\n");
    set_long("\nIsle of Havmand: Pirate Camp.\n"
    "   This is where the leader of the pirates has his camp. There is a small "
    "shelter built to one side with several empty bottles scattered around. "
    "There is a path leading to the beach, and another path leading to the "
    "main campfire. "
    "\n\n");
    add_item("shelter","A basic shelter made from the branches of trees, at least "
    "it looks as if it might be waterproof.\n");
    add_item("bottles","Empty bottles lie scattered around. You can only assume "
    "that they originally held some sort of alcoholic beverage.\n");
}
void init()
{
    add_exit("west",HAVMAND+"j20.c","path");
    add_exit("east",HAVMAND+"b02.c","path");
    add_exit("southwest",HAVMAND+"p03.c","path");

    ::init();
}
void reset()
{
   if(!captain)
   {
      captain = new(CHARS+"prat");
      captain->move(this_object());
   }
   ::reset();
}
void dest_me()
{
   if(captain) captain->dest_me();
   ::dest_me();
}
