inherit "/obj/monster";
void setup()
{
set_name("Paseante");
add_alias("paseante");
set_short("paseante");
set_long("Puedes observar a un hombre de mediana edad con grandes sintomas de cansancio "
	 ". Su cara refleja el resultado de un gran esfuerzo y se aprecian en el gestos de dolor.\n");
add_plural("Paseantes");
add_clone("/baseobs/armours/cape.c",1);
set_random_stats(10,15);
set_level(10+random(5));
set_gender(1);
set_al(-100);
set_aggressive(0);
set_wimpy(3);
load_chat (100,
  ({
  1,"' Uff!! El cansancio ya hace mella en mis cansadas piernas.\n",
  2," Paseante se coloca su capa con gran dificultad  .\n",
  }));
}
