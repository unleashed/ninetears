/* study command for shifter guild.  allows the shifter to study
 * the details of a player so that he may try and become that
 * player.  the actual rolling for how much the shifter really
 * learns will take place in the form player.c in the shifter guild 
 * forms dir.  the shifter must stay with the player being studied
 * the entire time or else the study fails.  the save is a battle of
 * luck with some random rolls thrown in.  also the studying is static
 * so its only good until the shifter logs out.
 * gonna change this to timed instead of static
 * Raskolnikov Nov 96
 */

#define TIME_FACTOR 100

void finished_studying(object shifter, object victim, mapping studied);
int do_env_check(object shifter, object victim);
int do_fighting_check(object shifter);

void study(string str) {
    int i, my_cha, vic_cha, study_time;
    string output, *p_studied;
    mapping studied;
    object victim;

    if(sizeof(this_player()->query_attacker_list()) ||
      sizeof(this_player()->query_call_outed())) {
	tell_object(this_player(), "Estas demasiado distraido por tus peleas "
	  "como para concentrarte en estudiar a alguien.\n");
	return 1;
    }

    if(this_player()->query_property("studying") == 1) {
	tell_object(this_player(), "Lo siento, pero ya estas demasiado "
	  "ocupado estudiando a alguien.\n");
	return 1;
    }

    studied = this_player()->query_timed_property("players_studied");
    if(!str) {
	if(!m_sizeof(studied)) {
	    tell_object(this_player(), "Aun no has estudiado a nadie.\n");
	    return 1;
	}

	p_studied = keys(studied);
	for(i=0;i<sizeof(p_studied);i++)
	    p_studied[i] = capitalize(p_studied[i]);
	tell_object(this_player(), "Has estudiado a los siguientes "
	  "seres:\n\n");
	output = implode(p_studied, "\n");
	printf("%-#*s", this_player()->query_cols(), output);
	write("\n");
	return 1;
    }


    victim = present(str, environment(this_player()));
    if(!victim) {
	tell_object(this_player(), "No parece que haya aqui nadie con "
	  "ese nombre.\n");
	return 1;
    }

    if(victim == this_player()) {
	tell_object(this_player(), "En realidad tu no eres tan "
	  "interesante.\n");
	return 1;
    }

    if(!interactive(victim)) {
	tell_object(this_player(), "Tan solo los jugadores pueden "
	  "ser estudiados.\n");
	return 1;
    }

    if(victim->query_dead()) {
	tell_object(this_player(), "No vas a aprender mucho estudiando "
	  "a un fantasma.\n");
	return 1;
    }

    if(m_sizeof(studied)) {
	p_studied = keys(studied);
	if(member_array(victim->query_name(), p_studied) != -1) {
	    tell_object(this_player(), "Ya has estudiado a esa persona "
	      "a fondo.\n");
	    return 1;
	}
    }

    tell_object(this_player(), "Comienza a estudiar a "
      +victim->query_cap_name()+"...\n");
    my_cha = this_player()->query_cha();
    my_cha += random(7);
    vic_cha = victim->query_cha();
    vic_cha += random(7);
    if(my_cha < vic_cha) {
	tell_object(victim, "Notas la presencia de alguien "
	  "y ves a "+this_player()->query_cap_name()+" "
	  "mirandote detenidamente. Te enfadas y le atacas!\n");
	tell_object(this_player(), "...Argh! Que mala suerte! "
	  +victim->query_cap_name()+" te detecta estudiando"
	  +victim->query_objective()+" y se enfada sobremanera!\n");
	victim->attack_ob(this_player());
	return 1;
    }

    tell_object(this_player(), "...y lo haces sin que "
      ""+victim->query_cap_name()+" se de cuenta.\n\n"
      "Ahora debes concentrarte y estudiar"
      +victim->query_objective()+" sin interrupciones "
      "y sin perder"
      +victim->query_objective()+" de vista.\n");
    study_time = 50 - (this_player()->query_int() + my_cha);
    if(study_time < 0)
	study_time = 2;
    if(!m_sizeof(studied))
	studied = ([ ]);
    this_player()->add_property("studying", 1);
    this_player()->add_spell_effect(study_time, "offensive", "study",
      this_object(), "hb_spell", ({ victim, studied }) );
    return 1;
}

int hb_spell(object shifter, mixed *params, int time) {
    int time_left, env_check, fight_check;
    object victim;

    victim = params[0];
    env_check = do_env_check(shifter, victim);
    fight_check = do_fighting_check(shifter);
    if((env_check == 1) || (fight_check == 1))
	call_out("end_study", 0, shifter);
    switch(time) {
    case 1:
	if((env_check != 1) && (fight_check != 1))
	    finished_studying(shifter, victim, params[1]);
	break;
    }
    return env_check;
}

int do_env_check(object shifter, object victim) {
    if(environment(shifter) != environment(victim)) {
	tell_object(shifter, "Parece que has perdido de vista a "
	  +victim->query_cap_name()+" y no consigues completar "
	  "tu estudio.\n");
	shifter->remove_property("studying");
	return 1;
    }
    return 10;
}

int do_fighting_check(object shifter) {
    if(sizeof(shifter->query_attacker_list()) ||
      sizeof(shifter->query_call_outed())) {
	tell_object(shifter, "Pierdes la concentracion debido a tu "
	  "lucha.\n");
	shifter->remove_property("studying");
	return 1;
    }
    return 10;
}

void end_study(object shifter) {
    shifter->remove_spell_effect("study");
}

void finished_studying(object shifter, object victim, mapping studied) {

    studied[victim->query_name()] = ([
      "stats" : ([
	"str": victim->query_real_str(),
	"dex": victim->query_real_dex(),
	"con": victim->query_real_con(),
	"int": victim->query_real_int(),
	"wis": victim->query_real_wis(),
	"cha": victim->query_real_cha(),
	"thac0": victim->query_thac0(),
	"ac": victim->query_body_ac(),
	"weight": victim->query_weight(),
	"gender": victim->query_gender(),
	"race": victim->query_race_ob(),
	"guild": victim->query_guild_ob(),
	"descrip" : victim->query_description(),
	"racename" : victim->query_race(),
      ]),
      "spells" : victim->query_spells(),
      "commands" : victim->query_known_commands(),
    ]);
    shifter->add_timed_property("players_studied", studied,
      TIME_FACTOR*this_player()->query_int());
    shifter->remove_property("studying");
shifter->adjust_gp(-20);
    tell_object(shifter, "Finalizas el estudio de "
      ""+victim->query_cap_name()+" satisfactoriamente.\n");
    return 1;
}

string help(string str) {
    return "Sintaxis: study <jugador>\n\n"
    "This command allows the shifter to attempt to learn all the "
    "attributes of a player and become that player.  It takes a great "
    "deal of concentration.  If the shifter is currently hostile toward "
    "anyone or loses track of the player to be studied, the study will fail.  "
    "How much of the player's attributes the shifter actually gets is based "
    "on how intelligent the shifter is and a LOT of luck.\n"
    "GP cost: 15\n\n";
}
