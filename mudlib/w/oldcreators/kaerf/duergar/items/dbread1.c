#define HP_RESTORE 1
#define VALUE 250

#include "/std/object.c"

int query_auto_load() { return 1; }
void setup() {
set_name("boronya");
set_main_plural("boronyas");
add_alias("borona");
add_plural("boronas");
set_short("Un duro bollo de boronya");
set_long("Un bollo de oscura boronya, esta duro pero es ideal como"
	 "alimento de viaje, tiene un olor caracteristico.\n");
set_value(VALUE);
set_weight(15);
}
void init() {
add_action("do_eat","comer");
::init();
}

int do_eat(string what) {
if(what == "boronya") {
 this_player()->adjust_hp(HP_RESTORE);
 write("\n Clavas tus dientes con fuerza en el duro bollo. "
 "\nEsta bastante bueno. \n\n");
 this_object()->dest_me();
 return(1);
 }
return(0);
}

