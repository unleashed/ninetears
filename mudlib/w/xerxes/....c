inherit "/obj/armour.c";

void setup()
{
  set_base_armour("culo");
  set_name("bolas chinas");
  set_short("%^RED%^BOLD%^Bolas Chinas%^RESET%^");
  add_alias("bolas");
  add_alias("chinas");
  set_main_plural("%^RED%^BOLD%^Bolas Chinas%^RESET%^");
  add_plural("chinas");
  add_plural("bolas");
  set_long("Una divertida cuerda con varias bolas de color rojo engastadas cual "
  "perlas en un collar. Solo para salvajes anales.\n");
  set_enchant(6);
}
