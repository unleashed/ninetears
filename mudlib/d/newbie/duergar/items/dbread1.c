#define HP_RESTORE 1
#define VALUE 250

#include "/std/object.c"

int query_auto_load() { return 1; }
void setup() {
set_name("roll");
set_main_plural("rolls");
add_alias("bread roll");
add_plural("bread rolls");
set_short("A hard travel bread roll");
set_long("A hard, dark travel roll that looks like it will last for a "
	 "while and still taste fairly good.\n");
set_value(VALUE);
set_weight(15);
}
void init() {
add_action("do_eat","eat");
::init();
}

int do_eat(string what) {
if(what == "roll") {
 this_player()->adjust_hp(HP_RESTORE);
 write("\n You bite into the hard bread roll with your teeth. "
 "\nIt tastes fair enough. \n\n");
 this_object()->dest_me();
 return(1);
 }
return(0);
}
