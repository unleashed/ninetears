#include "path.h"
inherit "/std/shop";
void setup()
{
    add_property("no_undead",1);
    set_short("Galastriia :  Shop.");
    set_light(65);
    set_long("\nGalastriia :  Shop.\n\n"
      "This shop is set in the base of a long dead tree.  It appears to be quite old, and "
      "the family that mantains it manages to keep it relatively well stocked.\n"
      "Type \"list\" to see a list of what is offered for sale "
      "\"browse\" to look at something before you buy it.  \"Value\" "
      "is to see the how much your object is worth before you \"sell\" it, and \"buy\" is "
      "to purchase an object from the store.\n\n");
    //set_open_condition("do_check");
    add_exit("north",ROOMS+"aaroc_center.c","door");
    set_store_room(ROOMS+"storeroom.c");

    add_clone(CHAR+"geldon.c",1);
    set_item_table(ROOMS+"SHOP_TABLE");



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



