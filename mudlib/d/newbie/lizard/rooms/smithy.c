#include "path.h"
inherit "std/shop";



void setup()
{

set_short("Realm of the Lizard:  Town Smithy");

   set_light(80);

set_long("\nRealm of the Lizard:  Town Smithy\n\n"
	 "     This is a small, somewhat cramped building that "
		"contains the town Smithy.  There is a counter along "
		"the northern wall with a sign on it.  Behind the "
		"counter are a number of items that were hand crafted "
		"by one of the best blacksmiths around.  To your right "
		"sits the forge.  It does not look as if it has been "
		"in use for quite some time. "
		"\n\n");

add_property("no_undead",1);
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

add_clone(CHAR+"longtail.c",1);
	add_exit("east",ROOM+"lizard24.c","door");
	set_store_room(ROOM+"storeroom.c");
set_item_table(ROOM+"SHOP_TABLE");
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
   return(1);
}
int buy_me(string str)
{
if(!present("longtail")) {
   write("There is no one here to take your order.\n");
   return(1);
   }
}
int do_out(string str)
{
   if(this_player()->query_properties("LONGTAIL"))
   {
   return(0);
   }
   else
   {
   return(1);
   }
}

int test_add(object ob, int flag)
{
 if(!interactive(ob)) { return(1); }
   call_out("do_enter",2);
   return(1);
}
int do_enter()
   {
if(present("longtail"))
     {
      write("Longtail says, 'Welcome "+this_player()->query_cap_name()+
            ", What may I do for you?'  \n\n");
      return(2);
     }
     else
     {
     return(2);
     }
   }
