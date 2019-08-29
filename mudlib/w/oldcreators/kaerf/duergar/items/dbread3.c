/* basic food item for the bakery */
#define HP_RESTORE 2
#define VALUE 350

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup() {
set_name("muffin");
set_main_plural("muffins");
set_short("Un ligero, muffin.");
set_long("Es un delicioso pastelito de niscalos.  Tiene incrustados "
	 "trocitos de alguna cosa que no distingues.\n\n");
set_value(VALUE);
set_weight(10);
}
void init() {
add_action("do_eat","comer");
::init();
}

int do_eat(string what) {
if(what == "muffin") {
 this_player()->adjust_hp(HP_RESTORE);
 write("\n Te metes en la boca el pastelito entero y notas un sabor a "
       "naranja.  Parece que aquellos trocitos eran de naranja. "
       "\nEs muy refrescante. "
       "\n\n");
 this_object()->dest_me();
 return(1);
 }
return(0);
}
