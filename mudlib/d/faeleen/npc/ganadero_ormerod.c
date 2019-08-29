#include "./../path.h"

inherit "obj/monster";

void setup()
{
  set_name("ganadero");
  add_alias("ganadero");  
  set_short("ganadero");
  set_long("Ganadero de ormerod.\n");
  set_main_plural("ganaderos");
  set_align(0);
  set_gender(1);
  set_level(5+random(5));
  adjust_money(random(10), "plata");
  new("/baseobs/armours/cloak.c")->move(this_object());
  
  this_object()->init_equip();

}