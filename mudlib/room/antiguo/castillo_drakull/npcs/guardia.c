// Guardia "imperial" por decir algo, mete cargas

inherit "/obj/monster";

#define MAGO "/room/castillo_drakull/npcs/mago.c"

/* LO DE HACER Q LOS MAGOS APAREZCAN AL CABO DE TANTOS ROUNDS
	LLEVA MAS CURRO, HAY Q SAKAR ESTO DE AKI
	Y COGERLOS POR FIND_MATCH Y TO ESO
	Y HACERL EL CALL_OUT A UNA FN FUERAAAA DE ESTE OBJETO! 
	O HACER UN HANDLER Q HAGA EN SI MISMO EL CALL_OUT
	PERO Q DE ALGUNA FORMA SEPAMOS LOS OBJETOS EN MAGO1 Y 2
	UNA VEZ CREADOS */
object mago1, mago2; /* el muy perro del driver me dice q no puede
			indexar un object *magos �? */

void setup() {
      set_name("Guardia Imperial");
      set_short("Guardia Imperial");
      set_al(60);
      set_main_plural("Guardias Imperiales");
	add_plural("soldados");
	add_plural("guardias");
	add_plural("imperiales");
      add_alias("soldado");
	add_alias("guardia");
	add_alias("imperial");
      set_race("human");
	set_gender(1);
      set_level(51+random(10));
	set_thac0(0);
	set_ac(-100);
      set_wimpy(0);
	set_max_hp(query_level() * 10);
	set_hp(query_max_hp());
	set_max_gp(query_level() * 8);
	set_gp(query_max_gp());
      set_random_stats(20, 22);
      set_long("Guardia Imperial.\n\n"
		"Es un crack, yo de ti no me meteria con el.\n\n");
      adjust_money(random(300), "gold");
//      set_aggressive(0);
	new("/baseobs/weapons/bastard_sword")->move(this_object());
	new("/baseobs/weapons/bastard_sword")->move(this_object());
	new("/baseobs/armours/fullplate")->move(this_object());
	this_object()->init_equip();
      load_chat(20,
         ({
               1, "'El honor, la verdad y la fidelidad al rey son sagrados.",
               1, ":observa horrorizado el castillo.",
//               1, "@grin evilly $lname$",
               1, ":pasa su lengua por el filo de su arma.",
               1, "'He visto horrores jamas imaginados en este castillo.",
               1, "'El Bien prevalecera.",
          }));
      load_a_chat(30,
         ({
               1, "'Nadie osa perturbar la paz de un Guardia Imperial!",
               1, ":te mira con los ojos inyectados en sangre.",
//               1, "@grin evilly $lname$",
               1, "'JERONIMOOOOO!!!",
          }));
	set_guild("paladin");
	add_attack_spell(90, "muro ilusorio", ({"/d/gremios/hechizos/mg/muro_ilusorio", "cast_spell",3,0}));
	add_attack_spell(40, "cargar", ({"/d/gremios/comandos/carga", "carga",0,1}));
	add_attack_spell(30, "curar heridas criticas",
	({"/d/gremios/hechizos/paladin/curar_heridas_criticas", "cast_spell",3,0}));
	add_attack_spell(10, "plegaria",
	({"/d/gremios/hechizos/paladin/plegaria", "cast_spell",3,0}));
	add_attack_spell(10, "bendicion",
	({"/d/gremios/hechizos/paladin/bendicion", "cast_spell",3,0}));
}

int already_attacking(object me,object victim);

void event_enter(object enterer, string message)
{
	if (!enterer) // la documentacion dice q hay q mirar esto
		return;

	if (enterer->query_dead())
		return;

	if (already_attacking(this_object(), enterer)) {
		if (!this_object()->query_dead()) {
		    if (!random(2))	
			if (!random(2))
				command("say Pagaras tu osadia con tu SANGRE!\n");
			else
				command("say Maldito bastardo, ahora moriras!\n");
		}
		return;
	}
}

// sacado de /d/gremios/comandos/base_command.c y modificado

int already_attacking(object me,object victim){
   if(member_array(me,victim->query_attacker_list()) != -1)
      return 1;
   if(member_array(me,victim->query_call_outed()) != -1) 
      return 1;
   return 0;
}

int same_object(object ob1, object ob2);
object *mis_colegas();

