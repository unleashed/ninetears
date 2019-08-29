#include "./../path.h"

inherit "obj/monster";

void setup()
{
  set_name("ganadera");
  add_alias("ganadera");  
  set_short("ganadera");
  set_long("Ganadera de ormerod.\n");
  set_main_plural("ganaderas");
  set_align(0);
  set_gender(2);
  set_level(5+random(5));
  adjust_money(random(10), "plata");
  new("/baseobs/armours/cloak.c")->move(this_object());
  
  this_object()->init_equip();
  load_chat (20,
	  ({
	  1,"'Estas vacas nunca se hinchan, parece que no tienen fondo",
	  1,":arrea al ganado"
  }));
}