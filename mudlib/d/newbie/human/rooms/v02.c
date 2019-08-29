#include "path.h"
inherit "/std/shop";
void setup()
{
    add_property("no_undead",1);
    set_short("Isle of Havmand: Shop");
    set_light(LIGHT);
    add_exit("east",HAVMAND+"t04.c","path");
    set_long("\nIsle of Havmand: Shop.\n\n"
    "   This is a small shop which doesn't seem to do a lot of business, mainly "
    "because everyone in this village is so poor.\n "
    "   Type \"list\" to get a list of the wonderful objects "
	 "\"browse\" to look at your object before you buy it, \"value\" "
	"to value your object before you \"sell\" it and of course \"buy\" "
    "to buy your wonderous object.\n\n");
   //set_open_condition("do_check");
    set_store_room(HAVMAND+"storeroom.c");

   add_clone(CHARS+"woman",1);
   set_item_table(HAVMAND+"SHOP_TABLE");

}
void init() {
::init();
add_action("do_check", "buy");
add_action("do_check", "se*ll");
}

int do_check(string str)
{
   if(!present("Old woman"))
   {
      notify_fail("Sorry, the shopkeeper is not present to help you.\n");
        return 0;
   }
   return(1);
}



