inherit "/obj/monster";
void setup()
{
set_name("Perro");
add_alias("perro");
set_short("Perro");
set_long("Es un perro labrador utilizado por los lugarenyos "
	 "para los duros trabajos del campo, se le nota algo desnutrido.\n");
add_plural("Perros");
set_random_stats(10,15);
set_level(8+random(5));
set_gender(1);
set_al(-100);
set_aggressive(0);
set_wimpy(0);
load_chat (100,
  ({
  1,"' Grrrrrrrrrr Goourrf Gooourf.\n",
  2,"Perro alza la cola en se�al de desafio.\n",
  }));
}
