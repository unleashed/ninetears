#include "path.h"
inherit "std/shop";
object parham;

void reset()
{
   if(!parham)
   {
      parham=clone_object(CHAR + "parham.c");
      parham->move(this_object());
   }
}

void setup() {

set_short("Realm of the Goblin:  Parham's Smelly Shop");

   set_light(80);

set_long("\nRealm of the Goblin:  Parham's Smelly Shop\n\n"
	 "     This is Parham's Smelly Shop. There are piles "
  "of equipment in the back of the shop that you can purchase. "
		"There is a small counter here with a "
		"large handwritten sign on the wall behind it.  "
		"\n\n");
add_property("no_undead",1);

	add_item("sign","The sign reads:\n"
		"Try /list/ to get a list of the items available.\n"
		"Try /sell/ to sell an unwanted item.\n"
		"Try /browse/ to look at the item before you buy.\n"
		"Try /buy/ to buy the item.\n\n");

	add_item("counter","This is a simple wooden counter that runs "
		"along the northern wall.  There is a small sign sitting "
		"upon it."
		"\n\n");

add_exit("south",ROOM+"ngob8.c","door");
	set_store_room(ROOM+"store2.c");
set_item_table(ROOM+"SHOP_TABLE");
}

void init()
{
   ::init();
   add_action("buy_me","buy");
   add_action("do_sell","se*ll");
}

int buy_me(string str)
{
   if(!parham)
   {
      write("There doesn't seem to be anyone here to take your order.\n");
return 1;
   }
}

int do_sell(string str)
{
   if(!parham)
   {
      write("Sorry, you cannot sell items here unless a clerk is present.\n");
return 1;
   }
}

int dest_me()
{
   if(parham)
   parham->dest_me();
   ::dest_me();
}
