//Leviathan Mayo �02

inherit "/obj/weapon";

void setup()
{
  set_base_weapon("esp_bastarda");
  set_name("luz del amanecer");
  add_alias("luz");
  add_alias("amanecer");
  set_short("%^BOLD%^YELLOW%^Luz %^WHITE%^del %^CYAN%^Amanecer%^RESET%^");
  set_long("Luz del Amanecer.\n"
  	   "Este arma pertenece a una pequenya parte del botin que Leviathan arrebato a Jade "
	   "en las antiguas guerras en la creacion del mundo. Tiene un lado afilado en uno de "
	   "por una parte, siendo el otro dentado para producir un mayor danyo. Un Halo blanco "
	   "y brillante refulge a su alrededor, haciendolo tambien sobre el afortunado portador "
	   "de la misma cuando esta es empunyada. La empunyadura, ricamente tallada en madera, "
	   "pulida y ligera, e incrustada en piedras preciosas, se amolda pefectamente a la "
	   "mano del portador, permitiendo una perfecta maniobrabilidad de la misma.\n");
  set_main_plural("%^BOLD%^YELLOW%^Luces %^WHITE%^del %^CYAN%^Amanecer%^RESET%^");
  add_plural("luces");
  add_plural("amaneceres");
  set_enchant(3);
  set_twohanded(0);
  add_property("guild", "paladin");
  add_property("no_slice", 1);

}
