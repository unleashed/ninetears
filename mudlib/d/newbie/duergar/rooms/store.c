/*  Text alterations and additions by Grimbrand 2-3-96                  */

#include "path.h"
inherit "std/shop";

void setup() {

   set_short("Realm of the Duergar:  Bentol's Odds and Ends");
   
   add_property("no_undead",1); set_light(0);
   
   set_long("\n   Realm of the Duergar:  Bentol's Odds and Ends.\n\n"
	    "     Welcome to Bentol's Odds and Ends!  From where you're "
	    "standing you can see an assortment of equipment piled in the "
	    "back of the shop that you can purchase.  A small counter "
	    "blocks your way to the back room and a sign can be seen "
	    "hanging on the wall behind the counter.\n"
	    "\n");

   add_property("no_undead",1);

   add_item("sign","The sign reads:\n"
	    "Try \"list\" to get a list of the items available.\n"
	    "Try \"sell\" to sell an unwanted item.\n"
	    "Try \"browse\" to look at the item before you buy.\n"
	    "Try \"buy\" to buy the item.\n\n");

   add_item("counter",
	    "   This is a simple wooden counter that runs "
	    "along the northern wall.  There is a small sign "
	    "hanging on the wall behind it.\n"
	    "\n");

   add_exit("southwest",NEWBIE+"main02","door");

  set_item_table(NEWBIE+"SHOP_TABLE.c");
set_store_room(NEWBIE+"storerm.c");
}
