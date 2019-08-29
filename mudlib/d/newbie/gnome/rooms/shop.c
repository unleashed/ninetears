#include "path.h"
inherit "std/shop";

void setup() {

set_short("Macedonia:  The Copper Shoppe");

   set_light(80);

set_long("Macedonia:  The Copper Shoppe\n\n"
            "   You are somewhat crowded in the small entryway "
           "to the shop, but you are happy with the selection "
           " of equipment that is sold here.  Directly in front"
           " of you there is a large wooden counter.  Normally"
           " used for displaying the merchandise, the store is"
           " so fully stocked that there is a list of available"
           " merchandise on the counter.  Feeling very comfortable"
           " with the shopkeeper, you realize you might be able to"
           " work out a good deal with him.  You also notice a"
           " sign hanging on the wall.\n\n");
add_property("no_undead",1);
add_clone("/d/newbie/gnome/npcs/shopkeeper.c", 1);

	add_item("sign","The sign reads:\n"
		"Try /list/ to get a list of the items available.\n"
		"Try /sell/ to sell an unwanted item.\n"
		"Try /browse/ to look at the item before you buy.\n"
		"Try /buy/ to buy the item.\n\n");

	add_item("counter","This is a simple wooden counter that runs "
		"along the northern wall.  There is a small sign sitting "
		"upon it."
		"\n\n");

add_exit("northeast",VALLEY+"gnome14.c","door");
set_item_table(VALLEY+"SHOP_TABLE.c");
set_store_room(VALLEY+"storeroom.c");

}
void init()
{
   ::init();
   add_action("buy_me","buy");
   add_action("do_sell","se*ll");
}

int buy_me(string str)
{
   if(!present("dahl"))
   {
      write("There doesn't seem to be anyone here to take your order.\n");
      return(1);
   }
}

int do_sell(string str)
{
   if(!present("dahl"))
   {
      write("Sorry, you cannot sell items here unless a clerk is present.\n");
      return(1);
   }
}

