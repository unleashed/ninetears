inherit "/obj/monster";
void setup()
{
set_name("Agricultor");
add_alias("agricultor");
set_short("Agricultor");
set_long("Es un hombre de aspecto desmejorado, debido al gran trabjo que requiere "
	 "la vida de un trabajador del campo, en sus manos puedes observar las marcas"
	" producidas por el trabajo.\n");
add_plural("Agricultores");
add_clone("/baseobs/weapons/hand_axe.c",1);
add_clone("/baseobs/armaours/gloves.c",1);
set_race ("human");
set_random_stats(10,15);
set_level(15+random(5));
set_gender(1);
set_al(10);
set_aggressive(1);
set_wimpy(0);
load_chat (100,
  ({
  1,"'Tu osadia al pisar mis terrenos no tiene nombre.\n",
  2," Agricultor te mira con cierta desconfianza  .\n",
  }));
}
