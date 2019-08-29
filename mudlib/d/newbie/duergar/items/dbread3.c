/* basic food item for the bakery */
#define HP_RESTORE 2
#define VALUE 350

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup() {
set_name("muffin");
set_main_plural("muffins");
set_short("A light, muffin.");
set_long("A small but delicious looking mushroom.  It appears to have a few "
	 "small chuncks of something inside to add flavor.\n\n");
set_value(VALUE);
set_weight(10);
}
void init() {
add_action("do_eat","eat");
::init();
}

int do_eat(string what) {
if(what == "muffin") {
 this_player()->adjust_hp(HP_RESTORE);
 write("\n You pop the whole muffin into your mouth and savor the flavor "
       "reminds you of oranges.  Thats what those chuncks were, the orange "
       "mushrooms of the farm to the north."
       "\nMy it was tasty. "
       "\n\n");
 this_object()->dest_me();
 return(1);
 }
return(0);
}
