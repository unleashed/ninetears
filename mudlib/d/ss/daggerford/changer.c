#include "path.h"
inherit "/std/money_changer";

object sign;
void setup() 
{
   add_property("location", "inside");
   set_short("Money changer");
   set_long("The money changer office.  You can see heavy steel bars on the "+
      "door and windows.  There is a large heavy looking door to the "+
      "south that is locked, bolted and chained shut.  There is a "+
      "small bench with a set of scales on it, behind which is a "+
      "small man.  There is a small sign hanging on the wall behind "+
      "the man.\n");
   set_light(80);
   add_exit("north", ROOM+"mark2", "door");
   
   add_item("small wooden bench", "A well-polished wooden bench.\n");
   add_item("golden scale", "A small set of golden scales, they look well "+
      "looked after and like they have had a lot of "+
      "use.\n");
   add_item("small man", "The small man is wearing expensive clothes "+
      "standing behind the counter.  He looks helpful "+
      "and informative.\n");
   add_item("heavy bolted chained large door",
      "The door looks very secure, if you could get through that "+
      "without the seven keys you need.. You would be impressed.\n");
   add_item("candle", "The candles are scattered around the rooms lighting "+
      "it up, on close inspection they don't seem to be "+
      "buring down.  The room is always lit by the candles "+
      "because, the windows don't let much light in.\n");
   add_item("window", "The windows are bolted barred and welded shut.  "+
      "You can see the light struggling to get in.\n");
   add_item("bar", "The bars are strong stuff, they are about an inch thick, "+
      "you assume they are made of solid steel.\n");
   add_item("chain", "The chains binding the door closed are made of black "+
      "strong looking steel.  It would take a heck of a "+
      "bolt cutter to break it.\n");
   sign = add_sign(
      "You should read it, really.\n",
      "\nType in:  change [number] [type] coins into [type]\n" +
      "    Example:  change 100 silver coins into gold\n\n");
}

dest_me() {
   if (sign) sign->dest_me();
   ::dest_me();
}

