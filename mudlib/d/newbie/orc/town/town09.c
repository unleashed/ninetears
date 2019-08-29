#include "path.h"
inherit "std/shop";


object shagrat;

void reset()
{
   if(!shagrat)
   {
      shagrat = clone_object(CHAR +"shagrat.c");
      shagrat->move(this_object());
   }
}

void setup() {

	set_short("Realm of the Orc:  Shagrat's Smithy");

   set_light(50);


   set_long("\n   Realm of the Orc:  Shagrat's Smithy.\n\n"
            "     This is a small stone building that houses Shagrat's "
            "Smithy.  There is a small counter along the southern wall "
            "with a number of recently made items that are for sale.  "
            "Shagrat keeps a large variety of high quality items "
            "here.  There is a small sign on the counter.  "
		"\n\n");
	add_item("sign","The sign reads:\n"
		"Try /list/ to get a list of the items available.\n"
		"Try /browse/ to look at the item before you buy.\n"
		"Try /buy/ to buy the item.\n\n");
	add_item("counter","This is a simple wooden counter that runs "
		"along the northern wall.  There is a small sign sitting "
		"upon it."
		"\n\n");
	add_item("forge","The forge is cold and looks like it hasn't "
		"been in use for quite some time.  It is covered with "
		"cobwebs and dust."
		"\n\n");
	add_item("cobweb","The forge is covered with these cobwebs.  "
		"Must have been a long time since this forge was used."
		"\n\n");
	add_item("dust","There is a thick layer of dust covering the "
		"forge.  This makes the forge look old and neglected."
		"\n\n");

	add_exit("out",TOWN+"town05.c","door");
	set_store_room(TOWN+"storeroom.c");
set_item_table(TOWN+"SHOP_TABLE");
}


void init()
{
   ::init();
   add_action("do_sell","se*ll");
   add_action("buy_me","buy");
   add_action("do_out","out");
}
int do_sell(string str)
{
     write("Sorry, we do not purchase items here.  Try the shop across "
          "the street.  I think they might buy it.\n\n");
return 1;
}
int buy_me(string str)
{
   if(!shagrat)
   {
   write("There is no one here to take your order.\n");
   return(1);
   }
}
int do_out(string str)
{
   if(this_player()->query_properties("BAERN"))
   {
   return(0);
   }
   else
   {
   return(1);
   }
}

int dest_me()
{
   if(shagrat)
   shagrat->dest_me();
   ::dest_me();
}
int test_add(object ob, int flag)
{
   call_out("do_enter",2);
   return(1);
}
