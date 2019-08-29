inherit "std/shop";
object master;

void setup() {
set_light(60);
set_short("QUICK-FIX SHOP");
set_long("\nQUICK-FIX SHOP.\n\n"
        "THIS IS JUST A QUICK FIX SO PEOPLE CAN SELL STUFF.\n"
        "THANKS TO SS AND M'DORN...I STOLE THE CODE FROM YOU.\n\n");
add_item("counter", "This simply crafted counter is made out "
	"of a light brown wood.\n");
add_item("wood", "This light brown wood forms the countertop "
	"in this store.\n");
add_item("door", "A door made from some light-colored wood hangs from "
	"simple leather hinges.\n");
add_item(({"wall", "walls"}), "A framework of wooden "
	"poles support bundles of straw which form the walls.\n");

add_exit("northeast","/d/mm/newbie/elf/center","door");
set_store_room("/d/mm/newbie/elf/quick_fix/store.c");
   set_buy_message(
      ({ "You pay the shopkeeper $money$ for $ob$.\n",
         "$client$ buys $ob$ from the shopkeeper.\n" }));
   set_sell_message(
      ({ "The shopkeeper gives you $money$ for $ob$.\n",
         "The shopkeeper gives $client$ some money for $ob$.\n" }));
   set_value_message(
      "The shopkeeper says: I could give you $money$ for $ob$.\n");
   set_browse_message(
      "The shopkeeper says: You need $money$ to purchase $ob$, which " 
      "looks like:\n$extra$");
   add_item(
      "counter",
      "A display counter for the wares of the shop.  Use the command " 
      "\"list\" to get a list of what they are.\n");
   add_item(
      ({ "objects", "object" , "items", "item" }), 
      "Use \"list\" to get a list of what is for sale.\n");
   add_sign(
      "The wooden sign is hanging from the ceiling by two small bronze " 
      "chains.  It is right over the counter.\n",
      "While here, you may perform the following commands:\n" 
      "    \"list\" <object> -- gives a listing of <object>\n" 
      "  \"browse\" <object> -- values and looks at <object>\n" 
      "     \"buy\" <object> -- purchases <object>\n" 
      "   \"value\" <object> -- show how much you would get for <object>\n" 
      "    \"sell\" <object> -- sell <object> to the shop.\n",
      "Wooden sign hanging from ceiling");
}
void reset() {
if (sizeof(find_match("master", this_object()))) return;
master = clone_object("/d/mm/newbie/elf/quick_fix/shopkeeper");
master->move(this_object());
}
void init(){
::init();
      add_action("nope", "browse");
      add_action("nope", "buy");
      add_action("nope", "value");
      add_action("nope", "sell");
     }
   nope(string str){
    if(!master){
   write("You cannot do that without the shopkeeper being present.  " 
      "All you can do is \"list\" <object>.  Somebody must have killed " 
      "the poor guy.\n");
say(this_player()->query_cap_name()+" looks for the shopkeeper but can't seem"
" to find him.\n");
  return (1);
}
}
