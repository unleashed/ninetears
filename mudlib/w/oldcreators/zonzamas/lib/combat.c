/* Ok, this time it's this code I will walk through...
 * Baldrick, april '94
 * Removed the deathstuff and pu tit in death.c.
 * looks a lot better that way.
 * Added change of alignment in attack_ob, removed from death.c
 * Hope it will work, Baldrick, june '96
 */

inherit "/std/unarmed_combat";

/* Hmm, are we using these now ? */
int *weapon_attack_out, *attack_out;                //dk

static object attackee;
static object *attacker_list,
*call_outed,
protector;

static object concentrate;
static int dodging;


#define DIV_NUM 6
#include "money.h"

void set_weapon_attack_out(int mess, object *held_ob) { }

int query_dodging() { return dodging; }
int query_my_att_level() { return (int)this_object()->query_level(); }
int set_concentrate(object ob)
{
    if ( member_array(ob, attacker_list) == -1 ) return 0;
    concentrate = ob;
    return 1;
}
object query_concentrate() { return concentrate; }
int query_concentrate_valid() { return 0; }

// Radix, added for unprotect add_action
int remove_protector(object ob) { return(protector = 0); }
object set_protector(object ob) { return (protector = ob); }
object query_protector() { return protector; }

int query_fighting()
{
    int i;

    attacker_list -= ({0});
    call_outed -= ({0});
    for (i=0;i<sizeof(attacker_list);i++)
    {
	if (interactive(attacker_list[i]))
	    return 4;
	if (attacker_list[i]->query_aggressive())
	    return 1;
	else
	    return 2; 
    }

    for (i=0;i<sizeof(call_outed);i++)
    {
	if (interactive(call_outed[i]))
	    return 4;
	if (call_outed[i]->query_aggressive())
	    return 1;
	else
	    return 2; 
    }
    return 0;
}

int query_protect_valid(object attacker, object protectee)
{
    int base_roll;

    // Wonderflug, dec 95, can't protect while berserk
    if ( this_object()->query_property("flipped") )
	return 0;

    base_roll = random(100);   /* this to be replaced by a guild obj call */
    if ( member_array( attacker, attacker_list ) == -1 )
	base_roll -= 20;

    return ( base_roll >= 30 );
}

void actual_death();

void create() 
{
    attacker_list = ({ });
    call_outed = ({ });
    concentrate = 0;
    unarmed_combat::create();
}

void combat_commands() 
{
    add_action("do_protect", "prot*eger");
    add_action("do_protect", "protect");
    add_action("do_unprotect","desprot*eger");
    add_action("do_unprotect","unprotect");
    unarmed_combat_commands();
}

object query_attackee() { return attackee; }

// NEW by Tyrael - Feb '02 - Fns Maskeables por shadows
int weapons_attack(object him, object me, int n, object *weaps) {
	int olav = 0, dam = 0;

	for(; olav < n; olav++)
	    dam += (int)weaps[olav]->weapon_attack(attackee,this_object());

	return dam;
}

int shields_attack(object him, object me, int n, object *shields) {
	int escudos_hits, olav = 0, dam = 0;

	// ahora golpear con escudos
	if ((escudos_hits = me->query_property("shield_hits"))) {
		if (escudos_hits > n)
			escudos_hits = n;
		for (; olav < escudos_hits; olav++)
			dam += (int)shields[olav]->shield_attack(attackee, TO);
	}
	return dam;
}

// no mu bonito el nombre pero sirve :P
// ia cambiaremos esto para que pegue tantas veces como manos libres.
// mirar el danyo medio de unarmeds, no vaya a ser q aun sea mejor
// ir sin armas q con ellas.
// considerar incluir flag por si se llamo antes a weapon o shield
// ultimo parm: si se usaron o no armas/escudos antes.
int unarmeds_attack(object him, object me, int n, int ws_used) {
	int dam = 0, olav = 0;
	// ahora golpes desarmado
	// es un poco flonante
	for (; olav < n; olav++)
		dam += TO->unarmed_attack(attackee,this_object());
	return dam;
}

