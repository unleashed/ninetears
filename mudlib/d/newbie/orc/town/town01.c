#include "path.h"
inherit "std/shop";

void setup() {

	set_short("Realm of the Orc:  Snaga's Equipment Shop");

   set_light(80);

        set_long("\n   Realm of the Orc:  Snaga's Equipment Shop.\n\n"
                 "     This is Snaga's Equipment Shop.  There are "
                 "shelves "
		"along each of the walls that are full of items for "
		"you to purchase.  It appears to be good quality used "
		"merchandise.  There is a small counter here with a "
		"large handwritten sign on the wall behind it.  "
		"\n\n");

	add_item("sign","The sign reads:\n"
		"Try /list/ to get a list of the items available.\n"
		"Try /sell/ to sell an unwanted item.\n"
		"Try /browse/ to look at the item before you buy.\n"
		"Try /buy/ to buy the item.\n\n");

	add_item("counter","This is a simple wooden counter that runs "
		"along the northern wall.  There is a small sign sitting "
		"upon it."
		"\n\n");

	add_exit("out",TOWN+"town04.c","door");
   add_alias("south","out");
	set_store_room(TOWN+"store2.c");
set_item_table(TOWN+"SHOP_TABLE");
add_clone(CHAR+"snaga.c",1);
}

void init()
{
   ::init();
   add_action("buy_me","buy");
   add_action("do_sell","se*ll");
}

int buy_me(string str)
{
if(!present("snaga")) {
      write("There doesn't seem to be anyone here to take your order.\n");
      return(1);
   }
}

int do_sell(string str)
{
if(!present("snaga")) {
      write("Sorry, you cannot sell items here unless a clerk is present.\n");
      return(1);
   }
}

