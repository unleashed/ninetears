inherit "/obj/weapon";

void setup()
{
//  set_base_weapon("twohanded_staff");
  set_base_weapon("baston_pesado");
  set_name("baston a dos manos");
  set_short("bast�n a dos manos");
  set_long("    Es un bast�n grande y pesado de madera, pulido de forma que no sobresalga "
     "ninguna astilla. Tiene tiras de cuero y metal en los bordes, y est� "
     "equilibrado para el combate.\n");
  set_main_plural("bastones a dos manos");
  add_alias("baston");
  add_alias("bast�n");
  add_plural("bastones");
  add_alias("bast�n a dos manos");
  set_genero(0);
  set_twohanded(1);
}
