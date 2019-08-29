#include "path.h"
inherit "std/shop";
object midea;
void setup()
{

    set_short("Realm of the Lizard:  Midea's Little Shop");

    set_light(80);

    set_long("\nRealm of the Lizard:  Midea's Little Shop\n\n"
      "     This is Midea's Equipment Shop.  There are shelves "
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

    add_clone(CHAR+"midea.c",1);
    add_exit("southwest",ROOM+"lizard26.c","door");
    set_store_room(ROOM+"store2.c");
    set_item_table(ROOM+"SHOP_TABLE.c");
   set_open_condition("do_check");
}
int do_check(string str)
{
   if(!present("midea"))
   {
      notify_fail("Sorry, there is no one here to help you right now. "
         "Maybe you could try again later.\n");
      return 0;
   }
return(1);
}

