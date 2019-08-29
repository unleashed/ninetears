/* By Shimmer */  /* codigo pa que salgan otros guardias a defender by Leviathan */ 

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

#define CAPITAN "/d/driade/shimmer/brethem/ciudad/npcs/capitan_guardia.c"

object capitan1, capitan2;

void setup() { 

      set_name("Cabo de la Guardia de Brethem");
      set_short("Cabo de la Guardia de Brethem");
      set_main_plural("Cabos de la Guardia de Brethem");
      add_alias("guardian");
      add_alias("guardia");
      add_alias("cabo");
      add_plural("guardianes");
      add_plural("guardias");
      add_plural("cabos");
      set_long("Es uno de los guardias de los arcos de entrada a Brethem, su cometido es vigilas tanto las cercanias de la ciudad "
               "como el interior de la misma, intentando evitar los posibles altercados que puedan sucederse. "
               "No dudara en atacar al minimo sintoma de peligro.\n");
      add_move_zone("brethem");
      set_race_ob("/std/races/human");      
      set_race("human");
      set_gender(1);
      set_max_hp(400);
      set_hp(400);
      set_max_gp(300);
      set_gp(300);
      set_random_stats(20, 22);      
      set_level(51+random(10));
      set_wimpy(0);
      set_al(-100+random(201));
      adjust_money(100+random(100), "gold");
      set_guild("fighther");
      set_guild_ob("/std/guilds/warriors/fighter");      
      load_chat(30,
         ({
               1, "@sonrrie al verte llegar.",
               1, "'En esta ciudad no queremos altercados, asi que es mejor que dejes quietas tus armas. ",
               1, "'Estoy aqui para vigilar la ciudad.",
               1, "'No me importa de que raza seas, en esta ciudad yo velo por la seguridad de todos. ",
               1, "'Me encantaria irme a la Taberna del Refugio a tomar algo, pero estoy de guardia, es una pena."
          }));
    

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

// sacado de /std/commands/base_command.c y modificado

int already_attacking(object me,object victim){
   if(member_array(me,victim->query_attacker_list()) != -1)
      return 1;
   if(member_array(me,victim->query_call_outed()) != -1) 
      return 1;
   return 0;
}

int same_object(object ob1, object ob2);
object *mis_colegas();

void capitanes_aki()
{
	//int i;
	//object *matacan;

	capitan1 = clone_object(CAPITAN, 1);
	capitan2 = clone_object(CAPITAN, 1);
	capitan1->move(environment(this_object()));
	capitan2->move(environment(this_object()));
	tell_room(environment(this_object()), "De pronto dos %^BOLD%^WHITE%^Capitanes de la Guardia de Brethem%^RESET%^ acuden a la llamada.\n");
}


/* ENO, DESPUES DE MUCHO CURRO, ESTO RULA, ES MUYYY PESADO */
/* CUANDO SE LLAMA A attack_by EL ATACANTE AUN NO ESTA EN attacker_list
   SI ACABA DE COMENZAR LA PELEA */
void attack_by(object atacante)
{
	object *obs;
	int i;


	if (!query_property("capitanes llamados")) {
		add_property("capitanes llamados", 1);

		tell_room(environment(this_object()), "%^BOLD%^YELLOW%^TURUUUUUU !!!%^RESET%^. El Cabo "
		"hace sonar su cuerno para avisar del peligro!\n");
		capitan1 = 0;
		capitan2 = 0;

		capitanes_aki();
	}

	obs = mis_colegas();


	if (capitan1) {
		if (sizeof(obs))
			capitan1->set_protector(obs[random(sizeof(obs))]);
		if (member_array(atacante,
		capitan1->query_attacker_list()) == -1)
			capitan1->attack_ob(atacante);
	}
	if (capitan2) {
		if (sizeof(obs))
			capitan2->set_protector(obs[random(sizeof(obs))]);
		if (member_array(atacante,
		capitan2->query_attacker_list()) == -1)
			capitan2->attack_ob(atacante);
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
					obs[i]->do_command("say Por la Gloria de Brethem!");
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