void magos_aki()
{
	//int i;
	//object *matacan;

	mago1 = clone_object(MAGO, 1);
	mago2 = clone_object(MAGO, 1);
	mago1->move(environment(this_object()));
	mago2->move(environment(this_object()));
	tell_room(environment(this_object()), "De pronto dos Magos acuden a la llamada de auxilio efectuada por el Guardia.\n");
/*	ESTO YA LO HASEMOS (ESPERO KE IWAL FX) EN attack_by() DE ABAJO
	matacan = query_attacker_list();
	for(i=0; i < sizeof(matacan); i++) {
		if (ENV(matacan[i]) == ENV(TO)) {
			mago1->attack_ob(matacan[i]);
			mago2->attack_ob(matacan[i]);
		}
	}*/
}


/* ENO, DESPUES DE MUCHO CURRO, ESTO RULA, ES MUYYY PESADO */
/* CUANDO SE LLAMA A attack_by EL ATACANTE AUN NO ESTA EN attacker_list
   SI ACABA DE COMENZAR LA PELEA */
void attack_by(object atacante)
{
	object *obs;
	int i;
	/* usar mago->set_protector(ob) para protegerlo por un solo tio */
	/* espero arreglar /std/living/combat.c para poder poner mas
	   de un protector y que rule bien! */

	/*if (!query_property("magos llamados")) {
		add_property("magos llamados", 1);
		tell_room(environment(this_object()), query_short() +
		" hace sonar una campanita avisando del peligro!\n");
		mago1 = 0;
		mago2 = 0;
		//call_out("magos_aki", 4); musho problems
		// nadie garantisa q te el wardia vivo tras 4 hbs
		tell_object(TP, "DEBUG\n");
		magos_aki();
		tell_object(TP, "DEBUG2\n");
	}*/

	obs = mis_colegas();

	// La parte de proteger es NASTY, deberia ser alguien al azar
	// pero bien fecho hasta arreglar /std/living/combat.c
	if (mago1) {
		if (sizeof(obs))
			mago1->set_protector(obs[random(sizeof(obs))]);
		if (member_array(atacante,
		mago1->query_attacker_list()) == -1)
			mago1->attack_ob(atacante);
	}
	if (mago2) {
		if (sizeof(obs))
			mago2->set_protector(obs[random(sizeof(obs))]);
		if (member_array(atacante,
		mago2->query_attacker_list()) == -1)
			mago2->attack_ob(atacante);
	}

	if (sizeof(obs) > 0)
	{
		for(i=0;i < sizeof(obs);i++) {
		// no sea que tengamos demasiados amigos en la room xD
			obs[i]->add_property("magos llamados", 1);
		// si nuestro compi no le pega... q le pegue!!!
			if (member_array(atacante,
			obs[i]->query_attacker_list()) == -1) {

				if (!sizeof(query_attacker_list())
					&& !query_property("ya lo has dicho")) {
					add_timed_property("ya lo has dicho", 1, random(6)+3);
					do_command("say A las Armas, Companyeros!");
				}
				else if (!query_property("ya lo has dicho")) {
					add_timed_property("ya lo has dicho", 1, random(6)+3);
					do_command("say Otro mas!! A por el!");
				}

				if (!obs[i]->query_property("ya lo has dicho")) {
					obs[i]->do_command("say Por la Gloria del Reino!");
				}
				obs[i]->add_timed_property("ya lo has dicho", 1, random(6)+3);
				obs[i]->attack_ob(atacante);
			}
		}
	}
	::attack_by(atacante);
}

object *mis_colegas()
{
	int i;
	object *obs;

	obs = find_match(this_object()->query_main_plural(), environment(this_object()));

	for(i=0;i < sizeof(obs);i++) {
			// somos nosotros (nuestro clon)? si es asi fuera
			if (file_name(obs[i]) == file_name(this_object())) {
				obs = delete(obs, i, 1);
				i--;
				continue;
			}

			// no son de mi misma clase? fuera
			if(!same_object(this_object(), obs[i])) {
				obs = delete(obs, i, 1);
				i--;
				continue;
			}
	}
	return obs;
}

/* Super Limpio! xD */
int same_object(object ob1, object ob2)
{
	return (explode(file_name(ob1), "#")[0] ==
		explode(file_name(ob2), "#")[0]);
}
