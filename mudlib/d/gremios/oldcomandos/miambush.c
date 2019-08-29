// Licenciado bajo la GNU General Public License
// Comando EMBOSCAR para Asesinos
// Totalmente reescrito - (c) Tyrael, Septiembre '01

inherit "/d/gremios/hechizos/patch.c";

#define SP_NAME "emboscar"
#define HEAL_LOCKOUT "emboscar_hecho"
#define HEAL_LOCKOUT_TIME 8

object roomorig;

string help() 
{
 return
    "\n\n"
    "Nombre del Comando: "+SP_NAME+"\n"
    "Sintaxis: emboscar <persona>\n"
    "Descripcion:\n"
    "Este comando permite golpear brutalmente a alguien.\n\n";
}

mixed spell(string str, object caster);

/* mmm no se si usar esta func, iwal impide emboscar a formulador ke
   no ha hecho kill
static int already_attacking(object me,object victim)
{
    if(sizeof(me->query_attacker_list()))return 1;
    if(member_array(me,victim->query_attacker_list()) != -1)
        return 1;
    if(member_array(me,victim->query_call_outed()) != -1)
        return 1;
    return 0;
}
*/

void end_hb_spell(object doer)
{
	doer->remove_spell_effect(SP_NAME);
}

int emboscar(string str,object cast)
{
  int skill;
  mixed ret;
  object caster;

  caster = cast ? cast : this_player();

	caster->adjust_gp(-1);

    if (!str)
    {
        tell_object(caster,"Estas intentando emboscar?\n");
        return 1;
    }

  str = (string)caster->expand_nickname(str);
  ret = spell(str, caster);
  if (stringp(ret))
  {
    notify_fail(ret);
    return 0;
  }
  roomorig = ENV(caster);
  tell_object(caster,"Empiezas a buscar un punto debil en la "
	"espalda de tu victima.\n");
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;

  if ((int)caster->query_spell_effect("emboscando"))
    return "Ya estas intentando emboscar a alguien.\n";
  if ((int)caster->query_property(HEAL_LOCKOUT))
    return "Aun no te encuentras con plenas facultades para emboscar.\n";

	if (sizeof(caster->query_attacker_list()))
		return "Emboscar en pleno combate?\n";

  ob = find_match(str, environment(caster));
  if (!sizeof(ob) || !living(ob=ob[0]) || ob->query_dead() || ob->query_hidden())
    return "El arte de emboscar consiste en intentar matar algo vivo "
      "que este aqui.\n";

	if (caster == ob) {
		return "Mmm, parece que no eres capaz de buscar un punto "
		"debil por tu propia espalda.\n";
	}

    if(ob->query_property("pacify_on"))
    {
        return "Te rompe el corazon el emboscar a alguien tan necesitado.\n";
    }


	if (!caster->query_hidden()) {
		tell_object(ob, caster->QCN+" se acerca por tu espalda, "
		"mirandola detenidamente al tiempo que babea, y te "
		"intenta emboscar!\n");
		caster->attack_by(ob);
		ob->attack_by(caster);

		return "Tu victima te ha visto acercandote a su espalda!\n";
	}

  caster->add_spell_effect(2, "emboscando", SP_NAME,
    this_object(), "hb_spell", ({ ob }));
  return 1;
}

int ambush_damage(object weapon,object me,object victim)
{
    int lvl;
    int dam;
    if(!weapon) return 0;

    dam = (int)weapon->query_damage_roll()+ (int)me->query_damage_bonus();
    lvl = (int)me->query_level()/2 + 1;
    dam = dam*lvl;
    // Temporary hack.
    dam = random(dam)/2 + random(dam)/2 + random(dam)/3 + 1;

    // Cap at current hp and min at level
    return dam + 150;
}

/* no mola esta funcion
int ambush_damage1(int dam,object me, object victim)
{
    int lvl;
    lvl = me->query_level();
    dam = (dam > me->query_hp() ? me->query_hp() : dam);
    dam = (dam < lvl ? lvl : dam);

    if(dam > (int)victim->query_max_hp() )
        dam = (int)victim->query_max_hp()+1;
    return dam;
}*/