// EDITAR AQUI PARA NO PERMITIR PEGAR A LA VEZ QUE SE FORMULA... - Tyrael
// La pregunta es... por ejemplo al formular un mayor, dejamos que se vea
// lo de "Estas persiguiendo a ..." antes de acabar el hechizo? _:P
void attack()
{
    int i, dam, his_att_lvl, olav, att_level;
    string his_name;
    object *obs,ob,*ww;

    if (!attacker_list)
	attacker_list = ({ });
	// New by Tyrael - Feb '02 - No pegamos mientras formulamos
	// a menos que llevemos la propiedad adecuada
	// si nadie nos ataka no tenemos q devolver golpes...
	if (sizeof(TO->query_attacker_list()))
    if (TO->query_spell_effect("spell") && !TO->query_property("pegar_y_formular")) {
		tell_object(TO, "Estas demasiado concentrado para devolver el golpe.\n");
		return;
    }

    while (i<sizeof(attacker_list)) {
	if (!attacker_list[i])       //dw have they died unexpecedaly? 
	    attacker_list = delete(attacker_list,i,1);
	else
	    //dw    I will put all the ones not in the correct environ in a new list.

	if (environment(attacker_list[i]) != environment(this_object())) {
	// NEW BY TYRAEL, arregla lo de Estas persiguiendo a *Alguien* / 0.
	// en lugar de tener que hacer funciones especiales en cada shadows, a partir
	// de ahora el short para estas cosas es combat_short()
		//if (attacker_list[i]->query_hidden())
	    //write("Estas persiguiendo a "+capitalize(attacker_list[i]->hidden_short())+".\n");
		//else
	    write("Estas persiguiendo a "+capitalize(attacker_list[i]->combat_short())+".\n");
	// no se puede tar en peleas por siempre jamas mirar a ver como
	//hacer para parar peleas tras cierto time y que no haya problemas de
	//call_out, como volver a empezarlas y q se pare por un call_out
	    if (!call_outed)
		call_outed = ({ attacker_list[i] });
	    else
		call_outed += ({ attacker_list[i] });
	    attacker_list = delete(attacker_list,i,1);
	} else
	    i++;
    }

    //dw check the not correct environ list to see if any one has come back.  
    i = 0;
    while (i<sizeof(call_outed))
	if (!call_outed[i])
	    call_outed = delete(call_outed,i,1);
	else if (environment(this_object()) == environment(call_outed[i])) {
	    attacker_list += ({ call_outed[i] });
	    call_outed = delete(call_outed,i,1);
	} else
	    i++;
	//dw not hitting anyone... do spell effects anyway... 
    if (!sizeof(attacker_list)) {
	attackee = 0;
	return;
    }
    //dw choose a random person from the attacker list; they're in correct env.
    if ( concentrate )
    {
	if ( member_array( concentrate, attacker_list ) == -1 )
	{
	    attackee = attacker_list[random(sizeof(attacker_list))];
	    concentrate = 0;
	}
	else
	{
	    attackee = concentrate;
	    if ( !this_object()->query_concentrate_valid(
		concentrate, attacker_list) )
		concentrate = 0;
	}
    }
    else
	attackee = attacker_list[random(sizeof(attacker_list))];

    //dw Check to see if they are being protected.

// Bug fixed protegiendo y haciendo kill al mismo. Alex.
// Cuando atacas a uno que proteges hasta que el no fone
// attack() no nos quitamos de protegerlo...

	if ((ob = (object) attackee->query_protector()) == TO) {
		attackee->remove_protector(TO);
	tell_object(attackee, TO->QCN + " deja de protegerte.\n");
	tell_room(environment(TO),TO->query_cap_name()+" deja de "
	  "proteger a "+attackee->QCN+".\n", ({attackee, TO }));
	}

// ahora esto ya sobra :)
    if (protector && member_array(protector, attacker_list) != -1) {
	tell_object(this_object(), protector->query_cap_name()+
	  " se vuelve contra ti y te ataca.\n");
	tell_object(protector, "Comienzas a atacar a "+
	  this_object()->query_cap_name()+" y dejas de proteger"+
	  this_object()->query_objective()+".\n");
	say(protector->query_cap_name()+" se vuelve contra "+
	  this_object()->query_cap_name()+" y le ataca.\n",
	  ({ protector, this_object() }));
	/* This has been missing far too long, Wonderflug */
	protector = 0;
    }
    // error si pasas un array VACIO
    if (ob && environment(ob) == environment(attackee) &&
      ob->query_protect_valid(this_object(), attackee) )
    {
	if (!ob->query_dead())
	{
	    tell_object(attackee, ob->query_cap_name()+
	      " te protege valientemente.\n");
	    tell_object(ob,"Proteges valientemente a "+attackee->query_cap_name()+".\n");
	    say(ob->query_cap_name()+" protege valientemente a "+
	      attackee->query_cap_name()+".\n", ({ attackee, ob }));
	    attackee = ob;
	}
    }
    his_att_lvl = maxi(({ (int)attackee->query_level(), 1 }) );

    his_name = (string)attackee->query_name();

    attackee->attack_by(this_object());


    // Attack code below by Aragorn / Fully rewritten by Tyrael.
	// QUIEN le ha dicho a este listo que solo tenemos una mano libre?

	// Sistema de ataques con manos/escudos/armas reescrito y mejorado
	// Tyrael - Nov 2001

	// Radix added this_object()-> for shadows

	// NUEVO SISTEMA para permitir shadows de golpeos con armas
	// y escudos (desarmado ya existe :P)
	// Tyrael - Feb '02
	// pasar TO sera necesario? de momento ahi keda
	// el tercer parametro es para no tener q repetir el sizeof
	{
	int armas_usadas = 0;

	if ((i = sizeof((ww = TO->query_weapons_wielded())))) {
		armas_usadas++;
		dam += TO->weapons_attack(attackee, TO, i, ww);
	}
	if ((i = sizeof((ww = TO->query_shields_held())))) {
		armas_usadas++;
		dam += TO->shields_attack(attackee, TO, i, ww);
	}
	// TB unarmeds_attack() para poder manejar a antojo los
	// atakes desarmado en shadows
	if (!armas_usadas || TO->query_property("unarmed_manos_libres"));
	{
	if ((i = TO->query_free_hands_left()))
		dam += TO->unarmeds_attack(attackee, TO, i, armas_usadas);
	}
	}

    if (!attackee)
    {
	tell_object(this_object(),"Has matado a "+his_name+"\n");
	say(this_object()->query_cap_name()+" ha matado a "+his_name+"\n");
    }

    // Fix by Aragorn
    att_level = (int)this_object()->query_level();
    att_level = att_level?att_level:1;
    ++att_level;
    this_object()->adjust_xp(dam*(his_att_lvl/att_level));
    event(environment(this_object()), "fight_in_progress", attackee);
}

