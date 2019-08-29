/* basic food item for the bakery */
#define HP_RESTORE 3
#define VALUE 300

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup() {
set_name("bollo");
set_main_plural("bollos");
add_alias("pan");
add_plural("panes");
set_short("Un pequenyo panecillo");
set_long("Un apetitoso bollo de pan.  Esta ligeramente tostado "
	 "y lleva una capa de miel por encima.\n\n");
set_value(VALUE);
set_weight(20);
}
void init() {
add_action("do_eat","comer");
::init();
}

int do_eat(string what) {
if(what == "bollo") {
 this_player()->adjust_hp(HP_RESTORE);
 write("\n Rebanas el bollo, y te comes las rodajas saboreandolas "
       "con placer.\n\n");
 this_object()->dest_me();
 return(1);
 }
return(0);
}
