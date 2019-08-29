/* basic food item for the bakery */
#define HP_RESTORE 3
#define VALUE 300

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup() {
set_name("loaf");
set_main_plural("loaves");
add_alias("bread loaf");
add_plural("bread loaves");
set_short("A short loaf of bread roll");
set_long("A rich smelling loaf bread.  It has a light crust and looks and "
	 "smells like it has honey spread on top.\n\n");
set_value(VALUE);
set_weight(20);
}
void init() {
add_action("do_eat","eat");
::init();
}

int do_eat(string what) {
if(what == "loaf") {
 this_player()->adjust_hp(HP_RESTORE);
 write("\n You cut the loaf into a few slices, and then eat them savoring the "
       "the taste.\n\n");
 this_object()->dest_me();
 return(1);
 }
return(0);
}
