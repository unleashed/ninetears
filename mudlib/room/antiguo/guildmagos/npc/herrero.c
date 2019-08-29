// Yebarcles

// habria k cancelar la entrega del objeto si estamos en peleas...

#define ESCUDO "/baseobs/shields/escudo_negro.c"

inherit "/obj/monster";

int haciendo_objeto = 0;

void setup() {
      set_name("Aaetram");
      set_short("Aaetram");
      set_al(60);
      set_race("human");
      set_gender(1);
      set_level(15+random(10));
      set_wimpy(0);
      set_max_hp(query_level() * 20);
      set_hp(query_max_hp());
      set_max_gp(query_level() * 20);
      set_gp(query_max_gp());
      set_random_stats(15, 18);
      set_long("Aaetram, Herrero\n\n"
		"Hijo de herreros y nieto de herreros, conoce el arte de la fragua mejor "+
		"que ningun otro ser en tierra conocida, sin duda una persona capaz de hacer "+
		"autenticas maravillas con el metal .\n\n");
      adjust_money(random(3), "gold");
//      set_aggressive(0);
      load_chat(50,
         ({
               1, "'Traeme un arma adecuada, y te hare una espada maravillosa.",
               1, ":se limpia el sudor de la frente.",
               3, "'Dice la leyenda que en el camino existia una gran bestia devoradora de hombres y animales.",
               2, "'Dos y dos son cuatro, cuatro y dos son seis.. seis y dos son ocho y ocho die ci seis...",
          }));
	add_attack_spell(50, "tormenta acida", ({"/d/gremios/hechizos/mago/tormenta_acida", "cast_spell",1,0}));
	add_attack_spell(50, "proyectil magico mayor",
	({"/d/gremios/hechizos/mago/proyectil_magico_mayor", "cast_spell",1,0}));
}

void init()
{
	::init();
	add_action("entregar", "entregar");
	haciendo_objeto = 0;
}

void empezar_show(object myp)
{
	do_command("decir Piel de Ogro! Por todos los dioses!");
	call_out("show1", 2, myp);
}

void show1(object myp)
{
	object escudo;

	escudo = clone_object(ESCUDO);
	escudo->move(TO);
	escudo->set_owner(myp);
	do_command("dejar negro");
	haciendo_objeto = 0;
}

int entregar(string str)
{
	int i;
	object myp = TP;
	object *obs;

	if (haciendo_objeto) 
	{
		do_command("say Un momento, por favor.");
		notify_fail("");
		return 0;
	}

	if (str != "escudo templanza") 
	{
		do_command("decir Que desea vuesa merced entregar?");
		notify_fail("");
		return 0;
	}
	obs = all_inventory(myp);
	for (i=0; i<sizeof(obs); i++) 
	{
		if (obs[i]->query_name() == "escudo templanza") 
				{
				obs[i]->dest_me();
				haciendo_objeto = 1;
				empezar_show(myp);
				return 1;
				}
	}
	do_command("decir entregarme tu cuerpo? porque me has tomado?");
	notify_fail("");
	return 0;
}