void attack_by(object ob)
{
    if (ob == this_object())
	return ;
    if(this_object()->query_hidden())
	return;
    if (!attacker_list)
	attacker_list = ({ });
    if (!sizeof(attacker_list)) 
    {
	dodging = (int)this_object()->query_level();
    }
    if (member_array(ob, attacker_list) == -1 &&
      member_array(ob, call_outed) == -1) 
    {
	tell_object(this_object(), "Estas siendo atacado por " + 
		ob->combat_short() + ".\n");
	  //ob->query_short() + ".\n");

	if (this_object()->query_consent("autogolpear")) attacker_list += ({ ob });
    }
    set_heart_beat(1);
}

/* Hmm, this is called by the attacker, object ob is the victim */
void attack_ob(object ob) 
{
    int align;

    if (ob == this_object())
	return;

    if (ob->query_dead())
	return;

    /*
     * Should use the one used by death.c before.
     */

    /*
      align = ob->query_align() * ob->query_level();

      if (align > 100) 
	align = 100;
      if (align < -100)
	align = -100;
    */
    // not good to attack evil, multiplying by level gave numbers too big
    // probably should be LAWFULL to attack evil... Anirudh
    align = ob->query_align();

    if (align > 0) align = 0;
    if (align < -100) align = -100;

    if (!attacker_list)
	attacker_list = ({ });
    if (!sizeof(attacker_list)) 
    {
	/* This will be changed later.. */
	dodging = (int)this_object()->query_level();
    }
    if (member_array(ob, attacker_list) == -1 &&
      member_array(ob, call_outed) == -1) 
    {
	if (this_object()->query_consent("autogolpear")) attacker_list += ({ ob });
	this_object()->adjust_align(-align); 
    }
    if (ob)
	ob->attack_by(this_object());
}

void check_stop_fight(object ob) 
{
    int i;
    if ((i=member_array(ob,call_outed)) != -1)
	call_outed = delete(call_outed,i,1);
}

int stop_fight(object ob) 
{
    int i;
    if ((i=member_array(ob,call_outed)) != -1) {
    	//if (call_outed[i]->query_hidden())
    	//tell_object(TO, "Paras de perseguir a "+call_outed[i]->hidden_short()+".\n");
    	//else
	tell_object(this_object(),"Paras de perseguir a "+CAP(call_outed[i]->combat_short(0))+
	  ".\n");
	call_outed = delete(call_outed, i, 1);
    }
    if ((i=member_array(ob,attacker_list)) != -1)
	attacker_list = delete(attacker_list,i,1);
}

