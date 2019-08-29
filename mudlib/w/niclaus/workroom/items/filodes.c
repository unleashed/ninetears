inherit "/obj/weapon.c";

void setup()
{
  set_base_weapon("mandoble");
  set_name("filo del destino");
  add_plural("filos");
  add_plural("destinos");
  add_alias("filo");
  add_alias("destino");
  set_short("%^BOLD%^Filo Del %^RESET%^RED%^D%^BOLD%^estino%^RESET%^.");
  set_long(" Observas el %^BOLD%^Filo Del %^RESET%^RED%^D%^BOLD%^estino%^RESET%^, "
  "espada creada por Niclaus especialmente para sus guardianes del CaoS, se dice que "
  "este utiliza su propia sangre para bendecir estas espadas, lo que confiere una "
  "fiereza sin igual a quien la empunya.\n\n");
  set_main_plural("%^BOLD%^Filos Del %^RESET%^RED%^D%^BOLD%^estino%^RESET%^.");
  set_enchant(6);
  set_twohanded(0);
}



