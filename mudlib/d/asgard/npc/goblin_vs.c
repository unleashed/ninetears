inherit "obj/monster";

void setup()
{
  set_name("goblin");
  set_race("goblin");
  add_alias("goblin");  
  set_short("Gobiln");
  set_long(query_short()+"\n"+"Este es un goblin, es de mediana estatura su aspecto es repugnante, no "
  "difiere mucho del resto de su raza, es vacil�n, atrevido y marrullero, te dan ganas de pegarle solo "
  "por el modo en que te mira, no parece ser extremadamente fuerte, pero hay que tener cuidado, las "
  "apariencias enga�an.\n");
  set_main_plural("goblins");
  set_align(0);
  set_gender(1);
  set_level(10+random(5));
  adjust_money(random(10), "cobre");
  add_clone("/baseobs/armas/daga.c",1);
  
  this_object()->init_equip();

}