string mensaje(int danio, object caster, object ob) {
	int factor, relativo;
	string mess1, mess2;

	factor = danio * 100 / ob->query_max_hp();
	relativo = danio * 100 / ob->query_hp();

	switch (factor) {
		case 125..149:
			mess1 = "Apalizas con todo tu odio el cuerpo de "+ob->QCN;
			break;
		case 115..124: // Algun brazalete puede salvarlo.
			mess1 = "Con un magnifico golpe pleno de elegancia, desnucas a "+ob->QCN;
			break;
		case 95..114:
			mess1 = "Hundes la cabeza de "+ob->QCN+" entre sus hombros";
			break;
		case 85..94:
			mess1 = "Encuentras un punto vital en la espalda de "+ob->QCN+" y hundes tu arma en el con todas tus fuerzas";
			break;
		case 75..84:
			mess1 = "Coges carrerilla y golpeas brutalmente la cabeza de "+ob->QCN;
			break;
		case 50..74:
			mess1 = "Das un salto y golpeas sin piedad la cabeza de "+ob->QCN;
			break;
		case 35..49:
			mess1 = "Golpeas fuertemente la cabeza de "+ob->QCN;
			break;
		case 20..34:
			mess1 = "Golpeas debilmente la cabeza de "+ob->QCN;
			break;
		case 10..19:
			mess1 = "Golpeas pateticamente la cabeza de "+ob->QCN;
			break;
		case 0..9:
			mess1 = "Golpeas casi sin querer la cabeza de "+ob->QCN;
			break;
		default:
			mess1 = "Abres brutalmente el craneo de "+ob->QCN+" esparciendo sus sesos por la zona";
	}

	if (danio > ob->query_hp()) {
		mess2 = ", lo que acaba con su vida de forma cruel.";
	}
	else if ((danio < ob->query_hp()) && (ob->query_hp() - danio < 25)) {
		mess2 = ". Eso deberia acabar con el.";
	}
	else
	switch (relativo) {
		case 70..89:
			mess2 = ", haciendole una herida que le llega hasta lo mas profundo de los huesos.";
			break;
		case 50..69:
			mess2 = ", haciendole sangrar sin control.";
			break;
		case 30..49:
			mess2 = ", abriendole una buena herida en la espalda.";
			break;
		case 20..29:
			mess2 = ", haciendole poco danyo.";
		case 0..19:
			mess2 = ", pero apenas parece sufrir.";
			break;
		default:
			mess2 = ". Su cabeza sangra a borbotones, no vivira por mucho tiempo.";
	}

	return mess1 + mess2 + "\n";
}

