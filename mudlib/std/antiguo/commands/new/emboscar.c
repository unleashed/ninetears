#include "tweaks.h"

#define LOCK_PROP "ambushing"

/** Ambush.c by Taniwha, with a spot of help from Ilmryn. **/
/** This is a very nasty attack command, designed for the Assassin's guild
    ONLY.  It is made pretty nasty because Assassins are killers, and they 
    are supposed to kill in one shot.  Since we can't do anything that nasty
    here, we decieded on a high damage command that does it's damage with a 
    single attack.  It maybe attempted with any weapon, and the damage is 
    level of the user, divided by 2, times the damage roll of the weapon 
    , and all of this randomized.  The damage multiplier stops going up at
    level 20, for a max multiplier of 10.  While testing it at level 10 the
    damage ranged from 15-30, and at level 30 the damage was around 50.  This
    was ALL well below the damage capable of being done by a wizard of equal
    or lower level.  Also of note is the fact that if the user is listed in
    the attacking list then they suffer damage.  Even if they have stopped,
    but are being hunted by a monster or character for 3 screens ago, they
    get damaged, and obviously fail the ambush.  This should be more than
    adequate balancing for the capabilities of this command. 

    Altered 1996, so they can use two weapons once the two handed 
	 penalty goes.
 ****/


static int already_attacking(object me,object victim)
{
    if(sizeof(me->query_attacker_list()))return 1;
    if(member_array(me,victim->query_attacker_list()) != -1) 
	return 1;
    if(member_array(me,victim->query_call_outed()) != -1) 
	return 1;
    return 0;
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
    return dam;
}

int ambush_damage1(int dam,object me, object victim)
{
    int lvl;
    lvl = me->query_level();
    dam = (dam > me->query_hp() ? me->query_hp() : dam);
    dam = (dam < lvl ? lvl : dam);

    if(dam > (int)victim->query_max_hp() ) 
	dam = (int)victim->query_max_hp()+1;
    return dam;
}

int ambush(string str,object x) 
{
    int i;
    int gp_cost;
    int damage;
    object me;
    object aweap;
    object *weap;
    object *vlist;
    object victim;

    if(x) 
	me = x;  
    else 
	me = this_player();

    str = me->expand_nickname(str);
    me->adjust_gp(-1);

    if (!str)
    {
	tell_object(me,"Estas intentando emboscar?\n");
	return 1;
    }

    weap = (object *)me->query_held_ob();
    aweap = 0;
    if ( weap[0] ) 
	aweap=weap[0];
    else if ( weap[1] ) 
	aweap=weap[1];
    else aweap=0;

    vlist = find_match(str,environment(me));
    if(!sizeof(vlist))
    {
	tell_object(me,"Fantaseando sobre alguna emboscada?  "
	  "intenta con algo que este aqui.\n");
	return 1;
    }

    victim = vlist[0];
    if(victim == me)
    {
	tell_object(me,"Emboscandote a ti mismo?  seguro que no te notas a ti "
	  "mismo..\n");
	return 1;
    }
    if( victim->query_dead() || !living(victim) )
    {
	tell_object(me,"Emboscas a "+victim->query_cap_name()+".\n"
	  "Procura lanzarte sobre algo vivo la proxima vez.\n");
	return 1;
    }
    gp_cost = (int)me->query_level() * 2;
    if(gp_cost > 25) 
	gp_cost = 25;
    if((int)me->adjust_gp(-gp_cost) == -1)
    {
	tell_object(me,"No tienes suficiente energia para emboscar! "
	  "Intentalo mas tarde.\n");
	return 1;
    }
    if(victim->query_property("pacify_on"))
    {
	write("Tu corazon se rompe al intentar emboscar a alguien tan necesitado de ayuda.\n");
	return 1;
    }
    // Taniwha 1996, once they ahve the skill, let them swing two blades
    if(me->query_guild_ob()->query_dual_weapon_penalty(me,weap[0],weap[1]))
    {
	if ( weap[0] && weap[1] )
	{
	    tell_object(me,"You try to make your ambush but slip up with your "
	      "hands all full like that, and screw it up severely.\n");
	    victim->attack_by(me);
	    return 1;
	}
	damage = ambush_damage(aweap,me,victim);
    }
    else
    {
	damage = ambush_damage(weap[0],me,victim) +
	ambush_damage(weap[1],me,victim);
    }	
    damage = ambush_damage1(damage,me,victim);
    if (!aweap)
    {
	tell_object(me,"Emboscar con que?\n");
	return 1;
    }
    if(me->query_property(LOCK_PROP))
    {
	tell_object(me, "No estas suficientemente calmado para emboscar.\n");
	return 1;
    }
    me->add_timed_property(LOCK_PROP,100,AMBUSH_LOCKOUT);


    if( (int)victim->query_property("sense_life"))
    {
	tell_object(me,"Tu victima parece haberte parado "
	  "preparando tus armas, no estas preparado. ?\n");
	tell_object(victim,"Marcas a "+me->query_cap_name()+" con un guinyo "
	  "espectacular.\nPreparas tus armas y realizas un ataque brutal con toda tu "
	  "furia!\n");
	victim->attack_by(me);
	return  1;
    }

    if(already_attacking(me,victim))
    {
	tell_object(me,"Ooops "+(string)victim->query_cap_name()+
	  " sees you coming, and turns in time to land a solid blow on you "
	  "first.\n");
	tell_object(victim," "+(string)me->query_cap_name()+
	  " suddenly makes a strange move, and then leaps at you.  You manage "
	  "to spin around in time and land a vicious blow on them.\n");
	me->adjust_hp(-damage/2, victim);
    }
    else
    {
	// Fake event trigger for "special" weapons - Radix
	aweap->event_ambush(damage,me,victim);
	victim->adjust_hp(-damage, me);
	me->add_timed_property("guildsuc",1,2);
	tell_object(victim,(string)me->query_cap_name()+" hits you "
	  "totally unexpectedly with a vicious blow.\n");
	tell_object(me,"You catch "+(string)victim->query_cap_name()+
	  " flat footed with your ambush.\n");
    }
    victim->attack_by(me);
    return 1;
}

string help(string str) 
{
    return
    "\nSyntax: ambush <person>\n\n"
    "Ambush is a nastier version of the backstab command.  It takes into "
    "account the assassin's detailed knowledge of the body, and of the art "
    "of killing.  Combining this with the element of surprise, it is "
    "deadly.  But because it takes total concentration, you must be at "
    "absolute peace with yourself and strong in heart and body to "
    "succeed, if not your opponent will most likely see you coming, and "
    "turn your attack back upon you.\n\n";
}
