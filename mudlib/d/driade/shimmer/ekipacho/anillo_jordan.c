// By Sinister '00

inherit "/obj/armour";
int TIEMPO=20;

void setup()

{

	set_base_armour("ring");
	set_short("Anillo de %^BOLD%^Michael Jordan%^RESET%^");
	set_name("Anillo de %^BOLD%^Michael Jordan%^RESET%^");
	set_main_plural("Anillos de %^BOLD%^Michael Jordan%^RESET%^");
	add_alias("anillo de michael jordan");
	add_alias("anillo");
	add_alias("jordan");
	add_plural("anillos");
	set_enchant(1);

	set_long("Este es el anillo de Campeones de la NBA, lleva grabado el numero 23 en su interior.\n");


}

void init()
{
  ::init();
  add_action("girar_anillo","girar");
}

int girar_anillo(string str)
{
object shadow;
 if (str == "anillo")
  {

if (!query_in_use())
{
return 0;
}


  if (TO->query_property("anillo_girado"))
  	{
  	tell_object(TP,"Tu anillo aun no ha recuperado sus propiedades magicas.\n");
  	return 1;
  	}
if (TP->query_property("anillo_girado"))
  	{
  	tell_object(TP,"Intentas girar el anillo, pero algo dentro de ti te dice que abusar de un poder asi no seria recomendable.\n");
  	return 1;
  	}
  tell_object(TP,"Empiezas a girar el anillo en torno a tu dedo y este parece ir "
  "moviendose, cogiendo fuerza, hasta que sorprendido ves como el anillo "
  "empieza a girar sobre tu dedo, provocandote una gran sensacion de "
  "velocidad.\n"
  "Te miras a los pies y ves unas %^BOLD%^%^WHITE%^Nike %^BOLD%^%^BLUE%^Air %^BOLD%^%^RED%^Jordan%^RESET%^, con ellas "
  "tu velocidad y tu capacidad de salto aunmentan considerablemente.\n");
  tell_room(environment(TP),TP->query_cap_name()+" empieza a girar su Anillo de %^BOLD%^Michael Jordan%^RESET%^ "
   "y de repente su velocidad y su capacidad de salto aumenta considerablemenet.\n",TP);

TP->adjust_tmp_dex(2,TIEMPO);
TP->add_timed_property("conmasdos",1,TIEMPO+5);
shadow = clone_object("/d/anduar/objetos/anillo_sh.c");
shadow->init_shadow(TP);
TP->add_timed_property("anillo_girado",1,3600);
TO->add_timed_property("anillo_girado",1,3600);
  return 1;
  }
 notify_fail("Girar el que?\n");
 return 0;
}