int hb_spell(object caster, mixed *params, int time)
{
  int amount, gp_cost;
	object aweap;
	object *weap;
	string mess;

	if (sizeof(caster->query_attacker_list())) {
		tell_object(caster, "Al entrar en combate no puedes continuar con tu emboscada.\n");
		call_out("end_hb_spell", 0, caster);
		return 0;
	}
	if (!caster->query_hidden()) {
		  if (params[0] && environment(caster) == environment(params[0])
			&& !params[0]->query_hidden() ) {
			tell_object(params[0], "Descubres a "+caster->QCN
			+ " intentando darte boleto para el otro barrio!\n");
			tell_object(caster, params[0]->QCN+" te descubre "
			"intentando emboscarle y te ataca!\n");
			tell_room(ENV(caster), params[0]->QCN+" descubre a "+caster->QCN+" intentando asesinarle!\n", ({caster, params[0]}));
			caster->attack_by(params[0]);
			params[0]->attack_by(caster);
			call_out("end_hb_spell", 0, caster);
			return 0;
			}
		tell_object(caster, "Tu victima no esta aqui!\n");
		call_out("end_hb_spell", 0, caster);
		return 0;
	}
	if (!params[0] || environment(caster) != environment(params[0])
		|| params[0]->query_hidden() ) {
		tell_object(caster, "Tu victima no esta aqui!\n");
		call_out("end_hb_spell", 0, caster);
		return 0;
	}
	if (ENV(caster) != roomorig) {
		tell_object(caster, "Si no paras de moverte no podras emboscar!!\n");
		call_out("end_hb_spell", 0, caster);
		return 0;
	}
	if (params[0]->query_dead() || !living(params[0])) {
		tell_object(caster, "Otro ya ha hecho el trabajo por ti.\n");
		call_out("end_hb_spell", 0, caster);
		return 0;
	}
	if (time > 1)
		return 1;
	// ROUND FINAL, DONDE SE ASESTA O NO LA EMBOSCADA
	// DEVOLVER DANYO FECHO

    gp_cost = (int)caster->query_level() * 2;
    if(gp_cost > 25)
        gp_cost = 25;
    if((int)caster->adjust_gp(-gp_cost) == -1)
    {
        tell_object(caster,"No tienes suficiente energia para emboscar! "
          "Intentalo mas tarde.\n");
		call_out("end_hb_spell", 0, caster);
        return 0;
    }

  caster->add_timed_property(HEAL_LOCKOUT, 1, HEAL_LOCKOUT_TIME);

    if( (int)params[0]->query_property("sens_life"))
    {
        tell_object(caster,"Tu victima parece haberte descubierto intentando "
          "prepararte tus armas, quizas correr pueda ser una buena idea.\n");
        tell_object(params[0],"Los ojos de "+caster->query_cap_name()+" te miran "
          "especulando.\nPrepara sus armas y ataca en un estallido de "
          "furia!\n");
	tell_room(ENV(caster), params[0]->QCN+" descubre a "+caster->QCN+" intentando asesinarle!\n", ({caster, params[0]}));
	//caster->dest_hide_shadow();
        caster->attack_by(params[0]); // creo q esto ya fuerza el dest_hide_shadow
	params[0]->attack_by(caster);
		call_out("end_hb_spell", 0, caster);
        return 0;
    }

    weap = (object *)caster->query_held_ob();
    aweap = 0;
    if ( weap[0] )
        aweap=weap[0];
    else if ( weap[1] )
        aweap=weap[1];
    else aweap=0;

    if (!aweap)
    {
	tell_object(params[0], ((caster->query_gender() == 1) ? "El" : "La") +
	" inutil de "+caster->QCN+" se disponia a asesinarte pero ve "
	"que lleva las manos vacias!\n");
        tell_object(caster,"Te diriges felizmente a golpear a tu victima cuando te ves con las manos vacias!\n");
	tell_room(ENV(caster), ((caster->query_gender() == 1) ? "El" : "La") +
	" inutil de "+caster->QCN+" se disponia a asesinar a "+
	params[0]->QCN+" pero ve que lleva las manos vacias!\n", ({caster, params[0]}));
	//caster->dest_hide_shadow();
	caster->attack_by(params[0]);
	params[0]->attack_by(caster);
		call_out("end_hb_spell", 0, caster);
        return 0;
    }

    // if (sizeof(weap) > 1) asi si weap[0] es NULL tb lo cuenta!
	if (sizeof(weap) > 1 && weap[0] && weap[1])
    {
	if (caster->query_level() < 38) {
	tell_object(params[0], caster->QCN+" se hace un lio con sus armas "
	"al intentar golpearte!\n");
        tell_object(caster,"Te haces un lio con tus armas y "+params[0]->QCN+" se da cuenta!\n");
	tell_room(ENV(caster), caster->QCN+" se hace un lio con sus armas "
	"al intentar golpear a "+params[0]->QCN+"!\n", ({caster, params[0]}));
	//caster->dest_hide_shadow();
	caster->attack_by(params[0]);
	params[0]->attack_by(caster);
		call_out("end_hb_spell", 0, caster);
        return 0;
	}
	// ambush a 2 armas
	amount = ambush_damage(weap[0],caster,params[0]) + ambush_damage(weap[1],caster,params[0]);
    }
    else
    	amount = ambush_damage(aweap,caster,params[0]);

    //amount = ambush_damage1(amount,caster,params[0]);

    if( sizeof(params[0]->query_attacker_list()) )
    {
	if (!random(caster->query_cha())) {
        tell_object(caster,"Ooops, "+(string)params[0]->query_cap_name()+
          " te ve llegar, y te asesta un soberano golpe a ti "
          "primero.\n");
        tell_object(params[0],(string)caster->query_cap_name()+
          " de repente hace un extranyo movimiento, y salta sobre ti. "
	  "Te diriges hacia el rodeandolo y le asestas un espectacular golpe.\n");
	tell_room(ENV(caster), params[0]->QCN+" descubre a "+caster->QCN+" intentando asesinarle!\n", ({caster, params[0]}));
        caster->adjust_hp(-amount/3, params[0]);
	caster->attack_by(params[0]);
	params[0]->attack_by(caster);
		call_out("end_hb_spell", 0, caster);

	return 0;
	}
	tell_object(caster, "Argh, "+params[0]->QCN+" se da cuenta de tus intenciones y te ataca!\n");
	tell_object(params[0], "Milagrosamente descubres a "+caster->QCN+" antes de que te parta la crisma!\n");
	tell_room(ENV(caster), params[0]->QCN+" descubre a "+caster->QCN+" intentando asesinarle!\n", ({caster, params[0]}));
	caster->attack_by(params[0]);
	params[0]->attack_by(caster);
		call_out("end_hb_spell", 0, caster);

	return 0;
    }


  mess = mensaje(amount, caster, params[0]);

        // aweap->event_ambush(amount,caster,params[0]);
	if (weap[0])
        	weap[0]->event_ambush(amount,caster,params[0]);
	if (weap[1])
        	weap[1]->event_ambush(amount,caster,params[0]);
        caster->add_timed_property("guildsuc",1,2); // ???

  tell_object(caster, mess);
  tell_object(params[0], caster->QCN+" te golpea inesperadamente con un ataque brutal!\n");
  tell_room(environment(caster), caster->QCN+ " golpea a "+ params[0]->QCN+
    " con un ataque brutal!\n", ({ caster, params[0] }) );

  params[0]->adjust_hp(-amount,caster);

	caster->attack_by(params[0]);
	params[0]->attack_by(caster);

  return amount;
}
