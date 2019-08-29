//Ljen nov -96
// This one by Joram for FR on 23 - 09 - '96

#include "path.h"
inherit "/std/shop";
void setup() {
   set_short("%^GREEN%^Jungle %^CYAN%^Town%^RESET%^ - %^BOLD%^WHITE%^Smithy%^RESET%^");
   set_light(80);
   set_long("This is one of the most important shacks in this "
            "small little jungle town, indeed it has the equipment "
            "needed by the inhabitants of this town, it's warriors and "
            "some things to care for the orchard at the northeast.  "
            "Behind a big counter there is a half elf which is looking "
            " at you quite interesting.  Behind the counter there is a "
            "sign with the list of utilities you can find in here.\n");

   add_item("sign","The sign reads:\n"
                "Try /list/ to get a list of the items available.\n"
                "Try /sell/ to sell an unwanted item.\n"
                "Try /browse/ to look at the item before you buy.\n"
                "Try /buy/ to buy the item.\n\n");

   add_item("counter","This seems to be made with the wood of the tree's trunk "
                      "itself.  It goes from the east wall to the west one and it "
                      "has an opening at the east side where you can access to a smaller "
                      "room and the counter itself.\n");

   add_clone(NPC+"sfaern.c",1);
   add_exit("out", TOWN+"b4.c", "door");
   set_store_room(TOWN+"storeroom.c");
   set_item_table(TOWN+"SHOP_TABLE");
}

/*
void init() {
::init();
add_action("do_check", "buy");
add_action("do_check", "se*ll");
}

do_check(string str)
{
   if(!present("sfaern"))
   {
      notify_fail("Sorry, the shopkeeper is not present to help you.\n");
        return 0;
   }
   return(1);
}


*/