mixed *query_attacker_list()
{
    attacker_list -= ({0});
    return attacker_list;
}

mixed *query_call_outed()
{
    call_outed -= ({0});
    return call_outed;
}

/** added by Raskolnikov Oct 96 **/
mixed *remove_call_outed()
{
    call_outed = ({ });
    return call_outed;
}

/** added by Raskolnikov Oct 96 **/
mixed *reset_attacker_list()
{
    attacker_list = ({ });
    return attacker_list;
}


//dw   Sets up protection matrixes.
int do_protect(string str) 
{
    object *obs, *ok, *enemies; int i;
    if (!str) 
    {
	notify_fail("Sintaxis: proteger <persona(s)>\n");
	return 0;
    }
    obs = find_match(str, environment(this_object()));
    if (!sizeof(obs)) 
    {
	notify_fail("Proteger a quien?\n");
	return 0;
    }
	// proteger a si mismo se puede!! esto no rula bien, fixeando - Tyrael
    //dk added member_array to this next line:
    if (member_array(this_object(), obs))
	//dk I changed this next line from this_player() to this_object():
	obs -= ({ this_object() });
    ok = ({ });
	enemies = TO->query_attacker_list();
    for (i=0; i<sizeof(obs); i++) {
	//if (sizeof(enemies))
		if (member_array(obs[i], enemies) != -1) {
			// eliminar msg para no floods?
			//tell_object(TO, "Proteger a "+obs[i]->QCN+" de ti mismo?\n");
			continue;
		}
		if (obs[i] == TO)
			continue;
	if (obs[i]->set_protector(this_object()))
	    ok += ({ obs[i] });
    }
// seria if (sizeof(obs - ok))... ? - Tyrael
//    if (!sizeof(ok)) 
    if (sizeof(obs) != sizeof(ok)) 
    {
	notify_fail(CAP(query_multiple_short(obs-ok))+ " no quiere" +
	  (sizeof(obs)==1?" ":"n ")+"tu proteccion.\n");
	return 0;
    }
/* unreachable y tal :)
    if (sizeof(obs) != sizeof(ok))
	write("No puedes proteger a "+query_multiple_short(obs - ok)+".\n");
*/
    write("Proteges a "+query_multiple_short(ok)+".\n");
    say(this_object()->query_cap_name()+" protege a "+query_multiple_short(ok)+
      ".\n", ok);
    for (i=0; i<sizeof(ok); i++)
	tell_object(ok[i], this_object()->query_cap_name()+" protege a "+
	  query_multiple_short(({ "ti" }) + (ok - ok[i..i]))+".\n");
    return 1;
}
// Added by Radix, missing too long...
int do_unprotect(string str)
{
    object tmp;
    if(!str)
    {
	notify_fail("Sintaxis: desproteger <persona(s)>\n");
	return(0);
    }
    tmp = find_living(str);
    if(!tmp)
    {
	notify_fail("Desproteger a quien?\n");
	return(0);
    }
    if(tmp->query_protector() != this_object())
    {
	write("No estabas protegiendo a "+tmp->query_cap_name()+".\n");
	return(1);
    }
    tmp->remove_protector(this_object());
    if(environment(tmp) == environment(this_object()))
    {
	tell_object(tmp,this_object()->query_cap_name()+" se aparta y "
	  "deja de protegerte.\n");
	tell_room(environment(),this_object()->query_cap_name()+" deja de "
	  "proteger a "+tmp->query_cap_name()+".\n", ({tmp, this_object() }));
    }
    write("Te apartas y dejas de proteger a "+tmp->query_cap_name()+".\n");
    return(1);
}

mixed stats() 
{
    int i; object ob; mixed *ret;
    if (ob=this_object()->query_held_ob(0) && ob->query_weapon())
	ret += ({ ({ "Weapon", ob->short() }) }) + (mixed)ob->weapon_stats();
    if (ob=this_object()->query_held_ob(1) && ob->query_weapon())
	ret += ({ ({ "Secondary weapon", ob->short() }) });
    for (i=0; i<sizeof(attack_out); i+=7) 
	ret += ({ ({ "If",    attack_out[i], }), 
	  ({ "Rate",  attack_out[i+1], }), 
	  ({ "Attack", attack_out[i+2], }), 
	  ({ "Tohit", attack_out[i+3], }), 
	  ({ "Number of damage dice", attack_out[i+4], }), 
	  ({ "Die size", attack_out[i+5], }), 
	  ({ "Addend", attack_out[i+6], }), 
	}); 
    return ret;
}
