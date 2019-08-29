// Arturin

inherit "/obj/monster";

void setup() {
      set_name("vrolgar");
      set_short("vrolgar");
      set_al(60);
      set_main_plural("vrolgars");
      add_alias("guildmaster");
      set_race("orc");
	set_gender(1);
      set_level(51+random(10));
      set_wimpy(0);
	set_max_hp(query_level() * 10 + 1000);
	set_hp(query_max_hp());
	set_max_gp(1000);
	set_gp(1000);
      set_random_stats(20, 22);
      set_long("Vrolgar, el guardian del gremio de los Barbaros Orcos.\n\n"
		"Es un crack, yo de ti no me meteria con el.\n\n");
      adjust_money(random(300), "gold");
//      set_aggressive(0);
	new("/baseobs/weapons/hacha_oneex")->move(this_object());
	new("/baseobs/weapons/hacha_oneex")->move(this_object());
	new("/baseobs/armours/fullplate")->move(this_object());
	this_object()->init_equip();
      load_chat(20,
         ({
               1, "'Para ser un buen guerrero debes ser capaz de batirme en duelo!",
               1, ":te mira pensativamente.",
//               1, "@grin evilly $lname$",
               1, ":pasa su lengua por el filo de su poderosa arma.",
               1, "'Sexo, Drogas y Rockn'roll, y si eso no es posible, Muerte!",
               1, "'Que vengan los drows, que vengan...",
          }));
      load_a_chat(40,
         ({
               1, "'Nadie osa perturbar la paz de un guerrero!",
               1, ":te mira con los ojos inyectados en sangre.",
//               1, "@grin evilly $lname$",
               1, "'JERONIMOOOOO!!!",
          }));
	set_guild("warriors/barbaro");
	set_guild_ob("/d/gremios/guerreros/barbaro");
	add_attack_spell(70, "golpear", ({"/d/gremios/comandos/golpear", "golpear",0,0}));
	add_attack_spell(50, "bash", ({"/d/gremios/comandos/bash", "bash",0,0}));
	add_property("NO_BUDGE", 1); // para q ningun hechizo lo haga marcharse de aki
}

void init()
{
	::init();
	add_action("do_bash", "pedir");
}

// VAYA BUUUUG, hay q controlar q sea de nuestro gremio!! xD
int do_bash(string str) {
	if (str != "bash") {
		notify_fail("");
		return 0;
	}
	if (member_array("bash", TP->query_known_commands()) != -1) {
		notify_fail("Vrolgar te dice: No puedo ensenyarte lo que ya sabes.\n");
		return 0;
	}
	if (TP->query_guild_name() != TO->query_guild_name()) {
		notify_fail("Rashnak te ensenya el arte del Bash.\n");
		return 0;
	}
	tell_object(TP, "Vrolgar te ensenya el arte del Bash.\n");
	TP->add_known_command("bash");
	return 1;
}

int already_attacking(object me,object victim);

void event_enter(object enterer, string message)
{
	/* BUG, HAY Q LLAMAR A ::event_enter al finalizar cada return */
	string msg;
	int lvl, luchando = 0;

	if (!enterer) // la documentacion dice q hay q mirar esto
		return;

	if (enterer->query_dead())
		return;

	if (already_attacking(this_object(), enterer)) {
		if (!this_object()->query_dead()) {
			if (!random(2))
				command("say Pagaras tu osadia con tu SANGRE!\n");
			else
				command("say Maldito bastardo, ahora moriras!\n");
		}
		return;
	}

	// hay q hacer de alguna forma q no salude a su CUERPO cuando muera, aunque
	// lo de comprobar el gremio rula, pero como hariamos si saludase a tol mundo?

	if (enterer->query_guild_name() != "barbaro")
		return;

	// buscar propiedad o fun q me diga si esta en peleas pa no saludar XD

	if (query_fighting()) { // no saludamos y advertimos al que entra
		tell_object(enterer, "Observas a Rashnak altamente excitada.\n");
		return;
	}

	lvl = enterer->query_level();
	switch(lvl) {
		case 0..10:
			msg = "discipulo";
			break;
		case 11..20:
			msg = "soldado";
			break;
		case 21..25:
			msg = "sargento";
			break;
		case 26..30:
			msg = "capitan";
			break;
		case 31..35:
			msg = "teniente";
			break;
		case 36..40:
			msg = "coronel";
			break;
		case 41..45:
			msg = "teniente coronel";
			break;
		case 46..50:
			msg = "general";
			break;
		case 51..55:
			msg = "lord";
			break;
		case 56..60:
			msg = "gran lord";
			break;
		default:
			msg = "mi senyor";
	}
	command("say Saludos, "+ msg + " " + enterer->query_short() + ".\n");
}

// sacado de /d/gremios/comandos/base_command.c y modificado

int already_attacking(object me,object victim){
   if(member_array(me,victim->query_attacker_list()) != -1)
      return 1;
   if(member_array(me,victim->query_call_outed()) != -1) 
      return 1;
   return 0;
}
